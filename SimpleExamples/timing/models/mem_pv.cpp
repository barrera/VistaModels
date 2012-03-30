
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
//* This file contains the PV class for mem.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.1.2
//* Generated on: Dec. 15, 2011 01:42:53 PM, (user: jon)
//* Automatically merged on: Mar. 30, 2012 09:19:54 AM, (user: jon)
//*>


#include "mem_pv.h"

//constructor
mem_pv::mem_pv(sc_module_name module_name)
  : mem_pv_base(module_name),
  m_memory_if(size_in_bytes, mb::sysc::get_instance_endianness(), 32)
{
  if (::mb::sysc::sdParameterExists("read_latency")) {
    m_memory_if.set_read_latency(::mb::sysc::sdGetParameterAsTime("read_latency"));
  }

  if (::mb::sysc::sdParameterExists("write_latency")) {
    m_memory_if.set_write_latency(::mb::sysc::sdGetParameterAsTime("write_latency"));
  }
}

//virtual 
void mem_pv::slave_callback(tlm::tlm_base_protocol_types::tlm_payload_type& trans, sc_core::sc_time& t) {

  m_memory_if.b_transport(trans, t);
}

//virtual 
unsigned mem_pv::slave_callback_dbg(tlm::tlm_base_protocol_types::tlm_payload_type& trans) {
  return m_memory_if.transport_dbg(trans);
}

//virtual 
bool mem_pv::slave_get_direct_memory_ptr_callback(tlm::tlm_base_protocol_types::tlm_payload_type& trans,
                                                                           tlm::tlm_dmi& dmiData) {
  return m_memory_if.get_direct_mem_ptr(trans, dmiData);
}

