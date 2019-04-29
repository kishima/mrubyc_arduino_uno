/* LPC1114 Memory Definitions */

MEMORY
{
  /* Flash: 56k */
/*  ROM (rx) : ORIGIN = 0x00000000, LENGTH = (56k) */
  /* SRAM: 8k - IAP work */
/*  RAM (w) : ORIGIN = 0x10000000, LENGTH = (8k-32) */

  /* Flash: 32k */
  ROM (rx) : ORIGIN = 0x00000000, LENGTH = (32k)
/* SRAM: 4k - IAP work */
  RAM (w) : ORIGIN = 0x10000000, LENGTH = (4k-32)
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

  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
}
