/*
  libmrubyc.h

  Header file for Arduino application
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#ifndef __LIBMRUBYC_H__
#define __LIBMRUBYC_H__

#include <WioLTEforArduino.h>
#include "mrubyc.h"
#include "libmrubyc_config.h"

void mrbc_define_wiolte_methods(void);
WioLTE* mrbc_get_wiolte_obj(void);


#endif
