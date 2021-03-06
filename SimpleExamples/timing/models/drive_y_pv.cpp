
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
//* This file contains the PV class for drive_y.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.1.2
//* Generated on: Dec. 15, 2011 02:57:59 PM, (user: jon)
//*>


#include "drive_y_pv.h"
#include <iostream>

using namespace sc_core;
using namespace sc_dt;
using namespace std;

//constructor
drive_y_pv::drive_y_pv(sc_module_name module_name) 
  : drive_y_pv_base(module_name) {
  SC_THREAD(thread);
}    

void drive_y_pv::thread() {
  unsigned char d[] = "hello";

  wait (10, SC_NS);
  y_write(0x0, d, 4);
  wait (100, SC_NS);
}
