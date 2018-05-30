/*
  ext_arduino.cpp

  Defining extension methods of Arduino on Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

static void class_arduino_delay(mrb_vm *vm, mrb_value *v, int argc )
{
	int d=GET_INT_ARG(1);
	delay(d);
	SET_TRUE_RETURN();
}

static void class_arduino_pin_mode(mrb_vm *vm, mrb_value *v, int argc )
{
	int pin = 0;
	if(GET_TT_ARG(1) == MRB_TT_FIXNUM){
		pin = GET_INT_ARG(1);
	}else{
		SET_FALSE_RETURN();
		return;
	}
	
	WiringPinMode mode = INPUT;
	if(GET_TT_ARG(2) != MRB_TT_SYMBOL){
		SET_FALSE_RETURN();
		return;
	}
	mrb_sym sym_in = str_to_symid((const char *)GET_STRING_ARG(2));
	mrb_sym sym_INPUT = str_to_symid("INPUT");
	mrb_sym sym_OUTPUT = str_to_symid("OUTPUT");
	mrb_sym sym_INPUT_PULLUP = str_to_symid("INPUT_PULLUP");

	if(sym_in == sym_INPUT){
		mode = INPUT;
	}else if(sym_in == sym_OUTPUT){
		mode = OUTPUT;
	}else if(sym_in == sym_INPUT_PULLUP){
		mode = INPUT_PULLUP;
	}else{
		SET_FALSE_RETURN();
		return;
	}
	pinMode(pin,mode);
	SET_TRUE_RETURN();
}

void define_arduino_class()
{
	mrb_class *class_arduino;
	class_arduino = mrbc_define_class(0, "Arduino", mrbc_class_object);
	//mrbc_define_method(0, class_arduino, "new", NULL);
	mrbc_define_method(0, class_arduino, "delay", class_arduino_delay);
	mrbc_define_method(0, class_arduino, "pin_mode", class_arduino_pin_mode);
	mrbc_define_method(0, class_arduino, "digital_wirte", NULL);
	mrbc_define_method(0, class_arduino, "digital_read", NULL);

}

void define_serial_class()
{
	mrb_class *class_serial;
	class_serial = mrbc_define_class(0, "Serial", mrbc_class_object);
	mrbc_define_method(0, class_serial, "new", NULL);
	mrbc_define_method(0, class_serial, "begin", NULL);
	mrbc_define_method(0, class_serial, "end", NULL);
	mrbc_define_method(0, class_serial, "available", NULL);
	mrbc_define_method(0, class_serial, "read", NULL);
	mrbc_define_method(0, class_serial, "write", NULL);
}

