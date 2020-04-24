 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>
#include "mcode.h"

unsigned int i;

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}

int main(void) {

  DDRB  = 0xFF;
  while(1) {

    PORTB = 0xAA;
    delayms(2500);

    PORTB = 0x09;
    delayms(1400);

    PORTB = 0x05;
    delayms(2500);

    PORTB = 0x06;
    delayms(1400);
  }
  return 0;
}
