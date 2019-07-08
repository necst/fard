# ==============================================================
# File generated on Sat Jun 29 13:10:07 CEST 2019
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../../testbench.cpp -cflags { -Wno-unknown-pragmas}
add_files fromFrameToBlobCount.cpp
add_files imageProcessing.cpp
add_files necstream.hpp
set_part xc7z020clg400-1
create_clock -name default -period 5
config_export -format=ip_catalog
config_export -rtl=verilog
