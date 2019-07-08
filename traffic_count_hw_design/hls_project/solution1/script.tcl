############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project hls_project
set_top fromFrameToBlobCount
add_files fromFrameToBlobCount.cpp
add_files imageProcessing.cpp
add_files necstream.hpp
add_files -tb testbench.cpp -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xc7z020clg400-1}
create_clock -period 5 -name default
config_export -format ip_catalog -rtl verilog
#source "./hls_project/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
