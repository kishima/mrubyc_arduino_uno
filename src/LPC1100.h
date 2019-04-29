/*-----------------------------------------------------------*/
/* LPC1100 Register Definitions                              */
/* This file is a non-copyrighted public domain software.    */
/*-----------------------------------------------------------*/

#ifndef __LPC1100
#define __LPC1100
#include <stdint.h>

/* System Configuration*/
#define SYSMEMREMAP		(*(volatile uint32_t*)0x40048000)
#define PRESETCTRL		(*(volatile uint32_t*)0x40048004)
#define SYSPLLCTRL		(*(volatile uint32_t*)0x40048008)
#define SYSPLLSTAT		(*(volatile uint32_t*)0x4004800C)
#define SYSOSCCTRL		(*(volatile uint32_t*)0x40048020)
#define WDTOSCCTRL		(*(volatile uint32_t*)0x40048024)
#define IRCCTRL			(*(volatile uint32_t*)0x40048028)
#define SYSRSTSTAT		(*(volatile uint32_t*)0x40048030)
#define SYSPLLCLKSEL	(*(volatile uint32_t*)0x40048040)
#define SYSPLLCLKUEN	(*(volatile uint32_t*)0x40048044)
#define MAINCLKSEL		(*(volatile uint32_t*)0x40048070)
#define MAINCLKUEN		(*(volatile uint32_t*)0x40048074)
#define SYSAHBCLKDIV	(*(volatile uint32_t*)0x40048078)
#define SYSAHBCLKCTRL	(*(volatile uint32_t*)0x40048080)
#define SSP0CLKDIV		(*(volatile uint32_t*)0x40048094)
#define UARTCLKDIV		(*(volatile uint32_t*)0x40048098)
#define SSP1CLKDIV		(*(volatile uint32_t*)0x4004809C)
#define WDTCLKSEL		(*(volatile uint32_t*)0x400480D0)
#define WDTCLKUEN		(*(volatile uint32_t*)0x400480D4)
#define WDTCLKDIV		(*(volatile uint32_t*)0x400480D8)
#define CLKOUTCLKSEL	(*(volatile uint32_t*)0x400480E0)
#define CLKOUTUEN		(*(volatile uint32_t*)0x400480E4)
#define CLKOUTCLKDIV	(*(volatile uint32_t*)0x400480E8)
#define PIOPORCAP0		(*(volatile uint32_t*)0x40048100)
#define PIOPORCAP1		(*(volatile uint32_t*)0x40048104)
#define BODCTRL			(*(volatile uint32_t*)0x40048150)
#define SYSTCKCAL		(*(volatile uint32_t*)0x40048154)
#define STARTAPRP0		(*(volatile uint32_t*)0x40048200)
#define STARTERP0		(*(volatile uint32_t*)0x40048204)
#define STARTRSRP0CLR	(*(volatile uint32_t*)0x40048208)
#define STARTSRP0		(*(volatile uint32_t*)0x4004820C)
#define PDSLEEPCFG		(*(volatile uint32_t*)0x40048230)
#define PDAWAKECFG		(*(volatile uint32_t*)0x40048234)
#define PDRUNCFG		(*(volatile uint32_t*)0x40048238)
#define DEVICE_ID		(*(volatile uint32_t*)0x400483F4)
#define FLASHCFG		(*(volatile uint32_t*)0x4003C010)

/* Power Monitor Unit*/
#define PCON			(*(volatile uint32_t*)0x40038000)
#define GPREG			( (volatile uint32_t*)0x40038004)
#define GPREG0			(*(volatile uint32_t*)0x40038004)
#define GPREG1			(*(volatile uint32_t*)0x40038008)
#define GPREG2			(*(volatile uint32_t*)0x4003800C)
#define GPREG3			(*(volatile uint32_t*)0x40038010)
#define GPREG4			(*(volatile uint32_t*)0x40038014)

