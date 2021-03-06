
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
//* This file contains the PV class for ip.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.5.0
//* Generated on: Jan. 03, 2013 12:10:26 PM, (user: markca)
//*>



#include "ip_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
ip_pv::ip_pv(sc_module_name module_name) 
  : ip_pv_base(module_name),
    master("master")
{
}    

// Read callback for ip_slave port.
// Returns true when successful.
bool ip_pv::ip_slave_callback_read(mb_address_type address, unsigned char* data, unsigned size) {

  tlm_generic_payload gp; 
  sc_time delay;

  gp.set_command(TLM_READ_COMMAND);
  gp.set_address(address);
  gp.set_data_ptr(data);
  gp.set_data_length(size);
  delay = sc_time(0, SC_NS);
  master->b_transport(gp, delay);

  return true;
}

// Write callback for ip_slave port.
// Returns true when successful.
bool ip_pv::ip_slave_callback_write(mb_address_type address, unsigned char* data, unsigned size) {

  tlm_generic_payload gp; 
  sc_time delay;

  gp.set_command(TLM_WRITE_COMMAND);
  gp.set_address(address);
  gp.set_data_ptr(data);
  gp.set_data_length(size);
  delay = sc_time(0, SC_NS);
  master->b_transport(gp, delay);

  return true;
} 




unsigned ip_pv::ip_slave_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

unsigned ip_pv::ip_slave_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size) {
  return 0;
} 

bool ip_pv::ip_slave_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData) {
  return false;
}


