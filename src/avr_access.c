#include <stdint.h>
#include <string.h>
//#include <Arduino.h>
//#include <avr/pgmspace.h>

#include "value.h"
#include "micro_vm.h"
#include "opcode.h"
#include "class.h"
#include "console.h"
#include "symbol.h"
#include "debug.h"

//external functions
#include "c_object.h"
#include "c_fixnum.h"
#include "c_string.h"
#include "c_common.h"
#include "ext.h"

//dynaic code generation
#define PROGMEM
#include "code.h"

#include "avr_access.h"

//inline static void memcpy_pgm2ram(uint8_t* buff, short pgm_p, uint16_t len){
inline static void memcpy_pgm2ram(uint8_t* buff, uint8_t* pgm_p, uint16_t len){
  int i=0;
  for(i=0;i<len;i++){
    buff[i] = pgm_read_byte_near( pgm_p+i );
  }
  buff[i]='\0';
}

//inline static void strcpy_pgm2ram(char* buff, short pgm_p){
inline static void strcpy_pgm2ram(char* buff, char* pgm_p){
  int i=0;
  for(i=0;i<MAX_SYMBOL_LEN;i++){
    char c = pgm_read_byte_near( pgm_p+i );
    buff[i] = c;
    if(c=='\0') break;
  }
}

// MIREP_HEADER_SIZE == 4, CODE_LEN == 4
uint32_t read_bytecode(mrb_irep_id irep_id, uint8_t pc){
//  printf("%d %d %d\n", mmruby_code_irep_table[irep_id], mmruby_code_irep_000, pgm_read_word_near(&mmruby_code_irep_table[irep_id]) + MIREP_HEADER_SIZE + pc*CODE_LEN);
  //return pgm_read_dword_near( pgm_read_word_near(&mmruby_code_irep_table[irep_id]) + MIREP_HEADER_SIZE + pc*CODE_LEN );
  //return *(uint32_t*)(mmruby_code_irep_000 + MIREP_HEADER_SIZE + pc * CODE_LEN);
  return *(uint32_t*)(mmruby_code_irep_table[irep_id] + MIREP_HEADER_SIZE + pc * CODE_LEN);
}

void get_irep_pool(uint8_t* buff, uint16_t* obj_size, mrb_irep_id irep_id, uint8_t no){
  uint16_t size=0;
//  short irep_addr = pgm_read_word_near(&mmruby_code_irep_table[irep_id]);
  const uint8_t* irep_addr = mmruby_code_irep_table[irep_id];
  uint8_t code_len = pgm_read_byte_near( irep_addr + MIREP_OFFSET_ILEN ) * CODE_LEN;
  uint8_t plen = pgm_read_byte_near( irep_addr + MIREP_OFFSET_PLEN );
  if(no > plen-1){
    DEBUG_FPRINTLN("ERROR no>plen");
    return;
  }
  int i;
  uint8_t p = 0;
  uint8_t tt = 0;
  short obj_p = 0;
  for(i=0;i<=no;i++){ //Num begins from 0
    tt = pgm_read_byte_near( irep_addr + MIREP_HEADER_SIZE + code_len + p);
    p++;
    uint16_t bin = pgm_read_word_near( irep_addr + MIREP_HEADER_SIZE + code_len + p);
    size = bin_to_uint16( &bin );
    p += 2;
    obj_p = p;
    p += size;
  }
  if(obj_size!=NULL) *obj_size = size;
  memcpy_pgm2ram(buff, irep_addr + MIREP_HEADER_SIZE + code_len + obj_p, size);
  return;
}

mrb_irep_id get_irep_irep_id(mrb_irep_id irep_id,uint8_t no){
//  short irep_addr = pgm_read_word_near(&mmruby_code_irep_table[irep_id]);
  const uint8_t* irep_addr = mmruby_code_irep_table[irep_id];
  uint8_t code_len = pgm_read_byte_near( irep_addr + MIREP_OFFSET_ILEN ) * CODE_LEN;
  uint8_t plen = pgm_read_byte_near( irep_addr + MIREP_OFFSET_PLEN );
  uint8_t slen = pgm_read_byte_near( irep_addr + MIREP_OFFSET_SLEN );
  return pgm_read_byte_near( irep_addr + MIREP_HEADER_SIZE + code_len + plen + slen + no);
}

