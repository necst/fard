// ==============================================================
// File generated on Wed Apr 17 14:26:41 CEST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->
    template< typename DT ,int D ,int U ,int TI ,int TD > struct my_ap_axis;
    template<> struct my_ap_axis<unsigned int, 32, 1, 1, 1> {
        unsigned int data;
        ap_uint<4> keep;
        ap_uint<4> strb;
        ap_uint<1> user;
        ap_uint<1> last;
        ap_uint<1> id;
        ap_uint<1> dest;
       } ;

extern unsigned char input_grey[32400];

extern unsigned char input[97200];

extern unsigned char foreground_clean[32400];

extern unsigned char foreground[32400];

extern unsigned char background[97200];



// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "streamIn_V_data"
#define AUTOTB_TVIN_streamIn_V_data  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_data.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_data  "../tv/stream_size/stream_size_in_streamIn_V_data.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data  "../tv/stream_size/stream_ingress_status_streamIn_V_data.dat"
// wrapc file define: "streamIn_V_keep_V"
#define AUTOTB_TVIN_streamIn_V_keep_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_keep_V  "../tv/stream_size/stream_size_in_streamIn_V_keep_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V  "../tv/stream_size/stream_ingress_status_streamIn_V_keep_V.dat"
// wrapc file define: "streamIn_V_strb_V"
#define AUTOTB_TVIN_streamIn_V_strb_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_strb_V  "../tv/stream_size/stream_size_in_streamIn_V_strb_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V  "../tv/stream_size/stream_ingress_status_streamIn_V_strb_V.dat"
// wrapc file define: "streamIn_V_user_V"
#define AUTOTB_TVIN_streamIn_V_user_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_user_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_user_V  "../tv/stream_size/stream_size_in_streamIn_V_user_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V  "../tv/stream_size/stream_ingress_status_streamIn_V_user_V.dat"
// wrapc file define: "streamIn_V_last_V"
#define AUTOTB_TVIN_streamIn_V_last_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_last_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_last_V  "../tv/stream_size/stream_size_in_streamIn_V_last_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V  "../tv/stream_size/stream_ingress_status_streamIn_V_last_V.dat"
// wrapc file define: "streamIn_V_id_V"
#define AUTOTB_TVIN_streamIn_V_id_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_id_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_id_V  "../tv/stream_size/stream_size_in_streamIn_V_id_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V  "../tv/stream_size/stream_ingress_status_streamIn_V_id_V.dat"
// wrapc file define: "streamIn_V_dest_V"
#define AUTOTB_TVIN_streamIn_V_dest_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamIn_V_dest_V.dat"
#define WRAPC_STREAM_SIZE_IN_streamIn_V_dest_V  "../tv/stream_size/stream_size_in_streamIn_V_dest_V.dat"
#define WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V  "../tv/stream_size/stream_ingress_status_streamIn_V_dest_V.dat"
// wrapc file define: "streamOut_V_data"
#define AUTOTB_TVOUT_streamOut_V_data  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_data.dat"
#define AUTOTB_TVIN_streamOut_V_data  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_data.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_data  "../tv/stream_size/stream_size_out_streamOut_V_data.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_data  "../tv/stream_size/stream_egress_status_streamOut_V_data.dat"
// wrapc file define: "streamOut_V_keep_V"
#define AUTOTB_TVOUT_streamOut_V_keep_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_keep_V.dat"
#define AUTOTB_TVIN_streamOut_V_keep_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_keep_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_keep_V  "../tv/stream_size/stream_size_out_streamOut_V_keep_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_keep_V  "../tv/stream_size/stream_egress_status_streamOut_V_keep_V.dat"
// wrapc file define: "streamOut_V_strb_V"
#define AUTOTB_TVOUT_streamOut_V_strb_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_strb_V.dat"
#define AUTOTB_TVIN_streamOut_V_strb_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_strb_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_strb_V  "../tv/stream_size/stream_size_out_streamOut_V_strb_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_strb_V  "../tv/stream_size/stream_egress_status_streamOut_V_strb_V.dat"
// wrapc file define: "streamOut_V_user_V"
#define AUTOTB_TVOUT_streamOut_V_user_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_user_V.dat"
#define AUTOTB_TVIN_streamOut_V_user_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_user_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_user_V  "../tv/stream_size/stream_size_out_streamOut_V_user_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_user_V  "../tv/stream_size/stream_egress_status_streamOut_V_user_V.dat"
// wrapc file define: "streamOut_V_last_V"
#define AUTOTB_TVOUT_streamOut_V_last_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_last_V.dat"
#define AUTOTB_TVIN_streamOut_V_last_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_last_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_last_V  "../tv/stream_size/stream_size_out_streamOut_V_last_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_last_V  "../tv/stream_size/stream_egress_status_streamOut_V_last_V.dat"
// wrapc file define: "streamOut_V_id_V"
#define AUTOTB_TVOUT_streamOut_V_id_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_id_V.dat"
#define AUTOTB_TVIN_streamOut_V_id_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_id_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_id_V  "../tv/stream_size/stream_size_out_streamOut_V_id_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_id_V  "../tv/stream_size/stream_egress_status_streamOut_V_id_V.dat"
// wrapc file define: "streamOut_V_dest_V"
#define AUTOTB_TVOUT_streamOut_V_dest_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvout_streamOut_V_dest_V.dat"
#define AUTOTB_TVIN_streamOut_V_dest_V  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_streamOut_V_dest_V.dat"
#define WRAPC_STREAM_SIZE_OUT_streamOut_V_dest_V  "../tv/stream_size/stream_size_out_streamOut_V_dest_V.dat"
#define WRAPC_STREAM_EGRESS_STATUS_streamOut_V_dest_V  "../tv/stream_size/stream_egress_status_streamOut_V_dest_V.dat"
// wrapc file define: "action"
#define AUTOTB_TVIN_action  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_action.dat"
// wrapc file define: "md_threshold"
#define AUTOTB_TVIN_md_threshold  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_md_threshold.dat"
// wrapc file define: "erosion_iteration"
#define AUTOTB_TVIN_erosion_iteration  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_erosion_iteration.dat"
// wrapc file define: "dilate_iteration"
#define AUTOTB_TVIN_dilate_iteration  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_dilate_iteration.dat"
// wrapc file define: "second_erosion_iteration"
#define AUTOTB_TVIN_second_erosion_iteration  "../tv/cdatafile/c.fromFrameToBlobCount.autotvin_second_erosion_iteration.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "streamOut_V_data"
#define AUTOTB_TVOUT_PC_streamOut_V_data  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_data.dat"
// tvout file define: "streamOut_V_keep_V"
#define AUTOTB_TVOUT_PC_streamOut_V_keep_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_keep_V.dat"
// tvout file define: "streamOut_V_strb_V"
#define AUTOTB_TVOUT_PC_streamOut_V_strb_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_strb_V.dat"
// tvout file define: "streamOut_V_user_V"
#define AUTOTB_TVOUT_PC_streamOut_V_user_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_user_V.dat"
// tvout file define: "streamOut_V_last_V"
#define AUTOTB_TVOUT_PC_streamOut_V_last_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_last_V.dat"
// tvout file define: "streamOut_V_id_V"
#define AUTOTB_TVOUT_PC_streamOut_V_id_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_id_V.dat"
// tvout file define: "streamOut_V_dest_V"
#define AUTOTB_TVOUT_PC_streamOut_V_dest_V  "../tv/rtldatafile/rtl.fromFrameToBlobCount.autotvout_streamOut_V_dest_V.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			streamIn_V_data_depth = 0;
			streamIn_V_keep_V_depth = 0;
			streamIn_V_strb_V_depth = 0;
			streamIn_V_user_V_depth = 0;
			streamIn_V_last_V_depth = 0;
			streamIn_V_id_V_depth = 0;
			streamIn_V_dest_V_depth = 0;
			streamOut_V_data_depth = 0;
			streamOut_V_keep_V_depth = 0;
			streamOut_V_strb_V_depth = 0;
			streamOut_V_user_V_depth = 0;
			streamOut_V_last_V_depth = 0;
			streamOut_V_id_V_depth = 0;
			streamOut_V_dest_V_depth = 0;
			action_depth = 0;
			md_threshold_depth = 0;
			erosion_iteration_depth = 0;
			dilate_iteration_depth = 0;
			second_erosion_iteration_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{streamIn_V_data " << streamIn_V_data_depth << "}\n";
			total_list << "{streamIn_V_keep_V " << streamIn_V_keep_V_depth << "}\n";
			total_list << "{streamIn_V_strb_V " << streamIn_V_strb_V_depth << "}\n";
			total_list << "{streamIn_V_user_V " << streamIn_V_user_V_depth << "}\n";
			total_list << "{streamIn_V_last_V " << streamIn_V_last_V_depth << "}\n";
			total_list << "{streamIn_V_id_V " << streamIn_V_id_V_depth << "}\n";
			total_list << "{streamIn_V_dest_V " << streamIn_V_dest_V_depth << "}\n";
			total_list << "{streamOut_V_data " << streamOut_V_data_depth << "}\n";
			total_list << "{streamOut_V_keep_V " << streamOut_V_keep_V_depth << "}\n";
			total_list << "{streamOut_V_strb_V " << streamOut_V_strb_V_depth << "}\n";
			total_list << "{streamOut_V_user_V " << streamOut_V_user_V_depth << "}\n";
			total_list << "{streamOut_V_last_V " << streamOut_V_last_V_depth << "}\n";
			total_list << "{streamOut_V_id_V " << streamOut_V_id_V_depth << "}\n";
			total_list << "{streamOut_V_dest_V " << streamOut_V_dest_V_depth << "}\n";
			total_list << "{action " << action_depth << "}\n";
			total_list << "{md_threshold " << md_threshold_depth << "}\n";
			total_list << "{erosion_iteration " << erosion_iteration_depth << "}\n";
			total_list << "{dilate_iteration " << dilate_iteration_depth << "}\n";
			total_list << "{second_erosion_iteration " << second_erosion_iteration_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int streamIn_V_data_depth;
		int streamIn_V_keep_V_depth;
		int streamIn_V_strb_V_depth;
		int streamIn_V_user_V_depth;
		int streamIn_V_last_V_depth;
		int streamIn_V_id_V_depth;
		int streamIn_V_dest_V_depth;
		int streamOut_V_data_depth;
		int streamOut_V_keep_V_depth;
		int streamOut_V_strb_V_depth;
		int streamOut_V_user_V_depth;
		int streamOut_V_last_V_depth;
		int streamOut_V_id_V_depth;
		int streamOut_V_dest_V_depth;
		int action_depth;
		int md_threshold_depth;
		int erosion_iteration_depth;
		int dilate_iteration_depth;
		int second_erosion_iteration_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void fromFrameToBlobCount (
hls::stream<my_ap_axis<unsigned int, 32, 1, 1, 1 > > (&streamIn),
hls::stream<my_ap_axis<unsigned int, 32, 1, 1, 1 > > (&streamOut),
int action,
int md_threshold,
int erosion_iteration,
int dilate_iteration,
int second_erosion_iteration);

