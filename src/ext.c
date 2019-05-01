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
void ext_out(int n, int m) {
	if (n < 1 || n > 4)
		return;
	n--;
	if (m) {
		GPIO1DATA |= 1 << n;
	} else {
		GPIO1DATA &= ~(1 << n);
	}
}

//
void ext_init() {
	InitSysTick(1000);
	
	IOCON_PIO1_5 = 0xd0; // digital out // LED

	IOCON_R_PIO1_0 = 0xd1; // digital out
	IOCON_R_PIO1_1 = 0xd1; // digital out
	IOCON_R_PIO1_2 = 0xd1; // digital out
	IOCON_SWDIO_PIO1_3 = 0xd1; // digital out

	GPIO1DIR = 0b101111;
	GPIO1DATA &= ~0b101111;
	
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
