# mmruby for IchigoJam / IchigoCake

This project is to run mruby/c on IchigoJam (LPC1114FN28/FDH28 by NXP) or IchigoCake (LPC1114FHN33 by NXP), which has 4KB/8KB RAM.
"micro mruby" or "mmruby" is a subset of mruby/c with a lot of limitation.
This project is based on "micro mruby for Arduino Uno".
"micro mruby for Arduino Uno" is a subset of mruby/c with a lot of limitations.  

micro mruby for Arduino Uno  
https://silentworlds.info/2018/10/26/hacked-mruby-c-can-work-on-arduino-uno/  

mruby/c  
https://www.s-itoc.jp/activity/research/mrubyc/  

mruby  
http://mruby.org/  

IchigoJam  
https://ichigojam.net/  

Be careful! This is still very buggy!!  

Known bug  
- crash: mruby code has more than 2 irep  
- not supported: mruby 2.0 code (for2.0 TBD)  

# Required environment

* IchigoJam, IchigoLatte, IchigoCake or LPC1114
* USB-Serial adapter
* Complile environment for C (gcc, make)

# How to run it?

## Install

```
$ make all write
```

Edit Makefile to change platform ROM/RAM.

## Prepare a transcoder tool

This project needs a transcoder tool. This transcodes a mrb file to C header file for mruby/c.

```
$ cd tool
$ make
```

You will get the TransCoder.

## Compile target mruby code

Compile your target mruby code by mrbc ver1.3.0/1.4.0/1.4.1. (ver2.0.0 or higher version is not supported since the bytecode format.)

```
$ mrbc code.rb
```

## Transcode

```
$ Transcode code.mrb
```

It will make two files "code.h" and "symbol_ids.h" in "../src" directory.

## Make a binary

```
$ make
```

```C
void main() {
	memman_init();
	hal_init();
	ext_init();

	init_symbol_table();
	mrbc_init_class();
	init_vm();
	run_vm();
}
```

```
$ make write
```

To run it on IchigoJam!