void AESL_WRAP_fromFrameToBlobCount (
hls::stream<my_ap_axis<unsigned int, 32, 1, 1, 1 > > (&streamIn),
hls::stream<my_ap_axis<unsigned int, 32, 1, 1, 1 > > (&streamOut),
int action,
int md_threshold,
int erosion_iteration,
int dilate_iteration,
int second_erosion_iteration)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		// pop stream input: "streamIn"
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_streamIn_V_data, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_IN_streamIn_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_streamIn_V_data, AESL_token); // pop_size
			int aesl_tmp_1 = atoi(AESL_token.c_str());
			for (int i = 0; i < aesl_tmp_1; i++)
			{
				streamIn.read();
			}
			aesl_fh.read(WRAPC_STREAM_SIZE_IN_streamIn_V_data, AESL_token); // [[/transaction]]
		}

		// define output stream variables: "streamOut"
		std::vector<my_ap_axis<unsigned int, 32, 1, 1, 1 > > aesl_tmp_3;
		int aesl_tmp_4;
		int aesl_tmp_5 = 0;

		// read output stream size: "streamOut"
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, AESL_token); // [[transaction]]
		aesl_fh.read(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, AESL_token); // pop_size
			aesl_tmp_4 = atoi(AESL_token.c_str());
			aesl_fh.read(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, AESL_token); // [[/transaction]]
		}

		// output port post check: "streamOut_V_data"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_data, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_data, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_data, AESL_token); // data

			std::vector<sc_bv<32> > streamOut_V_data_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_data', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_data_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_data, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_data))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_data
				{
					// bitslice(31, 0)
					// {
						// celement: streamOut.V.data(31, 0)
						// {
							sc_lv<32>* streamOut_V_data_lv0_0_0_1_lv1_0_0_1 = new sc_lv<32>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.data(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_data_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(31, 0) = sc_bv<32>(streamOut_V_data_pc_buffer[hls_map_index].range(31, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(31, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.data(31, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].data
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].data
									// output_left_conversion : aesl_tmp_3[i_0].data
									// output_type_conversion : (streamOut_V_data_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64()
									if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].data = (streamOut_V_data_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_uint64();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_keep_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_keep_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_keep_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_keep_V, AESL_token); // data

			std::vector<sc_bv<4> > streamOut_V_keep_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_keep_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_keep_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_keep_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_keep_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_keep_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_keep_V
				{
					// bitslice(3, 0)
					// {
						// celement: streamOut.V.keep.V(3, 0)
						// {
							sc_lv<4>* streamOut_V_keep_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<4>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(3, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.keep.V(3, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(3, 0) = sc_bv<4>(streamOut_V_keep_V_pc_buffer[hls_map_index].range(3, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(3, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.keep.V(3, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].keep
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].keep
									// output_left_conversion : aesl_tmp_3[i_0].keep
									// output_type_conversion : (streamOut_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].keep = (streamOut_V_keep_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_strb_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_strb_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_strb_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_strb_V, AESL_token); // data

			std::vector<sc_bv<4> > streamOut_V_strb_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_strb_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_strb_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_strb_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_strb_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_strb_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_strb_V
				{
					// bitslice(3, 0)
					// {
						// celement: streamOut.V.strb.V(3, 0)
						// {
							sc_lv<4>* streamOut_V_strb_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<4>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(3, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.strb.V(3, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].strb) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_strb_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(3, 0) = sc_bv<4>(streamOut_V_strb_V_pc_buffer[hls_map_index].range(3, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(3, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.strb.V(3, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].strb
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].strb
									// output_left_conversion : aesl_tmp_3[i_0].strb
									// output_type_conversion : (streamOut_V_strb_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].strb) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].strb = (streamOut_V_strb_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_user_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_user_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_user_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_user_V, AESL_token); // data

			std::vector<sc_bv<1> > streamOut_V_user_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_user_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_user_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_user_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_user_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_user_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_user_V
				{
					// bitslice(0, 0)
					// {
						// celement: streamOut.V.user.V(0, 0)
						// {
							sc_lv<1>* streamOut_V_user_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<1>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.user.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].user) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_user_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(0, 0) = sc_bv<1>(streamOut_V_user_V_pc_buffer[hls_map_index].range(0, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.user.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].user
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].user
									// output_left_conversion : aesl_tmp_3[i_0].user
									// output_type_conversion : (streamOut_V_user_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].user) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].user = (streamOut_V_user_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_last_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_last_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_last_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_last_V, AESL_token); // data

			std::vector<sc_bv<1> > streamOut_V_last_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_last_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_last_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_last_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_last_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_last_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_last_V
				{
					// bitslice(0, 0)
					// {
						// celement: streamOut.V.last.V(0, 0)
						// {
							sc_lv<1>* streamOut_V_last_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<1>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.last.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(0, 0) = sc_bv<1>(streamOut_V_last_V_pc_buffer[hls_map_index].range(0, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.last.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].last
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].last
									// output_left_conversion : aesl_tmp_3[i_0].last
									// output_type_conversion : (streamOut_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].last = (streamOut_V_last_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_id_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_id_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_id_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_id_V, AESL_token); // data

			std::vector<sc_bv<1> > streamOut_V_id_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_id_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_id_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_id_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_id_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_id_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_id_V
				{
					// bitslice(0, 0)
					// {
						// celement: streamOut.V.id.V(0, 0)
						// {
							sc_lv<1>* streamOut_V_id_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<1>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.id.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].id) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_id_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(0, 0) = sc_bv<1>(streamOut_V_id_V_pc_buffer[hls_map_index].range(0, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.id.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].id
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].id
									// output_left_conversion : aesl_tmp_3[i_0].id
									// output_type_conversion : (streamOut_V_id_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].id) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].id = (streamOut_V_id_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// output port post check: "streamOut_V_dest_V"
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_dest_V, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_dest_V, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_dest_V, AESL_token); // data

			std::vector<sc_bv<1> > streamOut_V_dest_V_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_dest_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'streamOut_V_dest_V', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					streamOut_V_dest_V_pc_buffer.push_back(AESL_token.c_str());
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_streamOut_V_dest_V, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_streamOut_V_dest_V))
				{
					exit(1);
				}
			}

			// correct the buffer size the current transaction
			if (i != aesl_tmp_4)
			{
				aesl_tmp_4 = i;
			}

			if (aesl_tmp_4 > 0 && aesl_tmp_3.size() < aesl_tmp_4)
			{
				int aesl_tmp_3_size = aesl_tmp_3.size();

				for (int tmp_aesl_tmp_3 = 0; tmp_aesl_tmp_3 < aesl_tmp_4 - aesl_tmp_3_size; tmp_aesl_tmp_3++)
				{
					my_ap_axis<unsigned int, 32, 1, 1, 1 > tmp;
					aesl_tmp_3.push_back(tmp);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: streamOut_V_dest_V
				{
					// bitslice(0, 0)
					// {
						// celement: streamOut.V.dest.V(0, 0)
						// {
							sc_lv<1>* streamOut_V_dest_V_lv0_0_0_1_lv1_0_0_1 = new sc_lv<1>[aesl_tmp_4 - aesl_tmp_5];
						// }
					// }

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.dest.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									if (&(aesl_tmp_3[0].dest) != NULL) // check the null address if the c port is array or others
									{
										streamOut_V_dest_V_lv0_0_0_1_lv1_0_0_1[hls_map_index].range(0, 0) = sc_bv<1>(streamOut_V_dest_V_pc_buffer[hls_map_index].range(0, 0));
										hls_map_index++;
									}
								}
							}
						}
					}

					// bitslice(0, 0)
					{
						int hls_map_index = 0;
						// celement: streamOut.V.dest.V(0, 0)
						{
							// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
							for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
							{
								// carray: (0) => (0) @ (1)
								for (int i_1 = 0; i_1 <= 0; i_1 += 1)
								{
									// sub                    : i_0 i_1
									// ori_name               : aesl_tmp_3[i_0].dest
									// sub_1st_elem           : 0 0
									// ori_name_1st_elem      : aesl_tmp_3[0].dest
									// output_left_conversion : aesl_tmp_3[i_0].dest
									// output_type_conversion : (streamOut_V_dest_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str()
									if (&(aesl_tmp_3[0].dest) != NULL) // check the null address if the c port is array or others
									{
										aesl_tmp_3[i_0].dest = (streamOut_V_dest_V_lv0_0_0_1_lv1_0_0_1[hls_map_index]).to_string(SC_BIN).c_str();
										hls_map_index++;
									}
								}
							}
						}
					}
				}
			}
		}

		// push back output stream: "streamOut"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			streamOut.write(aesl_tmp_3[i]);
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "streamIn_V_data"
		char* tvin_streamIn_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_data);
		char* wrapc_stream_size_in_streamIn_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_data);
		char* wrapc_stream_ingress_status_streamIn_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data);

		// "streamIn_V_keep_V"
		char* tvin_streamIn_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_keep_V);
		char* wrapc_stream_size_in_streamIn_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_keep_V);
		char* wrapc_stream_ingress_status_streamIn_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V);

		// "streamIn_V_strb_V"
		char* tvin_streamIn_V_strb_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_strb_V);
		char* wrapc_stream_size_in_streamIn_V_strb_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_strb_V);
		char* wrapc_stream_ingress_status_streamIn_V_strb_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V);

		// "streamIn_V_user_V"
		char* tvin_streamIn_V_user_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_user_V);
		char* wrapc_stream_size_in_streamIn_V_user_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_user_V);
		char* wrapc_stream_ingress_status_streamIn_V_user_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V);

		// "streamIn_V_last_V"
		char* tvin_streamIn_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_last_V);
		char* wrapc_stream_size_in_streamIn_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_last_V);
		char* wrapc_stream_ingress_status_streamIn_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V);

		// "streamIn_V_id_V"
		char* tvin_streamIn_V_id_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_id_V);
		char* wrapc_stream_size_in_streamIn_V_id_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_id_V);
		char* wrapc_stream_ingress_status_streamIn_V_id_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V);

		// "streamIn_V_dest_V"
		char* tvin_streamIn_V_dest_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamIn_V_dest_V);
		char* wrapc_stream_size_in_streamIn_V_dest_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_IN_streamIn_V_dest_V);
		char* wrapc_stream_ingress_status_streamIn_V_dest_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V);

		// "streamOut_V_data"
		char* tvin_streamOut_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_data);
		char* tvout_streamOut_V_data = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_data);
		char* wrapc_stream_size_out_streamOut_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_data);
		char* wrapc_stream_egress_status_streamOut_V_data = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_data);

		// "streamOut_V_keep_V"
		char* tvin_streamOut_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_keep_V);
		char* tvout_streamOut_V_keep_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_keep_V);
		char* wrapc_stream_size_out_streamOut_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_keep_V);
		char* wrapc_stream_egress_status_streamOut_V_keep_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_keep_V);

		// "streamOut_V_strb_V"
		char* tvin_streamOut_V_strb_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_strb_V);
		char* tvout_streamOut_V_strb_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_strb_V);
		char* wrapc_stream_size_out_streamOut_V_strb_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_strb_V);
		char* wrapc_stream_egress_status_streamOut_V_strb_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_strb_V);

		// "streamOut_V_user_V"
		char* tvin_streamOut_V_user_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_user_V);
		char* tvout_streamOut_V_user_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_user_V);
		char* wrapc_stream_size_out_streamOut_V_user_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_user_V);
		char* wrapc_stream_egress_status_streamOut_V_user_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_user_V);

		// "streamOut_V_last_V"
		char* tvin_streamOut_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_last_V);
		char* tvout_streamOut_V_last_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_last_V);
		char* wrapc_stream_size_out_streamOut_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_last_V);
		char* wrapc_stream_egress_status_streamOut_V_last_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_last_V);

		// "streamOut_V_id_V"
		char* tvin_streamOut_V_id_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_id_V);
		char* tvout_streamOut_V_id_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_id_V);
		char* wrapc_stream_size_out_streamOut_V_id_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_id_V);
		char* wrapc_stream_egress_status_streamOut_V_id_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_id_V);

		// "streamOut_V_dest_V"
		char* tvin_streamOut_V_dest_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_streamOut_V_dest_V);
		char* tvout_streamOut_V_dest_V = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_streamOut_V_dest_V);
		char* wrapc_stream_size_out_streamOut_V_dest_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_SIZE_OUT_streamOut_V_dest_V);
		char* wrapc_stream_egress_status_streamOut_V_dest_V = new char[50];
		aesl_fh.touch(WRAPC_STREAM_EGRESS_STATUS_streamOut_V_dest_V);

		// "action"
		char* tvin_action = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_action);

		// "md_threshold"
		char* tvin_md_threshold = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_md_threshold);

		// "erosion_iteration"
		char* tvin_erosion_iteration = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_erosion_iteration);

		// "dilate_iteration"
		char* tvin_dilate_iteration = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_dilate_iteration);

		// "second_erosion_iteration"
		char* tvin_second_erosion_iteration = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_second_erosion_iteration);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// dump stream tvin: "streamIn"
		std::vector<my_ap_axis<unsigned int, 32, 1, 1, 1 > > aesl_tmp_0;
		int aesl_tmp_1 = 0;
		while (!streamIn.empty())
		{
			aesl_tmp_0.push_back(streamIn.read());
			aesl_tmp_1++;
		}

		// dump stream tvin: "streamOut"
		std::vector<my_ap_axis<unsigned int, 32, 1, 1, 1 > > aesl_tmp_3;
		int aesl_tmp_4 = 0;
		while (!streamOut.empty())
		{
			aesl_tmp_3.push_back(streamOut.read());
			aesl_tmp_4++;
		}

		// [[transaction]]
		sprintf(tvin_action, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_action, tvin_action);

		sc_bv<32> action_tvin_wrapc_buffer;

		// RTL Name: action
		{
			// bitslice(31, 0)
			{
				// celement: action(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : action
						// sub_1st_elem          : 
						// ori_name_1st_elem     : action
						// regulate_c_name       : action
						// input_type_conversion : action
						if (&(action) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> action_tmp_mem;
							action_tmp_mem = action;
							action_tvin_wrapc_buffer.range(31, 0) = action_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_action, "%s\n", (action_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_action, tvin_action);
		}

		tcl_file.set_num(1, &tcl_file.action_depth);
		sprintf(tvin_action, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_action, tvin_action);

		// [[transaction]]
		sprintf(tvin_md_threshold, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_md_threshold, tvin_md_threshold);

		sc_bv<32> md_threshold_tvin_wrapc_buffer;

		// RTL Name: md_threshold
		{
			// bitslice(31, 0)
			{
				// celement: md_threshold(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : md_threshold
						// sub_1st_elem          : 
						// ori_name_1st_elem     : md_threshold
						// regulate_c_name       : md_threshold
						// input_type_conversion : md_threshold
						if (&(md_threshold) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> md_threshold_tmp_mem;
							md_threshold_tmp_mem = md_threshold;
							md_threshold_tvin_wrapc_buffer.range(31, 0) = md_threshold_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_md_threshold, "%s\n", (md_threshold_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_md_threshold, tvin_md_threshold);
		}

		tcl_file.set_num(1, &tcl_file.md_threshold_depth);
		sprintf(tvin_md_threshold, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_md_threshold, tvin_md_threshold);

		// [[transaction]]
		sprintf(tvin_erosion_iteration, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_erosion_iteration, tvin_erosion_iteration);

		sc_bv<32> erosion_iteration_tvin_wrapc_buffer;

		// RTL Name: erosion_iteration
		{
			// bitslice(31, 0)
			{
				// celement: erosion_iteration(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : erosion_iteration
						// sub_1st_elem          : 
						// ori_name_1st_elem     : erosion_iteration
						// regulate_c_name       : erosion_iteration
						// input_type_conversion : erosion_iteration
						if (&(erosion_iteration) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> erosion_iteration_tmp_mem;
							erosion_iteration_tmp_mem = erosion_iteration;
							erosion_iteration_tvin_wrapc_buffer.range(31, 0) = erosion_iteration_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_erosion_iteration, "%s\n", (erosion_iteration_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_erosion_iteration, tvin_erosion_iteration);
		}

		tcl_file.set_num(1, &tcl_file.erosion_iteration_depth);
		sprintf(tvin_erosion_iteration, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_erosion_iteration, tvin_erosion_iteration);

		// [[transaction]]
		sprintf(tvin_dilate_iteration, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_dilate_iteration, tvin_dilate_iteration);

		sc_bv<32> dilate_iteration_tvin_wrapc_buffer;

		// RTL Name: dilate_iteration
		{
			// bitslice(31, 0)
			{
				// celement: dilate_iteration(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : dilate_iteration
						// sub_1st_elem          : 
						// ori_name_1st_elem     : dilate_iteration
						// regulate_c_name       : dilate_iteration
						// input_type_conversion : dilate_iteration
						if (&(dilate_iteration) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> dilate_iteration_tmp_mem;
							dilate_iteration_tmp_mem = dilate_iteration;
							dilate_iteration_tvin_wrapc_buffer.range(31, 0) = dilate_iteration_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_dilate_iteration, "%s\n", (dilate_iteration_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_dilate_iteration, tvin_dilate_iteration);
		}

		tcl_file.set_num(1, &tcl_file.dilate_iteration_depth);
		sprintf(tvin_dilate_iteration, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_dilate_iteration, tvin_dilate_iteration);

		// [[transaction]]
		sprintf(tvin_second_erosion_iteration, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_second_erosion_iteration, tvin_second_erosion_iteration);

		sc_bv<32> second_erosion_iteration_tvin_wrapc_buffer;

		// RTL Name: second_erosion_iteration
		{
			// bitslice(31, 0)
			{
				// celement: second_erosion_iteration(31, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : second_erosion_iteration
						// sub_1st_elem          : 
						// ori_name_1st_elem     : second_erosion_iteration
						// regulate_c_name       : second_erosion_iteration
						// input_type_conversion : second_erosion_iteration
						if (&(second_erosion_iteration) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<32> second_erosion_iteration_tmp_mem;
							second_erosion_iteration_tmp_mem = second_erosion_iteration;
							second_erosion_iteration_tvin_wrapc_buffer.range(31, 0) = second_erosion_iteration_tmp_mem.range(31, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_second_erosion_iteration, "%s\n", (second_erosion_iteration_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_second_erosion_iteration, tvin_second_erosion_iteration);
		}

		tcl_file.set_num(1, &tcl_file.second_erosion_iteration_depth);
		sprintf(tvin_second_erosion_iteration, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_second_erosion_iteration, tvin_second_erosion_iteration);

		// push back input stream: "streamIn"
		for (int i = 0; i < aesl_tmp_1; i++)
		{
			streamIn.write(aesl_tmp_0[i]);
		}

		// push back input stream: "streamOut"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			streamOut.write(aesl_tmp_3[i]);
		}

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		fromFrameToBlobCount(streamIn, streamOut, action, md_threshold, erosion_iteration, dilate_iteration, second_erosion_iteration);

		CodeState = DUMP_OUTPUTS;
		// record input size to tv3: "streamIn"
		int aesl_tmp_2 = streamIn.size();

		// pop output stream: "streamOut"
		int aesl_tmp_5 = aesl_tmp_4;
		aesl_tmp_4 = 0;
     aesl_tmp_3.clear();
		while (!streamOut.empty())
		{
			aesl_tmp_3.push_back(streamOut.read());
			aesl_tmp_4++;
		}

		// [[transaction]]
		sprintf(tvin_streamIn_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_data, tvin_streamIn_V_data);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, tvin_streamIn_V_data);

		sc_bv<32>* streamIn_V_data_tvin_wrapc_buffer = new sc_bv<32>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.data(31, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].data
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].data
							// regulate_c_name       : streamIn_V_data
							// input_type_conversion : aesl_tmp_0[i_0].data
							if (&(aesl_tmp_0[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> streamIn_V_data_tmp_mem;
								streamIn_V_data_tmp_mem = aesl_tmp_0[i_0].data;
								streamIn_V_data_tvin_wrapc_buffer[hls_map_index].range(31, 0) = streamIn_V_data_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_data, "%s\n", (streamIn_V_data_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_data, tvin_streamIn_V_data);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_data = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, stream_ingress_size_streamIn_V_data.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_data--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, stream_ingress_size_streamIn_V_data.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_data = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, stream_ingress_size_streamIn_V_data.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_data_depth);
		sprintf(tvin_streamIn_V_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_data, tvin_streamIn_V_data);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_data, tvin_streamIn_V_data);

		// release memory allocation
		delete [] streamIn_V_data_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_data, wrapc_stream_size_in_streamIn_V_data);
		sprintf(wrapc_stream_size_in_streamIn_V_data, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_data, wrapc_stream_size_in_streamIn_V_data);
		sprintf(wrapc_stream_size_in_streamIn_V_data, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_data, wrapc_stream_size_in_streamIn_V_data);

		// [[transaction]]
		sprintf(tvin_streamIn_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_keep_V, tvin_streamIn_V_keep_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, tvin_streamIn_V_keep_V);

		sc_bv<4>* streamIn_V_keep_V_tvin_wrapc_buffer = new sc_bv<4>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_keep_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.keep.V(3, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].keep
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].keep
							// regulate_c_name       : streamIn_V_keep_V
							// input_type_conversion : (aesl_tmp_0[i_0].keep).to_string(2).c_str()
							if (&(aesl_tmp_0[0].keep) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<4> streamIn_V_keep_V_tmp_mem;
								streamIn_V_keep_V_tmp_mem = (aesl_tmp_0[i_0].keep).to_string(2).c_str();
								streamIn_V_keep_V_tvin_wrapc_buffer[hls_map_index].range(3, 0) = streamIn_V_keep_V_tmp_mem.range(3, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_keep_V, "%s\n", (streamIn_V_keep_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_keep_V, tvin_streamIn_V_keep_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_keep_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, stream_ingress_size_streamIn_V_keep_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_keep_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, stream_ingress_size_streamIn_V_keep_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_keep_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, stream_ingress_size_streamIn_V_keep_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_keep_V_depth);
		sprintf(tvin_streamIn_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_keep_V, tvin_streamIn_V_keep_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_keep_V, tvin_streamIn_V_keep_V);

		// release memory allocation
		delete [] streamIn_V_keep_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_keep_V, wrapc_stream_size_in_streamIn_V_keep_V);
		sprintf(wrapc_stream_size_in_streamIn_V_keep_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_keep_V, wrapc_stream_size_in_streamIn_V_keep_V);
		sprintf(wrapc_stream_size_in_streamIn_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_keep_V, wrapc_stream_size_in_streamIn_V_keep_V);

		// [[transaction]]
		sprintf(tvin_streamIn_V_strb_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_strb_V, tvin_streamIn_V_strb_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, tvin_streamIn_V_strb_V);

		sc_bv<4>* streamIn_V_strb_V_tvin_wrapc_buffer = new sc_bv<4>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_strb_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.strb.V(3, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].strb
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].strb
							// regulate_c_name       : streamIn_V_strb_V
							// input_type_conversion : (aesl_tmp_0[i_0].strb).to_string(2).c_str()
							if (&(aesl_tmp_0[0].strb) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<4> streamIn_V_strb_V_tmp_mem;
								streamIn_V_strb_V_tmp_mem = (aesl_tmp_0[i_0].strb).to_string(2).c_str();
								streamIn_V_strb_V_tvin_wrapc_buffer[hls_map_index].range(3, 0) = streamIn_V_strb_V_tmp_mem.range(3, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_strb_V, "%s\n", (streamIn_V_strb_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_strb_V, tvin_streamIn_V_strb_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_strb_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, stream_ingress_size_streamIn_V_strb_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_strb_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, stream_ingress_size_streamIn_V_strb_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_strb_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, stream_ingress_size_streamIn_V_strb_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_strb_V_depth);
		sprintf(tvin_streamIn_V_strb_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_strb_V, tvin_streamIn_V_strb_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_strb_V, tvin_streamIn_V_strb_V);

		// release memory allocation
		delete [] streamIn_V_strb_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_strb_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_strb_V, wrapc_stream_size_in_streamIn_V_strb_V);
		sprintf(wrapc_stream_size_in_streamIn_V_strb_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_strb_V, wrapc_stream_size_in_streamIn_V_strb_V);
		sprintf(wrapc_stream_size_in_streamIn_V_strb_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_strb_V, wrapc_stream_size_in_streamIn_V_strb_V);

		// [[transaction]]
		sprintf(tvin_streamIn_V_user_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_user_V, tvin_streamIn_V_user_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, tvin_streamIn_V_user_V);

		sc_bv<1>* streamIn_V_user_V_tvin_wrapc_buffer = new sc_bv<1>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_user_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.user.V(0, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].user
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].user
							// regulate_c_name       : streamIn_V_user_V
							// input_type_conversion : (aesl_tmp_0[i_0].user).to_string(2).c_str()
							if (&(aesl_tmp_0[0].user) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamIn_V_user_V_tmp_mem;
								streamIn_V_user_V_tmp_mem = (aesl_tmp_0[i_0].user).to_string(2).c_str();
								streamIn_V_user_V_tvin_wrapc_buffer[hls_map_index].range(0, 0) = streamIn_V_user_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_user_V, "%s\n", (streamIn_V_user_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_user_V, tvin_streamIn_V_user_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_user_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, stream_ingress_size_streamIn_V_user_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_user_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, stream_ingress_size_streamIn_V_user_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_user_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, stream_ingress_size_streamIn_V_user_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_user_V_depth);
		sprintf(tvin_streamIn_V_user_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_user_V, tvin_streamIn_V_user_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_user_V, tvin_streamIn_V_user_V);

		// release memory allocation
		delete [] streamIn_V_user_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_user_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_user_V, wrapc_stream_size_in_streamIn_V_user_V);
		sprintf(wrapc_stream_size_in_streamIn_V_user_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_user_V, wrapc_stream_size_in_streamIn_V_user_V);
		sprintf(wrapc_stream_size_in_streamIn_V_user_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_user_V, wrapc_stream_size_in_streamIn_V_user_V);

		// [[transaction]]
		sprintf(tvin_streamIn_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_last_V, tvin_streamIn_V_last_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, tvin_streamIn_V_last_V);

		sc_bv<1>* streamIn_V_last_V_tvin_wrapc_buffer = new sc_bv<1>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_last_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.last.V(0, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].last
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].last
							// regulate_c_name       : streamIn_V_last_V
							// input_type_conversion : (aesl_tmp_0[i_0].last).to_string(2).c_str()
							if (&(aesl_tmp_0[0].last) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamIn_V_last_V_tmp_mem;
								streamIn_V_last_V_tmp_mem = (aesl_tmp_0[i_0].last).to_string(2).c_str();
								streamIn_V_last_V_tvin_wrapc_buffer[hls_map_index].range(0, 0) = streamIn_V_last_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_last_V, "%s\n", (streamIn_V_last_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_last_V, tvin_streamIn_V_last_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_last_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, stream_ingress_size_streamIn_V_last_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_last_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, stream_ingress_size_streamIn_V_last_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_last_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, stream_ingress_size_streamIn_V_last_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_last_V_depth);
		sprintf(tvin_streamIn_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_last_V, tvin_streamIn_V_last_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_last_V, tvin_streamIn_V_last_V);

		// release memory allocation
		delete [] streamIn_V_last_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_last_V, wrapc_stream_size_in_streamIn_V_last_V);
		sprintf(wrapc_stream_size_in_streamIn_V_last_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_last_V, wrapc_stream_size_in_streamIn_V_last_V);
		sprintf(wrapc_stream_size_in_streamIn_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_last_V, wrapc_stream_size_in_streamIn_V_last_V);

		// [[transaction]]
		sprintf(tvin_streamIn_V_id_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_id_V, tvin_streamIn_V_id_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, tvin_streamIn_V_id_V);

		sc_bv<1>* streamIn_V_id_V_tvin_wrapc_buffer = new sc_bv<1>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_id_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.id.V(0, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].id
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].id
							// regulate_c_name       : streamIn_V_id_V
							// input_type_conversion : (aesl_tmp_0[i_0].id).to_string(2).c_str()
							if (&(aesl_tmp_0[0].id) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamIn_V_id_V_tmp_mem;
								streamIn_V_id_V_tmp_mem = (aesl_tmp_0[i_0].id).to_string(2).c_str();
								streamIn_V_id_V_tvin_wrapc_buffer[hls_map_index].range(0, 0) = streamIn_V_id_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_id_V, "%s\n", (streamIn_V_id_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_id_V, tvin_streamIn_V_id_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_id_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, stream_ingress_size_streamIn_V_id_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_id_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, stream_ingress_size_streamIn_V_id_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_id_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, stream_ingress_size_streamIn_V_id_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_id_V_depth);
		sprintf(tvin_streamIn_V_id_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_id_V, tvin_streamIn_V_id_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_id_V, tvin_streamIn_V_id_V);

		// release memory allocation
		delete [] streamIn_V_id_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_id_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_id_V, wrapc_stream_size_in_streamIn_V_id_V);
		sprintf(wrapc_stream_size_in_streamIn_V_id_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_id_V, wrapc_stream_size_in_streamIn_V_id_V);
		sprintf(wrapc_stream_size_in_streamIn_V_id_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_id_V, wrapc_stream_size_in_streamIn_V_id_V);

		// [[transaction]]
		sprintf(tvin_streamIn_V_dest_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_dest_V, tvin_streamIn_V_dest_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, tvin_streamIn_V_dest_V);

		sc_bv<1>* streamIn_V_dest_V_tvin_wrapc_buffer = new sc_bv<1>[aesl_tmp_1 - aesl_tmp_2];

		// RTL Name: streamIn_V_dest_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamIn.V.dest.V(0, 0)
				{
					// carray: (0) => (aesl_tmp_1 - aesl_tmp_2 - 1) @ (1)
					for (int i_0 = 0; i_0 <= aesl_tmp_1 - aesl_tmp_2 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_0[i_0].dest
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_0[0].dest
							// regulate_c_name       : streamIn_V_dest_V
							// input_type_conversion : (aesl_tmp_0[i_0].dest).to_string(2).c_str()
							if (&(aesl_tmp_0[0].dest) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamIn_V_dest_V_tmp_mem;
								streamIn_V_dest_V_tmp_mem = (aesl_tmp_0[i_0].dest).to_string(2).c_str();
								streamIn_V_dest_V_tvin_wrapc_buffer[hls_map_index].range(0, 0) = streamIn_V_dest_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			sprintf(tvin_streamIn_V_dest_V, "%s\n", (streamIn_V_dest_V_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_streamIn_V_dest_V, tvin_streamIn_V_dest_V);
		}

		// dump stream ingress status to file
     if (aesl_tmp_1 > aesl_tmp_2)
     {
		sc_int<32> stream_ingress_size_streamIn_V_dest_V = aesl_tmp_1;
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, stream_ingress_size_streamIn_V_dest_V.to_string().c_str());
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, "\n");

		for (int i = 0; i < aesl_tmp_1 - aesl_tmp_2; i++)
		{
			stream_ingress_size_streamIn_V_dest_V--;
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, stream_ingress_size_streamIn_V_dest_V.to_string().c_str());
			aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, "\n");
		}
     }
     else {
		    sc_int<32> stream_ingress_size_streamIn_V_dest_V = 0;
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, stream_ingress_size_streamIn_V_dest_V.to_string().c_str());
		    aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, "\n");
     }

		tcl_file.set_num(aesl_tmp_1 - aesl_tmp_2, &tcl_file.streamIn_V_dest_V_depth);
		sprintf(tvin_streamIn_V_dest_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_streamIn_V_dest_V, tvin_streamIn_V_dest_V);
		aesl_fh.write(WRAPC_STREAM_INGRESS_STATUS_streamIn_V_dest_V, tvin_streamIn_V_dest_V);

		// release memory allocation
		delete [] streamIn_V_dest_V_tvin_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_in_streamIn_V_dest_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_dest_V, wrapc_stream_size_in_streamIn_V_dest_V);
		sprintf(wrapc_stream_size_in_streamIn_V_dest_V, "%d\n", aesl_tmp_1 - aesl_tmp_2);
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_dest_V, wrapc_stream_size_in_streamIn_V_dest_V);
		sprintf(wrapc_stream_size_in_streamIn_V_dest_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_IN_streamIn_V_dest_V, wrapc_stream_size_in_streamIn_V_dest_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_data, tvout_streamOut_V_data);

		sc_bv<32>* streamOut_V_data_tvout_wrapc_buffer = new sc_bv<32>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_data
		{
			// bitslice(31, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.data(31, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].data
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].data
							// regulate_c_name       : streamOut_V_data
							// input_type_conversion : aesl_tmp_3[i_0].data
							if (&(aesl_tmp_3[0].data) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<32> streamOut_V_data_tmp_mem;
								streamOut_V_data_tmp_mem = aesl_tmp_3[i_0].data;
								streamOut_V_data_tvout_wrapc_buffer[hls_map_index].range(31, 0) = streamOut_V_data_tmp_mem.range(31, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_data, "%s\n", (streamOut_V_data_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_data, tvout_streamOut_V_data);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_data_depth);
		sprintf(tvout_streamOut_V_data, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_data, tvout_streamOut_V_data);

		// release memory allocation
		delete [] streamOut_V_data_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_data, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, wrapc_stream_size_out_streamOut_V_data);
		sprintf(wrapc_stream_size_out_streamOut_V_data, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, wrapc_stream_size_out_streamOut_V_data);
		sprintf(wrapc_stream_size_out_streamOut_V_data, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_data, wrapc_stream_size_out_streamOut_V_data);

		// [[transaction]]
		sprintf(tvout_streamOut_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_keep_V, tvout_streamOut_V_keep_V);

		sc_bv<4>* streamOut_V_keep_V_tvout_wrapc_buffer = new sc_bv<4>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_keep_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.keep.V(3, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].keep
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].keep
							// regulate_c_name       : streamOut_V_keep_V
							// input_type_conversion : (aesl_tmp_3[i_0].keep).to_string(2).c_str()
							if (&(aesl_tmp_3[0].keep) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<4> streamOut_V_keep_V_tmp_mem;
								streamOut_V_keep_V_tmp_mem = (aesl_tmp_3[i_0].keep).to_string(2).c_str();
								streamOut_V_keep_V_tvout_wrapc_buffer[hls_map_index].range(3, 0) = streamOut_V_keep_V_tmp_mem.range(3, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_keep_V, "%s\n", (streamOut_V_keep_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_keep_V, tvout_streamOut_V_keep_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_keep_V_depth);
		sprintf(tvout_streamOut_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_keep_V, tvout_streamOut_V_keep_V);

		// release memory allocation
		delete [] streamOut_V_keep_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_keep_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_keep_V, wrapc_stream_size_out_streamOut_V_keep_V);
		sprintf(wrapc_stream_size_out_streamOut_V_keep_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_keep_V, wrapc_stream_size_out_streamOut_V_keep_V);
		sprintf(wrapc_stream_size_out_streamOut_V_keep_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_keep_V, wrapc_stream_size_out_streamOut_V_keep_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_strb_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_strb_V, tvout_streamOut_V_strb_V);

		sc_bv<4>* streamOut_V_strb_V_tvout_wrapc_buffer = new sc_bv<4>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_strb_V
		{
			// bitslice(3, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.strb.V(3, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].strb
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].strb
							// regulate_c_name       : streamOut_V_strb_V
							// input_type_conversion : (aesl_tmp_3[i_0].strb).to_string(2).c_str()
							if (&(aesl_tmp_3[0].strb) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<4> streamOut_V_strb_V_tmp_mem;
								streamOut_V_strb_V_tmp_mem = (aesl_tmp_3[i_0].strb).to_string(2).c_str();
								streamOut_V_strb_V_tvout_wrapc_buffer[hls_map_index].range(3, 0) = streamOut_V_strb_V_tmp_mem.range(3, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_strb_V, "%s\n", (streamOut_V_strb_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_strb_V, tvout_streamOut_V_strb_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_strb_V_depth);
		sprintf(tvout_streamOut_V_strb_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_strb_V, tvout_streamOut_V_strb_V);

		// release memory allocation
		delete [] streamOut_V_strb_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_strb_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_strb_V, wrapc_stream_size_out_streamOut_V_strb_V);
		sprintf(wrapc_stream_size_out_streamOut_V_strb_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_strb_V, wrapc_stream_size_out_streamOut_V_strb_V);
		sprintf(wrapc_stream_size_out_streamOut_V_strb_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_strb_V, wrapc_stream_size_out_streamOut_V_strb_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_user_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_user_V, tvout_streamOut_V_user_V);

		sc_bv<1>* streamOut_V_user_V_tvout_wrapc_buffer = new sc_bv<1>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_user_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.user.V(0, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].user
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].user
							// regulate_c_name       : streamOut_V_user_V
							// input_type_conversion : (aesl_tmp_3[i_0].user).to_string(2).c_str()
							if (&(aesl_tmp_3[0].user) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamOut_V_user_V_tmp_mem;
								streamOut_V_user_V_tmp_mem = (aesl_tmp_3[i_0].user).to_string(2).c_str();
								streamOut_V_user_V_tvout_wrapc_buffer[hls_map_index].range(0, 0) = streamOut_V_user_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_user_V, "%s\n", (streamOut_V_user_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_user_V, tvout_streamOut_V_user_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_user_V_depth);
		sprintf(tvout_streamOut_V_user_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_user_V, tvout_streamOut_V_user_V);

		// release memory allocation
		delete [] streamOut_V_user_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_user_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_user_V, wrapc_stream_size_out_streamOut_V_user_V);
		sprintf(wrapc_stream_size_out_streamOut_V_user_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_user_V, wrapc_stream_size_out_streamOut_V_user_V);
		sprintf(wrapc_stream_size_out_streamOut_V_user_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_user_V, wrapc_stream_size_out_streamOut_V_user_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_last_V, tvout_streamOut_V_last_V);

		sc_bv<1>* streamOut_V_last_V_tvout_wrapc_buffer = new sc_bv<1>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_last_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.last.V(0, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].last
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].last
							// regulate_c_name       : streamOut_V_last_V
							// input_type_conversion : (aesl_tmp_3[i_0].last).to_string(2).c_str()
							if (&(aesl_tmp_3[0].last) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamOut_V_last_V_tmp_mem;
								streamOut_V_last_V_tmp_mem = (aesl_tmp_3[i_0].last).to_string(2).c_str();
								streamOut_V_last_V_tvout_wrapc_buffer[hls_map_index].range(0, 0) = streamOut_V_last_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_last_V, "%s\n", (streamOut_V_last_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_last_V, tvout_streamOut_V_last_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_last_V_depth);
		sprintf(tvout_streamOut_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_last_V, tvout_streamOut_V_last_V);

		// release memory allocation
		delete [] streamOut_V_last_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_last_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_last_V, wrapc_stream_size_out_streamOut_V_last_V);
		sprintf(wrapc_stream_size_out_streamOut_V_last_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_last_V, wrapc_stream_size_out_streamOut_V_last_V);
		sprintf(wrapc_stream_size_out_streamOut_V_last_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_last_V, wrapc_stream_size_out_streamOut_V_last_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_id_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_id_V, tvout_streamOut_V_id_V);

		sc_bv<1>* streamOut_V_id_V_tvout_wrapc_buffer = new sc_bv<1>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_id_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.id.V(0, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].id
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].id
							// regulate_c_name       : streamOut_V_id_V
							// input_type_conversion : (aesl_tmp_3[i_0].id).to_string(2).c_str()
							if (&(aesl_tmp_3[0].id) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamOut_V_id_V_tmp_mem;
								streamOut_V_id_V_tmp_mem = (aesl_tmp_3[i_0].id).to_string(2).c_str();
								streamOut_V_id_V_tvout_wrapc_buffer[hls_map_index].range(0, 0) = streamOut_V_id_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_id_V, "%s\n", (streamOut_V_id_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_id_V, tvout_streamOut_V_id_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_id_V_depth);
		sprintf(tvout_streamOut_V_id_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_id_V, tvout_streamOut_V_id_V);

		// release memory allocation
		delete [] streamOut_V_id_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_id_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_id_V, wrapc_stream_size_out_streamOut_V_id_V);
		sprintf(wrapc_stream_size_out_streamOut_V_id_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_id_V, wrapc_stream_size_out_streamOut_V_id_V);
		sprintf(wrapc_stream_size_out_streamOut_V_id_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_id_V, wrapc_stream_size_out_streamOut_V_id_V);

		// [[transaction]]
		sprintf(tvout_streamOut_V_dest_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_dest_V, tvout_streamOut_V_dest_V);

		sc_bv<1>* streamOut_V_dest_V_tvout_wrapc_buffer = new sc_bv<1>[aesl_tmp_4 - aesl_tmp_5];

		// RTL Name: streamOut_V_dest_V
		{
			// bitslice(0, 0)
			{
				int hls_map_index = 0;
				// celement: streamOut.V.dest.V(0, 0)
				{
					// carray: (aesl_tmp_5) => (aesl_tmp_4 - 1) @ (1)
					for (int i_0 = aesl_tmp_5; i_0 <= aesl_tmp_4 - 1; i_0 += 1)
					{
						// carray: (0) => (0) @ (1)
						for (int i_1 = 0; i_1 <= 0; i_1 += 1)
						{
							// sub                   : i_0 i_1
							// ori_name              : aesl_tmp_3[i_0].dest
							// sub_1st_elem          : 0 0
							// ori_name_1st_elem     : aesl_tmp_3[0].dest
							// regulate_c_name       : streamOut_V_dest_V
							// input_type_conversion : (aesl_tmp_3[i_0].dest).to_string(2).c_str()
							if (&(aesl_tmp_3[0].dest) != NULL) // check the null address if the c port is array or others
							{
								sc_lv<1> streamOut_V_dest_V_tmp_mem;
								streamOut_V_dest_V_tmp_mem = (aesl_tmp_3[i_0].dest).to_string(2).c_str();
								streamOut_V_dest_V_tvout_wrapc_buffer[hls_map_index].range(0, 0) = streamOut_V_dest_V_tmp_mem.range(0, 0);
                                 		       hls_map_index++;
							}
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < aesl_tmp_4 - aesl_tmp_5; i++)
		{
			sprintf(tvout_streamOut_V_dest_V, "%s\n", (streamOut_V_dest_V_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_streamOut_V_dest_V, tvout_streamOut_V_dest_V);
		}

		tcl_file.set_num(aesl_tmp_4 - aesl_tmp_5, &tcl_file.streamOut_V_dest_V_depth);
		sprintf(tvout_streamOut_V_dest_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_streamOut_V_dest_V, tvout_streamOut_V_dest_V);

		// release memory allocation
		delete [] streamOut_V_dest_V_tvout_wrapc_buffer;

		// dump stream size
		sprintf(wrapc_stream_size_out_streamOut_V_dest_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_dest_V, wrapc_stream_size_out_streamOut_V_dest_V);
		sprintf(wrapc_stream_size_out_streamOut_V_dest_V, "%d\n", aesl_tmp_4 - aesl_tmp_5);
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_dest_V, wrapc_stream_size_out_streamOut_V_dest_V);
		sprintf(wrapc_stream_size_out_streamOut_V_dest_V, "[[/transaction]] \n");
		aesl_fh.write(WRAPC_STREAM_SIZE_OUT_streamOut_V_dest_V, wrapc_stream_size_out_streamOut_V_dest_V);

		// push back output stream: "streamOut"
		for (int i = 0; i < aesl_tmp_4; i++)
		{
			streamOut.write(aesl_tmp_3[i]);
		}

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "streamIn_V_data"
		delete [] tvin_streamIn_V_data;
		delete [] wrapc_stream_size_in_streamIn_V_data;
		// release memory allocation: "streamIn_V_keep_V"
		delete [] tvin_streamIn_V_keep_V;
		delete [] wrapc_stream_size_in_streamIn_V_keep_V;
		// release memory allocation: "streamIn_V_strb_V"
		delete [] tvin_streamIn_V_strb_V;
		delete [] wrapc_stream_size_in_streamIn_V_strb_V;
		// release memory allocation: "streamIn_V_user_V"
		delete [] tvin_streamIn_V_user_V;
		delete [] wrapc_stream_size_in_streamIn_V_user_V;
		// release memory allocation: "streamIn_V_last_V"
		delete [] tvin_streamIn_V_last_V;
		delete [] wrapc_stream_size_in_streamIn_V_last_V;
		// release memory allocation: "streamIn_V_id_V"
		delete [] tvin_streamIn_V_id_V;
		delete [] wrapc_stream_size_in_streamIn_V_id_V;
		// release memory allocation: "streamIn_V_dest_V"
		delete [] tvin_streamIn_V_dest_V;
		delete [] wrapc_stream_size_in_streamIn_V_dest_V;
		// release memory allocation: "streamOut_V_data"
		delete [] tvout_streamOut_V_data;
		delete [] tvin_streamOut_V_data;
		delete [] wrapc_stream_size_out_streamOut_V_data;
		// release memory allocation: "streamOut_V_keep_V"
		delete [] tvout_streamOut_V_keep_V;
		delete [] tvin_streamOut_V_keep_V;
		delete [] wrapc_stream_size_out_streamOut_V_keep_V;
		// release memory allocation: "streamOut_V_strb_V"
		delete [] tvout_streamOut_V_strb_V;
		delete [] tvin_streamOut_V_strb_V;
		delete [] wrapc_stream_size_out_streamOut_V_strb_V;
		// release memory allocation: "streamOut_V_user_V"
		delete [] tvout_streamOut_V_user_V;
		delete [] tvin_streamOut_V_user_V;
		delete [] wrapc_stream_size_out_streamOut_V_user_V;
		// release memory allocation: "streamOut_V_last_V"
		delete [] tvout_streamOut_V_last_V;
		delete [] tvin_streamOut_V_last_V;
		delete [] wrapc_stream_size_out_streamOut_V_last_V;
		// release memory allocation: "streamOut_V_id_V"
		delete [] tvout_streamOut_V_id_V;
		delete [] tvin_streamOut_V_id_V;
		delete [] wrapc_stream_size_out_streamOut_V_id_V;
		// release memory allocation: "streamOut_V_dest_V"
		delete [] tvout_streamOut_V_dest_V;
		delete [] tvin_streamOut_V_dest_V;
		delete [] wrapc_stream_size_out_streamOut_V_dest_V;
		// release memory allocation: "action"
		delete [] tvin_action;
		// release memory allocation: "md_threshold"
		delete [] tvin_md_threshold;
		// release memory allocation: "erosion_iteration"
		delete [] tvin_erosion_iteration;
		// release memory allocation: "dilate_iteration"
		delete [] tvin_dilate_iteration;
		// release memory allocation: "second_erosion_iteration"
		delete [] tvin_second_erosion_iteration;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