/* I/O Configuration*/
#define IOCON_PIO2_6	(*(volatile uint32_t*)0x40044000)
#define IOCON_PIO2_0	(*(volatile uint32_t*)0x40044008)
#define IOCON_RESET_PIO0_0	(*(volatile uint32_t*)0x4004400C)
#define IOCON_PIO0_1	(*(volatile uint32_t*)0x40044010)
#define IOCON_PIO1_8	(*(volatile uint32_t*)0x40044014)
#define IOCON_PIO0_2	(*(volatile uint32_t*)0x4004401C)
#define IOCON_PIO2_7	(*(volatile uint32_t*)0x40044020)
#define IOCON_PIO2_8	(*(volatile uint32_t*)0x40044024)
#define IOCON_PIO2_1	(*(volatile uint32_t*)0x40044028)
#define IOCON_PIO0_3	(*(volatile uint32_t*)0x4004402C)
#define IOCON_PIO0_4	(*(volatile uint32_t*)0x40044030)
#define IOCON_PIO0_5	(*(volatile uint32_t*)0x40044034)
#define IOCON_PIO1_9	(*(volatile uint32_t*)0x40044038)
#define IOCON_PIO3_4	(*(volatile uint32_t*)0x4004403C)
#define IOCON_PIO2_4	(*(volatile uint32_t*)0x40044040)
#define IOCON_PIO2_5	(*(volatile uint32_t*)0x40044044)
#define IOCON_PIO3_5	(*(volatile uint32_t*)0x40044048)
#define IOCON_PIO0_6	(*(volatile uint32_t*)0x4004404C)
#define IOCON_PIO0_7	(*(volatile uint32_t*)0x40044050)
#define IOCON_PIO2_9	(*(volatile uint32_t*)0x40044054)
#define IOCON_PIO2_10	(*(volatile uint32_t*)0x40044058)
#define IOCON_PIO2_2	(*(volatile uint32_t*)0x4004405C)
#define IOCON_PIO0_8	(*(volatile uint32_t*)0x40044060)
#define IOCON_PIO0_9	(*(volatile uint32_t*)0x40044064)
#define IOCON_SWCLK_PIO0_10	(*(volatile uint32_t*)0x40044068)
#define IOCON_PIO1_10	(*(volatile uint32_t*)0x4004406C)
#define IOCON_PIO2_11	(*(volatile uint32_t*)0x40044070)
#define IOCON_R_PIO0_11	(*(volatile uint32_t*)0x40044074)
#define IOCON_R_PIO1_0	(*(volatile uint32_t*)0x40044078)
#define IOCON_R_PIO1_1	(*(volatile uint32_t*)0x4004407C)
#define IOCON_R_PIO1_2	(*(volatile uint32_t*)0x40044080)
#define IOCON_PIO3_0	(*(volatile uint32_t*)0x40044084)
#define IOCON_PIO3_1	(*(volatile uint32_t*)0x40044088)
#define IOCON_PIO2_3	(*(volatile uint32_t*)0x4004408C)
#define IOCON_SWDIO_PIO1_3	(*(volatile uint32_t*)0x40044090)
#define IOCON_PIO1_4	(*(volatile uint32_t*)0x40044094)
#define IOCON_PIO1_11	(*(volatile uint32_t*)0x40044098)
#define IOCON_PIO3_2	(*(volatile uint32_t*)0x4004409C)
#define IOCON_PIO1_5	(*(volatile uint32_t*)0x400440A0)
#define IOCON_PIO1_6	(*(volatile uint32_t*)0x400440A4)
#define IOCON_PIO1_7	(*(volatile uint32_t*)0x400440A8)
#define IOCON_PIO3_3	(*(volatile uint32_t*)0x400440AC)
#define IOCON_SCK_LOC	(*(volatile uint32_t*)0x400440B0)
#define IOCON_DSR_LOC	(*(volatile uint32_t*)0x400440B4)
#define IOCON_DCD_LOC	(*(volatile uint32_t*)0x400440B8)
#define IOCON_RI_LOC	(*(volatile uint32_t*)0x400440BC)


