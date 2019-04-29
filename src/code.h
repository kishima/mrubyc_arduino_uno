/* Irep table */
const unsigned char mmruby_code_irep_000[] PROGMEM= {
0x00,0x1D,0x00,0x02,0x00,0x40,0x0C,0x17,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x03,
0x00,0x80,0x00,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,0x00,0x80,0x40,0xA0,
0x00,0x80,0x00,0x06,0x01,0x3F,0xFF,0x83,0x00,0x80,0x00,0xA0,0x00,0x80,0x00,0x06,
0x01,0x40,0x04,0x83,0x00,0x80,0x40,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x03,
0x00,0x80,0x00,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x0E,0x83,0x00,0x80,0x40,0xA0,
0x00,0x80,0x00,0x06,0x01,0x3F,0xFF,0x83,0x00,0x80,0x00,0xA0,0x00,0x80,0x00,0x06,
0x01,0x40,0x0E,0x83,0x00,0x80,0x40,0xA0,0x00,0x80,0x00,0x07,0x00,0xBF,0xF3,0x18,
0x00,0x80,0x00,0x05,0x00,0x00,0x00,0x4A,0x1D,0x1E,
};
const unsigned char* const mmruby_code_irep_table[] PROGMEM = {
  mmruby_code_irep_000,
};

/* Proc table */
const unsigned char mmruby_code_proc_table_size PROGMEM = 45;


const uint8_t mmruby_code_proc_table_Object[] PROGMEM = {
  31,1,
  32,2,
  33,3,
  34,4,
  15,5,
  35,6,
  36,7,
  37,8,
  29,9,
  30,10,
  38,11,
  39,12,
  39,13,
  39,14,
  40,15,
  41,16,
  42,17,
  43,18,
  44,19,
  45,20,
  0
};

const uint8_t mmruby_code_proc_table_Proc[] PROGMEM = {
  46,36,
  15,37,
  0
};

const uint8_t mmruby_code_proc_table_False[] PROGMEM = {
  15,39,
  0
};

const uint8_t mmruby_code_proc_table_True[] PROGMEM = {
  15,40,
  0
};

const uint8_t mmruby_code_proc_table_Nil[] PROGMEM = {
  15,38,
  0
};

const uint8_t mmruby_code_proc_table_Array[] PROGMEM = {
  0
};

const uint8_t mmruby_code_proc_table_Fixnum[] PROGMEM = {
  24,21,
  47,22,
  48,23,
  49,24,
  50,25,
  51,26,
  52,27,
  53,28,
  23,29,
  28,30,
  54,31,
  55,32,
  56,33,
  57,34,
  15,35,
  0
};

const uint8_t mmruby_code_proc_table_String[] PROGMEM = {
  58,42,
  15,43,
  59,44,
  60,45,
  0
};

const uint8_t mmruby_code_proc_table_Symbol[] PROGMEM = {
  15,41,
  0
};

const uint8_t mmruby_code_proc_table_Range[] PROGMEM = {
  0
};

xinline mrb_func_t find_c_funcs_by_no(short no){
  mrb_func_t func=0;
  switch(no){
    case 1: func = c_puts; break;
    case 2: func = c_object_not; break;
    case 3: func = c_object_neq; break;
    case 4: func = c_object_compare; break;
    case 5: func = c_object_to_s; break;
    case 6: func = c_object_class; break;
    case 7: func = c_object_attr_reader; break;
    case 8: func = c_object_attr_accessor; break;
    case 9: func = c_object_led; break;
    case 10: func = c_object_wait; break;
    case 11: func = c_object_out; break;
    case 12: func = c_object_in; break;
    case 13: func = c_object_ana; break;
    case 14: func = c_object_pwm; break;
    case 15: func = c_object_cls; break;
    case 16: func = c_object_lc; break;
    case 17: func = c_object_scr; break;
    case 18: func = c_object_inkey; break;
    case 19: func = c_object_rnd; break;
    case 20: func = c_object_print; break;
    case 21: func = c_fixnum_bitref; break;
    case 22: func = c_fixnum_negative; break;
    case 23: func = c_fixnum_power; break;
    case 24: func = c_fixnum_mod; break;
    case 25: func = c_fixnum_and; break;
    case 26: func = c_fixnum_or; break;
    case 27: func = c_fixnum_xor; break;
    case 28: func = c_fixnum_not; break;
    case 29: func = c_fixnum_lshift; break;
    case 30: func = c_fixnum_rshift; break;
    case 31: func = c_fixnum_abs; break;
    case 32: func = c_fixnum_times; break;
    case 33: func = c_fixnum_chr; break;
    case 34: func = c_ineffect; break;
    case 35: func = c_fixnum_to_s; break;
    case 36: func = c_proc_call; break;
    case 37: func = c_proc_to_s; break;
    case 38: func = c_nil_to_s; break;
    case 39: func = c_false_to_s; break;
    case 40: func = c_true_to_s; break;
    case 41: func = c_true_to_s; break;
    case 42: func = c_all_symbols; break;
    case 43: func = c_to_s; break;
    case 44: func = c_to_s; break;
    case 45: func = c_ineffect; break;
    default: break;
  }
  return func;
}


