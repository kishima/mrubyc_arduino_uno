#include "memman.h"
#include "hal.h"
#include "ext.h"
#include "micro_vm.h"
#include "symbol.h"
#include "class.h"

void main() {
	memman_init();
	hal_init();
	ext_init();

	init_symbol_table();
	mrbc_init_class();
	init_vm();
	run_vm();
}
