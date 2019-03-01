/******************************************************************************
*
* Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
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
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*****************************************************************************/
/**
* @file xaietile_event.h
* @{
*
*  Header file for Event handling
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- -----------------------------------------------------
* 1.0   Hyun    10/02/2018  Initial creation
* 1.1   Nishad  12/05/2018  Renamed ME attributes to AIE
* 1.2   Hyun    12/13/2018  Added the core PC event API
* 1.4   Jubaer  02/14/2019  Add Broadcast Get API
* 1.5   Jubaer  02/26/2019  Add group Event API
* </pre>
*
******************************************************************************/
#ifndef XAIETILE_EVENT_H
#define XAIETILE_EVENT_H

/***************************** Include Files *********************************/

/***************************** Constant Definitions **************************/
#define XAIETILE_EVENT_TRACING_INVALID_VAL		0xFFU

#define XAIETILE_EVENT_NUM_TRACE_EVENT			8U

#define XAIETILE_EVENT_BLOCK_SOUTH			0U
#define XAIETILE_EVENT_BLOCK_WEST			1U
#define XAIETILE_EVENT_BLOCK_NORTH			2U
#define XAIETILE_EVENT_BLOCK_EAST			3U

#define XAIETILE_EVENT_BLOCK_ALL_MASK			0xFFFFU

#define XAIETILE_EVENT_BLOCK_SWITCHA			0U
#define XAIETILE_EVENT_BLOCK_SWITCHB			1U

#define XAIETILE_EVENT_MODE_EVENT_TIME			0x00U
#define XAIETILE_EVENT_MODE_EVENT_PC			0x01U
#define XAIETILE_EVENT_MODE_EXECUTION			0x10U

#define XAIETILE_EVENT_CORE_PC_EVENT0			0x0U
#define XAIETILE_EVENT_CORE_PC_EVENT1			0x1U
#define XAIETILE_EVENT_CORE_PC_EVENT2			0x2U
#define XAIETILE_EVENT_CORE_PC_EVENT3			0x3U

/*
 * Core Group Event ID
 */
#define XAIETILE_GROUP_EVENT_CORE_0			0x0U
#define XAIETILE_GROUP_EVENT_CORE_PC			0x1U
#define XAIETILE_GROUP_EVENT_CORE_CORE_STALL			0x2U
#define XAIETILE_GROUP_EVENT_CORE_CORE_PROGRAM_FLOW			0x3U
#define XAIETILE_GROUP_EVENT_CORE_ERROR0			0x4U
#define XAIETILE_GROUP_EVENT_CORE_ERROR1			0x5U
#define XAIETILE_GROUP_EVENT_CORE_STREAM_SWITCH			0x6U
#define XAIETILE_GROUP_EVENT_CORE_BROADCAST			0x7U
#define XAIETILE_GROUP_EVENT_CORE_USER_EVENT			0x8U

/*
 * Memory Group Event ID
 */
#define XAIETILE_GROUP_EVENT_MEM_0			0x0U
#define XAIETILE_GROUP_EVENT_MEM_WATCH_POINT			0x1U
#define XAIETILE_GROUP_EVENT_MEM_DMA			0x2U
#define XAIETILE_GROUP_EVENT_MEM_LOCK			0x3U
#define XAIETILE_GROUP_EVENT_MEM_MEMORY_CONFLICT			0x4U
#define XAIETILE_GROUP_EVENT_MEM_ERROR			0x5U
#define XAIETILE_GROUP_EVENT_MEM_BROADCAST			0x6U
#define XAIETILE_GROUP_EVENT_MEM_USER			0x7U

/*
 * PL Group Event ID
 */
#define XAIETILE_GROUP_EVENT_PL_0			0x0U
#define XAIETILE_GROUP_EVENT_PL_DMA_ACTIVITY			0x1U
#define XAIETILE_GROUP_EVENT_PL_LOCK			0x2U
#define XAIETILE_GROUP_EVENT_PL_ERRORS			0x3U
#define XAIETILE_GROUP_EVENT_PL_STREAM_SWITCH			0x4U
#define XAIETILE_GROUP_EVENT_PL_BROADCAST			0x5U
#define XAIETILE_GROUP_EVENT_PL_USER			0x6U

#define XAIETILE_GROUP_EVENT_LSB			0x0U

/*
 * Core module events
 */