/* GPIO0,GPIO1,GPIO2 */
#define GPIO0MASKED		( (volatile uint32_t*)0x50000000)
#define GPIO0DATA		(*(volatile uint32_t*)0x50003FFC)
#define GPIO0DIR		(*(volatile uint32_t*)0x50008000)
#define GPIO0IS			(*(volatile uint32_t*)0x50008004)
#define GPIO0IBE		(*(volatile uint32_t*)0x50008008)
#define GPIO0IEV		(*(volatile uint32_t*)0x5000800C)
#define GPIO0IE			(*(volatile uint32_t*)0x50008010)
#define GPIO0RIS		(*(volatile uint32_t*)0x50008014)
#define GPIO0MIS		(*(volatile uint32_t*)0x50008018)
#define GPIO0IC			(*(volatile uint32_t*)0x5000801C)
#define GPIO1MASKED		( (volatile uint32_t*)0x50010000)
#define GPIO1DATA		(*(volatile uint32_t*)0x50013FFC)
#define GPIO1DIR		(*(volatile uint32_t*)0x50018000)
#define GPIO1IS			(*(volatile uint32_t*)0x50018004)
#define GPIO1IBE		(*(volatile uint32_t*)0x50018008)
#define GPIO1IEV		(*(volatile uint32_t*)0x5001800C)
#define GPIO1IE			(*(volatile uint32_t*)0x50018010)
#define GPIO1RIS		(*(volatile uint32_t*)0x50018014)
#define GPIO1MIS		(*(volatile uint32_t*)0x50018018)
#define GPIO1IC			(*(volatile uint32_t*)0x5001801C)
#define GPIO2MASKED		( (volatile uint32_t*)0x50020000)
#define GPIO2DATA		(*(volatile uint32_t*)0x50023FFC)
#define GPIO2DIR		(*(volatile uint32_t*)0x50028000)
#define GPIO2IS			(*(volatile uint32_t*)0x50028004)
#define GPIO2IBE		(*(volatile uint32_t*)0x50028008)
#define GPIO2IEV		(*(volatile uint32_t*)0x5002800C)
#define GPIO2IE			(*(volatile uint32_t*)0x50028010)
#define GPIO2RIS		(*(volatile uint32_t*)0x50028014)
#define GPIO2MIS		(*(volatile uint32_t*)0x50028018)
#define GPIO2IC			(*(volatile uint32_t*)0x5002801C)
#define GPIO3MASKED		( (volatile uint32_t*)0x50030000)
#define GPIO3DATA		(*(volatile uint32_t*)0x50033FFC)
#define GPIO3DIR		(*(volatile uint32_t*)0x50038000)
#define GPIO3IS			(*(volatile uint32_t*)0x50038004)
#define GPIO3IBE		(*(volatile uint32_t*)0x50038008)
#define GPIO3IEV		(*(volatile uint32_t*)0x5003800C)
#define GPIO3IE			(*(volatile uint32_t*)0x50038010)
#define GPIO3RIS		(*(volatile uint32_t*)0x50038014)
#define GPIO3MIS		(*(volatile uint32_t*)0x50038018)
#define GPIO3IC			(*(volatile uint32_t*)0x5003801C)

/* UART0 */
#define	U0RBR			(*(volatile uint32_t*)0x40008000)
#define	U0THR			(*(volatile uint32_t*)0x40008000)
#define	U0DLL			(*(volatile uint32_t*)0x40008000)
#define	U0DLM			(*(volatile uint32_t*)0x40008004)
#define	U0IER			(*(volatile uint32_t*)0x40008004)
#define	U0IIR			(*(volatile uint32_t*)0x40008008)
#define	U0FCR			(*(volatile uint32_t*)0x40008008)
#define	U0LCR			(*(volatile uint32_t*)0x4000800C)
#define	U0MCR			(*(volatile uint32_t*)0x40008010)
#define	U0LSR			(*(volatile uint32_t*)0x40008014)
#define	U0MSR			(*(volatile uint32_t*)0x40008018)
#define	U0SCR			(*(volatile uint32_t*)0x4000801C)
#define	U0ACR			(*(volatile uint32_t*)0x40008020)
#define	U0FDR			(*(volatile uint32_t*)0x40008028)
#define	U0TER			(*(volatile uint32_t*)0x40008030)
#define	U0RS485CTRL		(*(volatile uint32_t*)0x4000804C)
#define	U0RS485ADRMATCH	(*(volatile uint32_t*)0x40008050)
#define	U0RS485DLY		(*(volatile uint32_t*)0x40008054)

