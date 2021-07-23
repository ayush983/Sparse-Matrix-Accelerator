############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Mul
set_top mul1
add_files Mul/new_sparse(s5).c
add_files -tb Mul/new_tb.c -cflags "-Wno-unknown-pragmas"
open_solution "solution1"
set_part {xa7a12tcsg325-1q}
create_clock -period 10 -name default
source "./Mul/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
