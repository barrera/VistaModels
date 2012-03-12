
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
//* This file contains the PV class for streamThread.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 23, 2012 08:28:55 AM, (user: jon)
//*>


#include "streamThread_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
streamThread_pv::streamThread_pv(sc_module_name module_name) 
  : streamThread_pv_base(module_name) 
{ 
  SC_THREAD(thread);
  processFactor = ProcessD;
  fifo.nb_bound(InputFifoDepth+PipelineStages);
  for (int i = 0; i < PipelineStages; i++) pipeInTimeQ.push(SC_ZERO_TIME);
}    

void streamThread_pv::thread() {
  datastruct *ds;
  int proc;
  sc_time startProcT;
  
  for(;;) {
    ds = fifo.peek();
    startProcT = pipeInTimeQ.front();
    pipeInTimeQ.pop();
    startProcT = (startProcT > ds->startT) ? startProcT : ds->startT;

    proc = (startProcT/clock) - (sc_time_stamp()/clock);
    proc = (proc < -processFactor) ? -processFactor : proc;

    m_processd = processFactor + proc;
    TP1 = (TP1 + 1) % 8; TP2 = (TP2 + 1) % 8;

    set_current_token(ds->currentToken);
    fifo.get();
    pipeInTimeQ.push(sc_time_stamp());

    master_1_write(ds->address, ds->data, ds->size);
    
    free(ds->data);
    free(ds);
  }
}

// Read callback for slave_a port.
// Returns true when successful.
bool streamThread_pv::slave_a_callback_read(mb_address_type address, unsigned char* data, unsigned size) {
  cout << sc_time_stamp() << ":" << name() << ".slave_a_callback_read(). Error: Read not supported." << endl;
  return true;
}


// Write callback for slave_a port.
// Returns true when successful.
bool streamThread_pv::slave_a_callback_write(mb_address_type address, unsigned char* data, unsigned size) {

  datastruct * ds = new datastruct;
  int receiveT;
  bool putBlocked;

  if (address == Id) {
    processFactor = *((int *)data);
  } else {
    ds->throughput = size / getSystemCBaseModel()->get_port_width(slave_a_idx);
    receiveT = (ds->throughput + InputD);
    ds->startT = sc_time_stamp() + (receiveT * clock);
    ds->read = false;
    ds->address = address;
    ds->data = new unsigned char [size];
    memcpy(ds->data, data, size);
    ds->size = size;
    ds->currentToken = get_current_token();

    inputDelta = receiveT;
    putBlocked = !fifo.nb_can_put();

    fifo.put(ds);

    if (putBlocked) {
      ds->startT = sc_time_stamp() + (receiveT * clock);
      TP3 = (TP3 + 1) % 8; TP4 = (TP4 + 1) % 8; }
  }
  
  return true;
}


unsigned streamThread_pv::slave_a_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
}

unsigned streamThread_pv::slave_a_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
}

bool streamThread_pv::slave_a_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}