/* SPI0,SPI1*/
#define	SSP0CR0			(*(volatile uint32_t*)0x40040000)
#define	SSP0CR1			(*(volatile uint32_t*)0x40040004)
#define	SSP0DR			(*(volatile uint32_t*)0x40040008)
#define	SSP0SR			(*(volatile uint32_t*)0x4004000C)
#define	SSP0CPSR		(*(volatile uint32_t*)0x40040010)
#define	SSP0IMSC		(*(volatile uint32_t*)0x40040014)
#define	SSP0RIS			(*(volatile uint32_t*)0x40040018)
#define	SSP0MIS			(*(volatile uint32_t*)0x4004001C)
#define	SSP0ICR			(*(volatile uint32_t*)0x40040020)
#define	SSP1CR0			(*(volatile uint32_t*)0x40058000)
#define	SSP1CR1			(*(volatile uint32_t*)0x40058004)
#define	SSP1DR			(*(volatile uint32_t*)0x40058008)
#define	SSP1SR			(*(volatile uint32_t*)0x4005800C)
#define	SSP1CPSR		(*(volatile uint32_t*)0x40058010)
#define	SSP1IMSC		(*(volatile uint32_t*)0x40058014)
#define	SSP1RIS			(*(volatile uint32_t*)0x40058018)
#define	SSP1MIS			(*(volatile uint32_t*)0x4005801C)
#define	SSP1ICR			(*(volatile uint32_t*)0x40058020)

/* I2C*/
#define	I2C0CONSET		(*(volatile uint32_t*)0x40000000)
#define	I2C0STAT		(*(volatile uint32_t*)0x40000004)
#define	I2C0DAT			(*(volatile uint32_t*)0x40000008)
#define	I2C0ADR0		(*(volatile uint32_t*)0x4000000C)
#define	I2C0SCLH		(*(volatile uint32_t*)0x40000010)
#define	I2C0SCLL		(*(volatile uint32_t*)0x40000014)
#define	I2C0CONCLR		(*(volatile uint32_t*)0x40000018)
#define	I2C0MMCTRL		(*(volatile uint32_t*)0x4000001C)
#define	I2C0ADR			( (volatile uint32_t*)0x4000001C)
#define	I2C0ADR1		(*(volatile uint32_t*)0x40000020)
#define	I2C0ADR2		(*(volatile uint32_t*)0x40000024)
#define	I2C0ADR3		(*(volatile uint32_t*)0x40000028)
#define	I2C0DATA_BUFFER	(*(volatile uint32_t*)0x4000002C)
#define	I2C0MASK		( (volatile uint32_t*)0x40000030)
#define	I2C0MASK0		(*(volatile uint32_t*)0x40000030)
#define	I2C0MASK1		(*(volatile uint32_t*)0x40000034)
#define	I2C0MASK2		(*(volatile uint32_t*)0x40000038)
#define	I2C0MASK3		(*(volatile uint32_t*)0x4000003C)

