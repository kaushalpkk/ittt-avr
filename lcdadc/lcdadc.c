#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>
#include "lcd4.h"

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}
void adc_init(void){
   
   ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Set ADC prescalar to 128 - 125KHz sample rate @ 16MHz

   ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
   ADMUX |= (1 << ADLAR); // Left adjust ADC result to allow easy 8 bit reading

   // No MUX values needed to be changed to use ADC0

   //ADCSRA |= (1 << ADFR);  // Set ADC to Free-Running Mode
   ADCSRA |= (1 << ADEN);  // Enable ADC
   ADCSRA |= (1 << ADSC);  // Start A2D Conversions
}
unsigned char adc_read(unsigned char ch){

    ADMUX &= 0xF8; // clear bottom 3 bits
    ADMUX |= ch; // then set bottom 3 bits to channel n 
    ADCSRA |= (1 << ADSC);  // Start A2D Conversions
    while(bit_is_set(ADCSRA,ADSC));
    
    return(ADCH);
}
void puthex( unsigned char data ){

  unsigned char ascii[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  SendData(ascii[(data >> 4)]);
  SendData(ascii[data & 0x0F]);
}

int main (void)
{
  char str[] = " ADC interface";
  unsigned char tmp,i = 0;
  adc_init();
  InitLCD();
  SendString(str, 1, 0);// plain string
  delayms(1000);

  SendCommand(0x80);
  while(1){
        tmp = adc_read(i);
  	SendData(i + 0x30);
        SendData(':');
  	puthex(tmp);
	SendData(' ');
	
//	i++;
//	if(i > 5){
//          i = 0;
          //SendCommand(0x01);
          SendCommand(0x80);  
//	}
//	if(i == 3)
          SendCommand(0xC0);
	delayms(1000);
  }
} 
