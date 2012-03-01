
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
//* This file is write protected. 
//* DO NOT MODIFY THIS FILE.
//*
//* This file is generated according to the parameters in the 
//* Model Builder form.
//* This class contains the infrastructure to define the behavior of the component.
//* The sink_pv will be derived from this class.
//*
//* Model Builder version: 3.2.0
//* Generated on: Feb. 29, 2012 03:31:59 AM, (user: jon)
//*>


#include "sink_model.h"

#ifdef MODEL_BUILDER_VERSION_NUMBER
#if 320 != MODEL_BUILDER_VERSION_NUMBER
#error "This model was generated using Model Builder 3.2.0. Please regenerate model."
#endif
#else
#error "Please regenerate model."
#endif

using namespace sc_core;
using namespace sc_dt;
using namespace std;


sink_pv_base::sink_pv_base(sc_module_name& module_name) : 
  sink_pv_base_mb_compatibility(module_name),
  VISTA_MB_PV_INIT_MEMBER(s),
  SD_INITIALIZE_PARAMETER(clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER(generic_clock, clock),
  SD_INITIALIZE_PARAMETER(nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER(mb_debug, false),
  SD_INITIALIZE_PARAMETER(verbose_parameters, true),
  SD_INITIALIZE_PARAMETER(s_pipeline_length, 2) { 
  payload_on_stack = 0;

  VISTA_MB_PV_BIND_FW_PROCESS_TO_TARGET(s);
  VISTA_MB_PV_REGISTER_SELF_FW_PROCESS_CALLBACKS(s);

  if(verbose_parameters) print_parameters();
}

void sink_pv_base::print_parameters()
{
  const char* name;
  if (!strcmp(this->basename(), "PV"))
    name = this->get_parent()->name();
  else
    name = this->name();

  std::cout.setf(ios::hex, ios::basefield);
  std::cout.setf(ios::showbase);
  std::cout << name << "::parameters:\n";
  std::cout << "\tclock = " << clock << "\n";
  std::cout << "\tgeneric_clock = " << generic_clock << "\n";
  std::cout << "\tnominal_voltage = " << nominal_voltage << "\n";
  std::cout << "\tmb_debug = " << mb_debug << "\n";
  std::cout << "\tverbose_parameters = " << verbose_parameters << "\n";
  std::cout << "\ts_pipeline_length = " << s_pipeline_length << "\n";
  std::cout.unsetf(ios::showbase);
  std::cout.setf(ios::dec, ios::basefield);
  std::cout << std::endl;
}

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
//* This file is write protected.
//* DO NOT MODIFY THIS FILE.
//*
//* This file is used only for learning the component.
//* It contains the machine architecture class for your sink model.
//* 
//* Model Builder version: 3.2.0
//* Generated on: Feb. 29, 2012 03:31:59 AM, (user: jon)
//*>

#include "sink_model.h"
#include "model_builder.h"

using namespace ::mb::utl::minmax;

sink_machine_arch::sink_machine_arch()
    : MachineArch(1, 0) {
        reset();
    }
    
    ////////////////////////////////////////////////////////////////////
    //   function for port: s
    ////////////////////////////////////////////////////////////////////
    
    
    //////
    // functions for port: s, transaction: READ
    //////
    
    void sink_machine_arch::transaction_instance__s__READ
      (
        sc_dt::uint64 address,
        sc_dt::uint64 size,
        sc_dt::uint64 data, 
        bool has_been_error, 
        sc_dt::uint64 currentTime
      )
    {
      
    }
    
    //////
    // functions for port: s, transaction: WRITE
    //////
    
    void sink_machine_arch::transaction_instance__s__WRITE
      (
        sc_dt::uint64 address,
        sc_dt::uint64 size,
        sc_dt::uint64 data, 
        bool has_been_error, 
        sc_dt::uint64 currentTime
      )
    {
      
    }

void sink_machine_arch::startTransaction(unsigned portIndex, unsigned transactionIndex, sc_dt::uint64 currentTime) {
  switch(portIndex) {
    case(0) : break;
    default: break;
  }
}
VariableBase* sink_machine_arch::getVariableBasePtrByName(const char* name) {
  return NULL;
}
Register* sink_machine_arch::getRegisterByName(const char* name) {
  return 0;
}
void sink_machine_arch::reset() { 
    MachineArch::reset();
}
bool sink_machine_arch::getAddressRange(unsigned portIndex, sc_dt::uint64& begin, sc_dt::uint64& end) {
    switch(portIndex) {
        case(0) :   return false;
        default: break;
    }
    return false; 
}
void sink_machine_arch::callTransaction(unsigned portIndex, unsigned transactionIndex, sc_dt::uint64 address, sc_dt::uint64 size, sc_dt::uint64 data, bool has_been_error, sc_dt::uint64 currentTime) {
    switch(portIndex) {
        case(0) : { //port: s
            switch(transactionIndex) {
                case(0) : { //transaction: READ
                    this->transaction_instance__s__READ
                      (
                        address, 
                        size, 
                        data, 
                        has_been_error, 
                        currentTime
                      );
                    break;
                }
                case(1) : { //transaction: WRITE
                    this->transaction_instance__s__WRITE
                      (
                        address, 
                        size, 
                        data, 
                        has_been_error, 
                        currentTime
                      );
                    break;
                }
            }
            break;
        }
        default: break;
    }
}


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
//* This file is write protected. 
//* DO NOT MODIFY THIS FILE.
//*
//* This file is generated according to the parameters in the 
//* Model Builder form.
//* 
//* Any change in parameters, policies, ports, protocols, etc. will change this file
//* upon generation of the timing model (using generate_timing_model command).
//* The sink_t will be derived from this class.
//*
//* Model Builder version: 3.2.0
//* Generated on: Feb. 29, 2012 03:31:59 AM, (user: jon)
//*>




#include "sink_model.h"
#include <math.h>
#include <stdlib.h>

using namespace esl::tlm_sim;
using namespace esl::sc_sim;
using namespace std;
using namespace sc_dt;
using namespace sc_core;




void sink_t_base::start_transaction_generic_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();
  
  this->getMachineArch()->startTransaction(port_index,
                                           0,
                                           startTime);
  
  this->accept_generic_READ
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3], 
     parameters[4], 
     parameters[5]);
}

