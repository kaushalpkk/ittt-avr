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

int main(void){

unsigned int i = 0;
static unsigned int arrk[5] = {0x15,0x13,0x17,0x13,0x15};

  DDRB  = 0xFF; //cathodes    ...displays the charecter as in line
  DDRC  = 0xFF; //anodes  ..shifts frm 11110 to 01111
  
  PORTC = 0xFF;  // LOGIC LOW horizontal anodes
  PORTB = 0x01;  // LOGIC HIGH vertical  cathodes


  while(1)
    {
     PORTC = arrk[i];

     PORTB = (0x01 << i);

//     delayms(10);

     i++;

   if (i > 4){
   i = 0;
      }
    }
return(0);
}
