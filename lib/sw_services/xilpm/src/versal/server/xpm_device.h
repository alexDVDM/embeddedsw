/******************************************************************************
*
* Copyright (C) 2018-2020 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
*
*
******************************************************************************/

#ifndef XPM_DEVICE_H_
#define XPM_DEVICE_H_

#include "xpm_node.h"
#include "xpm_power.h"
#include "xpm_clock.h"
#include "xpm_reset.h"
#include "xpm_requirement.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DDRMC_DEVID(IDX)	NODEID(XPM_NODECLASS_DEVICE, \
	XPM_NODESUBCL_DEV_MEM_CTRLR, XPM_NODETYPE_DEV_DDR, (IDX))

#define GT_DEVID(IDX)	NODEID(XPM_NODECLASS_DEVICE, \
	XPM_NODESUBCL_DEV_PHY, XPM_NODETYPE_DEV_GT, (IDX))

#define DEFINE_DEV_STATES(S)	.States = (S), \
				.StatesCnt = ARRAY_SIZE(S)

#define DEFINE_DEV_TRANS(T)	.Trans = (T), \
				.TransCnt = ARRAY_SIZE(T)

#define DEVICE_NO_IDLE_REQ	(0U)
#define DEVICE_IDLE_REQ		(1U)

/* Device states */
typedef enum {
	XPM_DEVSTATE_UNUSED,
	XPM_DEVSTATE_RUNNING,
	XPM_DEVSTATE_PWR_ON,	/* Power up the island/domain */
	XPM_DEVSTATE_CLK_ON,	/* Enable clock */
	XPM_DEVSTATE_RST_OFF,	/* De-assert reset */
	XPM_DEVSTATE_RST_ON,	/* Assert reset */
	XPM_DEVSTATE_CLK_OFF,	/* Disable clock */
	XPM_DEVSTATE_PWR_OFF,	/* Power down */
	XPM_DEVSTATE_SUSPENDING,
	XPM_DEVSTATE_RUNTIME_SUSPEND,
} XPm_DeviceState;

/* Device events */
typedef enum {
	XPM_DEVEVENT_BRINGUP_ALL,
	XPM_DEVEVENT_BRINGUP_CLKRST,
	XPM_DEVEVENT_SHUTDOWN,
	XPM_DEVEVENT_TIMER,
	XPM_DEVEVENT_RUNTIME_SUSPEND,
} XPm_DeviceEvent;

typedef struct XPm_Subsystem XPm_Subsystem;
typedef struct XPm_Requirement XPm_Requirement;
typedef struct XPm_Device XPm_Device;
typedef struct XPm_DeviceOps XPm_DeviceOps;
typedef struct XPm_DeviceStatus XPm_DeviceStatus;

/* Device Operations */
struct XPm_DeviceOps {
	XStatus (*Request)(XPm_Device *Device, XPm_Subsystem *Subsystem,
			   u32 Capabilities, const u32 QoS);
		/**< Request: Request the device */

	XStatus (*SetRequirement)(XPm_Device *Device,
		XPm_Subsystem *Subsystem,
		u32 Capabilities, const u32 QoS);
		/**< SetRequirement: Set the device requirement */

	XStatus (*Release)(XPm_Device *Device,
		XPm_Subsystem *Subsystem);
		/**< Release: Release the device */
};

/* Transition for a state in finite state machine */
typedef struct {
	const u32 Latency; /**< Transition latency in microseconds */
	const u32 FromState; /**< From which state the transition is taken */
	const u32 ToState; /**< To which state the transition is taken */
} XPm_StateTran;

/* Device capability in each state */
typedef struct {
	const u8 State; /**<  Device state */
	const u32 Cap; /**< Capability associated with state */
} XPm_StateCap;

