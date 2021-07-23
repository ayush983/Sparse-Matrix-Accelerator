set C_TypeInfoList {{ 
"mul1" : [[], { "return": [[], "void"]} , [{"ExternC" : 0}], [ {"A": [[], {"array": [ {"array": [ {"scalar": "int"}, [10]]}, [10]]}] }, {"B": [[], {"array": [ {"array": [ {"scalar": "int"}, [10]]}, [10]]}] }, {"C": [[], {"array": [ {"array": [ {"scalar": "int"}, [10]]}, [10]]}] }, {"sparse_new": [[], {"array": [ {"array": [ {"scalar": "int"}, [3]]}, [9]]}] }],[],""]
}}
set moduleName mul1
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
set C_modelName {mul1}
set C_modelType { void 0 }
set C_modelArgList {
	{ A int 32 unused {array 100 { } 0 1 }  }
	{ B_0 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_1 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_2 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_3 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_4 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_5 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_6 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_7 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_8 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ B_9 int 32 regular {array 10 { 1 3 } 1 1 }  }
	{ C_0 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_1 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_2 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_3 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_4 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_5 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_6 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_7 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_8 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ C_9 int 32 regular {array 10 { 2 3 } 1 1 }  }
	{ sparse_new int 32 regular {array 27 { 1 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "A", "interface" : "memory", "bitwidth" : 32, "direction" : "NONE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "A","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 0,"up" : 9,"step" : 1}]}]}]} , 
 	{ "Name" : "B_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "B_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "B_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "B_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "B_4", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "B_5", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "B_6", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "B_7", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "B_8", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 8,"up" : 8,"step" : 2}]}]}]} , 
 	{ "Name" : "B_9", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "B","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 9,"up" : 9,"step" : 2}]}]}]} , 
 	{ "Name" : "C_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 0,"up" : 0,"step" : 2}]}]}]} , 
 	{ "Name" : "C_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 1,"up" : 1,"step" : 2}]}]}]} , 
 	{ "Name" : "C_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 2,"up" : 2,"step" : 2}]}]}]} , 
 	{ "Name" : "C_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 3,"up" : 3,"step" : 2}]}]}]} , 
 	{ "Name" : "C_4", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 4,"up" : 4,"step" : 2}]}]}]} , 
 	{ "Name" : "C_5", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 5,"up" : 5,"step" : 2}]}]}]} , 
 	{ "Name" : "C_6", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 6,"up" : 6,"step" : 2}]}]}]} , 
 	{ "Name" : "C_7", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 7,"up" : 7,"step" : 2}]}]}]} , 
 	{ "Name" : "C_8", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 8,"up" : 8,"step" : 2}]}]}]} , 
 	{ "Name" : "C_9", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "C","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 9,"step" : 1},{"low" : 9,"up" : 9,"step" : 2}]}]}]} , 
 	{ "Name" : "sparse_new", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "sparse_new","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 8,"step" : 1},{"low" : 0,"up" : 2,"step" : 1}]}]}]} ]}
# RTL Port declarations: 
set portNum 102
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ A_address0 sc_out sc_lv 7 signal 0 } 
	{ A_ce0 sc_out sc_logic 1 signal 0 } 
	{ A_we0 sc_out sc_logic 1 signal 0 } 
	{ A_d0 sc_out sc_lv 32 signal 0 } 
	{ A_q0 sc_in sc_lv 32 signal 0 } 
	{ A_address1 sc_out sc_lv 7 signal 0 } 
	{ A_ce1 sc_out sc_logic 1 signal 0 } 
	{ A_we1 sc_out sc_logic 1 signal 0 } 
	{ A_d1 sc_out sc_lv 32 signal 0 } 
	{ A_q1 sc_in sc_lv 32 signal 0 } 
	{ B_0_address0 sc_out sc_lv 4 signal 1 } 
	{ B_0_ce0 sc_out sc_logic 1 signal 1 } 
	{ B_0_q0 sc_in sc_lv 32 signal 1 } 
	{ B_1_address0 sc_out sc_lv 4 signal 2 } 
	{ B_1_ce0 sc_out sc_logic 1 signal 2 } 
	{ B_1_q0 sc_in sc_lv 32 signal 2 } 
	{ B_2_address0 sc_out sc_lv 4 signal 3 } 
	{ B_2_ce0 sc_out sc_logic 1 signal 3 } 
	{ B_2_q0 sc_in sc_lv 32 signal 3 } 
	{ B_3_address0 sc_out sc_lv 4 signal 4 } 
	{ B_3_ce0 sc_out sc_logic 1 signal 4 } 
	{ B_3_q0 sc_in sc_lv 32 signal 4 } 
	{ B_4_address0 sc_out sc_lv 4 signal 5 } 
	{ B_4_ce0 sc_out sc_logic 1 signal 5 } 
	{ B_4_q0 sc_in sc_lv 32 signal 5 } 
	{ B_5_address0 sc_out sc_lv 4 signal 6 } 
	{ B_5_ce0 sc_out sc_logic 1 signal 6 } 
	{ B_5_q0 sc_in sc_lv 32 signal 6 } 
	{ B_6_address0 sc_out sc_lv 4 signal 7 } 
	{ B_6_ce0 sc_out sc_logic 1 signal 7 } 
	{ B_6_q0 sc_in sc_lv 32 signal 7 } 
	{ B_7_address0 sc_out sc_lv 4 signal 8 } 
	{ B_7_ce0 sc_out sc_logic 1 signal 8 } 
	{ B_7_q0 sc_in sc_lv 32 signal 8 } 
	{ B_8_address0 sc_out sc_lv 4 signal 9 } 
	{ B_8_ce0 sc_out sc_logic 1 signal 9 } 
	{ B_8_q0 sc_in sc_lv 32 signal 9 } 
	{ B_9_address0 sc_out sc_lv 4 signal 10 } 
	{ B_9_ce0 sc_out sc_logic 1 signal 10 } 
	{ B_9_q0 sc_in sc_lv 32 signal 10 } 
	{ C_0_address0 sc_out sc_lv 4 signal 11 } 
	{ C_0_ce0 sc_out sc_logic 1 signal 11 } 
	{ C_0_we0 sc_out sc_logic 1 signal 11 } 
	{ C_0_d0 sc_out sc_lv 32 signal 11 } 
	{ C_0_q0 sc_in sc_lv 32 signal 11 } 
	{ C_1_address0 sc_out sc_lv 4 signal 12 } 
	{ C_1_ce0 sc_out sc_logic 1 signal 12 } 
	{ C_1_we0 sc_out sc_logic 1 signal 12 } 
	{ C_1_d0 sc_out sc_lv 32 signal 12 } 
	{ C_1_q0 sc_in sc_lv 32 signal 12 } 
	{ C_2_address0 sc_out sc_lv 4 signal 13 } 
	{ C_2_ce0 sc_out sc_logic 1 signal 13 } 
	{ C_2_we0 sc_out sc_logic 1 signal 13 } 
	{ C_2_d0 sc_out sc_lv 32 signal 13 } 
	{ C_2_q0 sc_in sc_lv 32 signal 13 } 
	{ C_3_address0 sc_out sc_lv 4 signal 14 } 
	{ C_3_ce0 sc_out sc_logic 1 signal 14 } 
	{ C_3_we0 sc_out sc_logic 1 signal 14 } 
	{ C_3_d0 sc_out sc_lv 32 signal 14 } 
	{ C_3_q0 sc_in sc_lv 32 signal 14 } 
	{ C_4_address0 sc_out sc_lv 4 signal 15 } 
	{ C_4_ce0 sc_out sc_logic 1 signal 15 } 
	{ C_4_we0 sc_out sc_logic 1 signal 15 } 
	{ C_4_d0 sc_out sc_lv 32 signal 15 } 
	{ C_4_q0 sc_in sc_lv 32 signal 15 } 
	{ C_5_address0 sc_out sc_lv 4 signal 16 } 
	{ C_5_ce0 sc_out sc_logic 1 signal 16 } 
	{ C_5_we0 sc_out sc_logic 1 signal 16 } 
	{ C_5_d0 sc_out sc_lv 32 signal 16 } 
	{ C_5_q0 sc_in sc_lv 32 signal 16 } 
	{ C_6_address0 sc_out sc_lv 4 signal 17 } 
	{ C_6_ce0 sc_out sc_logic 1 signal 17 } 
	{ C_6_we0 sc_out sc_logic 1 signal 17 } 
	{ C_6_d0 sc_out sc_lv 32 signal 17 } 
	{ C_6_q0 sc_in sc_lv 32 signal 17 } 
	{ C_7_address0 sc_out sc_lv 4 signal 18 } 
	{ C_7_ce0 sc_out sc_logic 1 signal 18 } 
	{ C_7_we0 sc_out sc_logic 1 signal 18 } 
	{ C_7_d0 sc_out sc_lv 32 signal 18 } 
	{ C_7_q0 sc_in sc_lv 32 signal 18 } 
	{ C_8_address0 sc_out sc_lv 4 signal 19 } 
	{ C_8_ce0 sc_out sc_logic 1 signal 19 } 
	{ C_8_we0 sc_out sc_logic 1 signal 19 } 
	{ C_8_d0 sc_out sc_lv 32 signal 19 } 
	{ C_8_q0 sc_in sc_lv 32 signal 19 } 
	{ C_9_address0 sc_out sc_lv 4 signal 20 } 
	{ C_9_ce0 sc_out sc_logic 1 signal 20 } 
	{ C_9_we0 sc_out sc_logic 1 signal 20 } 
	{ C_9_d0 sc_out sc_lv 32 signal 20 } 
	{ C_9_q0 sc_in sc_lv 32 signal 20 } 
	{ sparse_new_address0 sc_out sc_lv 5 signal 21 } 
	{ sparse_new_ce0 sc_out sc_logic 1 signal 21 } 
	{ sparse_new_q0 sc_in sc_lv 32 signal 21 } 
	{ sparse_new_address1 sc_out sc_lv 5 signal 21 } 
	{ sparse_new_ce1 sc_out sc_logic 1 signal 21 } 
	{ sparse_new_q1 sc_in sc_lv 32 signal 21 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "A_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "A", "role": "address0" }} , 
 	{ "name": "A_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "A", "role": "ce0" }} , 
 	{ "name": "A_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "A", "role": "we0" }} , 
 	{ "name": "A_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "A", "role": "d0" }} , 
 	{ "name": "A_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "A", "role": "q0" }} , 
 	{ "name": "A_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "A", "role": "address1" }} , 
 	{ "name": "A_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "A", "role": "ce1" }} , 
 	{ "name": "A_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "A", "role": "we1" }} , 
 	{ "name": "A_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "A", "role": "d1" }} , 
 	{ "name": "A_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "A", "role": "q1" }} , 
 	{ "name": "B_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_0", "role": "address0" }} , 
 	{ "name": "B_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_0", "role": "ce0" }} , 
 	{ "name": "B_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_0", "role": "q0" }} , 
 	{ "name": "B_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_1", "role": "address0" }} , 
 	{ "name": "B_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_1", "role": "ce0" }} , 
 	{ "name": "B_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_1", "role": "q0" }} , 
 	{ "name": "B_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_2", "role": "address0" }} , 
 	{ "name": "B_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_2", "role": "ce0" }} , 
 	{ "name": "B_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_2", "role": "q0" }} , 
 	{ "name": "B_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_3", "role": "address0" }} , 
 	{ "name": "B_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_3", "role": "ce0" }} , 
 	{ "name": "B_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_3", "role": "q0" }} , 
 	{ "name": "B_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_4", "role": "address0" }} , 
 	{ "name": "B_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_4", "role": "ce0" }} , 
 	{ "name": "B_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_4", "role": "q0" }} , 
 	{ "name": "B_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_5", "role": "address0" }} , 
 	{ "name": "B_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_5", "role": "ce0" }} , 
 	{ "name": "B_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_5", "role": "q0" }} , 
 	{ "name": "B_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_6", "role": "address0" }} , 
 	{ "name": "B_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_6", "role": "ce0" }} , 
 	{ "name": "B_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_6", "role": "q0" }} , 
 	{ "name": "B_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_7", "role": "address0" }} , 
 	{ "name": "B_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_7", "role": "ce0" }} , 
 	{ "name": "B_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_7", "role": "q0" }} , 
 	{ "name": "B_8_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_8", "role": "address0" }} , 
 	{ "name": "B_8_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_8", "role": "ce0" }} , 
 	{ "name": "B_8_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_8", "role": "q0" }} , 
 	{ "name": "B_9_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "B_9", "role": "address0" }} , 
 	{ "name": "B_9_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "B_9", "role": "ce0" }} , 
 	{ "name": "B_9_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "B_9", "role": "q0" }} , 
 	{ "name": "C_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_0", "role": "address0" }} , 
 	{ "name": "C_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_0", "role": "ce0" }} , 
 	{ "name": "C_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_0", "role": "we0" }} , 
 	{ "name": "C_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_0", "role": "d0" }} , 
 	{ "name": "C_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_0", "role": "q0" }} , 
 	{ "name": "C_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_1", "role": "address0" }} , 
 	{ "name": "C_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_1", "role": "ce0" }} , 
 	{ "name": "C_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_1", "role": "we0" }} , 
 	{ "name": "C_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_1", "role": "d0" }} , 
 	{ "name": "C_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_1", "role": "q0" }} , 
 	{ "name": "C_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_2", "role": "address0" }} , 
 	{ "name": "C_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_2", "role": "ce0" }} , 
 	{ "name": "C_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_2", "role": "we0" }} , 
 	{ "name": "C_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_2", "role": "d0" }} , 
 	{ "name": "C_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_2", "role": "q0" }} , 
 	{ "name": "C_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_3", "role": "address0" }} , 
 	{ "name": "C_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_3", "role": "ce0" }} , 
 	{ "name": "C_3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_3", "role": "we0" }} , 
 	{ "name": "C_3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_3", "role": "d0" }} , 
 	{ "name": "C_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_3", "role": "q0" }} , 
 	{ "name": "C_4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_4", "role": "address0" }} , 
 	{ "name": "C_4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_4", "role": "ce0" }} , 
 	{ "name": "C_4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_4", "role": "we0" }} , 
 	{ "name": "C_4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_4", "role": "d0" }} , 
 	{ "name": "C_4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_4", "role": "q0" }} , 
 	{ "name": "C_5_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_5", "role": "address0" }} , 
 	{ "name": "C_5_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_5", "role": "ce0" }} , 
 	{ "name": "C_5_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_5", "role": "we0" }} , 
 	{ "name": "C_5_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_5", "role": "d0" }} , 
 	{ "name": "C_5_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_5", "role": "q0" }} , 
 	{ "name": "C_6_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_6", "role": "address0" }} , 
 	{ "name": "C_6_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_6", "role": "ce0" }} , 
 	{ "name": "C_6_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_6", "role": "we0" }} , 
 	{ "name": "C_6_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_6", "role": "d0" }} , 
 	{ "name": "C_6_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_6", "role": "q0" }} , 
 	{ "name": "C_7_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_7", "role": "address0" }} , 
 	{ "name": "C_7_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_7", "role": "ce0" }} , 
 	{ "name": "C_7_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_7", "role": "we0" }} , 
 	{ "name": "C_7_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_7", "role": "d0" }} , 
 	{ "name": "C_7_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_7", "role": "q0" }} , 
 	{ "name": "C_8_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_8", "role": "address0" }} , 
 	{ "name": "C_8_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_8", "role": "ce0" }} , 
 	{ "name": "C_8_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_8", "role": "we0" }} , 
 	{ "name": "C_8_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_8", "role": "d0" }} , 
 	{ "name": "C_8_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_8", "role": "q0" }} , 
 	{ "name": "C_9_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "C_9", "role": "address0" }} , 
 	{ "name": "C_9_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_9", "role": "ce0" }} , 
 	{ "name": "C_9_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_9", "role": "we0" }} , 
 	{ "name": "C_9_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_9", "role": "d0" }} , 
 	{ "name": "C_9_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_9", "role": "q0" }} , 
 	{ "name": "sparse_new_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "sparse_new", "role": "address0" }} , 
 	{ "name": "sparse_new_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sparse_new", "role": "ce0" }} , 
 	{ "name": "sparse_new_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sparse_new", "role": "q0" }} , 
 	{ "name": "sparse_new_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "sparse_new", "role": "address1" }} , 
 	{ "name": "sparse_new_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sparse_new", "role": "ce1" }} , 
 	{ "name": "sparse_new_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sparse_new", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "mul1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "46", "EstimateLatencyMax" : "46",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "A", "Type" : "Memory", "Direction" : "X"},
			{"Name" : "B_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "B_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "C_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_3", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_4", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_5", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_6", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_7", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_8", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "C_9", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sparse_new", "Type" : "Memory", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	mul1 {
		A {Type X LastRead -1 FirstWrite -1}
		B_0 {Type I LastRead 2 FirstWrite -1}
		B_1 {Type I LastRead 2 FirstWrite -1}
		B_2 {Type I LastRead 2 FirstWrite -1}
		B_3 {Type I LastRead 2 FirstWrite -1}
		B_4 {Type I LastRead 2 FirstWrite -1}
		B_5 {Type I LastRead 2 FirstWrite -1}
		B_6 {Type I LastRead 2 FirstWrite -1}
		B_7 {Type I LastRead 2 FirstWrite -1}
		B_8 {Type I LastRead 2 FirstWrite -1}
		B_9 {Type I LastRead 2 FirstWrite -1}
		C_0 {Type IO LastRead 4 FirstWrite 5}
		C_1 {Type IO LastRead 4 FirstWrite 5}
		C_2 {Type IO LastRead 4 FirstWrite 5}
		C_3 {Type IO LastRead 4 FirstWrite 5}
		C_4 {Type IO LastRead 4 FirstWrite 5}
		C_5 {Type IO LastRead 4 FirstWrite 5}
		C_6 {Type IO LastRead 4 FirstWrite 5}
		C_7 {Type IO LastRead 4 FirstWrite 5}
		C_8 {Type IO LastRead 4 FirstWrite 5}
		C_9 {Type IO LastRead 4 FirstWrite 5}
		sparse_new {Type I LastRead 3 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "46", "Max" : "46"}
	, {"Name" : "Interval", "Min" : "47", "Max" : "47"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	A { ap_memory {  { A_address0 mem_address 1 7 }  { A_ce0 mem_ce 1 1 }  { A_we0 mem_we 1 1 }  { A_d0 mem_din 1 32 }  { A_q0 mem_dout 0 32 }  { A_address1 mem_address 1 7 }  { A_ce1 mem_ce 1 1 }  { A_we1 mem_we 1 1 }  { A_d1 mem_din 1 32 }  { A_q1 mem_dout 0 32 } } }
	B_0 { ap_memory {  { B_0_address0 mem_address 1 4 }  { B_0_ce0 mem_ce 1 1 }  { B_0_q0 mem_dout 0 32 } } }
	B_1 { ap_memory {  { B_1_address0 mem_address 1 4 }  { B_1_ce0 mem_ce 1 1 }  { B_1_q0 mem_dout 0 32 } } }
	B_2 { ap_memory {  { B_2_address0 mem_address 1 4 }  { B_2_ce0 mem_ce 1 1 }  { B_2_q0 mem_dout 0 32 } } }
	B_3 { ap_memory {  { B_3_address0 mem_address 1 4 }  { B_3_ce0 mem_ce 1 1 }  { B_3_q0 mem_dout 0 32 } } }
	B_4 { ap_memory {  { B_4_address0 mem_address 1 4 }  { B_4_ce0 mem_ce 1 1 }  { B_4_q0 mem_dout 0 32 } } }
	B_5 { ap_memory {  { B_5_address0 mem_address 1 4 }  { B_5_ce0 mem_ce 1 1 }  { B_5_q0 mem_dout 0 32 } } }
	B_6 { ap_memory {  { B_6_address0 mem_address 1 4 }  { B_6_ce0 mem_ce 1 1 }  { B_6_q0 mem_dout 0 32 } } }
	B_7 { ap_memory {  { B_7_address0 mem_address 1 4 }  { B_7_ce0 mem_ce 1 1 }  { B_7_q0 mem_dout 0 32 } } }
	B_8 { ap_memory {  { B_8_address0 mem_address 1 4 }  { B_8_ce0 mem_ce 1 1 }  { B_8_q0 mem_dout 0 32 } } }
	B_9 { ap_memory {  { B_9_address0 mem_address 1 4 }  { B_9_ce0 mem_ce 1 1 }  { B_9_q0 mem_dout 0 32 } } }
	C_0 { ap_memory {  { C_0_address0 mem_address 1 4 }  { C_0_ce0 mem_ce 1 1 }  { C_0_we0 mem_we 1 1 }  { C_0_d0 mem_din 1 32 }  { C_0_q0 mem_dout 0 32 } } }
	C_1 { ap_memory {  { C_1_address0 mem_address 1 4 }  { C_1_ce0 mem_ce 1 1 }  { C_1_we0 mem_we 1 1 }  { C_1_d0 mem_din 1 32 }  { C_1_q0 mem_dout 0 32 } } }
	C_2 { ap_memory {  { C_2_address0 mem_address 1 4 }  { C_2_ce0 mem_ce 1 1 }  { C_2_we0 mem_we 1 1 }  { C_2_d0 mem_din 1 32 }  { C_2_q0 mem_dout 0 32 } } }
	C_3 { ap_memory {  { C_3_address0 mem_address 1 4 }  { C_3_ce0 mem_ce 1 1 }  { C_3_we0 mem_we 1 1 }  { C_3_d0 mem_din 1 32 }  { C_3_q0 mem_dout 0 32 } } }
	C_4 { ap_memory {  { C_4_address0 mem_address 1 4 }  { C_4_ce0 mem_ce 1 1 }  { C_4_we0 mem_we 1 1 }  { C_4_d0 mem_din 1 32 }  { C_4_q0 mem_dout 0 32 } } }
	C_5 { ap_memory {  { C_5_address0 mem_address 1 4 }  { C_5_ce0 mem_ce 1 1 }  { C_5_we0 mem_we 1 1 }  { C_5_d0 mem_din 1 32 }  { C_5_q0 mem_dout 0 32 } } }
	C_6 { ap_memory {  { C_6_address0 mem_address 1 4 }  { C_6_ce0 mem_ce 1 1 }  { C_6_we0 mem_we 1 1 }  { C_6_d0 mem_din 1 32 }  { C_6_q0 mem_dout 0 32 } } }
	C_7 { ap_memory {  { C_7_address0 mem_address 1 4 }  { C_7_ce0 mem_ce 1 1 }  { C_7_we0 mem_we 1 1 }  { C_7_d0 mem_din 1 32 }  { C_7_q0 mem_dout 0 32 } } }
	C_8 { ap_memory {  { C_8_address0 mem_address 1 4 }  { C_8_ce0 mem_ce 1 1 }  { C_8_we0 mem_we 1 1 }  { C_8_d0 mem_din 1 32 }  { C_8_q0 mem_dout 0 32 } } }
	C_9 { ap_memory {  { C_9_address0 mem_address 1 4 }  { C_9_ce0 mem_ce 1 1 }  { C_9_we0 mem_we 1 1 }  { C_9_d0 mem_din 1 32 }  { C_9_q0 mem_dout 0 32 } } }
	sparse_new { ap_memory {  { sparse_new_address0 mem_address 1 5 }  { sparse_new_ce0 mem_ce 1 1 }  { sparse_new_q0 mem_dout 0 32 }  { sparse_new_address1 mem_address 1 5 }  { sparse_new_ce1 mem_ce 1 1 }  { sparse_new_q1 mem_dout 0 32 } } }
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
