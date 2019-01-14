/*
  ext_ultrasonic.cpp

  Ultrasonic Ranger methods for Wio LTE

  Copyright (c) 2019, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"
#include "Ultrasonic.h"
Ultrasonic ultrasonic(WIOLTE_D38);

static void class_ultrasonic_read(mrb_vm *vm, mrb_value *v, int argc ){
	long val = ultrasonic.MeasureInCentimeters();
	SET_INT_RETURN(val);
}

void define_ultrasonic_class(){
	mrb_class *class_ultrasonic;
	class_ultrasonic = mrbc_define_class(0, "UltraSonic", mrbc_class_object);

	//method
	mrbc_define_method(0, class_ultrasonic, "read", class_ultrasonic_read);

}