/* Device Finite state machine */
typedef struct {
	const XPm_StateCap* const States; /**< Pointer to states array. */
	XStatus (*const EnterState)(XPm_Device* const Device, const u32 NextState);
	/**< Pointer to a function that executes FSM actions to enter a state*/
	const XPm_StateTran* const Trans;
	/**< Pointer to array of transitions of the FSM */
	const u8 StatesCnt; /**< Number of elements in states array */
	const u8 TransCnt; /**< Number of elements in transition array */
} XPm_DeviceFsm;

/**
 * The device class.  This is the base class for all the processor core,
 * memory bank and peripheral classes.
 */
struct XPm_Device {
	XPm_Node Node; /**< Node: Base class */
	XPm_Power *Power; /**< Device power node */
	XPm_ClockHandle *ClkHandles; /**< Head of the list of device clocks */
	XPm_ResetHandle *RstHandles; /**< Head of the list device resets */
	XPm_Requirement *Requirements;
		/**< Head of the list of requirements for all subsystems */

	XPm_Requirement *PendingReqm; /**< Requirement being updated */
	u8 WfDealloc; /**< Deallocation is pending */
	u8 WfPwrUseCnt; /**< Pending power use count */
	XPm_DeviceOps *DeviceOps; /**< Device operations */
	const XPm_DeviceFsm* DeviceFsm; /**< Device finite state machine */
	XStatus (* HandleEvent)(XPm_Node *Node, u32 Event);
		/**< HandleEvent: Pointer to event handler */
};

/************************** Function Prototypes ******************************/
XStatus XPmDevice_Init(XPm_Device *Device,
		u32 Id,
		u32 BaseAddress,
		XPm_Power *Power, XPm_ClockNode *Clock, XPm_ResetNode *Reset);

XStatus XPmDevice_AddClock(XPm_Device *Device, XPm_ClockNode *Clock);

XStatus XPmDevice_AddReset(XPm_Device *Device, XPm_ResetNode *Reset);

XStatus XPmDevice_Reset(XPm_Device *Device, const XPm_ResetActions Action);

int XPmDevice_CheckPermissions(XPm_Subsystem *Subsystem, u32 DeviceId);

XPm_Device *XPmDevice_GetById(const u32 DeviceId);

XPm_Device *XPmDevice_GetByIndex(const u32 DeviceIndex);

XStatus XPm_CheckCapabilities(XPm_Device *Device, u32 Capabilities);

XStatus XPmDevice_Request(const u32 SubsystemId, const u32 DeviceId,
			  const u32 Capabilities, const u32 QoS);

XStatus XPmDevice_Release(const u32 SubsystemId, const u32 DeviceId);

XStatus XPmDevice_SetRequirement(const u32 SubsystemId, const u32 DeviceId,
				 const u32 Capabilities, const u32 QoS);

XPm_Requirement *XPmDevice_FindRequirement(const u32 DeviceId,
					   const u32 SubsystemId);

XStatus XPmDevice_GetStatus(const u32 SubsystemId,
			const u32 DeviceId,
			XPm_DeviceStatus *const DeviceStatus);

XStatus XPmDevice_AddParent(u32 Id, u32 *Parents, u32 NumParents);
XStatus XPmDevice_GetPermissions(XPm_Device *Device, u32 *PermissionMask);

u32 XPmDevice_GetSubsystemIdOfCore(XPm_Device *Device);

int XPmDevice_SetMaxLatency(const u32 SubsystemId, const u32 DeviceId,
			    const u32 Latency);

XStatus XPmDevice_ChangeState(XPm_Device *Device, const u32 NextState);
XStatus XPmDevice_UpdateStatus(XPm_Device *Device);
XStatus XPmDevice_BringUp(XPm_Device *Device);
int XPmDevice_GetUsageStatus(XPm_Subsystem *Subsystem, XPm_Device *Device);
int XPmDevice_IsClockActive(XPm_Device *Device);
int XPmDevice_IsRequested(const u32 DeviceId, const u32 SubsystemId);
int XPmDevice_GetWakeupLatency(const u32 DeviceId, u32 *Latency);

#ifdef __cplusplus
}
#endif

/** @} */
#endif /* XPM_DEVICE_H_ */
