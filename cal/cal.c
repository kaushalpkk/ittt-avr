/*


1   2   3   +
4   5   6   -
7   8   9   x
.   0   =   %


*/
#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>
#include "lcd4.h"
#include "keypad.h"
#include "delay.h"

int main(void) {

  DDRB  = 0xFF;
  while(1){



   
  }
  return 0;
}
