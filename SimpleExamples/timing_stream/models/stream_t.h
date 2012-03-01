
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
//* This file contains the timing class for stream.
//*
//* This is a template file: You may modify this file to implement the 
//* timing behavior of your component.
//* The functions below allows advance users to customize the timing behavior of your model.
//* 
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 23, 2012 07:59:21 AM, (user: jon)
//*>


#pragma once

#include "stream_model.h"
#include "model_builder.h"

class stream_t : public stream_t_base {

public:
  typedef stream_t self_type;

public:  
  stream_t(sc_core::sc_module_name module_name, long simulation);

  /* policies callbacks */

  // The following callback is called for a target port. Note that the wait_states, power and 
  // influence_time are already computed using a learned policy (if any) or your defined
  // delay and/or power policy.
  // If under certain conditions you want to overwrite the above values, you have to overload
  // this callback in your derived class.
  
  virtual void evaluate_delay_policy(mb::mb_delay_request& request) {}

  // The following callback is called for an initiator port. Note that the latency, power and 
  // influence_time are already computed using a learned policy (if any) or your defined
  // split and/or power policy.
  // If under certain conditions you want to overwrite the above values, you have to overload
  // this callback in your derived class.

  virtual void evaluate_split_policy(mb::mb_split_request& request) {}
  
  // The following function is called whenever a pipeline policy is detected on
  // the current initiator port transaction. If you want to overwrite the latency parameter, you
  // have to overload these functions in your derived class
  virtual void evaluate_pipeline_policy(mb::mb_request& cause_request, mb::mb_effect_request& effect_request) {}

  // The following function is called whenever a sequential policy is detected on
  // the current initiator port transaction. If you want to overwrite the latency parameter, you
  // have to overload these functions in your derived class
  virtual void evaluate_sequential_policy(mb::mb_request& cause_request, mb::mb_effect_request& effect_request) {}

  // This is called whenever a variable/register involved in a state power policy is written
  // You can use setPowerInMw interface of the mb_effect_request class, to set the appropriate power value
  virtual void evaluate_state_power_policy(mb::mb_effect_request& request) {}
protected:
  // The following callbacks are called whenever there is a transaction start or end in the port
  // If you want to add your own code (like updating the machine architecture object), 
  // you have to overload these functions.

  virtual void accept_generic_READ
    (long port_index,
     sc_dt::int64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 rDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}
  virtual void end_generic_READ
    (long port_index,
     sc_dt::uint64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 rDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}

  virtual void accept_generic_WRITE
    (long port_index,
     sc_dt::int64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 wDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}
  virtual void end_generic_WRITE
    (long port_index,
     sc_dt::uint64 time,
     long& burst_size,
     sc_dt::uint64 ADDR,
     sc_dt::uint64 wDATA,
     sc_dt::uint64& PRIORITY,
     sc_dt::uint64& BURST,
     sc_dt::uint64 SIZE,
     sc_dt::uint64& STATUS) {}

};
