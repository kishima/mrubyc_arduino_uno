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

// ext by mmruby

void ext_led(int n) {
	if (n) {
		GPIO1DATA |= 1 << 5;
	} else {
		GPIO1DATA &= ~(1 << 5);
	}
}
void ext_wait(int n) {
	wait(n * 16);
}
int ext_btn() {
	return !(GPIO1DATA & (1 << 4));
}

//
void ext_init() {
	InitSysTick(1000);
	
	IOCON_PIO1_5 = 0xd0; // digital out
	GPIO1DIR = 1 << 5;

	IOCON_PIO1_4 = 0xd0; // digital in
}

	/*
	for (;;) {
		GPIO1DATA |= 1 << 5;
		wait(100);
		GPIO1DATA &= ~(1 << 5);
		wait(1000);
	}
	*/