/* Symbol table */
#include "symbol_ids.h"

const unsigned char mmruby_code_symbol_table_size PROGMEM = 61;
const char mmruby_code_symbol_ref00[] PROGMEM ="";
const char mmruby_code_symbol_ref01[] PROGMEM ="Object";
const char mmruby_code_symbol_ref02[] PROGMEM ="String";
const char mmruby_code_symbol_ref03[] PROGMEM ="Nil";
const char mmruby_code_symbol_ref04[] PROGMEM ="Proc";
const char mmruby_code_symbol_ref05[] PROGMEM ="False";
const char mmruby_code_symbol_ref06[] PROGMEM ="True";
const char mmruby_code_symbol_ref07[] PROGMEM ="Fixnum";
const char mmruby_code_symbol_ref08[] PROGMEM ="Symbol";
const char mmruby_code_symbol_ref09[] PROGMEM ="Array";
const char mmruby_code_symbol_ref0a[] PROGMEM ="Range";
const char mmruby_code_symbol_ref0b[] PROGMEM ="Hash";
const char mmruby_code_symbol_ref0c[] PROGMEM ="Arduino";
const char mmruby_code_symbol_ref0d[] PROGMEM ="true";
const char mmruby_code_symbol_ref0e[] PROGMEM ="false";
const char mmruby_code_symbol_ref0f[] PROGMEM ="to_s";
const char mmruby_code_symbol_ref10[] PROGMEM ="INPUT";
const char mmruby_code_symbol_ref11[] PROGMEM ="OUTPUT";
const char mmruby_code_symbol_ref12[] PROGMEM ="INPUT_PULLUP";
const char mmruby_code_symbol_ref13[] PROGMEM ="HIGH";
const char mmruby_code_symbol_ref14[] PROGMEM ="LOW";
const char mmruby_code_symbol_ref15[] PROGMEM ="+";
const char mmruby_code_symbol_ref16[] PROGMEM ="===";
const char mmruby_code_symbol_ref17[] PROGMEM ="<<";
const char mmruby_code_symbol_ref18[] PROGMEM ="[]";
const char mmruby_code_symbol_ref19[] PROGMEM ="[]=";
const char mmruby_code_symbol_ref1a[] PROGMEM ="()";
const char mmruby_code_symbol_ref1b[] PROGMEM ="-";
const char mmruby_code_symbol_ref1c[] PROGMEM =">>";
const char mmruby_code_symbol_ref1d[] PROGMEM ="led";
const char mmruby_code_symbol_ref1e[] PROGMEM ="wait";
const char mmruby_code_symbol_ref1f[] PROGMEM ="puts";
const char mmruby_code_symbol_ref20[] PROGMEM ="!";
const char mmruby_code_symbol_ref21[] PROGMEM ="!=";
const char mmruby_code_symbol_ref22[] PROGMEM ="<=>";
const char mmruby_code_symbol_ref23[] PROGMEM ="class";
const char mmruby_code_symbol_ref24[] PROGMEM ="attr_reader";
const char mmruby_code_symbol_ref25[] PROGMEM ="attr_accessor";
const char mmruby_code_symbol_ref26[] PROGMEM ="out";
const char mmruby_code_symbol_ref27[] PROGMEM ="in";
const char mmruby_code_symbol_ref28[] PROGMEM ="cls";
const char mmruby_code_symbol_ref29[] PROGMEM ="lc";
const char mmruby_code_symbol_ref2a[] PROGMEM ="scr";
const char mmruby_code_symbol_ref2b[] PROGMEM ="inkey";
const char mmruby_code_symbol_ref2c[] PROGMEM ="rnd";
const char mmruby_code_symbol_ref2d[] PROGMEM ="print";
const char mmruby_code_symbol_ref2e[] PROGMEM ="call";
const char mmruby_code_symbol_ref2f[] PROGMEM ="-@";
const char mmruby_code_symbol_ref30[] PROGMEM ="**";
const char mmruby_code_symbol_ref31[] PROGMEM ="%";
const char mmruby_code_symbol_ref32[] PROGMEM ="&";
const char mmruby_code_symbol_ref33[] PROGMEM ="|";
const char mmruby_code_symbol_ref34[] PROGMEM ="^";
const char mmruby_code_symbol_ref35[] PROGMEM ="~";
const char mmruby_code_symbol_ref36[] PROGMEM ="abs";
const char mmruby_code_symbol_ref37[] PROGMEM ="times";
const char mmruby_code_symbol_ref38[] PROGMEM ="chr";
const char mmruby_code_symbol_ref39[] PROGMEM ="to_i";
const char mmruby_code_symbol_ref3a[] PROGMEM ="all_symbols";
const char mmruby_code_symbol_ref3b[] PROGMEM ="id2name";
const char mmruby_code_symbol_ref3c[] PROGMEM ="to_sym";

