/*
  ext_wio.cpp

  Defining extension methods of Wio LTE

  Copyright (c) 2018, katsuhiko kageyama All rights reserved.

*/

#include "libmrubyc.h"
#include "ext.h"

static WioLTE* wio=NULL;

static void class_wio_control_led(mrb_vm *vm, mrb_value *v, int argc )
{
	if(argc!=3){
		SET_FALSE_RETURN();
		return;
	}
	if(wio==NULL){
		DEBUG_PRINT("wio==NULL\n");
		return;
	}
	int r=GET_INT_ARG(1);
	int g=GET_INT_ARG(2);
	int b=GET_INT_ARG(3);
	wio->LedSetRGB(r, g, b);
	SET_TRUE_RETURN();
}

static void class_wio_init(mrb_vm *vm, mrb_value *v, int argc )
{
	wio->Init();
	SET_TRUE_RETURN();
}

static void class_wio_power_supply_LTE(mrb_vm *vm, mrb_value *v, int argc )
{
	bool b = mrbc_trans_cppbool_value(GET_TT_ARG(1));
    DEBUG_PRINT("class_wio_power_supply_LTE\n");
	wio->PowerSupplyLTE(b);
	SET_TRUE_RETURN();
}
static void class_wio_power_supply_grove(mrb_vm *vm, mrb_value *v, int argc )
{
	bool b = mrbc_trans_cppbool_value(GET_TT_ARG(1));

	wio->PowerSupplyGrove(b);
	SET_TRUE_RETURN();
}

static void class_wio_turnon_or_reset(mrb_vm *vm, mrb_value *v, int argc )
{
	DEBUG_PRINT("class_wio_turnon_or_reset\n");
	bool result = wio->TurnOnOrReset();
	if(result){
		SET_TRUE_RETURN();
		DEBUG_PRINT("TurnOnOrReset OK\n");
	}else{
		SET_FALSE_RETURN();
		DEBUG_PRINT("TurnOnOrReset ERROR\n");
	}
}

static void class_wio_activate(mrb_vm *vm, mrb_value *v, int argc )
{
	uint8_t *arg1 = GET_STRING_ARG(1);
	uint8_t *arg2 = GET_STRING_ARG(2);
	uint8_t *arg3 = GET_STRING_ARG(3);
	bool result = wio->Activate((const char*)arg1, (const char*)arg2, (const char*)arg3);
	if(0 == result){
		DEBUG_PRINT("Activate fail!\n");
	}
	SET_TRUE_RETURN();
}

static char recv_buffer[RECV_BUFF_SIZE];

static void class_wio_sock_open(mrb_vm *vm, mrb_value *v, int argc )
{
	char* host = reinterpret_cast<char*>(GET_STRING_ARG(1));
	int port = GET_INT_ARG(1);

	int sock = wio->SocketOpen(host, port, WioLTE::SOCKET_TCP);
	if(sock<0){
		DEBUG_PRINT("SocketOpen fail!\n");
		SET_FALSE_RETURN();
		return;
	}

	SET_INT_RETURN(sock);
}

static void class_wio_sock_open_udp(mrb_vm *vm, mrb_value *v, int argc )
{
	char* host = reinterpret_cast<char*>(GET_STRING_ARG(1));
	int port = GET_INT_ARG(2);

	int sock = wio->SocketOpen(host, port, WIOLTE_UDP);
	if(sock<0){
		SET_FALSE_RETURN();
		return;
	}

	SET_INT_RETURN(sock);
}

static void class_wio_sock_send(mrb_vm *vm, mrb_value *v, int argc )
{
	int sock = GET_INT_ARG(1);
	char* data = reinterpret_cast<char*>(GET_STRING_ARG(2));
	int dataSize;

    DEBUG_PRINT("send:");
    DEBUG_PRINTLN(data);

	bool result = wio->SocketSend(sock,(const char*)data);

	if(result){
		SET_TRUE_RETURN();
	}else{
        DEBUG_PRINTLN("send error!");
		SET_FALSE_RETURN();
	}
}
static void class_wio_sock_close(mrb_vm *vm, mrb_value *v, int argc )
{
	int sock = GET_INT_ARG(1);
	bool result = wio->SocketClose(sock);

	if(result){
		SET_TRUE_RETURN();
	}else{
        DEBUG_PRINTLN("close error!");
		SET_FALSE_RETURN();
	}

}

static void class_wio_http_get(mrb_vm *vm, mrb_value *v, int argc )
{
	char* url = reinterpret_cast<char*>(GET_STRING_ARG(1));
	DEBUG_PRINT(url);
	DEBUG_PRINT("\n");
	int result = wio->HttpGet((const char*)url,recv_buffer,RECV_BUFF_SIZE);
	if(result>=0){
		DEBUG_PRINT("HTTP GET OK\n");
		DEBUG_PRINT(recv_buffer);
		mrb_value string = mrbc_string_new_cstr(vm,(const char*)recv_buffer);
		SET_RETURN(string);
	}else{
		DEBUG_PRINT("HTTP GET ERROR\n");
		SET_NIL_RETURN();
	}
}

static void class_wio_http_post(mrb_vm *vm, mrb_value *v, int argc )
{
	char* url = reinterpret_cast<char*>(GET_STRING_ARG(1));
	char* data = reinterpret_cast<char*>(GET_STRING_ARG(2));
	int response_code=0;
	DEBUG_PRINTLN(url);
	DEBUG_PRINTLN(data);
	bool result = wio->HttpPost((const char*)url,(const char*)data,&response_code);
	if(result>=0){
		DEBUG_PRINT("HTTP POST ResponseCode=");
		DEBUG_PRINTLN(response_code);
		SET_INT_RETURN(response_code);
	}else{
		DEBUG_PRINT("HTTP POST ERROR\n");
		SET_NIL_RETURN();
	}
}


void define_wiolte_class()
{
	wio=(WioLTE*)hal_get_modem_obj();

	mrb_class *class_wio;
	class_wio = mrbc_define_class(0, "Wio", mrbc_class_object);

	// --- LED ---
	mrbc_define_method(0, class_wio, "control_led", class_wio_control_led);

	// --- Power ---
	mrbc_define_method(0, class_wio, "init", class_wio_init);
	mrbc_define_method(0, class_wio, "power_supply_LTE", class_wio_power_supply_LTE);
	mrbc_define_method(0, class_wio, "power_supply_grove", class_wio_power_supply_grove);
	//power supply gnss .. not supported by JP module
	//power supply sd
	mrbc_define_method(0, class_wio, "turnon_or_reset", class_wio_turnon_or_reset);
	//turn off
	//sleep

	// --- Network ---
	mrbc_define_method(0, class_wio, "activate", class_wio_activate);
	//deactivate

	//get IMEI
	//get IMSI
	//get signal strength
	//get time

	//get location
	//sync time

	//socket func
	mrbc_define_method(0, class_wio, "sock_open", class_wio_sock_open);
	mrbc_define_method(0, class_wio, "sock_open_udp", class_wio_sock_open_udp);
	mrbc_define_method(0, class_wio, "sock_send", class_wio_sock_send);
	//mrbc_define_method(0, class_wio, "sock_recv", class_wio_sock_recv);
	mrbc_define_method(0, class_wio, "sock_close", class_wio_sock_close);

	//HTTP method
	mrbc_define_method(0, class_wio, "http_get", class_wio_http_get);
	mrbc_define_method(0, class_wio, "http_post", class_wio_http_post);

}
