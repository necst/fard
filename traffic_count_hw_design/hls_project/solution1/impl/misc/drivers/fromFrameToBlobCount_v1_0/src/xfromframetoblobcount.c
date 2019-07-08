// ==============================================================
// File generated on Sat Jun 29 13:10:07 CEST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xfromframetoblobcount.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XFromframetoblobcount_CfgInitialize(XFromframetoblobcount *InstancePtr, XFromframetoblobcount_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XFromframetoblobcount_Start(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL) & 0x80;
    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XFromframetoblobcount_IsDone(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XFromframetoblobcount_IsIdle(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XFromframetoblobcount_IsReady(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XFromframetoblobcount_EnableAutoRestart(XFromframetoblobcount *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XFromframetoblobcount_DisableAutoRestart(XFromframetoblobcount *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL, 0);
}

void XFromframetoblobcount_Set_action(XFromframetoblobcount *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_ACTION_DATA, Data);
}

u32 XFromframetoblobcount_Get_action(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_ACTION_DATA);
    return Data;
}

void XFromframetoblobcount_Set_md_threshold(XFromframetoblobcount *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_MD_THRESHOLD_DATA, Data);
}

u32 XFromframetoblobcount_Get_md_threshold(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_MD_THRESHOLD_DATA);
    return Data;
}

void XFromframetoblobcount_Set_erosion_iteration(XFromframetoblobcount *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_EROSION_ITERATION_DATA, Data);
}

u32 XFromframetoblobcount_Get_erosion_iteration(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_EROSION_ITERATION_DATA);
    return Data;
}

void XFromframetoblobcount_Set_dilate_iteration(XFromframetoblobcount *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_DILATE_ITERATION_DATA, Data);
}

u32 XFromframetoblobcount_Get_dilate_iteration(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_DILATE_ITERATION_DATA);
    return Data;
}

void XFromframetoblobcount_Set_second_erosion_iteration(XFromframetoblobcount *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_SECOND_EROSION_ITERATION_DATA, Data);
}

u32 XFromframetoblobcount_Get_second_erosion_iteration(XFromframetoblobcount *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_SECOND_EROSION_ITERATION_DATA);
    return Data;
}

void XFromframetoblobcount_InterruptGlobalEnable(XFromframetoblobcount *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_GIE, 1);
}

void XFromframetoblobcount_InterruptGlobalDisable(XFromframetoblobcount *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_GIE, 0);
}

void XFromframetoblobcount_InterruptEnable(XFromframetoblobcount *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER);
    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER, Register | Mask);
}

void XFromframetoblobcount_InterruptDisable(XFromframetoblobcount *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER);
    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER, Register & (~Mask));
}

void XFromframetoblobcount_InterruptClear(XFromframetoblobcount *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XFromframetoblobcount_WriteReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_ISR, Mask);
}

u32 XFromframetoblobcount_InterruptGetEnabled(XFromframetoblobcount *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER);
}

u32 XFromframetoblobcount_InterruptGetStatus(XFromframetoblobcount *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XFromframetoblobcount_ReadReg(InstancePtr->Control_BaseAddress, XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_ISR);
}

