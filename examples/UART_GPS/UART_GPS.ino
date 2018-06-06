#include <libmrubyc.h>

#include <stdint.h>
extern const uint8_t code[];

#define MEMSIZE (1024*30)
static uint8_t mempool[MEMSIZE];


void setup() {
  delay(1000);

  SerialUSB.println("--- begin setup"); 
  mrbc_init(mempool, MEMSIZE);
  mrbc_define_wiolte_methods();
  if(NULL == mrbc_create_task( code, 0 )){
    SerialUSB.println("mrbc_create_task error");
    return;
  }
  SerialUSB.println("--- run mruby script"); 
  mrbc_run();
}

void loop() {
  delay(1000);
}
