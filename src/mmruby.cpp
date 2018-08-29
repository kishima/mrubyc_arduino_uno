#include "mmruby.h"
#include "micro_vm.h"
#include "class.h"
#include "hal.h"
#include "debug.h"

void mmruby_setup(){
  init_hal();
  init_vm();
  mrbc_init_class();
}


void mmruby_run(void){
  run_vm();
}

