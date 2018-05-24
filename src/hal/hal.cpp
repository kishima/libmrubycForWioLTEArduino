/*
  hal.cpp

  mruby/c hardware abstract layer for Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include <WioLTEforArduino.h>
#include "hal.h"


extern "C" void hal_write_string(char* text){
  SerialUSB.print(text);
}

extern "C" void hal_delay(unsigned long t){
  delay(t);
}


