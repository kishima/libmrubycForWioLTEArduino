/*
  libmrubyc.h

  Header file for Arduino application
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#ifndef __LIBMRUBYC_H__
#define __LIBMRUBYC_H__

#define WIOMRBC_VERSION "0.1.0"

#define WIOMRBC_DEBUG

#include <WioLTEforArduino.h>
#include "mrubyc.h"

void mrbc_define_wiolte_methods(void);
WioLTE* mrbc_get_wiolte_obj(void);

/* Specific Devices */
#define USE_GPS_NEO6M
#define USE_RTC

/* for debug */

#ifdef WIOMRBC_DEBUG
//#define DEBUG_PRINT(str)			DebugPrint(str)
//#define DEBUG_PRINTLN(str)			DebugPrintln(str)
#define DEBUG_PRINT(str)
#define DEBUG_PRINTLN(str)
#else
#define DEBUG_PRINT(str)
#define DEBUG_PRINTLN(str)
#endif

#endif
