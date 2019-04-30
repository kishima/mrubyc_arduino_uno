#include "mmruby_lpc1114.h"
#include "LPC1100.h"
#include "ext.h"

void main() {
	ext_init();
	
	mmruby_setup();
	mmruby_run();
}

// for standard
/*
int _kill() {
	return 0;
}
int _getpid() {
	return 0;
}
void _exit(__attribute__((unused)) int n) {
    for (;;)
        ;
}
void* _sbrk(__attribute__((unused)) int incr) {
    return (void*)0x10000000;
}

// for compiler
void _write() {
}
void _close() {
}
void _lseek() {
}
void _read() {
}
void _fstat() {
}
void _isatty() {
}
*/