/* CAN*/
#define CANCNTL			(*(volatile uint32_t*)0x40050000)
#define CANSTAT			(*(volatile uint32_t*)0x40050004)
#define CANEC			(*(volatile uint32_t*)0x40050008)
#define CANBT			(*(volatile uint32_t*)0x4005000C)
#define CANINT			(*(volatile uint32_t*)0x40050010)
#define CANTEST			(*(volatile uint32_t*)0x40050014)
#define CANBRPE			(*(volatile uint32_t*)0x40050018)
#define CANIF1_CMDREQ	(*(volatile uint32_t*)0x40050020)
#define CANIF1_CMDMSK	(*(volatile uint32_t*)0x40050024)
#define CANIF1_CMDMSK	(*(volatile uint32_t*)0x40050024)
#define CANIF1_MSK1		(*(volatile uint32_t*)0x40050028)
#define CANIF1_MSK2		(*(volatile uint32_t*)0x4005002C)
#define CANIF1_ARB1		(*(volatile uint32_t*)0x40050030)
#define CANIF1_ARB2		(*(volatile uint32_t*)0x40050034)
#define CANIF1_MCTRL	(*(volatile uint32_t*)0x40050038)
#define CANIF1_DA1		(*(volatile uint32_t*)0x4005003C)
#define CANIF1_DA2		(*(volatile uint32_t*)0x40050040)
#define CANIF1_DB1		(*(volatile uint32_t*)0x40050044)
#define CANIF1_DB2		(*(volatile uint32_t*)0x40050048)
#define CANIF2_CMDREQ	(*(volatile uint32_t*)0x40050080)
#define CANIF2_CMDMSK	(*(volatile uint32_t*)0x40050084)
#define CANIF2_MSK1		(*(volatile uint32_t*)0x40050088)
#define CANIF2_MSK2		(*(volatile uint32_t*)0x4005008C)
#define CANIF2_ARB1		(*(volatile uint32_t*)0x40050090)
#define CANIF2_ARB2		(*(volatile uint32_t*)0x40050094)
#define CANIF2_MCTRL	(*(volatile uint32_t*)0x40050098)
#define CANIF2_DA1		(*(volatile uint32_t*)0x4005009C)
#define CANIF2_DA2		(*(volatile uint32_t*)0x400500A0)
#define CANIF2_DB1		(*(volatile uint32_t*)0x400500A4)
#define CANIF2_DB2		(*(volatile uint32_t*)0x400500A8)
#define CANTXREQ1		(*(volatile uint32_t*)0x40050100)
#define CANTXREQ2		(*(volatile uint32_t*)0x40050104)
#define CANND1			(*(volatile uint32_t*)0x40050120)
#define CANND2			(*(volatile uint32_t*)0x40050124)
#define CANIR1			(*(volatile uint32_t*)0x40050140)
#define CANIR2			(*(volatile uint32_t*)0x40050144)
#define CANMSGV1		(*(volatile uint32_t*)0x40050160)
#define CANMSGV2		(*(volatile uint32_t*)0x40050164)
#define CANCLKDIV		(*(volatile uint32_t*)0x40050180)

/* 16-bit counter/timer*/
#define	TMR16B0IR		(*(volatile uint32_t*)0x4000C000)
#define	TMR16B0TCR		(*(volatile uint32_t*)0x4000C004)
#define	TMR16B0TC		(*(volatile uint32_t*)0x4000C008)
#define	TMR16B0PR		(*(volatile uint32_t*)0x4000C00C)
#define	TMR16B0PC		(*(volatile uint32_t*)0x4000C010)
#define	TMR16B0MCR		(*(volatile uint32_t*)0x4000C014)
#define	TMR16B0MR		( (volatile uint32_t*)0x4000C018)
#define	TMR16B0MR0		(*(volatile uint32_t*)0x4000C018)
#define	TMR16B0MR1		(*(volatile uint32_t*)0x4000C01C)
#define	TMR16B0MR2		(*(volatile uint32_t*)0x4000C020)
#define	TMR16B0MR3		(*(volatile uint32_t*)0x4000C024)
#define	TMR16B0CCR		(*(volatile uint32_t*)0x4000C028)
#define	TMR16B0CR0		(*(volatile uint32_t*)0x4000C02C)
#define	TMR16B0EMR		(*(volatile uint32_t*)0x4000C03C)
#define	TMR16B0CTCR		(*(volatile uint32_t*)0x4000C070)
#define	TMR16B0PWMC		(*(volatile uint32_t*)0x4000C074)
#define	TMR16B1IR		(*(volatile uint32_t*)0x40010000)
#define	TMR16B1TCR		(*(volatile uint32_t*)0x40010004)
#define	TMR16B1TC		(*(volatile uint32_t*)0x40010008)
#define	TMR16B1PR		(*(volatile uint32_t*)0x4001000C)
#define	TMR16B1PC		(*(volatile uint32_t*)0x40010010)
#define	TMR16B1MCR		(*(volatile uint32_t*)0x40010014)
#define	TMR16B1MR		( (volatile uint32_t*)0x40010018)
#define	TMR16B1MR0		(*(volatile uint32_t*)0x40010018)
#define	TMR16B1MR1		(*(volatile uint32_t*)0x4001001C)
#define	TMR16B1MR2		(*(volatile uint32_t*)0x40010020)
#define	TMR16B1MR3		(*(volatile uint32_t*)0x40010024)
#define	TMR16B1CCR		(*(volatile uint32_t*)0x40010028)
#define	TMR16B1CR0		(*(volatile uint32_t*)0x4001002C)
#define	TMR16B1EMR		(*(volatile uint32_t*)0x4001003C)
#define	TMR16B1CTCR		(*(volatile uint32_t*)0x40010070)
#define	TMR16B1PWMC		(*(volatile uint32_t*)0x40010074)

