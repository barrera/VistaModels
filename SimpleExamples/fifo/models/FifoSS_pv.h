
/**************************************************************/
/*                                                            */
/*      Copyright Mentor Graphics Corporation 2006 - 2011     */
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
//* This file contains the PV class for FifoSS.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 1.7.0.beta2
//* Generated on: Mar. 07, 2010 04:57:11 AM, (user: jon)
//* Automatically merged on: Jul. 02, 2010 02:43:32 PM, (user: jon)
//* Automatically merged on: Feb. 03, 2011 04:11:50 PM, (user: jon)
//* Automatically merged on: Mar. 07, 2011 10:05:21 AM, (user: jon)
//* Automatically merged on: Sep. 26, 2011 07:41:19 AM, (user: jon)
//* Automatically merged on: Jan. 09, 2012 02:04:27 PM, (user: jon)
//* Automatically merged on: Jan. 20, 2012 09:12:43 AM, (user: jon)
//*>


#pragma once

#include "FifoSS_model.h"
#include "datastruct.h"

using namespace tlm;

//This class inherits from the FifoSS_pv_base class
class FifoSS_pv : public FifoSS_pv_base {
 public:
  typedef esl::tlm_types::Address mb_address_type;
 public:
  // Constructor
  // Do not add parameters here.
  // To add parameters - use the Model Builder form (under PV->Parameters tab)
  SC_HAS_PROCESS(FifoSS_pv);
  FifoSS_pv(sc_core::sc_module_name module_name);   

 protected:
  ////////////////////////////////////////
  // target ports read callbacks
  //////////////////////////////////////// 
  bool d_in_callback_read(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_in_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size);
  bool d_out_callback_read(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_out_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size); 

 protected:
  ////////////////////////////////////////
  // target ports write callbacks
  //////////////////////////////////////// 
  bool d_in_callback_write(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_in_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size);
  bool d_in_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData);
  bool d_out_callback_write(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_out_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size);
  bool d_out_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData);  

  void **ffdata;
  unsigned int countin;
  unsigned int countout;
  sc_event dataEv;
  unsigned int FFmask;
  tlm::tlm_fifo< datastruct *> fifo_ds;
  datastruct *m_ds_i, *m_ds_o;
  unsigned int m_count;
};

