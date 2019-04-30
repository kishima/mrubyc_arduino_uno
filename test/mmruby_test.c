#include <stdio.h>
#include "memman.h"
#include "debug.h"
#include "ext.h"
#include "micro_vm.h"
#include "symbol.h"
#include "class.h"

void not_supported() {
	printf("not supported()\n");
}

int main() {
	memman_init();
	ext_init();

	init_symbol_table();
	mrbc_init_class();
	init_vm();
	run_vm();
	return 0;
}
