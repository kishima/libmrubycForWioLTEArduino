/*
  ext.cpp

  Defining extension methods for Wio LTE
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

bool mrbc_trans_cppbool_value(mrbc_vtype tt)
{
	if(tt==MRBC_TT_TRUE){
		return true;
	}
	return false;
}

void mrbc_define_wiolte_methods(void)
{
	define_arduino_class();
	define_serial_class();
	define_wiolte_class();
}
