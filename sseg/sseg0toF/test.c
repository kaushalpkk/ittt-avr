#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>
#include "ssegc.h"

unsigned int count;
void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}


void Delay(uint32_t count)
{
    while(count)count--;
}

int main(void) {

  DDRB  = 0xFF;
  PORTB = 0XFF;
  while(1) {

    PORTB = segs[count++];
        if(count > 15)
          count = 0;
    delayms(500);
  
}
  return 0;
}
