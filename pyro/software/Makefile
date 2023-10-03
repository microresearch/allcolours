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
CFLAGS=-mmcu=$(MCU) -Os
DEVICE = m168
AVRDUDE = avrdude -c usbasp -p $(DEVICE)
FUSEH = 0xdf
FUSEL = 0xf7

# commented for pololu
#from top //pyro// is : RESET, MOSI, MISO, SCK, GND

#-------------------
all: pyro000.hex
#-------------------
help: 
	@echo "Usage: make all|load|load_pre|rdfuses|wrfuse1mhz|wrfuse4mhz|wrfusecrystal"
	@echo "Warning: you will not be able to undo wrfusecrystal unless you connect an"
	@echo "         external crystal! uC is dead after wrfusecrystal if you do not"
	@echo "         have an external crystal."
#-------------------
pyro000.hex : pyro000.out 
	$(OBJCOPY) -R .eeprom -O ihex pyro000.out pyro000.hex 
#	$(OBJCOPY) -O ihex pyro000.out pyro000.hex 
#pyro000.out : pyro000.o 
#	$(CC) $(CFLAGS) -o pyro000.out -Wl,-Map,pyro000.map pyro000.o 
pyro000.out : pyro000.o 
	$(CC) ${LDFLAGS} $(CFLAGS) -o pyro000.out  pyro000.o 


pyro000.o : pyro000.c 
	$(CC) $(CFLAGS) -Os -c pyro000.c

pyro000.elf: pyro000.o
	$(CC) ${LDFLAGS} $(CFLAGS) -o pyro000.elf pyro000.o

disasm:	pyro000.elf
	avr-objdump -d pyro000.elf

fuse:
#	$(AVRDUDE) -F -U hfuse:w:$(FUSEH):m -U lfuse:w:$(FUSEL):m
	 avrdude -y -c stk500v2 -P /dev/ttyACM0 -p $(MCU) -U lfuse:w:$(FUSEL):m 
flash: all
#	$(AVRDUDE) -F -U flash:w:pyro000.hex:i
	 avrdude -y -c stk500v2 -P /dev/ttyACM0 -p $(MCU)  -U flash:w:pyro000.hex:i



#-------------------
clean:
	rm -f *.o *.map *.out *t.hex
#-------------------