const char* const mmruby_code_symbol_table[] PROGMEM = {
  mmruby_code_symbol_ref00,
  mmruby_code_symbol_ref01,
  mmruby_code_symbol_ref02,
  mmruby_code_symbol_ref03,
  mmruby_code_symbol_ref04,
  mmruby_code_symbol_ref05,
  mmruby_code_symbol_ref06,
  mmruby_code_symbol_ref07,
  mmruby_code_symbol_ref08,
  mmruby_code_symbol_ref09,
  mmruby_code_symbol_ref0a,
  mmruby_code_symbol_ref0b,
  mmruby_code_symbol_ref0c,
  mmruby_code_symbol_ref0d,
  mmruby_code_symbol_ref0e,
  mmruby_code_symbol_ref0f,
  mmruby_code_symbol_ref10,
  mmruby_code_symbol_ref11,
  mmruby_code_symbol_ref12,
  mmruby_code_symbol_ref13,
  mmruby_code_symbol_ref14,
  mmruby_code_symbol_ref15,
  mmruby_code_symbol_ref16,
  mmruby_code_symbol_ref17,
  mmruby_code_symbol_ref18,
  mmruby_code_symbol_ref19,
  mmruby_code_symbol_ref1a,
  mmruby_code_symbol_ref1b,
  mmruby_code_symbol_ref1c,
  mmruby_code_symbol_ref1d,
  mmruby_code_symbol_ref1e,
  mmruby_code_symbol_ref1f,
  mmruby_code_symbol_ref20,
  mmruby_code_symbol_ref21,
  mmruby_code_symbol_ref22,
  mmruby_code_symbol_ref23,
  mmruby_code_symbol_ref24,
  mmruby_code_symbol_ref25,
  mmruby_code_symbol_ref26,
  mmruby_code_symbol_ref27,
  mmruby_code_symbol_ref28,
  mmruby_code_symbol_ref29,
  mmruby_code_symbol_ref2a,
  mmruby_code_symbol_ref2b,
  mmruby_code_symbol_ref2c,
  mmruby_code_symbol_ref2d,
  mmruby_code_symbol_ref2e,
  mmruby_code_symbol_ref2f,
  mmruby_code_symbol_ref30,
  mmruby_code_symbol_ref31,
  mmruby_code_symbol_ref32,
  mmruby_code_symbol_ref33,
  mmruby_code_symbol_ref34,
  mmruby_code_symbol_ref35,
  mmruby_code_symbol_ref36,
  mmruby_code_symbol_ref37,
  mmruby_code_symbol_ref38,
  mmruby_code_symbol_ref39,
  mmruby_code_symbol_ref3a,
  mmruby_code_symbol_ref3b,
  mmruby_code_symbol_ref3c,
};

