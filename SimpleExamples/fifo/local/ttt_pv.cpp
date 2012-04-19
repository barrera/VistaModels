
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
//* This file contains the PV class for ttt.
//* This is a template file: You may modify this file to implement the 
//* behavior of your component. 
//* 
//* Model Builder version: 3.1.2
//* Generated on: Nov. 02, 2011 03:09:32 AM, (user: jon)
//*>


#include "ttt_pv.h"

//constructor
ttt_pv::ttt_pv(sc_module_name module_name)
  : ttt_pv_base(module_name)
{
  SC_THREAD(thread);
}

ttt_pv::~ttt_pv() {
}

void ttt_pv::thread() {
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
}

void ttt_pv::simple() {
  unsigned int d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  wait(10*generic_clock);

  y_write(0x0, d, 1);
  wait(4*generic_clock);

  y_write(0x0, d, 2);
  wait(10*generic_clock);

  y_write(0x0, d, 4);
  wait(10*generic_clock);

  y_write(0x0, d, 2);
  y_write(0x0, d, 4);
  y_write(0x0, d, 2);

  wait(4*generic_clock);
  y_write(0x0, d, 1);

  wait(50*generic_clock);
}

void ttt_pv::random() {
  mb_distribution *sizedist = mb_CreateDistribution(SizeDist);
  mb_distribution *addrdist = mb_CreateDistribution(AddrDist);
  mb_distribution *waitdist = mb_CreateDistribution(WaitDist);
  unsigned int d[MaxPacketSize];
  unsigned int dcheck[MaxPacketSize];
  unsigned int s, a;

  srand(5647);

  for (unsigned i = 0; i < NumberPackets; i++) {
    a = addrdist->getNextInt();
    s = sizedist->getNextInt();
    s = s % MaxPacketSize;

    for (unsigned j = 0; j < s; j++) d[j] = rand();
    memcpy(dcheck, d, s*4);

    y_write(a, d, s);
    wait(clock);
    y_read(a, dcheck, s);

    for (unsigned j = 0; j < s; j++) {
      assert (d[j] == dcheck[j]);
    }

    wait(waitdist->getNextInt() * clock);
  }
}
