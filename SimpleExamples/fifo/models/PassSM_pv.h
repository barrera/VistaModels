
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
//* This file contains the PV class for PassSM.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 1.7.0.beta2
//* Generated on: Mar. 07, 2010 04:53:57 AM, (user: jon)
//* Automatically merged on: Jul. 15, 2010 11:42:19 AM, (user: jon)
//* Automatically merged on: Feb. 03, 2011 04:11:53 PM, (user: jon)
//* Automatically merged on: Mar. 07, 2011 10:05:22 AM, (user: jon)
//* Automatically merged on: Jun. 22, 2011 08:52:58 AM, (user: jon)
//* Automatically merged on: Jun. 22, 2011 09:08:16 AM, (user: jon)
//* Automatically merged on: Aug. 19, 2011 04:35:46 PM, (user: jon)
//* Automatically merged on: Sep. 26, 2011 07:41:20 AM, (user: jon)
//* Automatically merged on: Jan. 09, 2012 02:04:32 PM, (user: jon)
//* Automatically merged on: Jan. 20, 2012 09:12:45 AM, (user: jon)
//*>


#pragma once

#include "PassSM_model.h"
#include "datastruct.h"

using namespace tlm;

//This class inherits from the PassSM_pv_base class
class PassSM_pv : public PassSM_pv_base {
 public:
  typedef esl::tlm_types::Address mb_address_type;
 public:
  // Constructor
  // Do not add parameters here.
  // To add parameters - use the Model Builder form (under PV->Parameters tab)
  SC_HAS_PROCESS(PassSM_pv);
  PassSM_pv(sc_core::sc_module_name module_name); 

 protected:
  ////////////////////////////////////////
  // read callbacks of registers
  ////////////////////////////////////////// 
  unsigned int cb_read_myreg(); 
  
 protected:
  /////////////////////////////////////////
  // write callbacks of registers
  ////////////////////////////////////////// 
  void cb_write_myreg(unsigned int newValue);

 protected:
  /////////////////////////////////////////
  // io_memory callbacks
  ///////////////////////////////////////// 
  virtual void cb_write_mem(uint64_t offset, unsigned char* data, unsigned length);
  virtual void cb_read_mem(uint64_t offset, unsigned char* data, unsigned length); 

  void thread();

 protected:
  ////////////////////////////////////////
  // target ports read callbacks
  //////////////////////////////////////// 
  bool d_in_callback_read(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_in_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size); 

 ////////////////////////////////////////
 // target ports write callbacks
 //////////////////////////////////////// 
 protected: 
  // This function will be called whenever the port d_in is written
  bool d_in_callback_write(mb_address_type address, unsigned char* data, unsigned size);
  unsigned d_in_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size);
  bool d_in_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData);  

  tlm::tlm_fifo< datastruct *> fifo_ds;
  datastruct *m_ds_i, *m_ds_o;
  bool m_busy;
};