#define XAIETILE_EVENT_CORE_NONE				0U
#define XAIETILE_EVENT_CORE_TRUE				1U
#define XAIETILE_EVENT_CORE_GROUP_0			2U
#define XAIETILE_EVENT_CORE_TIMER_SYNC			3U
#define XAIETILE_EVENT_CORE_TIMER_VALUE_REACHED		4U
#define XAIETILE_EVENT_CORE_PERF_CNT0			5U
#define XAIETILE_EVENT_CORE_PERF_CNT1			6U
#define XAIETILE_EVENT_CORE_PERF_CNT2			7U
#define XAIETILE_EVENT_CORE_PERF_CNT3			8U
#define XAIETILE_EVENT_CORE_COMBO_EVENT_0		9U
#define XAIETILE_EVENT_CORE_COMBO_EVENT_1		10U
#define XAIETILE_EVENT_CORE_COMBO_EVENT_2		11U
#define XAIETILE_EVENT_CORE_COMBO_EVENT_3		12U
#define XAIETILE_EVENT_CORE_GROUP_PC_EVENT		15U
#define XAIETILE_EVENT_CORE_PC_0				16U
#define XAIETILE_EVENT_CORE_PC_1				17U
#define XAIETILE_EVENT_CORE_PC_2				18U
#define XAIETILE_EVENT_CORE_PC_3				19U
#define XAIETILE_EVENT_CORE_PC_RANGE_0_1			20U
#define XAIETILE_EVENT_CORE_PC_RANGE_2_3			21U
#define XAIETILE_EVENT_CORE_GROUP_CORE_STALL		22U
#define XAIETILE_EVENT_CORE_MEMORY_STALL			23U
#define XAIETILE_EVENT_CORE_STREAM_STALL			24U
#define XAIETILE_EVENT_CORE_CASCADE_STALL		25U
#define XAIETILE_EVENT_CORE_LOCK_STALL			26U
#define XAIETILE_EVENT_CORE_DEBUG_HALTED			27U
#define XAIETILE_EVENT_CORE_ACTIVE			28U
#define XAIETILE_EVENT_CORE_DISABLED			29U
#define XAIETILE_EVENT_CORE_ECC_ERROR_STALL		30U
#define XAIETILE_EVENT_CORE_ECC_SCRUBBING_STALL		31U
#define XAIETILE_EVENT_CORE_GROUP_CORE_PROGRAM_FLOW	32U
#define XAIETILE_EVENT_CORE_INSTR_EVENT_0		33U
#define XAIETILE_EVENT_CORE_INSTR_EVENT_1		34U
#define XAIETILE_EVENT_CORE_INSTR_CALL			35U
#define XAIETILE_EVENT_CORE_INSTR_RETURN			36U
#define XAIETILE_EVENT_CORE_INSTR_VECTOR			37U
#define XAIETILE_EVENT_CORE_INSTR_LOAD			38U
#define XAIETILE_EVENT_CORE_INSTR_STORE			39U
#define XAIETILE_EVENT_CORE_INSTR_STREAM_GET		40U
#define XAIETILE_EVENT_CORE_INSTR_STREAM_PUT		41U
#define XAIETILE_EVENT_CORE_INSTR_CASCADE_GET		42U
#define XAIETILE_EVENT_CORE_INSTR_CASCADE_PUT		43U
#define XAIETILE_EVENT_CORE_INSTR_LOCK_ACQUIRE_REQ	44U
#define XAIETILE_EVENT_CORE_INSTR_LOCK_RELEASE_REQ	45U
#define XAIETILE_EVENT_CORE_GROUP_ERRORS0		46U
#define XAIETILE_EVENT_CORE_GROUP_ERRORS1		47U
#define XAIETILE_EVENT_CORE_SRS_SATURATE			48U
#define XAIETILE_EVENT_CORE_UPS_SATURATE			49U
#define XAIETILE_EVENT_CORE_FP_OVERFLOW			50U
#define XAIETILE_EVENT_CORE_FP_UNDERFLOW			51U
#define XAIETILE_EVENT_CORE_FP_INVALID			52U
#define XAIETILE_EVENT_CORE_FP_DIV_BY_ZERO		53U
#define XAIETILE_EVENT_CORE_TLAST_IN_WSS_WORDS_0_2	54U
#define XAIETILE_EVENT_CORE_PM_REG_ACCESS_FAILURE	55U
#define XAIETILE_EVENT_CORE_STREAM_PKT_PARITY_ERROR	56U
#define XAIETILE_EVENT_CORE_CONTROL_PKT_ERROR		57U
#define XAIETILE_EVENT_CORE_AXI_MM_SLAVE_ERROR		58U
#define XAIETILE_EVENT_CORE_INSTRUCTION_DECOMPRESSION_ERROR	59U
#define XAIETILE_EVENT_CORE_DM_ADDRESS_OUT_OF_RANGE	60U
#define XAIETILE_EVENT_CORE_PM_ECC_ERROR_SCRUB_CORRECTED	61U
#define XAIETILE_EVENT_CORE_PM_ECC_ERROR_SCRUB_2BIT	62U
#define XAIETILE_EVENT_CORE_PM_ECC_ERROR_1BIT		63U
#define XAIETILE_EVENT_CORE_PM_ECC_ERROR_2BIT		64U
#define XAIETILE_EVENT_CORE_PM_ADDRESS_OUT_OF_RANGE	65U
#define XAIETILE_EVENT_CORE_DM_ACCESS_TO_UNAVAILABLE	66U
#define XAIETILE_EVENT_CORE_LOCK_ACCESS_TO_UNAVAILABLE	67U
#define XAIETILE_EVENT_CORE_INSTR_WARNING		68U
#define XAIETILE_EVENT_CORE_INSTR_ERROR			69U
#define XAIETILE_EVENT_CORE_GROUP_STREAM_SWITCH		73U
#define XAIETILE_EVENT_CORE_PORT_IDLE_0			74U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_0		75U
#define XAIETILE_EVENT_CORE_PORT_STALLED_0		76U
#define XAIETILE_EVENT_CORE_PORT_TLAST_0			77U
#define XAIETILE_EVENT_CORE_PORT_IDLE_1			78U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_1		79U
#define XAIETILE_EVENT_CORE_PORT_STALLED_1		80U
#define XAIETILE_EVENT_CORE_PORT_TLAST_1			81U
#define XAIETILE_EVENT_CORE_PORT_IDLE_2			82U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_2		83U
#define XAIETILE_EVENT_CORE_PORT_STALLED_2		84U
#define XAIETILE_EVENT_CORE_PORT_TLAST_2			85U
#define XAIETILE_EVENT_CORE_PORT_IDLE_3			86U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_3		87U
#define XAIETILE_EVENT_CORE_PORT_STALLED_3		88U
#define XAIETILE_EVENT_CORE_PORT_TLAST_3			89U
#define XAIETILE_EVENT_CORE_PORT_IDLE_4			90U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_4		91U
#define XAIETILE_EVENT_CORE_PORT_STALLED_4		92U
#define XAIETILE_EVENT_CORE_PORT_TLAST_4			93U
#define XAIETILE_EVENT_CORE_PORT_IDLE_5			94U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_5		95U
#define XAIETILE_EVENT_CORE_PORT_STALLED_5		96U
#define XAIETILE_EVENT_CORE_PORT_TLAST_5			97U
#define XAIETILE_EVENT_CORE_PORT_IDLE_6			98U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_6		99U
#define XAIETILE_EVENT_CORE_PORT_STALLED_6		100U
#define XAIETILE_EVENT_CORE_PORT_TLAST_6			101U
#define XAIETILE_EVENT_CORE_PORT_IDLE_7			102U
#define XAIETILE_EVENT_CORE_PORT_RUNNING_7		103U
#define XAIETILE_EVENT_CORE_PORT_STALLED_7		104U
#define XAIETILE_EVENT_CORE_PORT_TLAST_7			105U
#define XAIETILE_EVENT_CORE_GROUP_BROADCAST		106U
#define XAIETILE_EVENT_CORE_BROADCAST_0			107U
#define XAIETILE_EVENT_CORE_BROADCAST_1			108U
#define XAIETILE_EVENT_CORE_BROADCAST_2			109U
#define XAIETILE_EVENT_CORE_BROADCAST_3			110U
#define XAIETILE_EVENT_CORE_BROADCAST_4			111U
#define XAIETILE_EVENT_CORE_BROADCAST_5			112U
#define XAIETILE_EVENT_CORE_BROADCAST_6			113U
#define XAIETILE_EVENT_CORE_BROADCAST_7			114U
#define XAIETILE_EVENT_CORE_BROADCAST_8			115U
#define XAIETILE_EVENT_CORE_BROADCAST_9			116U
#define XAIETILE_EVENT_CORE_BROADCAST_10			117U
#define XAIETILE_EVENT_CORE_BROADCAST_11			118U
#define XAIETILE_EVENT_CORE_BROADCAST_12			119U
#define XAIETILE_EVENT_CORE_BROADCAST_13			120U
#define XAIETILE_EVENT_CORE_BROADCAST_14			121U
#define XAIETILE_EVENT_CORE_BROADCAST_15			122U
#define XAIETILE_EVENT_CORE_GROUP_USER_EVENT		123U
#define XAIETILE_EVENT_CORE_USER_EVENT_0			124U
#define XAIETILE_EVENT_CORE_USER_EVENT_1			125U
#define XAIETILE_EVENT_CORE_USER_EVENT_2			126U
#define XAIETILE_EVENT_CORE_USER_EVENT_3			127U

