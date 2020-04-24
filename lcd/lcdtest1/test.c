 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <avr/portpins.h>
#include <util/delay.h>
#include "lcd8k.h"

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

initlcd();

  while(1) {

sendcmd(0x01);

senddata(K);


  }
  return 0;
}
