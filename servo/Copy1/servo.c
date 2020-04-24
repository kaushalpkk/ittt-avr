#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

int x = 1500;

int main(void) {

  DDRD  = 0xFF;
  while(1) {

    PORTD = 0xFF;
    _delay_us(x);


    PORTD = 0x00;
    _delay_us(20000-x);
//        x = x * 2;

  }
  return 0;
}