/*
 * Memory module events
 */
#define XAIETILE_EVENT_MEM_NONE				0U
#define XAIETILE_EVENT_MEM_TRUE				1U
#define XAIETILE_EVENT_MEM_GROUP_0			2U
#define XAIETILE_EVENT_MEM_TIMER_SYNC			3U
#define XAIETILE_EVENT_MEM_TIMER_VALUE_REACHED		4U
#define XAIETILE_EVENT_MEM_PERF_CNT0_EVENT		5U
#define XAIETILE_EVENT_MEM_PERF_CNT1_EVENT		6U
#define XAIETILE_EVENT_MEM_COMBO_EVENT_0			7U
#define XAIETILE_EVENT_MEM_COMBO_EVENT_1			8U
#define XAIETILE_EVENT_MEM_COMBO_EVENT_2			9U
#define XAIETILE_EVENT_MEM_COMBO_EVENT_3			10U
#define XAIETILE_EVENT_MEM_GROUP_WATCHPOINT		15U
#define XAIETILE_EVENT_MEM_WATCHPOINT_0			16U
#define XAIETILE_EVENT_MEM_WATCHPOINT_1			17U
#define XAIETILE_EVENT_MEM_GROUP_DMA_ACTIVITY		20U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_START_BD		21U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_START_BD		22U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_START_BD		23U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_START_BD		24U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_FINISHED_BD	25U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_FINISHED_BD	26U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_FINISHED_BD	27U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_FINISHED_BD	28U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_GO_TO_IDLE		29U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_GO_TO_IDLE		30U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_GO_TO_IDLE		31U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_GO_TO_IDLE		32U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_STALLED_LOCK_ACQUIRE	33U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_STALLED_LOCK_ACQUIRE	34U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_STALLED_LOCK_ACQUIRE	35U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_STALLED_LOCK_ACQUIRE	36U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_MEMORY_CONFLICT	37U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_MEMORY_CONFLICT	38U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_MEMORY_CONFLICT	39U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_MEMORY_CONFLICT	40U
#define XAIETILE_EVENT_MEM_GROUP_LOCK			43U
#define XAIETILE_EVENT_MEM_LOCK_0_ACQUIRED		44U
#define XAIETILE_EVENT_MEM_LOCK_0_RELEASE		45U
#define XAIETILE_EVENT_MEM_LOCK_1_ACQUIRED		46U
#define XAIETILE_EVENT_MEM_LOCK_1_RELEASE		47U
#define XAIETILE_EVENT_MEM_LOCK_2_ACQUIRED		48U
#define XAIETILE_EVENT_MEM_LOCK_2_RELEASE		49U
#define XAIETILE_EVENT_MEM_LOCK_3_ACQUIRED		50U
#define XAIETILE_EVENT_MEM_LOCK_3_RELEASE		51U
#define XAIETILE_EVENT_MEM_LOCK_4_ACQUIRED		52U
#define XAIETILE_EVENT_MEM_LOCK_4_RELEASE		53U
#define XAIETILE_EVENT_MEM_LOCK_5_ACQUIRED		54U
#define XAIETILE_EVENT_MEM_LOCK_5_RELEASE		55U
#define XAIETILE_EVENT_MEM_LOCK_6_ACQUIRED		56U
#define XAIETILE_EVENT_MEM_LOCK_6_RELEASE		57U
#define XAIETILE_EVENT_MEM_LOCK_7_ACQUIRED		58U
#define XAIETILE_EVENT_MEM_LOCK_7_RELEASE		59U
#define XAIETILE_EVENT_MEM_LOCK_8_ACQUIRED		60U
#define XAIETILE_EVENT_MEM_LOCK_8_RELEASE		61U
#define XAIETILE_EVENT_MEM_LOCK_9_ACQUIRED		62U
#define XAIETILE_EVENT_MEM_LOCK_9_RELEASE		63U
#define XAIETILE_EVENT_MEM_LOCK_10_ACQUIRED		64U
#define XAIETILE_EVENT_MEM_LOCK_10_RELEASE		65U
#define XAIETILE_EVENT_MEM_LOCK_11_ACQUIRED		66U
#define XAIETILE_EVENT_MEM_LOCK_11_RELEASE		67U
#define XAIETILE_EVENT_MEM_LOCK_12_ACQUIRED		68U
#define XAIETILE_EVENT_MEM_LOCK_12_RELEASE		69U
#define XAIETILE_EVENT_MEM_LOCK_13_ACQUIRED		70U
#define XAIETILE_EVENT_MEM_LOCK_13_RELEASE		71U
#define XAIETILE_EVENT_MEM_LOCK_14_ACQUIRED		72U
#define XAIETILE_EVENT_MEM_LOCK_14_RELEASE		73U
#define XAIETILE_EVENT_MEM_LOCK_15_ACQUIRED		74U
#define XAIETILE_EVENT_MEM_LOCK_15_RELEASE		75U
#define XAIETILE_EVENT_MEM_GROUP_MEMORY_CONFLICT		76U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_0		77U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_1		78U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_2		79U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_3		80U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_4		81U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_5		82U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_6		83U
#define XAIETILE_EVENT_MEM_CONFLICT_DM_BANK_7		84U
#define XAIETILE_EVENT_MEM_GROUP_ERRORS			86U
#define XAIETILE_EVENT_MEM_DM_ECC_ERROR_SCRUB_CORRECTED	87U
#define XAIETILE_EVENT_MEM_DM_ECC_ERROR_SCRUB_2BIT	88U
#define XAIETILE_EVENT_MEM_DM_ECC_ERROR_1BIT		89U
#define XAIETILE_EVENT_MEM_DM_ECC_ERROR_2BIT		90U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_2	91U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_3	92U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_4	93U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_5	94U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_6	95U
#define XAIETILE_EVENT_MEM_DM_PARITY_ERROR_BANK_7	96U
#define XAIETILE_EVENT_MEM_DMA_S2MM_0_ERROR		97U
#define XAIETILE_EVENT_MEM_DMA_S2MM_1_ERROR		98U
#define XAIETILE_EVENT_MEM_DMA_MM2S_0_ERROR		99U
#define XAIETILE_EVENT_MEM_DMA_MM2S_1_ERROR		100U
#define XAIETILE_EVENT_MEM_GROUP_BROADCAST		106U
#define XAIETILE_EVENT_MEM_BROADCAST_0			107U
#define XAIETILE_EVENT_MEM_BROADCAST_1			108U
#define XAIETILE_EVENT_MEM_BROADCAST_2			109U
#define XAIETILE_EVENT_MEM_BROADCAST_3			110U
#define XAIETILE_EVENT_MEM_BROADCAST_4			111U
#define XAIETILE_EVENT_MEM_BROADCAST_5			112U
#define XAIETILE_EVENT_MEM_BROADCAST_6			113U
#define XAIETILE_EVENT_MEM_BROADCAST_7			114U
#define XAIETILE_EVENT_MEM_BROADCAST_8			115U
#define XAIETILE_EVENT_MEM_BROADCAST_9			116U
#define XAIETILE_EVENT_MEM_BROADCAST_10			117U
#define XAIETILE_EVENT_MEM_BROADCAST_11			118U
#define XAIETILE_EVENT_MEM_BROADCAST_12			119U
#define XAIETILE_EVENT_MEM_BROADCAST_13			120U
#define XAIETILE_EVENT_MEM_BROADCAST_14			121U
#define XAIETILE_EVENT_MEM_BROADCAST_15			122U
#define XAIETILE_EVENT_MEM_GROUP_USER_EVENT		123U
#define XAIETILE_EVENT_MEM_USER_EVENT_0			124U
#define XAIETILE_EVENT_MEM_USER_EVENT_1			125U
#define XAIETILE_EVENT_MEM_USER_EVENT_2			126U
#define XAIETILE_EVENT_MEM_USER_EVENT_3			127U

