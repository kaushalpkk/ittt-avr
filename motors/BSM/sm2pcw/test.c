 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>

#define PORT PORTB                    //CHANGE PORTS EASILY...
#define timed 100
#define DDR DDRB

unsigned int i;

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}
/*shifts as 2 phase motor ...

0100    1100
0010    0110
0001    0011
0000    1001
*/

int main(void) {

  DDR  = 0xFF;
  while(1) {
for (i=0;i<3;i++){
        PORT = Ox4C >> i;
        delay(timed);
    }
}
  return 0;
}
