/*--------------------------------------------------------------/
/  Startup Module for NXP LPC1100 Microcontrollers              /
/                                                               /
/ * This module defines vector table, startup code, default     /
/   exception handlers, main stack and miscellanous functions.  /
/ * This file is a non-copyrighted public domain software.      /
/--------------------------------------------------------------*/

#include "LPC1100.h"

/*-------------------------------------------------------------------*/
/* Basic Configurations                                              */

#define STACK_SIZE	1024	/* Stack size (Must be multiple of 8. If zero, MSP is set to last RAM address) */

#define	CLK_SEL	3			/* Main clock selection = 0:IRC(12MHz), 1:PLL-in, 2:WDT or 3:PLL-out */
#define OSC_SEL	0			/* PLL input selection = 0:IRC osc or 1:Main osc */
#define	F_OSC	12000000	/* Oscillator frequency */
#define PLL_M	4			/* PLL multiplier = 1..32 */
#define	MCLK	48000000	/* Expected main clock frequency = F_OSC * (CLK_SEL == 3 ? PLL_M : 1) */
#define	SYSCLK	(MCLK / 1)	/* System clock frequency */

/*-------------------------------------------------------------------*/


#if MCLK != F_OSC * (CLK_SEL == 3 ? PLL_M : 1)
#error MCLK does not match calcurated value
#endif

#if CLK_SEL == 3
#if F_OSC < 10000000 || F_OSC > 25000000
#error F_OSC is out of range for PLL input
#endif
#if MCLK * 2 >= 156000000
#define P_SEL 0
#elif MCLK * 4 >= 156000000
#define P_SEL 1
#elif MCLK * 8 >= 156000000
#define P_SEL 2
#else
#define P_SEL 3
#endif
#endif

#if   SYSCLK <= 20000000
#define FLASH_WAIT 0
#elif SYSCLK <= 40000000
#define FLASH_WAIT 1
#else
#define FLASH_WAIT 2
#endif



/*--------------------------------------------------------------------/
/ Declareations                                                       /
/--------------------------------------------------------------------*/

/* Section address defined in linker script */
extern long _sidata[], _sdata[], _edata[], _sbss[], _ebss[], _endof_sram[];
extern int main (void);

/* Exception/IRQ Handlers */
void Reset_Handler (void)		__attribute__ ((noreturn, naked));
void NMI_Handler (void)			__attribute__ ((weak, alias ("Exception_Trap")));
void HardFault_Hander (void)	__attribute__ ((weak, alias ("Exception_Trap")));
void SVC_Handler (void)			__attribute__ ((weak, alias ("Exception_Trap")));
void PendSV_Handler (void)		__attribute__ ((weak, alias ("Exception_Trap")));
void SysTick_Handler (void)		__attribute__ ((weak, alias ("Exception_Trap")));
void PIO0_0_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_1_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_2_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_3_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_4_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_5_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_6_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_7_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_8_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_9_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_10_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO0_11_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO1_0_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void C_CAN_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void SPI1_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void I2C_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void CT16B0_IRQHandler	(void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void CT16B1_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void CT32B0_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void CT32B1_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void SPI0_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void UART_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void ADC_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void WDT_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void BOD_IRQHandler (void)		__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO_3_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO_2_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO_1_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));
void PIO_0_IRQHandler (void)	__attribute__ ((weak, alias ("IRQ_Trap")));



/*--------------------------------------------------------------------/
/ Main Stack                                                          /
/--------------------------------------------------------------------*/

#if STACK_SIZE > 0
static
char mstk[STACK_SIZE] __attribute__ ((aligned(8), section(".STACK")));
#define INITIAL_MSP	&mstk[STACK_SIZE]
#else
#define INITIAL_MSP	_endof_sram
#endif



/*--------------------------------------------------------------------/
/ Exception Vector Table                                              /
/--------------------------------------------------------------------*/