/*
 * Memory module events: Macros with _NOC is for NoC tile only, not for PL tile.
 */
#define XAIETILE_EVENT_SHIM_NONE				0U
#define XAIETILE_EVENT_SHIM_TRUE				1U
#define XAIETILE_EVENT_SHIM_GROUP_0_			2U
#define XAIETILE_EVENT_SHIM_TIMER_SYNC			3U
#define XAIETILE_EVENT_SHIM_TIMER_VALUE_REACHED		4U
#define XAIETILE_EVENT_SHIM_PERF_CNT0_EVENT		5U
#define XAIETILE_EVENT_SHIM_PERF_CNT1_EVENT		6U
#define XAIETILE_EVENT_SHIM_COMBO_EVENT_0		7U
#define XAIETILE_EVENT_SHIM_COMBO_EVENT_1		8U
#define XAIETILE_EVENT_SHIM_COMBO_EVENT_2		9U
#define XAIETILE_EVENT_SHIM_COMBO_EVENT_3		10U
#define XAIETILE_EVENT_SHIM_GROUP_DMA_ACTIVITY_NOC	11U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_0_START_BD_NOC	12U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_1_START_BD_NOC	13U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_0_START_BD_NOC	14U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_1_START_BD_NOC	15U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_0_FINISHED_BD_NOC	16U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_1_FINISHED_BD_NOC	17U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_0_FINISHED_BD_NOC	18U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_1_FINISHED_BD_NOC	19U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_0_GO_TO_IDLE_NOC	20U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_1_GO_TO_IDLE_NOC	21U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_0_GO_TO_IDLE_NOC	22U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_1_GO_TO_IDLE_NOC	23U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_0_STALLED_LOCK_ACQUIRE_NOC	24U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_1_STALLED_LOCK_ACQUIRE_NOC	25U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_0_STALLED_LOCK_ACQUIRE_NOC	26U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_1_STALLED_LOCK_ACQUIRE_NOC	27U
#define XAIETILE_EVENT_SHIM_GROUP_LOCK_NOC		28U
#define XAIETILE_EVENT_SHIM_LOCK_0_ACQUIRED_NOC		29U
#define XAIETILE_EVENT_SHIM_LOCK_0_RELEASE_NOC		30U
#define XAIETILE_EVENT_SHIM_LOCK_1_ACQUIRED_NOC		31U
#define XAIETILE_EVENT_SHIM_LOCK_1_RELEASE_NOC		32U
#define XAIETILE_EVENT_SHIM_LOCK_2_ACQUIRED_NOC		33U
#define XAIETILE_EVENT_SHIM_LOCK_2_RELEASE_NOC		34U
#define XAIETILE_EVENT_SHIM_LOCK_3_ACQUIRED_NOC		35U
#define XAIETILE_EVENT_SHIM_LOCK_3_RELEASE_NOC		36U
#define XAIETILE_EVENT_SHIM_LOCK_4_ACQUIRED_NOC		37U
#define XAIETILE_EVENT_SHIM_LOCK_4_RELEASE_NOC		38U
#define XAIETILE_EVENT_SHIM_LOCK_5_ACQUIRED_NOC		39U
#define XAIETILE_EVENT_SHIM_LOCK_5_RELEASE_NOC		40U
#define XAIETILE_EVENT_SHIM_LOCK_6_ACQUIRED_NOC		41U
#define XAIETILE_EVENT_SHIM_LOCK_6_RELEASE_NOC		42U
#define XAIETILE_EVENT_SHIM_LOCK_7_ACQUIRED_NOC		43U
#define XAIETILE_EVENT_SHIM_LOCK_7_RELEASE_NOC		44U
#define XAIETILE_EVENT_SHIM_LOCK_8_ACQUIRED_NOC		45U
#define XAIETILE_EVENT_SHIM_LOCK_8_RELEASE_NOC		46U
#define XAIETILE_EVENT_SHIM_LOCK_9_ACQUIRED_NOC		47U
#define XAIETILE_EVENT_SHIM_LOCK_9_RELEASE_NOC		48U
#define XAIETILE_EVENT_SHIM_LOCK_10_ACQUIRED_NOC		49U
#define XAIETILE_EVENT_SHIM_LOCK_10_RELEASE_NOC		50U
#define XAIETILE_EVENT_SHIM_LOCK_11_ACQUIRED_NOC		51U
#define XAIETILE_EVENT_SHIM_LOCK_11_RELEASE_NOC		52U
#define XAIETILE_EVENT_SHIM_LOCK_12_ACQUIRED_NOC		53U
#define XAIETILE_EVENT_SHIM_LOCK_12_RELEASE_NOC		54U
#define XAIETILE_EVENT_SHIM_LOCK_13_ACQUIRED_NOC		55U
#define XAIETILE_EVENT_SHIM_LOCK_13_RELEASE_NOC		56U
#define XAIETILE_EVENT_SHIM_LOCK_14_ACQUIRED_NOC		57U
#define XAIETILE_EVENT_SHIM_LOCK_14_RELEASE_NOC		58U
#define XAIETILE_EVENT_SHIM_LOCK_15_ACQUIRED_NOC		59U
#define XAIETILE_EVENT_SHIM_LOCK_15_RELEASE_NOC		60U
#define XAIETILE_EVENT_SHIM_GROUP_ERRORS_		61U
#define XAIETILE_EVENT_SHIM_AXI_MM_SLAVE_TILE_ERROR	62U
#define XAIETILE_EVENT_SHIM_CONTROL_PKT_ERROR		63U
#define XAIETILE_EVENT_SHIM_AXI_MM_DECODE_NSU_ERROR_NOC	64U
#define XAIETILE_EVENT_SHIM_AXI_MM_SLAVE_NSU_ERROR_NOC	65U
#define XAIETILE_EVENT_SHIM_AXI_MM_UNSUPPORTED_TRAFFIC_NOC	66U
#define XAIETILE_EVENT_SHIM_AXI_MM_UNSECURE_ACCESS_IN_SECURE_MODE_NOC	67U
#define XAIETILE_EVENT_SHIM_AXI_MM_BYTE_STROBE_ERROR_NOC	68U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_0_ERROR_NOC		69U
#define XAIETILE_EVENT_SHIM_DMA_S2MM_1_ERROR_NOC		70U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_0_ERROR_NOC		71U
#define XAIETILE_EVENT_SHIM_DMA_MM2S_1_ERROR_NOC		72U
#define XAIETILE_EVENT_SHIM_GROUP_STREAM_SWITCH		73U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_0			74U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_0		75U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_0		76U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_0			77U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_1			78U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_1		79U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_1		80U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_1			81U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_2			82U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_2		83U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_2		84U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_2			85U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_3			86U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_3		87U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_3		88U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_3			89U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_4			90U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_4		91U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_4		92U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_4			93U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_5			94U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_5		95U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_5		96U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_5			97U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_6			98U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_6		99U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_6		100U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_6			101U
#define XAIETILE_EVENT_SHIM_PORT_IDLE_7			102U
#define XAIETILE_EVENT_SHIM_PORT_RUNNING_7		103U
#define XAIETILE_EVENT_SHIM_PORT_STALLED_7		104U
#define XAIETILE_EVENT_SHIM_PORT_TLAST_7			105U
#define XAIETILE_EVENT_SHIM_GROUP_BROADCAST_A		106U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_0		107U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_1		108U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_2		109U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_3		110U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_4		111U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_5		112U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_6		113U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_7		114U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_8		115U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_9		116U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_10		117U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_11		118U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_12		119U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_13		120U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_14		121U
#define XAIETILE_EVENT_SHIM_BROADCAST_A_15		122U
#define XAIETILE_EVENT_SHIM_GROUP_USER_EVENT		123U
#define XAIETILE_EVENT_SHIM_USER_EVENT_0			124U
#define XAIETILE_EVENT_SHIM_USER_EVENT_1			125U
#define XAIETILE_EVENT_SHIM_USER_EVENT_2			126U
#define XAIETILE_EVENT_SHIM_USER_EVENT_3			127U

