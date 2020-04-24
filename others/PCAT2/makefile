# Simple Makefile
# Volker Oth (c) 1999


########### change this lines according to your project ##################

#put the name of the target mcu here (at90s8515, at90s8535, attiny22, atmega603 etc.)
    MCU = atmega163
	
#put the name of the target file here (without extension)
	TRG	= main

#put your C sourcefiles here 
	SRC	= $(TRG).c kb.c serial.c StdDefs.c

#put additional assembler source file here
	ASRC    =

#additional libraries and object files to link
	LIB	=

#additional includes to compile
	INC	= 

#compiler flags
   CPFLAGS	= -g -O3 -w -Wa,-ahlms=$(<:.c=.lst) -Wno-cast-qual
#	CPFLAGS	= -g -O3 -Wall -Wstrict-prototypes -Wa,-ahlms=$(<:.c=.lst) -Wno-cast-qual

#linker flags
	LDFLAGS = -Wl,-Map=$(TRG).map,--cref,-lm

########### you should not need to change the following line #############
include $(AVR)/include/avr_make

###### dependecies, add any dependencies you need here ###################
$(TRG).o : $(TRG).c kb.c serial.c kb.h serial.h scancodes.h pindefs.h StdDefs.c StdDefs.h