void* const vector[] __attribute__ ((section(".VECTOR"))) =
{
	INITIAL_MSP,	/* Initial value of MSP */
	Reset_Handler,
	NMI_Handler,
	HardFault_Hander,
	0,
	0,
	0,
	0,	/* Checksum for the entry 0 to 7 (set by flash programmer) */
	0,
	0,
	0,
	SVC_Handler,
	0,
	0,
	PendSV_Handler,
	SysTick_Handler,

	PIO0_0_IRQHandler,
	PIO0_1_IRQHandler,
	PIO0_2_IRQHandler,
	PIO0_3_IRQHandler,
	PIO0_4_IRQHandler,
	PIO0_5_IRQHandler,
	PIO0_6_IRQHandler,
	PIO0_7_IRQHandler,
	PIO0_8_IRQHandler,
	PIO0_9_IRQHandler,
	PIO0_10_IRQHandler,
	PIO0_11_IRQHandler,
	PIO1_0_IRQHandler,
	C_CAN_IRQHandler,
	SPI1_IRQHandler,
	I2C_IRQHandler,
	CT16B0_IRQHandler,
	CT16B1_IRQHandler,
	CT32B0_IRQHandler,
	CT32B1_IRQHandler,
	SPI0_IRQHandler,
	UART_IRQHandler,
	0,
	0,
	ADC_IRQHandler,
	WDT_IRQHandler,
	BOD_IRQHandler,
	0,
	PIO_3_IRQHandler,
	PIO_2_IRQHandler,
	PIO_1_IRQHandler,
	PIO_0_IRQHandler
};



/*---------------------------------------------------------------------/
/ Reset_Handler is the start-up routine. It configures processor core, /
/ system clock generator then initialize .data and .bss sections and   /
/ then start main().                                                   /
/---------------------------------------------------------------------*/

void Reset_Handler (void)
{
	long *s, *d;

	/* Configure BOD control (Reset on Vcc dips below 2.7V) */
	BODCTRL = 0x13;

	/* Configure system clock generator */

	MAINCLKSEL = 0;		/* Select IRC as main clock */
	MAINCLKUEN = 0; MAINCLKUEN = 1;

	FLASHCFG = (FLASHCFG & 0xFFFFFFFC) | FLASH_WAIT;	/* Configure flash access timing */

#if CLK_SEL == 1 || (CLK_SEL == 3 && OSC_SEL == 1) 		/* Configure main oscillator if needed */
	SYSOSCCTRL = (F_OSC >= 17500000) ? 2 : 0;
	PDRUNCFG &= ~0x20;
#endif
#if CLK_SEL == 2		/* Enable WDT oscillator if needed */
	PDRUNCFG &= ~0x40;
#endif
#if CLK_SEL == 3	/* Configure PLL if needed */
	SYSPLLCLKSEL = OSC_SEL;
	SYSPLLCLKUEN = 0; SYSPLLCLKUEN = 1;
	SYSPLLCTRL = (PLL_M - 1) | (P_SEL << 6);
	PDRUNCFG &= ~0x80;
	while ((SYSPLLSTAT & 1) == 0) ;
#endif

	SYSAHBCLKDIV = MCLK / SYSCLK;	/* Select system clock divisor */
	MAINCLKSEL = CLK_SEL;				/* Select desired main clock source */
	MAINCLKUEN = 0; MAINCLKUEN = 1;

	SYSAHBCLKCTRL = 0x1005F;		/* Enable clock for only SYS, ROM, RAM, FLASH, GPIO and IOCON */


	/* Initialize .data/.bss section and static objects get ready to use after this process */
	for (s = _sidata, d = _sdata; d < _edata; *d++ = *s++) ;
	for (d = _sbss; d < _ebss; *d++ = 0) ;


	main();		/* Start main() with MSP */

	for (;;) ;
}



/*--------------------------------------------------------------------/
/ Unexpected Exception/IRQ Trap                                       /
/--------------------------------------------------------------------*/

void Exception_Trap (void)
{
	GPIO1DATA &= ~_BV(5);	// Blue
	for (;;) ;
}


void IRQ_Trap (void)
{
	GPIO2DATA &= ~_BV(0);	// Red
	for (;;) ;
}

