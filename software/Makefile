# makefile, written by guido socher
MCU=atmega168
#MCU=at90s4433
CC=avr-gcc
#CEXTRA=-Wa,-adhlns=$(<:.c=.lst)
#EXTERNAL_RAM = -Wl,--defsym=__heap_start=0x801100,--defsym=__heap_end=0x80ffff
#EXTERNAL_RAM = -Wl,-Tdata=0x801100,--defsym=__heap_end=0x80ffff
LDFLAGS  = -mmcu=${MCU} -Wl,-u, -lm
#LDFLAGS  = -mmcu=${MCU} -Wl,-u,vfprintf -lprintf_flt -lm
OBJCOPY=avr-objcopy
# optimize for size:
#CFLAGS=-g -mmcu=$(MCU) -Wall -Wstrict-prototypes -mcall-prologues ${CEXTRA}
CFLAGS=-mmcu=$(MCU) -Os -D'AVR_IS'
DEVICE = m168
AVRDUDE = avrdude -c usbasp -p $(DEVICE)
FUSEH = 0xdf
FUSEL = 0xf7


#-------------------
all: all_colours.hex
#-------------------
help: 
	@echo "Usage: make all|load|load_pre|rdfuses|wrfuse1mhz|wrfuse4mhz|wrfusecrystal"
	@echo "Warning: you will not be able to undo wrfusecrystal unless you connect an"
	@echo "         external crystal! uC is dead after wrfusecrystal if you do not"
	@echo "         have an external crystal."
#-------------------
all_colours.hex : all_colours.out 
	$(OBJCOPY) -R .eeprom -O ihex all_colours.out all_colours.hex 
#	$(OBJCOPY) -O ihex all_colours.out all_colours.hex 
#all_colours.out : all_colours.o 
#	$(CC) $(CFLAGS) -o all_colours.out -Wl,-Map,all_colours.map all_colours.o 
all_colours.out : all_colours.o 
	$(CC) ${LDFLAGS} $(CFLAGS) -o all_colours.out  all_colours.o 


all_colours.o : all_colours.c 
	$(CC) $(CFLAGS) -Os -c all_colours.c

all_colours.elf: all_colours.o
	$(CC) ${LDFLAGS} $(CFLAGS) -o all_colours.elf all_colours.o

disasm:	all_colours.elf
	avr-objdump -d noise.elf

fuse:
	$(AVRDUDE) -F -U hfuse:w:$(FUSEH):m -U lfuse:w:$(FUSEL):m

flash: all
	$(AVRDUDE) -F -U flash:w:all_colours.hex:i



#-------------------
clean:
	rm -f *.o *.map *.out *t.hex
#-------------------
