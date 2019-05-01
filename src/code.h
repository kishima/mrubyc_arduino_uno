/* Irep table */
const unsigned char mmruby_code_irep_000[] PROGMEM= {
0x00,0x3B,0x00,0x05,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x03,0x00,0x80,0x00,0xA0,
0x00,0x40,0x00,0x17,0x00,0x80,0x00,0x06,0x00,0x80,0x40,0x20,0x01,0x3F,0xFF,0x83,
0x00,0x80,0x80,0xB2,0x00,0xBF,0xFD,0x98,0x00,0x80,0x00,0x06,0x01,0x3F,0xFF,0x83,
0x00,0x80,0x00,0xA0,0x00,0x40,0x15,0x17,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x83,
0x01,0xC0,0x00,0x03,0x00,0x80,0xC1,0x20,0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,
0x00,0x81,0x00,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x01,0x03,0x01,0xC0,0x00,0x03,
0x00,0x80,0xC1,0x20,0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,0x00,0x81,0x00,0xA0,
0x00,0x80,0x00,0x06,0x01,0x40,0x01,0x83,0x01,0xC0,0x00,0x03,0x00,0x80,0xC1,0x20,
0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,0x00,0x81,0x00,0xA0,0x00,0x80,0x00,0x06,
0x01,0x40,0x01,0x83,0x01,0xBF,0xFF,0x83,0x00,0x80,0xC1,0x20,0x00,0x80,0x00,0x06,
0x01,0x40,0x04,0x83,0x00,0x81,0x00,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x01,0x03,
0x01,0xBF,0xFF,0x83,0x00,0x80,0xC1,0x20,0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,
0x00,0x81,0x00,0xA0,0x00,0x80,0x00,0x06,0x01,0x40,0x00,0x83,0x01,0xBF,0xFF,0x83,
0x00,0x80,0xC1,0x20,0x00,0x80,0x00,0x06,0x01,0x40,0x04,0x83,0x00,0x81,0x00,0xA0,
0x00,0x80,0x00,0x07,0x00,0xBF,0xEA,0x18,0x00,0x80,0x00,0x05,0x00,0x00,0x00,0x4A,
0x1C,0x1D,0x1E,0x1F,0x20,
};
const unsigned char* const mmruby_code_irep_table[] PROGMEM = {
  mmruby_code_irep_000,
};

/* Proc table */
const unsigned char mmruby_code_proc_table_size PROGMEM = 46;


const uint8_t mmruby_code_proc_table_Object[] PROGMEM = {
  33,1,
  34,2,
  35,3,
  36,4,
  14,5,
  37,6,
  38,7,
  39,8,
  28,9,
  29,10,
  32,11,
  31,12,
  40,13,
  41,14,
  42,15,
  43,16,
  44,17,
  45,18,
  46,19,
  47,20,
  48,21,
  0
};

const uint8_t mmruby_code_proc_table_Proc[] PROGMEM = {
  49,37,
  14,38,
  0
};

const uint8_t mmruby_code_proc_table_False[] PROGMEM = {
  14,40,
  0
};

const uint8_t mmruby_code_proc_table_True[] PROGMEM = {
  14,41,
  0
};

const uint8_t mmruby_code_proc_table_Nil[] PROGMEM = {
  14,39,
  0
};

const uint8_t mmruby_code_proc_table_Array[] PROGMEM = {
  0
};

const uint8_t mmruby_code_proc_table_Fixnum[] PROGMEM = {
  23,22,
  50,23,
  51,24,
  52,25,
  53,26,
  54,27,
  55,28,
  56,29,
  22,30,
  27,31,
  57,32,
  58,33,
  59,34,
  60,35,
  14,36,
  0
};

const uint8_t mmruby_code_proc_table_String[] PROGMEM = {
  61,43,
  14,44,
  62,45,
  63,46,
  0
};

const uint8_t mmruby_code_proc_table_Symbol[] PROGMEM = {
  14,42,
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
    case 10: func = c_object_btn; break;
    case 11: func = c_object_wait; break;
    case 12: func = c_object_out; break;
    case 13: func = c_object_in; break;
    case 14: func = c_object_ana; break;
    case 15: func = c_object_pwm; break;
    case 16: func = c_object_cls; break;
    case 17: func = c_object_lc; break;
    case 18: func = c_object_scr; break;
    case 19: func = c_object_inkey; break;
    case 20: func = c_object_rnd; break;
    case 21: func = c_object_print; break;
    case 22: func = c_fixnum_bitref; break;
    case 23: func = c_fixnum_negative; break;
    case 24: func = c_fixnum_power; break;
    case 25: func = c_fixnum_mod; break;
    case 26: func = c_fixnum_and; break;
    case 27: func = c_fixnum_or; break;
    case 28: func = c_fixnum_xor; break;
    case 29: func = c_fixnum_not; break;
    case 30: func = c_fixnum_lshift; break;
    case 31: func = c_fixnum_rshift; break;
    case 32: func = c_fixnum_abs; break;
    case 33: func = c_fixnum_times; break;
    case 34: func = c_fixnum_chr; break;
    case 35: func = c_ineffect; break;
    case 36: func = c_fixnum_to_s; break;
    case 37: func = c_proc_call; break;
    case 38: func = c_proc_to_s; break;
    case 39: func = c_nil_to_s; break;
    case 40: func = c_false_to_s; break;
    case 41: func = c_true_to_s; break;
    case 42: func = c_true_to_s; break;
    case 43: func = c_all_symbols; break;
    case 44: func = c_to_s; break;
    case 45: func = c_to_s; break;
    case 46: func = c_ineffect; break;
    default: break;
  }
  return func;
}


