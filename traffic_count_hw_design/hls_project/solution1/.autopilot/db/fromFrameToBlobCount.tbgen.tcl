set moduleName fromFrameToBlobCount
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fromFrameToBlobCount}
set C_modelType { void 0 }
set C_modelArgList {
	{ streamIn_V_data int 32 regular {axi_s 0 volatile  { streamIn Data } }  }
	{ streamIn_V_keep_V int 4 regular {axi_s 0 volatile  { streamIn Keep } }  }
	{ streamIn_V_strb_V int 4 regular {axi_s 0 volatile  { streamIn Strb } }  }
	{ streamIn_V_user_V int 1 regular {axi_s 0 volatile  { streamIn User } }  }
	{ streamIn_V_last_V int 1 regular {axi_s 0 volatile  { streamIn Last } }  }
	{ streamIn_V_id_V int 1 regular {axi_s 0 volatile  { streamIn ID } }  }
	{ streamIn_V_dest_V int 1 regular {axi_s 0 volatile  { streamIn Dest } }  }
	{ streamOut_V_data int 32 regular {axi_s 1 volatile  { streamOut Data } }  }
	{ streamOut_V_keep_V int 4 regular {axi_s 1 volatile  { streamOut Keep } }  }
	{ streamOut_V_strb_V int 4 regular {axi_s 1 volatile  { streamOut Strb } }  }
	{ streamOut_V_user_V int 1 regular {axi_s 1 volatile  { streamOut User } }  }
	{ streamOut_V_last_V int 1 regular {axi_s 1 volatile  { streamOut Last } }  }
	{ streamOut_V_id_V int 1 regular {axi_s 1 volatile  { streamOut ID } }  }
	{ streamOut_V_dest_V int 1 regular {axi_s 1 volatile  { streamOut Dest } }  }
	{ action int 32 regular {axi_slave 0}  }
	{ md_threshold int 32 regular {axi_slave 0}  }
	{ erosion_iteration int 32 regular {axi_slave 0}  }
	{ dilate_iteration int 32 regular {axi_slave 0}  }
	{ second_erosion_iteration int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "streamIn_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamIn.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamOut.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "action", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "action","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "md_threshold", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "md_threshold","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "dilate_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dilate_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "second_erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "second_erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} ]}
