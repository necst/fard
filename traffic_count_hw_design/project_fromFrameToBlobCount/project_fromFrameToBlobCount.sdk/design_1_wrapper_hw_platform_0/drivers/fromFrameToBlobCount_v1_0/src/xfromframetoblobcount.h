// ==============================================================
// File generated on Thu Apr 11 15:39:06 CEST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XFROMFRAMETOBLOBCOUNT_H
#define XFROMFRAMETOBLOBCOUNT_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xfromframetoblobcount_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XFromframetoblobcount_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XFromframetoblobcount;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XFromframetoblobcount_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XFromframetoblobcount_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XFromframetoblobcount_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XFromframetoblobcount_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XFromframetoblobcount_Initialize(XFromframetoblobcount *InstancePtr, u16 DeviceId);
XFromframetoblobcount_Config* XFromframetoblobcount_LookupConfig(u16 DeviceId);
int XFromframetoblobcount_CfgInitialize(XFromframetoblobcount *InstancePtr, XFromframetoblobcount_Config *ConfigPtr);
#else
int XFromframetoblobcount_Initialize(XFromframetoblobcount *InstancePtr, const char* InstanceName);
int XFromframetoblobcount_Release(XFromframetoblobcount *InstancePtr);
#endif

void XFromframetoblobcount_Start(XFromframetoblobcount *InstancePtr);
u32 XFromframetoblobcount_IsDone(XFromframetoblobcount *InstancePtr);
u32 XFromframetoblobcount_IsIdle(XFromframetoblobcount *InstancePtr);
u32 XFromframetoblobcount_IsReady(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_EnableAutoRestart(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_DisableAutoRestart(XFromframetoblobcount *InstancePtr);

void XFromframetoblobcount_Set_width(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_width(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_Set_height(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_height(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_Set_md_threshold(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_md_threshold(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_Set_erosion_iteration(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_erosion_iteration(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_Set_dilate_iteration(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_dilate_iteration(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_Set_second_erosion_iteration(XFromframetoblobcount *InstancePtr, u32 Data);
u32 XFromframetoblobcount_Get_second_erosion_iteration(XFromframetoblobcount *InstancePtr);

void XFromframetoblobcount_InterruptGlobalEnable(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_InterruptGlobalDisable(XFromframetoblobcount *InstancePtr);
void XFromframetoblobcount_InterruptEnable(XFromframetoblobcount *InstancePtr, u32 Mask);
void XFromframetoblobcount_InterruptDisable(XFromframetoblobcount *InstancePtr, u32 Mask);
void XFromframetoblobcount_InterruptClear(XFromframetoblobcount *InstancePtr, u32 Mask);
u32 XFromframetoblobcount_InterruptGetEnabled(XFromframetoblobcount *InstancePtr);
u32 XFromframetoblobcount_InterruptGetStatus(XFromframetoblobcount *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
