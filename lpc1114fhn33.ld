/* LPC1114 Memory Definitions */

MEMORY
{
  /* Flash: 56k */
  ROM (rx) : ORIGIN = 0x00000000, LENGTH = (56k)
  /* SRAM: 8k - IAP work */
  RAM (w) : ORIGIN = 0x10000000, LENGTH = (8k-32)

  /* Flash: 32k */
/*  ROM (rx) : ORIGIN = 0x00000000, LENGTH = (32k) */   
/* SRAM: 4k - IAP work */
/*  RAM (w) : ORIGIN = 0x10000000, LENGTH = (4k-32) */  
}

_startof_flash = ORIGIN(ROM);               /* Start of available flash memory address */
_endof_flash = ORIGIN(ROM) + LENGTH(ROM);   /* End of available flash memory address + 1 */
_startof_sram = ORIGIN(RAM);                /* Start of available SRAM address */
_endof_sram = ORIGIN(RAM) + LENGTH(RAM);    /* End of available SRAM address + 1 */


/* Section Definitions */

SECTIONS
{
  /* .text section has program code, constants and read-only data. */
  /* It is located in ROM. */
   .text :
  {
    KEEP(*(.VECTOR))       /* Exception vector table */
/*    . = 0x2FC; */
/*    KEEP(*(.CRP)) */          /* CRP value */
    *(.text .text.*)       /* Program code */
    *(.gnu.linkonce.t*)
    *(.gcc_except_table)
    *(.rodata .rodata.*)   /* Read-only data (constants) */
    *(.gnu.linkonce.r*)
  } > ROM

   .ARM.excep :            /* Data table for library exception handling */
  {
    *(.ARM.exidx*)
    *(.ARM.extab*)
  } > ROM

  . = ALIGN(4);
  _etext = .;         /* End of .text section */
  _sidata = .;        /* Start of the initialization values of the .data section */


  /* .data section has static objects with initial value. It is located in RAM */
  /* but the content is placed to ROM area just below .text section. */
  /* This section will be initialized with the ROM data by startup code */
  .data : AT(_sidata)
  {
    _sdata = .;
    *(.data .data.*)
    *(.gnu.linkonce.d*)
    . = ALIGN(4);
    _edata = .;
  } > RAM


  /* .bss section has static oobjects with no initial value. */
  /* This section will be filled with zero by startup code to meet ANSI C standard. */
  .bss (NOLOAD) : ALIGN(4)
  {
    _sbss = .;
    *(.bss .bss.*)
    *(.gnu.linkonce.b*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
  } > RAM

  .stack (NOLOAD) : ALIGN(8)
  {
    *(.stack)
    *(.STACK)
    . = ALIGN(4);
  } > RAM

  . = ALIGN(4);
  _end = .;
}
