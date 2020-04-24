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
/*shifts the bits as shown below..
0001
0010
0100
1000
*/

int main(void) {

  DDRB  = 0xFF;
  while(1) {

for (i=0;i<3;i++){

PORTB = 0x01 << i;

delayms(100);

    }
}
  return 0;
}
