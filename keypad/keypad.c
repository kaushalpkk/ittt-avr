

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

unsigned int keypad(void) {

unsigned int temp, i, j;

//DDRX = 0X0F;  //UPPER INPUT.. - LOWER OUTPUT..
//PORTX = 0xFF; 
  

  while(1){
for (i=0;i<4;i++){

PORTB = ~(0x01 << i); //left shift lower nibble ... wid i value and invert it "1101"

temp = PINB; //move the higher nibble input to a temp value..

// anding with 0xF0 - > will give a hex value definite to the input pressed..

if ((temp & 0xF0) != 0xF0){
    switch (temp){
        case ():                //the case values may return functions... or to any other valvues... 

  }
  return 0;
}
