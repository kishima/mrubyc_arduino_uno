#include "../src/ext_conf.h"

static const char* const basic_class_names[] = {
  "Object",
  "Proc",
  "False",
  "True",
  "Nil",
  "Array",
  "Fixnum",
  "String",
  "Symbol",
  "Range",
#ifdef USE_ARDUION
  "Arduino",
#endif
#ifdef USE_RGB_LCD
  "RGB_LCD",
#endif
};

static const char* const static_procs[] = {
  //class name => sym_id, Ruby method name => sym_id, C func name,
  "Object","puts","c_puts",
  "Object","!","c_object_not",
  "Object","!=","c_object_neq",
  "Object","<=>","c_object_compare",
  "Object","to_s","c_object_to_s",
  //"Object","new","c_object_new",
  "Object","class","c_object_class",
  "Object","attr_reader","c_object_attr_reader",
  "Object","attr_accessor","c_object_attr_accessor",

  // add by taisukef
  "Object","led","c_object_led",
  "Object","wait","c_object_wait",
  "Object","out","c_object_out",
  "Object","in","c_object_in",
  "Object","in","c_object_ana",
  "Object","in","c_object_pwm",
  "Object","cls","c_object_cls",
  "Object","lc","c_object_lc",
  "Object","scr","c_object_scr",
  "Object","inkey","c_object_inkey",
  "Object","rnd","c_object_rnd",
  "Object","print","c_object_print",

  "Fixnum","[]","c_fixnum_bitref",
  "Fixnum","-@","c_fixnum_negative",
  "Fixnum","**","c_fixnum_power",
  "Fixnum","%","c_fixnum_mod",
  "Fixnum","&","c_fixnum_and",
  "Fixnum","|","c_fixnum_or",
  "Fixnum","^","c_fixnum_xor",
  "Fixnum","~","c_fixnum_not",
  "Fixnum","<<","c_fixnum_lshift",
  "Fixnum",">>","c_fixnum_rshift",
  "Fixnum","abs","c_fixnum_abs",
  "Fixnum","times","c_fixnum_times",
  "Fixnum","chr","c_fixnum_chr",
  "Fixnum","to_i","c_ineffect",
  "Fixnum","to_s","c_fixnum_to_s",

  "Proc","call","c_proc_call",
  "Proc","to_s","c_proc_to_s",
  "Nil","to_s","c_nil_to_s",
  "False","to_s","c_false_to_s",
  "True","to_s","c_true_to_s",

  "Symbol","to_s","c_true_to_s",

  "String","all_symbols","c_all_symbols",
  "String","to_s","c_to_s",
  "String","id2name","c_to_s",
  "String","to_sym","c_ineffect",

#ifdef USE_ARDUINO
  "Arduino","delay","class_arduino_delay",
  "Arduino","pin_mode","class_arduino_pin_mode",
  "Arduino","digital_write","class_arduino_digital_write",
  "Arduino","digital_read","class_arduino_digital_read",
#endif

#ifdef USE_RGB_LCD
  "RGB_LCD","initialize","class_rbg_lcd_initialize",
  "RGB_LCD","clear","class_rbg_lcd_clear",
  "RGB_LCD","set_cursor","class_rbg_lcd_set_cursor",
  "RGB_LCD","write","class_rbg_lcd_write",
  "RGB_LCD","set_rgb","class_rbg_lcd_set_rgb",
#endif
  
  "","","",//don't delete this line
};