/* Symbol table */
#include "symbol_ids.h"

const unsigned char mmruby_code_symbol_table_size PROGMEM = 64;
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
const char mmruby_code_symbol_ref0c[] PROGMEM ="true";
const char mmruby_code_symbol_ref0d[] PROGMEM ="false";
const char mmruby_code_symbol_ref0e[] PROGMEM ="to_s";
const char mmruby_code_symbol_ref0f[] PROGMEM ="INPUT";
const char mmruby_code_symbol_ref10[] PROGMEM ="OUTPUT";
const char mmruby_code_symbol_ref11[] PROGMEM ="INPUT_PULLUP";
const char mmruby_code_symbol_ref12[] PROGMEM ="HIGH";
const char mmruby_code_symbol_ref13[] PROGMEM ="LOW";
const char mmruby_code_symbol_ref14[] PROGMEM ="+";
const char mmruby_code_symbol_ref15[] PROGMEM ="===";
const char mmruby_code_symbol_ref16[] PROGMEM ="<<";
const char mmruby_code_symbol_ref17[] PROGMEM ="[]";
const char mmruby_code_symbol_ref18[] PROGMEM ="[]=";
const char mmruby_code_symbol_ref19[] PROGMEM ="()";
const char mmruby_code_symbol_ref1a[] PROGMEM ="-";
const char mmruby_code_symbol_ref1b[] PROGMEM =">>";
const char mmruby_code_symbol_ref1c[] PROGMEM ="led";
const char mmruby_code_symbol_ref1d[] PROGMEM ="btn";
const char mmruby_code_symbol_ref1e[] PROGMEM ="==";
const char mmruby_code_symbol_ref1f[] PROGMEM ="out";
const char mmruby_code_symbol_ref20[] PROGMEM ="wait";
const char mmruby_code_symbol_ref21[] PROGMEM ="puts";
const char mmruby_code_symbol_ref22[] PROGMEM ="!";
const char mmruby_code_symbol_ref23[] PROGMEM ="!=";
const char mmruby_code_symbol_ref24[] PROGMEM ="<=>";
const char mmruby_code_symbol_ref25[] PROGMEM ="class";
const char mmruby_code_symbol_ref26[] PROGMEM ="attr_reader";
const char mmruby_code_symbol_ref27[] PROGMEM ="attr_accessor";
const char mmruby_code_symbol_ref28[] PROGMEM ="in";
const char mmruby_code_symbol_ref29[] PROGMEM ="ana";
const char mmruby_code_symbol_ref2a[] PROGMEM ="pwm";
const char mmruby_code_symbol_ref2b[] PROGMEM ="cls";
const char mmruby_code_symbol_ref2c[] PROGMEM ="lc";
const char mmruby_code_symbol_ref2d[] PROGMEM ="scr";
const char mmruby_code_symbol_ref2e[] PROGMEM ="inkey";
const char mmruby_code_symbol_ref2f[] PROGMEM ="rnd";
const char mmruby_code_symbol_ref30[] PROGMEM ="print";
const char mmruby_code_symbol_ref31[] PROGMEM ="call";
const char mmruby_code_symbol_ref32[] PROGMEM ="-@";
const char mmruby_code_symbol_ref33[] PROGMEM ="**";
const char mmruby_code_symbol_ref34[] PROGMEM ="%";
const char mmruby_code_symbol_ref35[] PROGMEM ="&";
const char mmruby_code_symbol_ref36[] PROGMEM ="|";
const char mmruby_code_symbol_ref37[] PROGMEM ="^";
const char mmruby_code_symbol_ref38[] PROGMEM ="~";
const char mmruby_code_symbol_ref39[] PROGMEM ="abs";
const char mmruby_code_symbol_ref3a[] PROGMEM ="times";
const char mmruby_code_symbol_ref3b[] PROGMEM ="chr";
const char mmruby_code_symbol_ref3c[] PROGMEM ="to_i";
const char mmruby_code_symbol_ref3d[] PROGMEM ="all_symbols";
const char mmruby_code_symbol_ref3e[] PROGMEM ="id2name";
const char mmruby_code_symbol_ref3f[] PROGMEM ="to_sym";

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
  mmruby_code_symbol_ref3d,
  mmruby_code_symbol_ref3e,
  mmruby_code_symbol_ref3f,
};