/***************************** Macro Definitions *****************************/

/***************************** Type Definitions ******************************/
typedef struct {
	u8 TraceEvent[XAIETILE_EVENT_NUM_TRACE_EVENT];
} XAie_TraceEvents;

/************************** Function Prototypes  *****************************/
u8 XAieTile_EventTraceEventInit(XAieGbl_Tile *TileInstPtr, XAie_TraceEvents *TraceEvents);
u8 XAieTile_EventTraceEventAdd(XAieGbl_Tile *TileInstPtr, XAie_TraceEvents *TraceEvents, u8 Idx, u8 Event);

/*
 * Core module
 */
u8 XAieTileCore_EventTraceEventWrite(XAieGbl_Tile *TileInstPtr, XAie_TraceEvents *TraceEvents);
u8 XAieTileCore_EventTraceEventWriteId(XAieGbl_Tile *TileInstPtr, u8 Event, u8 Idx);
u8 XAieTileCore_EventTraceControl(XAieGbl_Tile *TileInstPtr, u8 Mode, u8 StartEvent, u8 StopEvent, u8 Id, u8 Packet);
u8 XAieTileCore_EventGenerate(XAieGbl_Tile *TileInstPtr, u8 Event);
u8 XAieTileCore_EventBroadcast(XAieGbl_Tile *TileInstPtr, u8 BroadcastId, u8 Event);
u8 XAieTileCore_EventBroadcastBlockSet(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);
u8 XAieTileCore_EventBroadcastBlockClear(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);
u32 XAieTileCore_EventBroadcastBlockValue(XAieGbl_Tile *TileInstPtr, u8 Dir);
u8 XAieTileCore_EventPCEvent(XAieGbl_Tile *TileInstPtr, u8 PCEvent, u16 PCAddr, u8 Valid);
u32 XAieTile_CoreEventBroadcastGet(XAieGbl_Tile *TileInstPtr, u8 BroadcastId);
u32 XAieTile_CoreEventStatusGet(XAieGbl_Tile *TileInstPtr, u8 Event);
void XAieTile_CoreEventStatusClear(XAieGbl_Tile *TileInstPtr, u8 Event, u32 Mask);
u32 XAieTile_CoreGroupEventGet(XAieGbl_Tile *TileInstPtr, u8 groupId);
void XAieTile_CoreGroupEventSet(XAieGbl_Tile *TileInstPtr, u8 groupId, u32 Mask);

