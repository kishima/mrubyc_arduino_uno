#include "vm_config.h"
#include "string_mini.h"

#include "value.h"
#include "micro_vm.h"
#include "class.h"
#include "alloc.h"
#include "c_string.h"
#include "global.h"
#include "symbol.h"
#include "console.h"
#include "debug.h"
#include "avr_access.h"
#include "symbol_ids.h"

#include "ext_arduino.h"

mrb_class *mrbc_class_arduino;

void class_arduino_delay(mrb_mvm *vm, mrb_value *v, int argc )
{ 
	//DEBUG_FPRINTLN(">delay");
	int d=GET_INT_ARG(1);
	//delay(d);
	SET_TRUE_RETURN();
}

static uint8_t sym_to_pinmode(mrb_sym sym_in){
/*	uint8_t mode = INPUT;

	if(sym_in == MRBC_SSYM_INPUT){
		mode = INPUT;
	}else if(sym_in == MRBC_SSYM_OUTPUT){
		mode = OUTPUT;
	}else if(sym_in == MRBC_SSYM_INPUT_PULLUP){
		mode = INPUT_PULLUP;
	}
	return mode;
	*/
	return 0;
}

static uint8_t sym_to_siglevel(mrb_sym sym_in){
	/*
	uint8_t sig = LOW;

	if(sym_in == MRBC_SSYM_HIGH){
		sig = HIGH;
	}else{
		sig = LOW;
	}
	return sig;
	*/
	return 0;
}

void class_arduino_pin_mode(mrb_mvm *vm, mrb_value *v, int argc )
{
	/*
 	int pin = 0;
	if(GET_TT_ARG(1) == MRB_TT_FIXNUM){
		pin = GET_INT_ARG(1);
	}else{
		SET_FALSE_RETURN();
		return;
	}
	
	mrb_sym sym_in = 0;
	if(GET_TT_ARG(2) == MRB_TT_SYMBOL){
		sym_in = GET_INT_ARG(2);
	}else if(GET_TT_ARG(2) == MRB_TT_STRING){
		sym_in = str_to_symid((const char *)GET_STRING_ARG(2));
	}else{
		SET_FALSE_RETURN();
		return;
	}
	uint8_t mode = sym_to_pinmode( sym_in );
	
	pinMode(pin,mode);
	*/
	SET_TRUE_RETURN();
}

void class_arduino_digital_write(mrb_mvm *vm, mrb_value *v, int argc )
{
	/*
	int pin = 0;
	if(GET_TT_ARG(1) == MRB_TT_FIXNUM){
		pin = GET_INT_ARG(1);
	}else{
		SET_FALSE_RETURN();
		return;
	}
	mrb_sym sym_in = 0;
	if(GET_TT_ARG(2) == MRB_TT_SYMBOL){
		sym_in = GET_INT_ARG(2);
	}else if(GET_TT_ARG(2) == MRB_TT_STRING){
		sym_in = str_to_symid((const char *)GET_STRING_ARG(2));
	}else{
		SET_FALSE_RETURN();
		return;
	}
	uint8_t sig = sym_to_siglevel( sym_in );
	//cprintf("dwrite %d %d\n",pin,sig);

	digitalWrite(pin,sig);
	*/
	SET_TRUE_RETURN();
}
void class_arduino_digital_read(mrb_mvm *vm, mrb_value *v, int argc )
{
	/*
	int pin = 0;
	if(GET_TT_ARG(1) == MRB_TT_FIXNUM){
		pin = GET_INT_ARG(1);
	}else{
		SET_FALSE_RETURN();
		return;
	}
	uint8_t sig = INPUT;
	sig = digitalRead(pin);
	SET_INT_RETURN(sig);
	*/
	SET_INT_RETURN(0);
}

void mrbc_init_class_arduino(void)
{
  mrbc_class_arduino = mrbc_define_class((char*)MRBC_SSYM_Arduino, 0);
}