# RTL Port declarations: 
set portNum 38
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ streamIn_TDATA sc_in sc_lv 32 signal 0 } 
	{ streamIn_TVALID sc_in sc_logic 1 invld 6 } 
	{ streamIn_TREADY sc_out sc_logic 1 inacc 6 } 
	{ streamIn_TKEEP sc_in sc_lv 4 signal 1 } 
	{ streamIn_TSTRB sc_in sc_lv 4 signal 2 } 
	{ streamIn_TUSER sc_in sc_lv 1 signal 3 } 
	{ streamIn_TLAST sc_in sc_lv 1 signal 4 } 
	{ streamIn_TID sc_in sc_lv 1 signal 5 } 
	{ streamIn_TDEST sc_in sc_lv 1 signal 6 } 
	{ streamOut_TDATA sc_out sc_lv 32 signal 7 } 
	{ streamOut_TVALID sc_out sc_logic 1 outvld 13 } 
	{ streamOut_TREADY sc_in sc_logic 1 outacc 7 } 
	{ streamOut_TKEEP sc_out sc_lv 4 signal 8 } 
	{ streamOut_TSTRB sc_out sc_lv 4 signal 9 } 
	{ streamOut_TUSER sc_out sc_lv 1 signal 10 } 
	{ streamOut_TLAST sc_out sc_lv 1 signal 11 } 
	{ streamOut_TID sc_out sc_lv 1 signal 12 } 
	{ streamOut_TDEST sc_out sc_lv 1 signal 13 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"continue","value":"0","valid_bit":"4"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"},{"name":"action","role":"data","value":"16"},{"name":"md_threshold","role":"data","value":"24"},{"name":"erosion_iteration","role":"data","value":"32"},{"name":"dilate_iteration","role":"data","value":"40"},{"name":"second_erosion_iteration","role":"data","value":"48"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"done","value":"0","valid_bit":"1"},{"name":"fromFrameToBlobCount","role":"idle","value":"0","valid_bit":"2"},{"name":"fromFrameToBlobCount","role":"ready","value":"0","valid_bit":"3"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "streamIn_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamIn_V_data", "role": "default" }} , 
 	{ "name": "streamIn_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_keep_V", "role": "default" }} , 
 	{ "name": "streamIn_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_strb_V", "role": "default" }} , 
 	{ "name": "streamIn_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_user_V", "role": "default" }} , 
 	{ "name": "streamIn_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_last_V", "role": "default" }} , 
 	{ "name": "streamIn_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_id_V", "role": "default" }} , 
 	{ "name": "streamIn_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_keep_V", "role": "default" }} , 
 	{ "name": "streamOut_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_strb_V", "role": "default" }} , 
 	{ "name": "streamOut_TUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_user_V", "role": "default" }} , 
 	{ "name": "streamOut_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_last_V", "role": "default" }} , 
 	{ "name": "streamOut_TID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_id_V", "role": "default" }} , 
 	{ "name": "streamOut_TDEST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "13", "14", "15", "16", "17", "18", "19", "20"],
		"CDFG" : "fromFrameToBlobCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state27", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_563"},
			{"State" : "ap_ST_fsm_state35", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_563"},
			{"State" : "ap_ST_fsm_state40", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_blobsCount_fu_571"},
			{"State" : "ap_ST_fsm_state31", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_dilate_fu_577"},
			{"State" : "ap_ST_fsm_state38", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_cleanBorders_fu_585"},
			{"State" : "ap_ST_fsm_state29", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_591"},
			{"State" : "ap_ST_fsm_state33", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_591"},
			{"State" : "ap_ST_fsm_state37", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_591"}],
		"Port" : [
			{"Name" : "streamIn_V_data", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "streamIn_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamIn_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamOut_V_data", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "streamOut_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamOut_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_user_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_id_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_dest_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "action", "Type" : "None", "Direction" : "I"},
			{"Name" : "md_threshold", "Type" : "None", "Direction" : "I"},
			{"Name" : "erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "dilate_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "second_erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "background", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_grey", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_copy_fu_591", "Port" : "output_r"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_563", "Port" : "input_r"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_577", "Port" : "foreground"}]},
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_copy_fu_591", "Port" : "input_r"},
					{"ID" : "15", "SubInstance" : "grp_cleanBorders_fu_585", "Port" : "input_r"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_563", "Port" : "output_r"},
					{"ID" : "13", "SubInstance" : "grp_blobsCount_fu_571", "Port" : "foreground_clean"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_577", "Port" : "output_r"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.background_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_r_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_grey_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_clean_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_control_s_axi_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563", "Parent" : "0", "Child" : ["8", "9", "10", "11", "12"],
		"CDFG" : "erode_filter",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32609", "EstimateLatencyMax" : "32609",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563.lineBuf_val_1_U", "Parent" : "7"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563.lineBuf_val_2_U", "Parent" : "7"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563.fromFrameToBlobCount_urem_10ns_9ns_10_14_1_U1", "Parent" : "7"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563.fromFrameToBlobCount_mac_muladd_9ns_8ns_8ns_15_3_1_U2", "Parent" : "7"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_563.fromFrameToBlobCount_mul_mul_10ns_12ns_22_3_1_U3", "Parent" : "7"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_blobsCount_fu_571", "Parent" : "0",
		"CDFG" : "blobsCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "64449", "EstimateLatencyMax" : "64449",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dilate_fu_577", "Parent" : "0",
		"CDFG" : "dilate",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "158425", "EstimateLatencyMax" : "158425",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_cleanBorders_fu_585", "Parent" : "0",
		"CDFG" : "cleanBorders",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1084", "EstimateLatencyMax" : "1084",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_copy_fu_591", "Parent" : "0",
		"CDFG" : "copy",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32403", "EstimateLatencyMax" : "32403",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_3_1_U16", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_3_1_U17", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_3_1_U18", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_3_1_U19", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fromFrameToBlobCount {
		streamIn_V_data {Type I LastRead 3 FirstWrite -1}
		streamIn_V_keep_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_strb_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_user_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_last_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_id_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_dest_V {Type I LastRead 3 FirstWrite -1}
		streamOut_V_data {Type O LastRead -1 FirstWrite 12}
		streamOut_V_keep_V {Type O LastRead -1 FirstWrite 12}
		streamOut_V_strb_V {Type O LastRead -1 FirstWrite 12}
		streamOut_V_user_V {Type O LastRead -1 FirstWrite 12}
		streamOut_V_last_V {Type O LastRead -1 FirstWrite 12}
		streamOut_V_id_V {Type O LastRead -1 FirstWrite 12}
		streamOut_V_dest_V {Type O LastRead -1 FirstWrite 12}
		action {Type I LastRead 0 FirstWrite -1}
		md_threshold {Type I LastRead 0 FirstWrite -1}
		erosion_iteration {Type I LastRead 0 FirstWrite -1}
		dilate_iteration {Type I LastRead 0 FirstWrite -1}
		second_erosion_iteration {Type I LastRead 0 FirstWrite -1}
		background {Type IO LastRead -1 FirstWrite -1}
		input_r {Type IO LastRead -1 FirstWrite -1}
		input_grey {Type IO LastRead -1 FirstWrite -1}
		foreground {Type IO LastRead -1 FirstWrite -1}
		foreground_clean {Type IO LastRead -1 FirstWrite -1}}
	erode_filter {
		input_r {Type I LastRead 5 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 10}}
	blobsCount {
		foreground_clean {Type I LastRead 6 FirstWrite -1}}
	dilate {
		output_r {Type O LastRead -1 FirstWrite 5}
		foreground {Type I LastRead 4 FirstWrite -1}}
	cleanBorders {
		input_r {Type O LastRead -1 FirstWrite 1}}
	copy {
		input_r {Type I LastRead 1 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
]}

set Spec2ImplPortList { 
	streamIn_V_data { axis {  { streamIn_TDATA in_data 0 32 } } }
	streamIn_V_keep_V { axis {  { streamIn_TKEEP in_data 0 4 } } }
	streamIn_V_strb_V { axis {  { streamIn_TSTRB in_data 0 4 } } }
	streamIn_V_user_V { axis {  { streamIn_TUSER in_data 0 1 } } }
	streamIn_V_last_V { axis {  { streamIn_TLAST in_data 0 1 } } }
	streamIn_V_id_V { axis {  { streamIn_TID in_data 0 1 } } }
	streamIn_V_dest_V { axis {  { streamIn_TVALID in_vld 0 1 }  { streamIn_TREADY in_acc 1 1 }  { streamIn_TDEST in_data 0 1 } } }
	streamOut_V_data { axis {  { streamOut_TDATA out_data 1 32 }  { streamOut_TREADY out_acc 0 1 } } }
	streamOut_V_keep_V { axis {  { streamOut_TKEEP out_data 1 4 } } }
	streamOut_V_strb_V { axis {  { streamOut_TSTRB out_data 1 4 } } }
	streamOut_V_user_V { axis {  { streamOut_TUSER out_data 1 1 } } }
	streamOut_V_last_V { axis {  { streamOut_TLAST out_data 1 1 } } }
	streamOut_V_id_V { axis {  { streamOut_TID out_data 1 1 } } }
	streamOut_V_dest_V { axis {  { streamOut_TVALID out_vld 1 1 }  { streamOut_TDEST out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
set moduleName fromFrameToBlobCount
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fromFrameToBlobCount}
set C_modelType { void 0 }
set C_modelArgList {
	{ streamIn_V_data int 32 regular {axi_s 0 volatile  { streamIn Data } }  }
	{ streamIn_V_keep_V int 4 regular {axi_s 0 volatile  { streamIn Keep } }  }
	{ streamIn_V_strb_V int 4 regular {axi_s 0 volatile  { streamIn Strb } }  }
	{ streamIn_V_user_V int 1 regular {axi_s 0 volatile  { streamIn User } }  }
	{ streamIn_V_last_V int 1 regular {axi_s 0 volatile  { streamIn Last } }  }
	{ streamIn_V_id_V int 1 regular {axi_s 0 volatile  { streamIn ID } }  }
	{ streamIn_V_dest_V int 1 regular {axi_s 0 volatile  { streamIn Dest } }  }
	{ streamOut_V_data int 32 regular {axi_s 1 volatile  { streamOut Data } }  }
	{ streamOut_V_keep_V int 4 regular {axi_s 1 volatile  { streamOut Keep } }  }
	{ streamOut_V_strb_V int 4 regular {axi_s 1 volatile  { streamOut Strb } }  }
	{ streamOut_V_user_V int 1 regular {axi_s 1 volatile  { streamOut User } }  }
	{ streamOut_V_last_V int 1 regular {axi_s 1 volatile  { streamOut Last } }  }
	{ streamOut_V_id_V int 1 regular {axi_s 1 volatile  { streamOut ID } }  }
	{ streamOut_V_dest_V int 1 regular {axi_s 1 volatile  { streamOut Dest } }  }
	{ action int 32 regular {axi_slave 0}  }
	{ md_threshold int 32 regular {axi_slave 0}  }
	{ erosion_iteration int 32 regular {axi_slave 0}  }
	{ dilate_iteration int 32 regular {axi_slave 0}  }
	{ second_erosion_iteration int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "streamIn_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamIn.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamOut.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "action", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "action","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "md_threshold", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "md_threshold","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "dilate_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dilate_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "second_erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "second_erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} ]}
# RTL Port declarations: 
set portNum 38
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ streamIn_TDATA sc_in sc_lv 32 signal 0 } 
	{ streamIn_TVALID sc_in sc_logic 1 invld 6 } 
	{ streamIn_TREADY sc_out sc_logic 1 inacc 6 } 
	{ streamIn_TKEEP sc_in sc_lv 4 signal 1 } 
	{ streamIn_TSTRB sc_in sc_lv 4 signal 2 } 
	{ streamIn_TUSER sc_in sc_lv 1 signal 3 } 
	{ streamIn_TLAST sc_in sc_lv 1 signal 4 } 
	{ streamIn_TID sc_in sc_lv 1 signal 5 } 
	{ streamIn_TDEST sc_in sc_lv 1 signal 6 } 
	{ streamOut_TDATA sc_out sc_lv 32 signal 7 } 
	{ streamOut_TVALID sc_out sc_logic 1 outvld 13 } 
	{ streamOut_TREADY sc_in sc_logic 1 outacc 7 } 
	{ streamOut_TKEEP sc_out sc_lv 4 signal 8 } 
	{ streamOut_TSTRB sc_out sc_lv 4 signal 9 } 
	{ streamOut_TUSER sc_out sc_lv 1 signal 10 } 
	{ streamOut_TLAST sc_out sc_lv 1 signal 11 } 
	{ streamOut_TID sc_out sc_lv 1 signal 12 } 
	{ streamOut_TDEST sc_out sc_lv 1 signal 13 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"continue","value":"0","valid_bit":"4"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"},{"name":"action","role":"data","value":"16"},{"name":"md_threshold","role":"data","value":"24"},{"name":"erosion_iteration","role":"data","value":"32"},{"name":"dilate_iteration","role":"data","value":"40"},{"name":"second_erosion_iteration","role":"data","value":"48"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"done","value":"0","valid_bit":"1"},{"name":"fromFrameToBlobCount","role":"idle","value":"0","valid_bit":"2"},{"name":"fromFrameToBlobCount","role":"ready","value":"0","valid_bit":"3"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "streamIn_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamIn_V_data", "role": "default" }} , 
 	{ "name": "streamIn_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_keep_V", "role": "default" }} , 
 	{ "name": "streamIn_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_strb_V", "role": "default" }} , 
 	{ "name": "streamIn_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_user_V", "role": "default" }} , 
 	{ "name": "streamIn_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_last_V", "role": "default" }} , 
 	{ "name": "streamIn_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_id_V", "role": "default" }} , 
 	{ "name": "streamIn_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_keep_V", "role": "default" }} , 
 	{ "name": "streamOut_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_strb_V", "role": "default" }} , 
 	{ "name": "streamOut_TUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_user_V", "role": "default" }} , 
 	{ "name": "streamOut_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_last_V", "role": "default" }} , 
 	{ "name": "streamOut_TID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_id_V", "role": "default" }} , 
 	{ "name": "streamOut_TDEST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "13", "14", "15", "16", "17", "18", "19", "20"],
		"CDFG" : "fromFrameToBlobCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state28", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state36", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_blobsCount_fu_573"},
			{"State" : "ap_ST_fsm_state32", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_dilate_fu_579"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_cleanBorders_fu_587"},
			{"State" : "ap_ST_fsm_state30", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state34", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state38", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"}],
		"Port" : [
			{"Name" : "streamIn_V_data", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "streamIn_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamIn_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamOut_V_data", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "streamOut_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamOut_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_user_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_id_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_dest_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "action", "Type" : "None", "Direction" : "I"},
			{"Name" : "md_threshold", "Type" : "None", "Direction" : "I"},
			{"Name" : "erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "dilate_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "second_erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "background", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_grey", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "output_r"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "foreground"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "input_r"}]},
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_cleanBorders_fu_587", "Port" : "input_r"},
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "input_r"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "output_r"},
					{"ID" : "13", "SubInstance" : "grp_blobsCount_fu_573", "Port" : "foreground_clean"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "output_r"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.background_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_r_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_grey_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_clean_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_control_s_axi_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565", "Parent" : "0", "Child" : ["8", "9", "10", "11", "12"],
		"CDFG" : "erode_filter",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32609", "EstimateLatencyMax" : "32609",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_1_U", "Parent" : "7"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_2_U", "Parent" : "7"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_urem_10ns_9ns_10_14_1_U1", "Parent" : "7"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mac_muladd_9ns_8ns_8ns_15_3_1_U2", "Parent" : "7"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mul_mul_10ns_12ns_22_3_1_U3", "Parent" : "7"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_blobsCount_fu_573", "Parent" : "0",
		"CDFG" : "blobsCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "64449", "EstimateLatencyMax" : "64449",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dilate_fu_579", "Parent" : "0",
		"CDFG" : "dilate",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "158425", "EstimateLatencyMax" : "158425",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_cleanBorders_fu_587", "Parent" : "0",
		"CDFG" : "cleanBorders",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1084", "EstimateLatencyMax" : "1084",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_copy_fu_593", "Parent" : "0",
		"CDFG" : "copy",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32403", "EstimateLatencyMax" : "32403",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_3_1_U16", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_3_1_U17", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_1_1_U18", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_1_1_U19", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fromFrameToBlobCount {
		streamIn_V_data {Type I LastRead 3 FirstWrite -1}
		streamIn_V_keep_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_strb_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_user_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_last_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_id_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_dest_V {Type I LastRead 3 FirstWrite -1}
		streamOut_V_data {Type O LastRead -1 FirstWrite 13}
		streamOut_V_keep_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_strb_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_user_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_last_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_id_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_dest_V {Type O LastRead -1 FirstWrite 13}
		action {Type I LastRead 0 FirstWrite -1}
		md_threshold {Type I LastRead 0 FirstWrite -1}
		erosion_iteration {Type I LastRead 0 FirstWrite -1}
		dilate_iteration {Type I LastRead 0 FirstWrite -1}
		second_erosion_iteration {Type I LastRead 0 FirstWrite -1}
		background {Type IO LastRead -1 FirstWrite -1}
		input_r {Type IO LastRead -1 FirstWrite -1}
		input_grey {Type IO LastRead -1 FirstWrite -1}
		foreground {Type IO LastRead -1 FirstWrite -1}
		foreground_clean {Type IO LastRead -1 FirstWrite -1}}
	erode_filter {
		input_r {Type I LastRead 5 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 10}}
	blobsCount {
		foreground_clean {Type I LastRead 6 FirstWrite -1}}
	dilate {
		output_r {Type O LastRead -1 FirstWrite 5}
		foreground {Type I LastRead 4 FirstWrite -1}}
	cleanBorders {
		input_r {Type O LastRead -1 FirstWrite 1}}
	copy {
		input_r {Type I LastRead 1 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
]}

set Spec2ImplPortList { 
	streamIn_V_data { axis {  { streamIn_TDATA in_data 0 32 } } }
	streamIn_V_keep_V { axis {  { streamIn_TKEEP in_data 0 4 } } }
	streamIn_V_strb_V { axis {  { streamIn_TSTRB in_data 0 4 } } }
	streamIn_V_user_V { axis {  { streamIn_TUSER in_data 0 1 } } }
	streamIn_V_last_V { axis {  { streamIn_TLAST in_data 0 1 } } }
	streamIn_V_id_V { axis {  { streamIn_TID in_data 0 1 } } }
	streamIn_V_dest_V { axis {  { streamIn_TVALID in_vld 0 1 }  { streamIn_TREADY in_acc 1 1 }  { streamIn_TDEST in_data 0 1 } } }
	streamOut_V_data { axis {  { streamOut_TDATA out_data 1 32 }  { streamOut_TREADY out_acc 0 1 } } }
	streamOut_V_keep_V { axis {  { streamOut_TKEEP out_data 1 4 } } }
	streamOut_V_strb_V { axis {  { streamOut_TSTRB out_data 1 4 } } }
	streamOut_V_user_V { axis {  { streamOut_TUSER out_data 1 1 } } }
	streamOut_V_last_V { axis {  { streamOut_TLAST out_data 1 1 } } }
	streamOut_V_id_V { axis {  { streamOut_TID out_data 1 1 } } }
	streamOut_V_dest_V { axis {  { streamOut_TVALID out_vld 1 1 }  { streamOut_TDEST out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
set moduleName fromFrameToBlobCount
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fromFrameToBlobCount}
set C_modelType { void 0 }
set C_modelArgList {
	{ streamIn_V_data int 32 regular {axi_s 0 volatile  { streamIn Data } }  }
	{ streamIn_V_keep_V int 4 regular {axi_s 0 volatile  { streamIn Keep } }  }
	{ streamIn_V_strb_V int 4 regular {axi_s 0 volatile  { streamIn Strb } }  }
	{ streamIn_V_user_V int 1 regular {axi_s 0 volatile  { streamIn User } }  }
	{ streamIn_V_last_V int 1 regular {axi_s 0 volatile  { streamIn Last } }  }
	{ streamIn_V_id_V int 1 regular {axi_s 0 volatile  { streamIn ID } }  }
	{ streamIn_V_dest_V int 1 regular {axi_s 0 volatile  { streamIn Dest } }  }
	{ streamOut_V_data int 32 regular {axi_s 1 volatile  { streamOut Data } }  }
	{ streamOut_V_keep_V int 4 regular {axi_s 1 volatile  { streamOut Keep } }  }
	{ streamOut_V_strb_V int 4 regular {axi_s 1 volatile  { streamOut Strb } }  }
	{ streamOut_V_user_V int 1 regular {axi_s 1 volatile  { streamOut User } }  }
	{ streamOut_V_last_V int 1 regular {axi_s 1 volatile  { streamOut Last } }  }
	{ streamOut_V_id_V int 1 regular {axi_s 1 volatile  { streamOut ID } }  }
	{ streamOut_V_dest_V int 1 regular {axi_s 1 volatile  { streamOut Dest } }  }
	{ action int 32 regular {axi_slave 0}  }
	{ md_threshold int 32 regular {axi_slave 0}  }
	{ erosion_iteration int 32 regular {axi_slave 0}  }
	{ dilate_iteration int 32 regular {axi_slave 0}  }
	{ second_erosion_iteration int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "streamIn_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamIn.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamOut.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "action", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "action","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "md_threshold", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "md_threshold","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "dilate_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dilate_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "second_erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "second_erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} ]}
# RTL Port declarations: 
set portNum 38
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ streamIn_TDATA sc_in sc_lv 32 signal 0 } 
	{ streamIn_TVALID sc_in sc_logic 1 invld 6 } 
	{ streamIn_TREADY sc_out sc_logic 1 inacc 6 } 
	{ streamIn_TKEEP sc_in sc_lv 4 signal 1 } 
	{ streamIn_TSTRB sc_in sc_lv 4 signal 2 } 
	{ streamIn_TUSER sc_in sc_lv 1 signal 3 } 
	{ streamIn_TLAST sc_in sc_lv 1 signal 4 } 
	{ streamIn_TID sc_in sc_lv 1 signal 5 } 
	{ streamIn_TDEST sc_in sc_lv 1 signal 6 } 
	{ streamOut_TDATA sc_out sc_lv 32 signal 7 } 
	{ streamOut_TVALID sc_out sc_logic 1 outvld 13 } 
	{ streamOut_TREADY sc_in sc_logic 1 outacc 7 } 
	{ streamOut_TKEEP sc_out sc_lv 4 signal 8 } 
	{ streamOut_TSTRB sc_out sc_lv 4 signal 9 } 
	{ streamOut_TUSER sc_out sc_lv 1 signal 10 } 
	{ streamOut_TLAST sc_out sc_lv 1 signal 11 } 
	{ streamOut_TID sc_out sc_lv 1 signal 12 } 
	{ streamOut_TDEST sc_out sc_lv 1 signal 13 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"continue","value":"0","valid_bit":"4"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"},{"name":"action","role":"data","value":"16"},{"name":"md_threshold","role":"data","value":"24"},{"name":"erosion_iteration","role":"data","value":"32"},{"name":"dilate_iteration","role":"data","value":"40"},{"name":"second_erosion_iteration","role":"data","value":"48"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"done","value":"0","valid_bit":"1"},{"name":"fromFrameToBlobCount","role":"idle","value":"0","valid_bit":"2"},{"name":"fromFrameToBlobCount","role":"ready","value":"0","valid_bit":"3"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "streamIn_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamIn_V_data", "role": "default" }} , 
 	{ "name": "streamIn_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_keep_V", "role": "default" }} , 
 	{ "name": "streamIn_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_strb_V", "role": "default" }} , 
 	{ "name": "streamIn_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_user_V", "role": "default" }} , 
 	{ "name": "streamIn_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_last_V", "role": "default" }} , 
 	{ "name": "streamIn_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_id_V", "role": "default" }} , 
 	{ "name": "streamIn_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_keep_V", "role": "default" }} , 
 	{ "name": "streamOut_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_strb_V", "role": "default" }} , 
 	{ "name": "streamOut_TUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_user_V", "role": "default" }} , 
 	{ "name": "streamOut_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_last_V", "role": "default" }} , 
 	{ "name": "streamOut_TID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_id_V", "role": "default" }} , 
 	{ "name": "streamOut_TDEST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "13", "14", "15", "16", "17", "18", "19", "20"],
		"CDFG" : "fromFrameToBlobCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state28", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state36", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_blobsCount_fu_573"},
			{"State" : "ap_ST_fsm_state32", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_dilate_fu_579"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_cleanBorders_fu_587"},
			{"State" : "ap_ST_fsm_state30", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state34", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state38", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"}],
		"Port" : [
			{"Name" : "streamIn_V_data", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "streamIn_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamIn_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamOut_V_data", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "streamOut_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamOut_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_user_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_id_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_dest_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "action", "Type" : "None", "Direction" : "I"},
			{"Name" : "md_threshold", "Type" : "None", "Direction" : "I"},
			{"Name" : "erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "dilate_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "second_erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "background", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_grey", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "foreground"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "input_r"},
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "output_r"}]},
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "output_r"},
					{"ID" : "15", "SubInstance" : "grp_cleanBorders_fu_587", "Port" : "input_r"},
					{"ID" : "13", "SubInstance" : "grp_blobsCount_fu_573", "Port" : "foreground_clean"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "output_r"},
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "input_r"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.background_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_r_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_grey_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_clean_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_control_s_axi_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565", "Parent" : "0", "Child" : ["8", "9", "10", "11", "12"],
		"CDFG" : "erode_filter",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32609", "EstimateLatencyMax" : "32609",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_1_U", "Parent" : "7"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_2_U", "Parent" : "7"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_urem_10ns_9ns_10_14_1_U1", "Parent" : "7"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mac_muladd_9ns_8ns_8ns_15_3_1_U2", "Parent" : "7"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mul_mul_10ns_12ns_22_3_1_U3", "Parent" : "7"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_blobsCount_fu_573", "Parent" : "0",
		"CDFG" : "blobsCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "64449", "EstimateLatencyMax" : "64449",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dilate_fu_579", "Parent" : "0",
		"CDFG" : "dilate",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "158425", "EstimateLatencyMax" : "158425",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_cleanBorders_fu_587", "Parent" : "0",
		"CDFG" : "cleanBorders",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1084", "EstimateLatencyMax" : "1084",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_copy_fu_593", "Parent" : "0",
		"CDFG" : "copy",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32403", "EstimateLatencyMax" : "32403",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_3_1_U16", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_3_1_U17", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_1_1_U18", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_1_1_U19", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fromFrameToBlobCount {
		streamIn_V_data {Type I LastRead 3 FirstWrite -1}
		streamIn_V_keep_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_strb_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_user_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_last_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_id_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_dest_V {Type I LastRead 3 FirstWrite -1}
		streamOut_V_data {Type O LastRead -1 FirstWrite 13}
		streamOut_V_keep_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_strb_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_user_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_last_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_id_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_dest_V {Type O LastRead -1 FirstWrite 13}
		action {Type I LastRead 0 FirstWrite -1}
		md_threshold {Type I LastRead 0 FirstWrite -1}
		erosion_iteration {Type I LastRead 0 FirstWrite -1}
		dilate_iteration {Type I LastRead 0 FirstWrite -1}
		second_erosion_iteration {Type I LastRead 0 FirstWrite -1}
		background {Type IO LastRead -1 FirstWrite -1}
		input_r {Type IO LastRead -1 FirstWrite -1}
		input_grey {Type IO LastRead -1 FirstWrite -1}
		foreground {Type IO LastRead -1 FirstWrite -1}
		foreground_clean {Type IO LastRead -1 FirstWrite -1}}
	erode_filter {
		input_r {Type I LastRead 5 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 10}}
	blobsCount {
		foreground_clean {Type I LastRead 6 FirstWrite -1}}
	dilate {
		output_r {Type O LastRead -1 FirstWrite 5}
		foreground {Type I LastRead 4 FirstWrite -1}}
	cleanBorders {
		input_r {Type O LastRead -1 FirstWrite 1}}
	copy {
		input_r {Type I LastRead 1 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
]}

