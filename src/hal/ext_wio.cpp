/*
  ext_wio.cpp

  Defining extension methods of Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

static WioLTE* wio=NULL;

static void class_wio_new(mrb_vm *vm, mrb_value *v, int argc )
{
	
}

static void class_wio_control_led(mrb_vm *vm, mrb_value *v, int argc )
{
	if(argc!=3){
		SET_FALSE_RETURN();
		return;
	}
	if(wio==NULL){
		DEBUG_PRINT("wio==NULL\n");
		return;
	}
	int r=GET_INT_ARG(1);
	int g=GET_INT_ARG(2);
	int b=GET_INT_ARG(3);
	wio->LedSetRGB(r, g, b);
	SET_TRUE_RETURN();
}

void define_wiolte_class()
{
	wio=(WioLTE*)hal_get_modem_obj();

	mrb_class *class_wio;
	class_wio = mrbc_define_class(0, "Wio", mrbc_class_object);
	mrbc_define_method(0, class_wio, "new", class_wio_new);
	//LED
	mrbc_define_method(0, class_wio, "control_led", class_wio_control_led);
	//Modem Power
	//HTTP
}
