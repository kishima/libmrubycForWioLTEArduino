/*
  ext.cpp

  Defining extension methods for Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

void mrbc_define_wiolte_methods(void)
{
	define_arduino_class();
	define_serial_class();
	define_wiolte_class();
}