set Spec2ImplPortList { 
	streamIn_V_data { axis {  { streamIn_TDATA in_data 0 32 } } }
	streamIn_V_keep_V { axis {  { streamIn_TKEEP in_data 0 4 } } }
	streamIn_V_strb_V { axis {  { streamIn_TSTRB in_data 0 4 } } }
	streamIn_V_user_V { axis {  { streamIn_TUSER in_data 0 1 } } }
	streamIn_V_last_V { axis {  { streamIn_TLAST in_data 0 1 } } }
	streamIn_V_id_V { axis {  { streamIn_TID in_data 0 1 } } }
	streamIn_V_dest_V { axis {  { streamIn_TVALID in_vld 0 1 }  { streamIn_TREADY in_acc 1 1 }  { streamIn_TDEST in_data 0 1 } } }
	streamOut_V_data { axis {  { streamOut_TDATA out_data 1 32 }  { streamOut_TREADY out_acc 0 1 } } }
	streamOut_V_keep_V { axis {  { streamOut_TKEEP out_data 1 4 } } }
	streamOut_V_strb_V { axis {  { streamOut_TSTRB out_data 1 4 } } }
	streamOut_V_user_V { axis {  { streamOut_TUSER out_data 1 1 } } }
	streamOut_V_last_V { axis {  { streamOut_TLAST out_data 1 1 } } }
	streamOut_V_id_V { axis {  { streamOut_TID out_data 1 1 } } }
	streamOut_V_dest_V { axis {  { streamOut_TVALID out_vld 1 1 }  { streamOut_TDEST out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
set moduleName fromFrameToBlobCount
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {fromFrameToBlobCount}
set C_modelType { void 0 }
set C_modelArgList {
	{ streamIn_V_data int 32 regular {axi_s 0 volatile  { streamIn Data } }  }
	{ streamIn_V_keep_V int 4 regular {axi_s 0 volatile  { streamIn Keep } }  }
	{ streamIn_V_strb_V int 4 regular {axi_s 0 volatile  { streamIn Strb } }  }
	{ streamIn_V_user_V int 1 regular {axi_s 0 volatile  { streamIn User } }  }
	{ streamIn_V_last_V int 1 regular {axi_s 0 volatile  { streamIn Last } }  }
	{ streamIn_V_id_V int 1 regular {axi_s 0 volatile  { streamIn ID } }  }
	{ streamIn_V_dest_V int 1 regular {axi_s 0 volatile  { streamIn Dest } }  }
	{ streamOut_V_data int 32 regular {axi_s 1 volatile  { streamOut Data } }  }
	{ streamOut_V_keep_V int 4 regular {axi_s 1 volatile  { streamOut Keep } }  }
	{ streamOut_V_strb_V int 4 regular {axi_s 1 volatile  { streamOut Strb } }  }
	{ streamOut_V_user_V int 1 regular {axi_s 1 volatile  { streamOut User } }  }
	{ streamOut_V_last_V int 1 regular {axi_s 1 volatile  { streamOut Last } }  }
	{ streamOut_V_id_V int 1 regular {axi_s 1 volatile  { streamOut ID } }  }
	{ streamOut_V_dest_V int 1 regular {axi_s 1 volatile  { streamOut Dest } }  }
	{ action int 32 regular {axi_slave 0}  }
	{ md_threshold int 32 regular {axi_slave 0}  }
	{ erosion_iteration int 32 regular {axi_slave 0}  }
	{ dilate_iteration int 32 regular {axi_slave 0}  }
	{ second_erosion_iteration int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "streamIn_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamIn.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "READONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamIn.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamIn_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamIn.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_data", "interface" : "axis", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "streamOut.V.data","cData": "unsigned int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_keep_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.keep.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_strb_V", "interface" : "axis", "bitwidth" : 4, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":3,"cElement": [{"cName": "streamOut.V.strb.V","cData": "uint4","bit_use": { "low": 0,"up": 3},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_user_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.user.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_last_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.last.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_id_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.id.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "streamOut_V_dest_V", "interface" : "axis", "bitwidth" : 1, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "streamOut.V.dest.V","cData": "uint1","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 1}]}]}]} , 
 	{ "Name" : "action", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "action","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "md_threshold", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "md_threshold","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "dilate_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "dilate_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "second_erosion_iteration", "interface" : "axi_slave", "bundle":"control","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "second_erosion_iteration","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":48}, "offset_end" : {"in":55}} ]}
# RTL Port declarations: 
set portNum 38
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ streamIn_TDATA sc_in sc_lv 32 signal 0 } 
	{ streamIn_TVALID sc_in sc_logic 1 invld 6 } 
	{ streamIn_TREADY sc_out sc_logic 1 inacc 6 } 
	{ streamIn_TKEEP sc_in sc_lv 4 signal 1 } 
	{ streamIn_TSTRB sc_in sc_lv 4 signal 2 } 
	{ streamIn_TUSER sc_in sc_lv 1 signal 3 } 
	{ streamIn_TLAST sc_in sc_lv 1 signal 4 } 
	{ streamIn_TID sc_in sc_lv 1 signal 5 } 
	{ streamIn_TDEST sc_in sc_lv 1 signal 6 } 
	{ streamOut_TDATA sc_out sc_lv 32 signal 7 } 
	{ streamOut_TVALID sc_out sc_logic 1 outvld 13 } 
	{ streamOut_TREADY sc_in sc_logic 1 outacc 7 } 
	{ streamOut_TKEEP sc_out sc_lv 4 signal 8 } 
	{ streamOut_TSTRB sc_out sc_lv 4 signal 9 } 
	{ streamOut_TUSER sc_out sc_lv 1 signal 10 } 
	{ streamOut_TLAST sc_out sc_lv 1 signal 11 } 
	{ streamOut_TID sc_out sc_lv 1 signal 12 } 
	{ streamOut_TDEST sc_out sc_lv 1 signal 13 } 
	{ s_axi_control_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_AWADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_control_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_control_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_ARADDR sc_in sc_lv 6 signal -1 } 
	{ s_axi_control_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_control_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_control_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_control_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_control_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_control_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "AWADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"continue","value":"0","valid_bit":"4"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"},{"name":"action","role":"data","value":"16"},{"name":"md_threshold","role":"data","value":"24"},{"name":"erosion_iteration","role":"data","value":"32"},{"name":"dilate_iteration","role":"data","value":"40"},{"name":"second_erosion_iteration","role":"data","value":"48"}] },
	{ "name": "s_axi_control_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWVALID" } },
	{ "name": "s_axi_control_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "AWREADY" } },
	{ "name": "s_axi_control_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WVALID" } },
	{ "name": "s_axi_control_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "WREADY" } },
	{ "name": "s_axi_control_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "WDATA" } },
	{ "name": "s_axi_control_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "control", "role": "WSTRB" } },
	{ "name": "s_axi_control_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "control", "role": "ARADDR" },"address":[{"name":"fromFrameToBlobCount","role":"start","value":"0","valid_bit":"0"},{"name":"fromFrameToBlobCount","role":"done","value":"0","valid_bit":"1"},{"name":"fromFrameToBlobCount","role":"idle","value":"0","valid_bit":"2"},{"name":"fromFrameToBlobCount","role":"ready","value":"0","valid_bit":"3"},{"name":"fromFrameToBlobCount","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_control_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARVALID" } },
	{ "name": "s_axi_control_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "ARREADY" } },
	{ "name": "s_axi_control_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RVALID" } },
	{ "name": "s_axi_control_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "RREADY" } },
	{ "name": "s_axi_control_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "control", "role": "RDATA" } },
	{ "name": "s_axi_control_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "RRESP" } },
	{ "name": "s_axi_control_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BVALID" } },
	{ "name": "s_axi_control_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "BREADY" } },
	{ "name": "s_axi_control_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "control", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "control", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "streamIn_TDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamIn_V_data", "role": "default" }} , 
 	{ "name": "streamIn_TVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "invld", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "inacc", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamIn_TKEEP", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_keep_V", "role": "default" }} , 
 	{ "name": "streamIn_TSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamIn_V_strb_V", "role": "default" }} , 
 	{ "name": "streamIn_TUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_user_V", "role": "default" }} , 
 	{ "name": "streamIn_TLAST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_last_V", "role": "default" }} , 
 	{ "name": "streamIn_TID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_id_V", "role": "default" }} , 
 	{ "name": "streamIn_TDEST", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamIn_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }} , 
 	{ "name": "streamOut_TREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "outacc", "bundle":{"name": "streamOut_V_data", "role": "default" }} , 
 	{ "name": "streamOut_TKEEP", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_keep_V", "role": "default" }} , 
 	{ "name": "streamOut_TSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "streamOut_V_strb_V", "role": "default" }} , 
 	{ "name": "streamOut_TUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_user_V", "role": "default" }} , 
 	{ "name": "streamOut_TLAST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_last_V", "role": "default" }} , 
 	{ "name": "streamOut_TID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_id_V", "role": "default" }} , 
 	{ "name": "streamOut_TDEST", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "streamOut_V_dest_V", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "13", "14", "15", "16", "17", "18", "19", "20"],
		"CDFG" : "fromFrameToBlobCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state28", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state36", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_erode_filter_fu_565"},
			{"State" : "ap_ST_fsm_state41", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_blobsCount_fu_573"},
			{"State" : "ap_ST_fsm_state32", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_dilate_fu_579"},
			{"State" : "ap_ST_fsm_state39", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_cleanBorders_fu_587"},
			{"State" : "ap_ST_fsm_state30", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state34", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"},
			{"State" : "ap_ST_fsm_state38", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_copy_fu_593"}],
		"Port" : [
			{"Name" : "streamIn_V_data", "Type" : "Axis", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "streamIn_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamIn_V_keep_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_strb_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_user_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_last_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_id_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamIn_V_dest_V", "Type" : "Axis", "Direction" : "I"},
			{"Name" : "streamOut_V_data", "Type" : "Axis", "Direction" : "O",
				"BlockSignal" : [
					{"Name" : "streamOut_TDATA_blk_n", "Type" : "RtlSignal"}]},
			{"Name" : "streamOut_V_keep_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_strb_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_user_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_last_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_id_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "streamOut_V_dest_V", "Type" : "Axis", "Direction" : "O"},
			{"Name" : "action", "Type" : "None", "Direction" : "I"},
			{"Name" : "md_threshold", "Type" : "None", "Direction" : "I"},
			{"Name" : "erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "dilate_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "second_erosion_iteration", "Type" : "None", "Direction" : "I"},
			{"Name" : "background", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "input_grey", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "input_r"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "foreground"},
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "output_r"}]},
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_cleanBorders_fu_587", "Port" : "input_r"},
					{"ID" : "7", "SubInstance" : "grp_erode_filter_fu_565", "Port" : "output_r"},
					{"ID" : "13", "SubInstance" : "grp_blobsCount_fu_573", "Port" : "foreground_clean"},
					{"ID" : "14", "SubInstance" : "grp_dilate_fu_579", "Port" : "output_r"},
					{"ID" : "16", "SubInstance" : "grp_copy_fu_593", "Port" : "input_r"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.background_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_r_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_grey_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.foreground_clean_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_control_s_axi_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565", "Parent" : "0", "Child" : ["8", "9", "10", "11", "12"],
		"CDFG" : "erode_filter",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32609", "EstimateLatencyMax" : "32609",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_1_U", "Parent" : "7"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.lineBuf_val_2_U", "Parent" : "7"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_urem_10ns_9ns_10_14_1_U1", "Parent" : "7"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mac_muladd_9ns_8ns_8ns_15_3_1_U2", "Parent" : "7"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_erode_filter_fu_565.fromFrameToBlobCount_mul_mul_10ns_12ns_22_3_1_U3", "Parent" : "7"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_blobsCount_fu_573", "Parent" : "0",
		"CDFG" : "blobsCount",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "64449", "EstimateLatencyMax" : "64449",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "foreground_clean", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_dilate_fu_579", "Parent" : "0",
		"CDFG" : "dilate",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "158425", "EstimateLatencyMax" : "158425",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "foreground", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_cleanBorders_fu_587", "Parent" : "0",
		"CDFG" : "cleanBorders",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1084", "EstimateLatencyMax" : "1084",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_copy_fu_593", "Parent" : "0",
		"CDFG" : "copy",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "32403", "EstimateLatencyMax" : "32403",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_r", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_r", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_3_1_U16", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_3_1_U17", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mac_muladd_8ns_5ns_15ns_15_1_1_U18", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fromFrameToBlobCount_mul_mul_17ns_19ns_36_1_1_U19", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	fromFrameToBlobCount {
		streamIn_V_data {Type I LastRead 3 FirstWrite -1}
		streamIn_V_keep_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_strb_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_user_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_last_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_id_V {Type I LastRead 3 FirstWrite -1}
		streamIn_V_dest_V {Type I LastRead 3 FirstWrite -1}
		streamOut_V_data {Type O LastRead -1 FirstWrite 13}
		streamOut_V_keep_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_strb_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_user_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_last_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_id_V {Type O LastRead -1 FirstWrite 13}
		streamOut_V_dest_V {Type O LastRead -1 FirstWrite 13}
		action {Type I LastRead 0 FirstWrite -1}
		md_threshold {Type I LastRead 0 FirstWrite -1}
		erosion_iteration {Type I LastRead 0 FirstWrite -1}
		dilate_iteration {Type I LastRead 0 FirstWrite -1}
		second_erosion_iteration {Type I LastRead 0 FirstWrite -1}
		background {Type IO LastRead -1 FirstWrite -1}
		input_r {Type IO LastRead -1 FirstWrite -1}
		input_grey {Type IO LastRead -1 FirstWrite -1}
		foreground {Type IO LastRead -1 FirstWrite -1}
		foreground_clean {Type IO LastRead -1 FirstWrite -1}}
	erode_filter {
		input_r {Type I LastRead 5 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 10}}
	blobsCount {
		foreground_clean {Type I LastRead 6 FirstWrite -1}}
	dilate {
		output_r {Type O LastRead -1 FirstWrite 5}
		foreground {Type I LastRead 4 FirstWrite -1}}
	cleanBorders {
		input_r {Type O LastRead -1 FirstWrite 1}}
	copy {
		input_r {Type I LastRead 1 FirstWrite -1}
		output_r {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
]}

set Spec2ImplPortList { 
	streamIn_V_data { axis {  { streamIn_TDATA in_data 0 32 } } }
	streamIn_V_keep_V { axis {  { streamIn_TKEEP in_data 0 4 } } }
	streamIn_V_strb_V { axis {  { streamIn_TSTRB in_data 0 4 } } }
	streamIn_V_user_V { axis {  { streamIn_TUSER in_data 0 1 } } }
	streamIn_V_last_V { axis {  { streamIn_TLAST in_data 0 1 } } }
	streamIn_V_id_V { axis {  { streamIn_TID in_data 0 1 } } }
	streamIn_V_dest_V { axis {  { streamIn_TVALID in_vld 0 1 }  { streamIn_TREADY in_acc 1 1 }  { streamIn_TDEST in_data 0 1 } } }
	streamOut_V_data { axis {  { streamOut_TDATA out_data 1 32 }  { streamOut_TREADY out_acc 0 1 } } }
	streamOut_V_keep_V { axis {  { streamOut_TKEEP out_data 1 4 } } }
	streamOut_V_strb_V { axis {  { streamOut_TSTRB out_data 1 4 } } }
	streamOut_V_user_V { axis {  { streamOut_TUSER out_data 1 1 } } }
	streamOut_V_last_V { axis {  { streamOut_TLAST out_data 1 1 } } }
	streamOut_V_id_V { axis {  { streamOut_TID out_data 1 1 } } }
	streamOut_V_dest_V { axis {  { streamOut_TVALID out_vld 1 1 }  { streamOut_TDEST out_data 1 1 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
