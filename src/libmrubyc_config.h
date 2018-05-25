/*
  libmrubyc_config.h

  Header file for Arduino application
  
  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/
#ifndef __LIBMRUBYC_CONFIG_H__
#define __LIBMRUBYC_CONFIG_H__

#define WIOMRBC_VERSION "0.1.0"

/* Specific Devices */
#define USE_GPS_NEO6M
#define USE_RTC

/* for debug */
#define WIOMRBC_DEBUG

#ifdef WIOMRBC_DEBUG
#define DEBUG_PRINT(str)    hal_write_string(str)
#else
#define DEBUG_PRINT(str)
#endif

#endif
