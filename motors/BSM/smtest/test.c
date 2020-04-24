 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>
#define PORT PORTC                    //CHANGE PORTS EASILY...
#define timed 100
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

PORT = 0x01;
delayms(timed);

PORT = 0x02;
delayms(timed);

PORT = 0x04;
delayms(timed);

PORT = 0x08;
delayms(timed);

    }
}
  return 0;
}
