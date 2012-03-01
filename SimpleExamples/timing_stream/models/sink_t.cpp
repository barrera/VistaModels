
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
//* This file contains the timing class for sink.
//*
//* This is a template file: You may modify this file to implement the 
//* timing behavior of your component.
//* The functions below allows advance users to customize the timing behavior of your model.
//* 
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 23, 2012 07:58:11 AM, (user: jon)
//*>


#include "sink_t.h"


#include <iostream>

using namespace std;
using namespace sc_dt;
using namespace sc_core;

sink_t_base* sink_t_base::create_t(const char* name, long simulation) {
  return new sink_t(name, simulation);
}

sink_t::sink_t(sc_module_name _name, long simulation)
  : sink_t_base(_name, simulation) {

  
  std::cout << this->name() << " policy : user defined" << std::endl;  
  
}