/* 32-bit timer/counter*/
#define	TMR32B0IR		(*(volatile uint32_t*)0x40014000)
#define	TMR32B0TCR		(*(volatile uint32_t*)0x40014004)
#define	TMR32B0TC		(*(volatile uint32_t*)0x40014008)
#define	TMR32B0PR		(*(volatile uint32_t*)0x4001400C)
#define	TMR32B0PC		(*(volatile uint32_t*)0x40014010)
#define	TMR32B0MCR		(*(volatile uint32_t*)0x40014014)
#define	TMR32B0MR		( (volatile uint32_t*)0x40014018)
#define	TMR32B0MR0		(*(volatile uint32_t*)0x40014018)
#define	TMR32B0MR1		(*(volatile uint32_t*)0x4001401C)
#define	TMR32B0MR2		(*(volatile uint32_t*)0x40014020)
#define	TMR32B0MR3		(*(volatile uint32_t*)0x40014024)
#define	TMR32B0CCR		(*(volatile uint32_t*)0x40014028)
#define	TMR32B0CR0		(*(volatile uint32_t*)0x4001402C)
#define	TMR32B0EMR		(*(volatile uint32_t*)0x4001403C)
#define	TMR32B0CTCR		(*(volatile uint32_t*)0x40014070)
#define	TMR32B0PWMC		(*(volatile uint32_t*)0x40014074)
#define	TMR32B1IR		(*(volatile uint32_t*)0x40018000)
#define	TMR32B1TCR		(*(volatile uint32_t*)0x40018004)
#define	TMR32B1TC		(*(volatile uint32_t*)0x40018008)
#define	TMR32B1PR		(*(volatile uint32_t*)0x4001800C)
#define	TMR32B1PC		(*(volatile uint32_t*)0x40018010)
#define	TMR32B1MCR		(*(volatile uint32_t*)0x40018014)
#define	TMR32B1MR		( (volatile uint32_t*)0x40018018)
#define	TMR32B1MR0		(*(volatile uint32_t*)0x40018018)
#define	TMR32B1MR1		(*(volatile uint32_t*)0x4001801C)
#define	TMR32B1MR2		(*(volatile uint32_t*)0x40018020)
#define	TMR32B1MR3		(*(volatile uint32_t*)0x40018024)
#define	TMR32B1CCR		(*(volatile uint32_t*)0x40018028)
#define	TMR32B1CR0		(*(volatile uint32_t*)0x4001802C)
#define	TMR32B1EMR		(*(volatile uint32_t*)0x4001803C)
#define	TMR32B1CTCR		(*(volatile uint32_t*)0x40018070)
#define	TMR32B1PWMC		(*(volatile uint32_t*)0x40018074)

/* Watchdog timer*/
#define	WDMOD		(*(volatile uint32_t*)0x40004000)
#define	WDTC		(*(volatile uint32_t*)0x40004004)
#define	WDFEED		(*(volatile uint32_t*)0x40004008)
#define	WDTV		(*(volatile uint32_t*)0x4000400C)

/* A-D converter */
#define	AD0CR		(*(volatile uint32_t*)0x4001C000)
#define	AD0GDR		(*(volatile uint32_t*)0x4001C004)
#define	AD0INTEN	(*(volatile uint32_t*)0x4001C00C)
#define	AD0DR		( (volatile uint32_t*)0x4001C010)
#define	AD0DR0		(*(volatile uint32_t*)0x4001C010)
#define	AD0DR1		(*(volatile uint32_t*)0x4001C014)
#define	AD0DR2		(*(volatile uint32_t*)0x4001C018)
#define	AD0DR3		(*(volatile uint32_t*)0x4001C01C)
#define	AD0DR4		(*(volatile uint32_t*)0x4001C020)
#define	AD0DR5		(*(volatile uint32_t*)0x4001C024)
#define	AD0DR6		(*(volatile uint32_t*)0x4001C028)
#define	AD0DR7		(*(volatile uint32_t*)0x4001C02C)
#define	AD0STAT		(*(volatile uint32_t*)0x4001C030)


