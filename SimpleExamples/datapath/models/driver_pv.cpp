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
//* This file contains the PV class for driver.
//* This is a template file: You may modify this file to implement the
//* behavior of your component.
//*
//* Model Builder version: 3.2.0RC
//* Generated on: Feb. 23, 2012 07:57:39 AM, (user: jon)
//*>


#include "driver_pv.h"

//constructor
driver_pv::driver_pv(sc_module_name module_name)
    : driver_pv_base(module_name)
{
    SC_THREAD(thread);
}

driver_pv::~driver_pv()
{
}

void driver_pv::thread()
{
    if (strcmp(DriverFunction, "off") == 0);
    //do nothing
    else if (strcmp(DriverFunction, "simple") == 0)
        simple();
    else if (strcmp(DriverFunction, "random") == 0)
        random();
    else {
        std::cout << this->name() << " thread(): Parameter DriverFunction = " << DriverFunction;
        std::cout << ". This value is not defined, it will be ignored." << endl;
    }
    cout << sc_simulation_time() << ":" << name() << " ended thread" << endl;
}

bool driver_pv::general_write(mb_address_type address, unsigned int *data, unsigned size, const char* extra,
                              bool (driver_pv_base::*writeMethod)(mb_address_type, unsigned int *, unsigned, unsigned))
{
    mb::mb_token_ptr tokenptr = new mb::mb_token;
    tokenptr->setField("CreateTime", sc_simulation_time());
    set_current_token(tokenptr);

    cout << sc_simulation_time() << ":" << name() << " " << extra << " sending data = " << data[0] << endl;
    return (this->*writeMethod)(address, data, size, 0);
}

void driver_pv::simple()
{
    unsigned int d[11] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
    wait(10*generic_clock);

    general_write(0x0, &d[0], 1, "master_1", &driver_pv_base::master_1_write);
    wait(4*generic_clock);

    general_write(0x0, &d[1], 2, "master_2", &driver_pv_base::master_2_write);
    wait(10*generic_clock);

    general_write(0x0, &d[2], 4, "master_3", &driver_pv_base::master_3_write);
    wait(10*generic_clock);

    general_write(0x0, &d[3], 2, "master_4", &driver_pv_base::master_4_write);
    general_write(0x0, &d[4], 6, "master_5", &driver_pv_base::master_5_write);
    general_write(0x0, &d[5], 2, "master_6", &driver_pv_base::master_6_write);

    wait(4*generic_clock);
    general_write(0x0, &d[6], 1, "master_7", &driver_pv_base::master_7_write);

    wait(9*generic_clock);
    general_write(0x0, &d[7], 1, "master_8", &driver_pv_base::master_8_write);
}

void driver_pv::random()
{
    mb_distribution *sizedist = mb_CreateDistribution(SizeDist);
    mb_distribution *addrdist = mb_CreateDistribution(AddrDist);
    mb_distribution *waitdist = mb_CreateDistribution(WaitDist);
    unsigned int d[MaxPacketSize];
    unsigned int s, a;

    srand(5647);

    for (unsigned i = 0; i < NumberPackets; i++) {
        a = addrdist->getNextInt();
        s = sizedist->getNextInt();
        s = s % MaxPacketSize;

        d[0] = i+1;

        general_write(a, d, s, "master_1", &driver_pv_base::master_1_write);

        wait(waitdist->getNextInt() * clock);
    }
}
