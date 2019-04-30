PROJECT	= mmruby

CSRC	= main.c startup1100.c alloc.c c_object.c debug.c hal.c value.c avr_access.c c_string.c vm.c c_common.c class.c c_fixnum.c console.c global.c symbol.c memman.c string_mini.c ext.c
ASRC	=
CSRCARM	=
ASRCARM	=
VPATH   =

# Optimization (0, 1, 2, 3, 4, s)
OPTIMIZE = s

# C Standard (c89, gnu89, c99, gnu99)
CSTD = gnu99

# Processor type and use Thumb(-2) mode for CSRC/ASRC files (YES or NO)
CPU   = cortex-m0
THUMB = YES

# Linker script for the target MCU
LINKSCRIPT = lpc1114fn28.ld # ROM:32KB RAM:4KB
#LINKSCRIPT = lpc1114fhn33.ld # ROM:56KB RAM:8KB

### Output file type (hex, bin or both) and debugger type
OUTPUT	= both
HEXFMT  = ihex
DEBUG	= # dwarf-2

### Include dirs, library dirs and definitions
MATHLIB	= #-lm
LIBS	=
LIBDIRS	=
INCDIRS	=
DEFS	=
ADEFS	=

# Warning contorls
WARNINGS = all extra

# Directory
SRCDIR = src
OBJDIR = obj

# Programs to build porject
CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size
NM      = arm-none-eabi-nm

# Programs to write
LPC21ISP  = ../../../c/lpc21isp_197k/lpc21isp
USBSERIAL = /dev/tty.SLAB_USBtoUART

# Define all object files
COBJ      = $(CSRC:.c=.o)
AOBJ      = $(ASRC:.S=.o)
COBJARM   = $(CSRCARM:.c=.o)
AOBJARM   = $(ASRCARM:.S=.o)
COBJ      := $(addprefix $(OBJDIR)/,$(COBJ))
AOBJ      := $(addprefix $(OBJDIR)/,$(AOBJ))
COBJARM   := $(addprefix $(OBJDIR)/,$(COBJARM))
AOBJARM   := $(addprefix $(OBJDIR)/,$(AOBJARM))
PROJECT   := $(OBJDIR)/$(PROJECT)

### Compiler flags
ifeq ($(THUMB),YES)
THUMBFLAG = -mthumb
THUMBIW = -mthumb-interwork
else
THUMBFLAG =
THUMBIW =
endif

# Compiler flags
CFLAGS += -std=$(CSTD)
CFLAGS += -g$(DEBUG)
CFLAGS += -O$(OPTIMIZE)
#CFLAGS += $(addprefix -W,$(WARNINGS))
#CFLAGS += -Wunused-parameter
CFLAGS += $(addprefix -I,$(INCDIRS))
CFLAGS += $(addprefix -D,$(DEFS))
CFLAGS += -fomit-frame-pointer -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections
#CFLAGS += -w -c
# -W -Wall -c -fno-builtin
#CFLAGS += -Wp,-M,-MP,-MT,$(OBJDIR)/$(*F).o,-MF,$(OBJDIR)/$(*F).d
CFLAGS += -Wp,-M,-MP,-MT,$(OBJDIR)/$(*F).o,-MF,$(OBJDIR)/$(*F).d

# Assembler flags
ASFLAGS += $(addprefix -D,$(ADEFS)) -Wa,-g$(DEBUG)

# Linker flags
LDFLAGS += -nostartfiles -Wl,-Map=$(PROJECT).map,--cref,--gc-sections
LDFLAGS += -lc -lgcc
LDFLAGS += $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
LDFLAGS += $(MATHLIB)
LDFLAGS += -T$(LINKSCRIPT)

ALL_CFLAGS  = -mcpu=$(CPU) $(THUMBIW) -I. $(CFLAGS)
ALL_ASFLAGS = -mcpu=$(CPU) $(THUMBIW) -I. -x assembler-with-cpp $(ASFLAGS)

all: build size

ifeq ($(OUTPUT),hex)
build: axf hex lst sym
hex: $(PROJECT).hex
else
ifeq ($(OUTPUT),bin)
build: axf bin lst sym
bin: $(PROJECT).bin
else
ifeq ($(OUTPUT),both)
build: axf hex bin lst sym
hex: $(PROJECT).hex
bin: $(PROJECT).bin
else
$(error "Invalid format: $(OUTPUT)")
endif
endif
endif

axf: $(PROJECT).axf
lst: $(PROJECT).lst 
sym: $(PROJECT).sym

%.hex: %.axf
	@echo
	$(OBJCOPY) -O $(HEXFMT) $< $@

%.bin: %.axf
	@echo
	$(OBJCOPY) -O binary $< $@

%.lst: %.axf
	@echo
	$(OBJDUMP) -h -S -C $< > $@

%.sym: %.axf
	@echo
	$(NM) -n $< > $@

size:
	$(SIZE) $(PROJECT).axf
	ls -l $(PROJECT).bin

%.axf:  $(AOBJARM) $(AOBJ) $(COBJARM) $(COBJ)
	@echo
	@echo Linking...
	$(CC) $(THUMBFLAG) $(ALL_CFLAGS) $(AOBJARM) $(AOBJ) $(COBJARM) $(COBJ) -o $@ $(LDFLAGS)

$(COBJ) : $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo
	@echo $< :
	$(CC) -c $(THUMBFLAG) $(ALL_CFLAGS) $< -o $@

$(COBJARM) : $(OBJDIR)/%.o : %.c
	@echo
	@echo $< :
	$(CC) -c $(ALL_CFLAGS) $< -o $@ 

$(AOBJ) : $(OBJDIR)/%.o : %.S
	@echo
	@echo $< :
	$(CC) -c $(THUMBFLAG) $(ALL_ASFLAGS) $< -o $@

$(AOBJARM) : $(OBJDIR)/%.o : %.S
	@echo
	@echo $< :
	$(CC) -c $(ALL_ASFLAGS) $< -o $@

clean:
	@echo
	rm -f -r $(OBJDIR) | exit 0

write:
	$(LPC21ISP) -control -hex $(PROJECT).hex $(USBSERIAL) 115200 1200

-include $(shell mkdir $(OBJDIR) 2>/dev/null) $(wildcard $(OBJDIR)/*.d)
