// ==============================================================
// File generated on Sat Jun 29 13:10:07 CEST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __fromFrameToBlobCount_urem_10ns_9ns_10_14_1__HH__
#define __fromFrameToBlobCount_urem_10ns_9ns_10_14_1__HH__
#include "ACMP_urem.h"
#include <systemc>

template<
    int ID,
    int NUM_STAGE,
    int din0_WIDTH,
    int din1_WIDTH,
    int dout_WIDTH>
SC_MODULE(fromFrameToBlobCount_urem_10ns_9ns_10_14_1) {
    sc_core::sc_in_clk clk;
    sc_core::sc_in<sc_dt::sc_logic> reset;
    sc_core::sc_in<sc_dt::sc_logic> ce;
    sc_core::sc_in< sc_dt::sc_lv<din0_WIDTH> >   din0;
    sc_core::sc_in< sc_dt::sc_lv<din1_WIDTH> >   din1;
    sc_core::sc_out< sc_dt::sc_lv<dout_WIDTH> >   dout;



    ACMP_urem<ID, 14, din0_WIDTH, din1_WIDTH, dout_WIDTH> ACMP_urem_U;

    SC_CTOR(fromFrameToBlobCount_urem_10ns_9ns_10_14_1):  ACMP_urem_U ("ACMP_urem_U") {
        ACMP_urem_U.clk(clk);
        ACMP_urem_U.reset(reset);
        ACMP_urem_U.ce(ce);
        ACMP_urem_U.din0(din0);
        ACMP_urem_U.din1(din1);
        ACMP_urem_U.dout(dout);

    }

};

#endif //