/* Cortex-M0 System timer */
#define	SYST_CSR	(*(volatile uint32_t*)0xE000E010)
#define	SYST_RVR	(*(volatile uint32_t*)0xE000E014)
#define	SYST_CVR	(*(volatile uint32_t*)0xE000E018)
#define	SYST_CALIB	(*(volatile uint32_t*)0xE000E01C)

/* Cortex-M0 NVIC */
#define ISER	(*(volatile uint32_t*)0xE000E100)
#define ICER	(*(volatile uint32_t*)0xE000E180)
#define ISPR	(*(volatile uint32_t*)0xE000E200)
#define ICPR	(*(volatile uint32_t*)0xE000E280)
#define IPR		( (volatile uint8_t *)0xE000E400)

/* Cortex-M0 SCB */
#define	CPUID	(*(volatile uint32_t*)0xE000ED00)
#define	ICSR	(*(volatile uint32_t*)0xE000ED04)
#define	AIRCR	(*(volatile uint32_t*)0xE000ED0C)
#define	SCR		(*(volatile uint32_t*)0xE000ED10)
#define	CCR		(*(volatile uint32_t*)0xE000ED14)
#define	SHPR	( (volatile uint32_t*)0xE000ED14)


/*--------------------------------------------------------------*/
/* Declareations of the public functions defined in startup.c.  */
/* These are used to access LPC1100 resources from C code.      */
/*--------------------------------------------------------------*/

/* Cortex-M0 core/peripheral access macros */
#define __enable_irq() asm volatile ("CPSIE i\n")
#define __disable_irq() asm volatile ("CPSID i\n")
#define __enable_fault_irq() asm volatile ("CPSIE f\n")
#define __disable_fault_irq() asm volatile ("CPSID f\n")
#define __enable_irqn(n) ISER = 1 << (n)
#define __disable_irqn(n) ICER = 1 << (n)
#define __test_irqn_enabled(n) (ICER & (1 << (n)))
#define __set_irqn(n) ISPR = 1 << (n)
#define __clear_irqn(n) ICPR = 1 << (n)
#define __test_irqn(n) (ICPR & (1 << n))
#define __test_irqn_active(n) (IABR & (1 << (n)))
#define __set_irqn_priority(n,v) IPR[n] = (v)
#define __set_faultn_priority(n,v) SHPR[n + 16] = (v)
#define __get_MSP() ({uint32_t __rv; asm ("MRS %0, MSP\n" : "=r" (__rv)); __rv;})
#define __get_PSP() ({uint32_t __rv; asm ("MRS %0, PSP\n" : "=r" (__rv)); __rv;})
#define __get_PRIMASK() ({uint32_t __rv; asm ("MRS %0, PRIMASK\n" : "=r" (__rv)); __rv;})
#define __get_FAULTMASK() ({uint32_t __rv; asm ("MRS %0, FAULTMASK\n" : "=r" (__rv)); __rv;})
#define __get_BASEPRI() ({uint32_t __rv; asm ("MRS %0, BASEPRI\n" : "=r" (__rv)); __rv;})
#define __get_CONTROL() ({uint32_t __rv; asm ("MRS %0, CONTROL\n" : "=r" (__rv)); __rv;})
#define __set_MSP(arg) {uint32_t __v=arg; asm ("MSR MSP, %0\n" : : "r" (__v));}
#define __set_PSP(arg) {uint32_t __v=arg; asm ("MSR PSP, %0\n" : : "r" (__v));}
#define __set_PRIMASK(arg) {uint32_t __v=arg; asm ("MSR PRIMASK, %0\n" : : "r" (__v));}
#define __set_FAULTMASK(arg) {uint32_t __v=arg; asm ("MSR FAULTMASK, %0\n" : : "r" (__v));}
#define __set_BASEPRI(arg) {uint32_t __v=arg; asm ("MSR BASEPRI, %0\n" : : "r" (__v));}
#define __set_CONTORL(arg) {uint32_t __v=arg; asm ("MSR CONTROL, %0\nISB\n" : : "r" (__v));}
#define __REV(arg)   ({uint32_t __r, __v=arg; asm ("REV %0,%1\n"   : "=r" (__r) : "r" (__v) ); __r;})
#define __REV16(arg) ({uint32_t __r, __v=arg; asm ("REV16 %0,%1\n" : "=r" (__r) : "r" (__v) ); __r;})
#define __REVSH(arg) ({uint32_t __r, __v=arg; asm ("REVSH %0,%1\n" : "=r" (__r) : "r" (__v) ); __r;})
#define __SEV() asm volatile ("SEV\n")
#define __WFE() asm volatile ("WFE\n")
#define __WFI() asm volatile ("WFI\n")


