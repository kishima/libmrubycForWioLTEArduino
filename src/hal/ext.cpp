#include <WioLTEforArduino.h>
#include "libmrubyc.h"

static WioLTE *Wiop;

void wiomrbc_control_led(mrb_vm *vm, mrb_value *v, int argc ){
	if(argc!=3)return;  
	int r=GET_INT_ARG(1);
	int g=GET_INT_ARG(2);
	int b=GET_INT_ARG(3);
	Wiop->LedSetRGB(r, g, b);
}

void mrbc_define_wiolte_methods(WioLTE *wio)
{
	Wiop=wio;
	mrbc_define_method(0,mrbc_class_object, "control_led", wiomrbc_control_led);

}