void sink_t_base::end_transaction_generic_READ
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();                                                                         
  this->getMachineArch()->callTransaction(port_index, 
                                          0, 
                                          request->getAddress(),
                                          burstSize,
                                          request->getFirstDataBlock(),
                                          hasBeenError,
                                          startTime);
  
  this->end_generic_READ
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3],
     parameters[4],
     parameters[5]);
}
void sink_t_base::start_transaction_generic_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();
  
  this->getMachineArch()->startTransaction(port_index,
                                           1,
                                           startTime);
  
  this->accept_generic_WRITE
    (port_index, 
     startTime, 
     burstSize, 
     parameters[0], 
     parameters[1], 
     parameters[2], 
     parameters[3], 
     parameters[4], 
     parameters[5]);
}

void sink_t_base::end_transaction_generic_WRITE
(esl::include::TRequest* request,
 unsigned port_index,
 sc_dt::uint64 startTime,
 sc_dt::uint64 endTime,
 sc_dt::uint64* parameters,
 bool hasBeenError) {
  long burstSize = request->getSize();
  parameters[0] = request->getAddress();
  parameters[1] = request->getFirstDataBlock();
  parameters[4] = request->getBlockSize();                                                                         
  this->getMachineArch()->callTransaction(port_index, 
                                          1, 
                                          request->getAddress(),
                                          burstSize,
                                          request->getFirstDataBlock(),
                                          hasBeenError,
                                          startTime);
  
  this->end_generic_WRITE
    (port_index,
     endTime,
     burstSize,
     parameters[0],
     parameters[1],
     parameters[2],
     parameters[3],
     parameters[4],
     parameters[5]);
}

sink_t_base::TransactionCallbackFunctionPointer sink_t_base::getTransactionCallback(unsigned callbackIndex) {
  static TransactionCallbackFunctionPointer funcArray[] = {
    static_cast<TransactionCallbackFunctionPointer>(&sink_t_base::start_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&sink_t_base::start_transaction_generic_WRITE),
    static_cast<TransactionCallbackFunctionPointer>(&sink_t_base::end_transaction_generic_READ),
    static_cast<TransactionCallbackFunctionPointer>(&sink_t_base::end_transaction_generic_WRITE),
    0
  };
  if(callbackIndex >= sizeof(funcArray) / sizeof(*funcArray) - 1)
    return 0;
  return funcArray[callbackIndex];
}




