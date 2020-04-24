 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

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

  DDRD  = 0xFF;
  while(1) {

    PORTD = 0xFF;
    delayms(500);


    PORTD = 0x00;
    delayms(500);
  }
  return 0;
}