/*
 * PL module
 */
u8 XAieTilePl_EventTraceEventWrite(XAieGbl_Tile *TileInstPtr, XAie_TraceEvents *TraceEvents);
u8 XAieTilePl_EventTraceEventWriteId(XAieGbl_Tile *TileInstPtr, u8 Event, u8 Idx);
u8 XAieTilePl_EventTraceControl(XAieGbl_Tile *TileInstPtr, u8 StartEvent, u8 StopEvent, u8 Id, u8 Packet);
u8 XAieTilePl_EventGenerate(XAieGbl_Tile *TileInstPtr, u8 Event);
u8 XAieTilePl_EventBroadcast(XAieGbl_Tile *TileInstPtr, u8 BroadcastId, u8 Event);
u8 XAieTilePl_EventBroadcastBlockSet(XAieGbl_Tile *TileInstPtr, u8 Dir, u8 SwitchAB, u16 Mask);
u8 XAieTilePl_EventBroadcastBlockClear(XAieGbl_Tile *TileInstPtr, u8 Dir, u8 SwitchAB, u16 Mask);
u32 XAieTilePl_EventBroadcastBlockValue(XAieGbl_Tile *TileInstPtr, u8 Dir, u8 SwitchAB);
u32 XAieTile_PlEventBroadcastGet(XAieGbl_Tile *TileInstPtr, u8 BroadcastId);
u32 XAieTile_PlEventStatusGet(XAieGbl_Tile *TileInstPtr, u8 Event);
void XAieTile_PlEventStatusClear(XAieGbl_Tile *TileInstPtr, u8 Event, u32 Mask);
u32 XAieTile_PlGroupEventGet(XAieGbl_Tile *TileInstPtr, u8 groupId);
void XAieTile_PlGroupEventSet(XAieGbl_Tile *TileInstPtr, u8 groupId, u32 Mask);

