
#include <WioLTEforArduino.h>
#include "hal.h"


extern "C" void hal_write_string(char* text){
  SerialUSB.print(text);
}

extern "C" void hal_delay(unsigned long t){
  delay(t);
}