//read_symbol
mrb_sym get_irep_symbol_id(mrb_irep_id irep_id, uint8_t no){
  //short irep_addr = pgm_read_word_near(&mmruby_code_irep_table[irep_id]);
  const uint8_t* irep_addr = mmruby_code_irep_table[irep_id];
  uint8_t code_len = pgm_read_byte_near( irep_addr + MIREP_OFFSET_ILEN ) * CODE_LEN;
  uint8_t plen = pgm_read_byte_near( irep_addr + MIREP_OFFSET_PLEN );
  return pgm_read_byte_near( irep_addr + MIREP_HEADER_SIZE + code_len + plen + no);
}

uint8_t get_max_static_symbol_id(){
  return pgm_read_byte_near(&mmruby_code_symbol_table_size);
}

mrb_sym search_index_static(const char *str){
  char buff[MAX_SYMBOL_LEN];
  uint8_t max = pgm_read_byte_near(&mmruby_code_symbol_table_size);
  int i;
  for(i=0;i<max;i++){
    //short addr = pgm_read_word_near(&mmruby_code_symbol_table[i]);
    const char* addr = mmruby_code_symbol_table[i];
//    strcpy_pgm2ram(buff, addr);
//printf("search_index_static %s %s\n", str, addr); 
    if(0 == strcmp(str, addr)){
      if(i==0)return INVALID_SYMBOL; //str is null char
      return i;
    }
  }
  return INVALID_SYMBOL;
}

void copy_symbol_str(char* buff, mrb_sym sym_id){
//  short addr = pgm_read_word_near(&mmruby_code_symbol_table[sym_id]);
  const char* addr = mmruby_code_symbol_table[sym_id];
  strcpy_pgm2ram(buff, addr);
}

short find_func_no_by_sym_id(const uint8_t* addr,mrb_sym target_sym_id){
  int i=0;
  uint8_t v=0;
  while(1){
    mrb_sym sym_id = pgm_read_byte_near( addr + i*2 );
    if(sym_id == target_sym_id) return (short)pgm_read_byte_near( addr + i*2 +1 ); //addr > 0
    if(sym_id == 0) return 0;
    i++;
  }
  return 0;
}

mrb_func_t find_c_funcs(mrb_proc* proc){
  return find_c_funcs_by_no((short)proc);
}

xinline mrb_proc *find_static_procs(mrb_sym class_sym_id, mrb_sym sym_id){
  short addr=0;
  //cprintf(" class %d %d\n",class_sym_id,sym_id);
  switch(class_sym_id){
  case MRBC_SSYM_Object:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Object , sym_id);
    break;
  case MRBC_SSYM_Proc:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Proc , sym_id);
    break;
  case MRBC_SSYM_False:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_False , sym_id);
    break;
  case MRBC_SSYM_True:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_True , sym_id);
    break;
  case MRBC_SSYM_Nil:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Nil , sym_id);
    break;
  case MRBC_SSYM_Array:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Array , sym_id);
    break;
  case MRBC_SSYM_Fixnum:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Fixnum , sym_id);
    break;
  case MRBC_SSYM_String:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_String , sym_id);
    break;
  case MRBC_SSYM_Symbol:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Symbol , sym_id);
    break;
  case MRBC_SSYM_Range:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Range , sym_id);
    break;
#ifdef USE_ARDUINO
  case MRBC_SSYM_Arduino:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_Arduino , sym_id);
    break;
#endif
#ifdef USE_RGB_LCD
  case MRBC_SSYM_RGB_LCD:
    addr = (short)find_func_no_by_sym_id( mmruby_code_proc_table_RGB_LCD , sym_id);
    break;
#endif
  default:
    addr=0;
    break;
  }

  return (mrb_proc*)(addr);
}

