#
#The makefile
#

PROJECT = clock
MMCU = atmega8
P = m8

#HFUSE=0xc9
#LFUSE=0xef

#Beyond this line things should be pretty much constant

AVRDUDE = c:\winavr\bin\avrdude -c usbasp -p $(P) -P usb

CFLAGS=-Os -Wall -mmcu=$(MMCU)
#-O -mmcu=atmega32 -Wall -Wstrict-prototypes -Os -mcall-prologues

all: $(PROJECT).hex

$(PROJECT).hex : $(PROJECT).out 
	c:\winavr\bin\avr-objcopy -R .eeprom -O ihex $(PROJECT).out $(PROJECT).hex 

$(PROJECT).out : $(PROJECT).o 
	c:\winavr\bin\avr-gcc $(CFLAGS) -o $(PROJECT).out -Wl,-Map,$(PROJECT).map $(PROJECT).o 

$(PROJECT).o : $(PROJECT).c 
	c:\winavr\bin\avr-gcc $(CFLAGS) -Os -c $(PROJECT).c

##test
flash: $(PROJECT).hex
	$(AVRDUDE) -U flash:w:$(PROJECT).hex

##test
fuse:
	$(AVRDUDE) -U hfuse:w:$(HFUSE):m -U lfuse:w:$(LFUSE):m

clean:
	rm -f *.o *.map *.out *.hex
