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
//* This file contains the PV class for process.
//* This is a template file: You may modify this file to implement the
//* behavior of your component.
//*
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 23, 2012 08:28:55 AM, (user: jon)
//* Automatically merged on: Feb. 25, 2012 01:05:50 PM, (user: jon)
//* Automatically merged on: Feb. 25, 2012 01:12:23 PM, (user: jon)
//*>


#pragma once

#include "process_model.h"
#include "datastruct.h"
#include <queue>

using namespace tlm;

//This class inherits from the process_pv_base class
class process_pv : public process_pv_base
{
public:
    typedef esl::tlm_types::Address mb_address_type;
public:
    // Constructor
    // Do not add parameters here.
    // To add parameters - use the Model Builder form (under PV->Parameters tab)
    SC_HAS_PROCESS(process_pv);
    process_pv(sc_core::sc_module_name module_name);

    void general_thread(tlm::tlm_fifo<datastruct *> & fifo,
                        queue<sc_time> & pipeInTime,
                        bool (process_pv_base::*writeMethod)(mb_address_type, unsigned char *, unsigned, unsigned),
                        mb::mb_variable<int>& deltaVar,
                        mb::mb_variable<int>& startVar,
                        mb::mb_variable<int>& stopVar);
    void thread1();
    void thread2();
    void thread3();
    void thread4();
    void thread5();
    void thread6();
    void thread7();
    void thread8();

protected:
    // target ports write callbacks
    bool general_write(mb_address_type address,
                       unsigned char* data,
                       unsigned int size,
                       port_enum idx,
                       tlm::tlm_fifo<datastruct *> & fifo,
                       mb::mb_variable<int>& deltaVar,
                       mb::mb_variable<int>& startVar,
                       mb::mb_variable<int>& stopVar);

    bool slave_1_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_2_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_3_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_4_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_5_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_6_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_7_callback_write(mb_address_type address, unsigned char* data, unsigned size);
    bool slave_8_callback_write(mb_address_type address, unsigned char* data, unsigned size);

#define NumberOfPorts 8
    tlm::tlm_fifo< datastruct *> fifo[NumberOfPorts];
    queue<sc_time> pipeInTime[NumberOfPorts];
};

