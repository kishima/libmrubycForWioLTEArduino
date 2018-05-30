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

static void class_wio_init(mrb_vm *vm, mrb_value *v, int argc )
{
	wio.Init();
}

static void class_wio_power_supply_LTE(mrb_vm *vm, mrb_value *v, int argc )
{
	bool p = true;
	
	wio.PowerSupplyLTE(p);
}

static void class_wio_turnon_or_reset(mrb_vm *vm, mrb_value *v, int argc )
{
	bool result = wio.TurnOnOrReset();
	if(result){
		SET_FALSE_RETURN();
	}else{
		SET_TRUE_RETURN();
	}
}


void define_wiolte_class()
{
	wio=(WioLTE*)hal_get_modem_obj();
	
	mrb_class *class_wio;
	class_wio = mrbc_define_class(0, "Wio", mrbc_class_object);
	mrbc_define_method(0, class_wio, "new", class_wio_new);

	// --- LED ---
	mrbc_define_method(0, class_wio, "control_led", class_wio_control_led);
	
	// --- Power ---
	mrbc_define_method(0, class_wio, "init", class_wio_init);
	mrbc_define_method(0, class_wio, "power_supply_LTE", class_wio_power_supply_LTE);
	//power supply gnss
	//power supply grove
	//power supply sd
	mrbc_define_method(0, class_wio, "turnon_or_reset", class_wio_turnon_or_reset);
	//turn off
	//sleep
	
	// --- Network ---
	mrbc_define_method(0, class_wio, "activate", class_wio_activate);
	//deactivate

	//get IMEI
	//get IMSI
	//get signal strength
	//get time

	//get location
	//sync time

	//sock open
	//sock send
	//sock recv
	//sock close
	
	mrbc_define_method(0, class_wio, "http_get", class_wio_http_get);
	//POST

}
