 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

unsigned int i;

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}
/*
shifts as shown
1000
0100
0010
0001
*/

int main(void) {

  DDRB  = 0xFF;
  while(1) {

for (i=0;i<3;i++){

PORTB = 0x08 >> i;

delayms(100);

    }
}
  return 0;
}
