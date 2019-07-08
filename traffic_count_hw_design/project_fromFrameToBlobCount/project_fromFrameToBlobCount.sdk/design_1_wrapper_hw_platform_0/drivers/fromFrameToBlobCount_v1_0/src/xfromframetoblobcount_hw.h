// ==============================================================
// File generated on Thu Apr 11 15:39:06 CEST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of width
//        bit 31~0 - width[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of height
//        bit 31~0 - height[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of md_threshold
//        bit 31~0 - md_threshold[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of erosion_iteration
//        bit 31~0 - erosion_iteration[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of dilate_iteration
//        bit 31~0 - dilate_iteration[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of second_erosion_iteration
//        bit 31~0 - second_erosion_iteration[31:0] (Read/Write)
// 0x3c : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_AP_CTRL                       0x00
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_GIE                           0x04
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_IER                           0x08
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_ISR                           0x0c
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_WIDTH_DATA                    0x10
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_WIDTH_DATA                    32
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_HEIGHT_DATA                   0x18
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_HEIGHT_DATA                   32
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_MD_THRESHOLD_DATA             0x20
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_MD_THRESHOLD_DATA             32
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_EROSION_ITERATION_DATA        0x28
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_EROSION_ITERATION_DATA        32
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_DILATE_ITERATION_DATA         0x30
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_DILATE_ITERATION_DATA         32
#define XFROMFRAMETOBLOBCOUNT_CONTROL_ADDR_SECOND_EROSION_ITERATION_DATA 0x38
#define XFROMFRAMETOBLOBCOUNT_CONTROL_BITS_SECOND_EROSION_ITERATION_DATA 32

