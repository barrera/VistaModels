
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
//* This file contains the PV class for mytest.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.1.3
//* Generated on: Jan. 11, 2012 04:55:41 PM, (user: jon)
//*>


#pragma once

#include "mytest_model.h"

using namespace tlm;

//This class inherits from the mytest_pv_base class
class mytest_pv : public mytest_pv_base {
 public:
  typedef esl::tlm_types::Address mb_address_type;
 public:
  // Constructor
  // Do not add parameters here.
  // To add parameters - use the Model Builder form (under PV->Parameters tab)
  SC_HAS_PROCESS(mytest_pv);
  mytest_pv(sc_core::sc_module_name module_name);  
  
 protected:
  /////////////////////////////////////////
  // write callbacks of registers
  ////////////////////////////////////////// 
  void cb_write_reg1(unsigned int newValue); 

 protected:
  ////////////////////////////////////////
  // target ports read callbacks
  //////////////////////////////////////// 
  bool myin_callback_read(mb_address_type address, unsigned char* data, unsigned size);
  
  unsigned myin_callback_read_dbg(mb_address_type address, unsigned char* data, unsigned size); 

 protected:
  ////////////////////////////////////////
  // target ports write callbacks
  //////////////////////////////////////// 
  bool myin_callback_write(mb_address_type address, unsigned char* data, unsigned size);
  
  unsigned myin_callback_write_dbg(mb_address_type address, unsigned char* data, unsigned size);
  bool myin_get_direct_memory_ptr(mb_address_type address, tlm::tlm_dmi& dmiData);   
};

