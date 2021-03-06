
/**************************************************************/
/*                                                            */
/*      Copyright Mentor Graphics Corporation 2006 - 2012     */
/*                  All Rights Reserved                       */
/*                                                            */
/*       THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY      */
/*         INFORMATION WHICH IS THE PROPERTY OF MENTOR        */
/*         GRAPHICS CORPORATION OR ITS LICENSORS AND IS       */
/*                 SUBJECT TO LICENSE TERMS.                  */
/*                                                            */
/**************************************************************/

//*<
//* Generated By Model Builder, Mentor Graphics Computer Systems, Inc.
//*
//* This file contains the PV class for streamTrans.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 27, 2012 10:41:18 AM, (user: jon)
//*>

#include "streamTrans_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
streamTrans_pv::streamTrans_pv(sc_module_name module_name) 
  : streamTrans_pv_base(module_name) {
  SC_THREAD(thread);
  processFactor = ProcessD;
}    

// Read callback for slave_a port.
// Returns true when successful.
bool streamTrans_pv::slave_a_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

// Write callback for slave_a port.
// Returns true when successful.
bool streamTrans_pv::slave_a_callback_write(mb_address_type address, unsigned char* data, unsigned size) {
  
  return true;
}

unsigned streamTrans_pv::slave_a_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
}

unsigned streamTrans_pv::slave_a_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
}

bool streamTrans_pv::slave_a_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}

void streamTrans_pv::slave_a_callback(tlm::tlm_base_protocol_types::tlm_payload_type& trans, sc_core::sc_time& t) {
  datastruct * ds = new datastruct;

  ds->throughput = trans.get_data_length() / getSystemCBaseModel()->get_port_width(slave_a_idx);
  ds->startT = sc_time_stamp() + ((ds->throughput + InputD) * clock);
  ds->transptr = &trans;
  trans.acquire();

  fifo.put(ds);

  trans.set_response_status(TLM_OK_RESPONSE);
}

void streamTrans_pv::thread() {
  datastruct *ds;
  int proc;
  sc_time startProcT = SC_ZERO_TIME;

  for(;;) {
    ds = fifo.peek();

    startProcT = (startProcT > ds->startT) ? startProcT : ds->startT;

    proc = processFactor - ((sc_time_stamp() - startProcT)/clock);
    m_processd = (proc < 0) ? 0 : proc;

    TP1 = 0;
    TP2 = 0;

    fifo.get();
    startProcT = sc_time_stamp();

    master_1_transport(*(ds->transptr));
    ds->transptr->release();
    free(ds);
  }
}