sink_t_base::sink_t_base(sc_module_name& module_name, long simulation) :
  papoulis::SystemCBaseModel(module_name),
  m_machineArch(new sink_machine_arch()),
  SD_INITIALIZE_PARAMETER(clock, sc_core::sc_time(10, sc_core::SC_NS)),
  SD_INITIALIZE_PARAMETER(generic_clock, clock),
  SD_INITIALIZE_PARAMETER(nominal_voltage, 1),
  SD_INITIALIZE_PARAMETER(mb_debug, false),
  SD_INITIALIZE_PARAMETER(verbose_parameters, true),
  SD_INITIALIZE_PARAMETER(s_pipeline_length, 2),
  m_simulation(simulation)
{
  bool separate_read_channel = false;
  bool separate_write_channel = false;
  fix_clock_parameter(generic_clock, "generic_clock");
  separate_read_channel = false;
  separate_write_channel = false;
  port_descriptions[s].port_name = "s";
  port_descriptions[s].port_kind = PortDescription::READ_WRITE_CHANNEL_PORT;
  if (separate_write_channel && separate_read_channel)
    port_descriptions[s].port_kind = PortDescription::SEPARATE_READ_WRIE_CHANNEL_PORT;
  port_descriptions[s].is_read_write_address_channel = 0;
  
  port_descriptions[s].is_read_write_address_channel = 1;
  port_descriptions[s].is_master_port = 0;
  port_descriptions[s].is_signal_port = 0;
  port_descriptions[s].port_width = 4;
  port_descriptions[s].protocol_name = "generic";
  port_descriptions[s].params_count = 10;
  port_descriptions[s].clock = generic_clock;
  m_machineArch->configureClock(s, mb::sysc::sc_time_to_ps(generic_clock));
  port_descriptions[s].add_read_phase(tlm::tlm_phase(tlm::BEGIN_REQ), !0, 1);
  port_descriptions[s].add_read_phase(tlm::tlm_phase(tlm::BEGIN_RESP), !1, 1);


  port_descriptions[s].default_read_transaction_name = "READ";
  port_descriptions[s].default_write_transaction_name = "WRITE";

  fix_internal_clock_parameter(clock, "clock");
  set_ports(mb::sysc::sc_time_to_ps(clock), port_count, port_descriptions);

  bool isCpu = false;
  
  esl::tlm_sim::UserRunningModel* userRunningModel = Papoulis_CreateUserRunningModel(name(),
                                                                                     0,
                                                                                     this,
                                                                                     simulation,
                                                                                     false,
                                                                                     isCpu);
  setUserRunningModel(userRunningModel);
  set_nominal_voltage(nominal_voltage);
  set_sync_all(0);
  
  
  
  
  

  
  

  


  

  constant_global_power_policy* p = new constant_global_power_policy(userRunningModel);
  
  
  
  set_global_power_policy(p);
}

void sink_t_base::update_sync_all() {
  set_sync_all(0);
  
}

void sink_t_base::update_pipeline_parameters(esl::sc_sim::pipeline_policy* handle) {
  if (m_pipeline_vector.size() == 0)
    return;


}

void sink_t_base::update_sequential_parameters(esl::sc_sim::sequential_policy* handle) {
  if (m_sequential_vector.size() == 0)
    return;

}

void sink_t_base::update_delay_parameters(esl::sc_sim::delay_policy* handle) {
  if (m_delay_vector.size() == 0)
    return;

}

void sink_t_base::update_bus_parameters(esl::sc_sim::uniform_bus_policy* handle) {
  if (m_bus_vector.size() == 0)
    return;

}

void sink_t_base::update_power_parameters(esl::sc_sim::power_policy* handle) {
  if (m_power_vector.size() == 0)
    return;

}

void sink_t_base::update_state_power_parameters(esl::sc_sim::state_power_policy* handle) {
  if (m_state_power_vector.size() == 0)
    return;

}


bool sink_t_base::triggerRegistersGotHit(unsigned portIndex, tlm::tlm_generic_payload& trans) {
  mb::utl::Segment<uint64_t> transactionRange(trans.get_address(), trans.get_address() + trans.get_data_length());

  return false;
}

bool sink_t_base::portHasRegisters(unsigned portIndex) {
  switch (portIndex) {

  }
  return false;
}


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
//* This file is write protected.
//* DO NOT MODIFY THIS FILE.
//*
//* This file contains the PVT class for sink.
//* It connects between the PV and T models.
//* Your top-level design should instantiate this model.
//* 
//* In order to synchronize the activty between the PV and the T models, every 
//* PV transaction is monitored and queued in the T sync ports.
//* Whenever a synchronization point is reached, the T models are executed and 
//* the corresponding T transactions are launched.
//* A synchronization point is reached whenever there is a wait statement on a testbench thread. 
//*
//* Model Builder version: 3.2.0
//* Generated on: Feb. 29, 2012 03:31:59 AM, (user: jon)
//*>

#include "sink_model.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


#include "sink_pv.h"

// Constructor
sink_pvt::sink_pvt(sc_module_name module_name)
  : esl::sc_sim::PVTBaseModel(module_name, 0),
    sink_pvt_param_defaults(this->name()),
    s("s"),
    s_entry("unvisible_s_entry"),
    m_s_nb_connector(*this)
{
  m_sink_t = sink_t_base::create_t("T", 1);
  m_sink_pv = new sink_pv("PV");
  bind();
}

sink_pvt::~sink_pvt() {
  delete m_sink_t; delete m_sink_pv;
}



void sink_pvt::bind()
{
  /* connect pv to entry ports */
  
  
  s_entry.bind(getPV()->s);   

  /* set callbacks on external and entry ports */ 

  s.b_transport_cb.set(&s_entry, &s_entry_type::b_transport);
  s.transport_dbg_cb.set(&s_entry, &s_entry_type::transport_dbg);
  s.get_direct_mem_ptr_cb.set(&s_entry, &s_entry_type::get_direct_mem_ptr);

  
  /* connect t non blocking callbacks */

  s.nb_transport_fw_cb.set(this, &self_type::receive_nb_transport_s);
  getT()->set_port_cb(0, &m_s_nb_connector);

  s_entry.invalidate_direct_mem_ptr_cb.set(&s, &s_type::invalidate_direct_mem_ptr);

}