/*
 * Memory module
 */
u8 XAieTileMem_EventTraceEventWrite(XAieGbl_Tile *TileInstPtr, XAie_TraceEvents *TraceEvents);
u8 XAieTileMem_EventTraceEventWriteId(XAieGbl_Tile *TileInstPtr, u8 Event, u8 Idx);
u8 XAieTileMem_EventTraceControl(XAieGbl_Tile *TileInstPtr, u8 StartEvent, u8 StopEvent, u8 Id, u8 Packet);
u8 XAieTileMem_EventGenerate(XAieGbl_Tile *TileInstPtr, u8 Event);
u8 XAieTileMem_EventBroadcast(XAieGbl_Tile *TileInstPtr, u8 BroadcastId, u8 Event);
u8 XAieTileMem_EventBroadcastBlockSet(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);
u8 XAieTileMem_EventBroadcastBlockClear(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);
u32 XAieTileMem_EventBroadcastBlockValue(XAieGbl_Tile *TileInstPtr, u8 Dir);
u32 XAieTile_MemEventBroadcastGet(XAieGbl_Tile *TileInstPtr, u8 BroadcastId);
u32 XAieTile_MemEventStatusGet(XAieGbl_Tile *TileInstPtr, u8 Event);
void XAieTile_MemEventStatusClear(XAieGbl_Tile *TileInstPtr, u8 Event, u32 Mask);
u32 XAieTile_MemGroupEventGet(XAieGbl_Tile *TileInstPtr, u8 groupId);
void XAieTile_MemGroupEventSet(XAieGbl_Tile *TileInstPtr, u8 groupId, u32 Mask);

/*
 * Core module Column
 */
u8 XAieGbl_CoreEventBroadcastColumn(XAieGbl_Tile *TileInstPtr, u8 BroadcastId, u8 Event);
u8 XAieGbl_CoreEventBroadcastBlockClearColumn(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);

/*
 * Memory module Column
 */
u8 XAieGbl_MemEventBroadcastColumn(XAieGbl_Tile *TileInstPtr, u8 BroadcastId, u8 Event);
u8 XAieGbl_MemEventBroadcastBlockClearColumn(XAieGbl_Tile *TileInstPtr, u8 Dir, u16 Mask);

/*
 * Block all
 */
u8 XAieGbl_Column_EventBroadcastBlockAll(XAieGbl_Tile *TileInstPtr);

#endif		/* end of protection macro */

/** @} */
