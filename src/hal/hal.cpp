/*
  hal.cpp

  mruby/c hardware abstract layer for Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include <WioLTEforArduino.h>
#include "hal.h"

static WioLTE *Wio=NULL;

extern "C" void hal_init_modem(void){
	if(Wio!=NULL)return;
	Wio = new WioLTE();
	Wio->Init();
}
extern "C" void* hal_get_modem_obj(void){
	return (void*)Wio;
}

extern "C" void hal_write_string(char* text){
  SerialUSB.print(text);
}

extern "C" void hal_delay(unsigned long t){
  delay(t);
}


