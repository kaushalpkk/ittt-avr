#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

unsigned int x = 2000;


int main(void) {

//  x = 1;

  DDRD=0xFF;
  while(1) {
    PORTC = 0xFF;
    _delay_us(2500);


    PORTC = 0x00;
    _delay_us(20000 - 2500);

  }
  return 0;
}
