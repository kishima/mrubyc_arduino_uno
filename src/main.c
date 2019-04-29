#include "mmruby_lpc1114.h"
#include "LPC1100.h"

// SysTick
volatile int systick = 0;
void InitSysTick(int hz) {
	SYST_RVR = 48000000 / hz - 1;
	SYST_CSR = 0x07;
}
void SysTick_Handler(void) {
	systick++;
}
void wait(int n) {
	int endt = systick + n;
	for (;;) {
		if (systick > endt)
			break;
	}
}

// emb by mmruby

void emb_led(int n) {
	if (n) {
		GPIO1DATA |= 1 << 5;
	} else {
		GPIO1DATA &= ~(1 << 5);
	}
}
void emb_wait(int n) {
	wait(n * 16);
}

// main

void main() {
	InitSysTick(1000);
	
	IOCON_PIO1_5 = 0x000000d0;
	GPIO1DIR = 1 << 5;
	
	mmruby_setup();
	mmruby_run();

	for (;;) {
		GPIO1DATA |= 1 << 5;
		wait(100);
		GPIO1DATA &= ~(1 << 5);
		wait(1000);
	}
}

// for standard
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
