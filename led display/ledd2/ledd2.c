#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

int i;
void delayms(uint16_t millis) 
{
  while ( millis ) 
  {
    _delay_ms(1);
    millis--;
  }
}


void nxtdelay(){
                 //replace this fuction wid the lines in main prgm 
if (i < 5){
delayms(33);
PORTC = PORTC << 1;
i++;
}
else {
i = 0;
delayms(33);
PORTC = 0x01;
}
//return(0);
}

int main(void) 
{

  DDRB  = 0xFF; //cathodes    ...displays the charecter as in line
  DDRC  = 0xFF; //anodes  ..shifts frm 11110 to 01111
  
  PORTC = 0x01;  // LOGIC LOW horizontal
  PORTB = 0x00;  // LOGIC HIGH vertical

  while(1)

   {
    PORTB = 0x0E;
    nxtdelay();

    PORTB = 0x0E;
    nxtdelay();

    PORTB = 0x00;
    nxtdelay();

    PORTB = 0x15;
    nxtdelay();

    PORTB = 0x1B;
    nxtdelay();
   }
return(0);
}