/* LPC1100 IRQ number */
#define	SVC_IRQn		(-5)
#define	DebugMon_IRQn	(-4)
#define	PendSV_IRQn		(-2)
#define	SysTick_IRQn	(-1)
#define	PIO0_0_IRQn		0
#define	PIO0_1_IRQn		1
#define	PIO0_2_IRQn		2
#define	PIO0_3_IRQn		3
#define	PIO0_4_IRQn		4
#define	PIO0_5_IRQn		5
#define	PIO0_6_IRQn		6
#define	PIO0_7_IRQn		7
#define	PIO0_8_IRQn		8
#define	PIO0_9_IRQn		9
#define	PIO0_10_IRQn	10
#define	PIO0_11_IRQn	11
#define	PIO1_0_IRQn		12
#define	C_CAN_IRQn		13
#define	SPI1_IRQn		14
#define	I2C_IRQn		15
#define	CT16B0_IRQn		16
#define	CT16B1_IRQn		17
#define	CT32B0_IRQn		18
#define	CT32B1_IRQn		19
#define	SPI0_IRQn		20
#define	UART_IRQn		21
#define	ADC_IRQn		24
#define	WDT_IRQn		25
#define	BOD_IRQn		26
#define	PIO_3_IRQn		28
#define	PIO_2_IRQn		29
#define	PIO_1_IRQn		30
#define	PIO_0_IRQn		31

/* LPC1100 Power Control */
#define	__set_SYSAHBCLKCTRL(p,v)	SYSAHBCLKCTRL = (SYSAHBCLKCTRL & ~(1 << (p))) | ((v) << (p))
#define	PCROM		1
#define	PCRAM		2
#define	PCFLASHREG	3
#define	PCFLASHARRAY	4
#define	PCI2C		5
#define	PCGPIO		6
#define	PCCT16B0	7
#define	PCCT16B1	8
#define	PCCT32B0	9
#define	PCCT32B1	10
#define	PCSSP0		11
#define	PCUART		12
#define	PCADC		13
#define	PCWDT		15
#define	PCIOCON		16
#define	PCCAN		17
#define	PCSSP1		18



/*--------------------------------------------------------------*/
/* Misc Macros                                                  */
/*--------------------------------------------------------------*/


#define	_BV(bit) (1<<(bit))

#define	IMPORT_BIN(file, sym) asm (\
		".section \".rodata\"\n"\
		".balign 4\n"\
		".global " #sym "\n"\
		#sym ":\n"\
		".incbin \"" file "\"\n"\
		".global _sizeof_" #sym "\n"\
		".set _sizeof_" #sym ", . - " #sym "\n"\
		".balign 4\n"\
		".section \".text\"\n")

#define	IMPORT_BIN_PART(file, ofs, siz, sym) asm (\
		".section \".rodata\"\n"\
		".balign 4\n"\
		".global " #sym "\n"\
		#sym ":\n"\
		".incbin \"" file "\"," #ofs "," #siz "\n"\
		".global _sizeof_" #sym "\n"\
		".set _sizeof_" #sym ", . - " #sym "\n"\
		".balign 4\n"\
		".section \".text\"\n")


#endif	/* #ifdef __LPC1100 */
