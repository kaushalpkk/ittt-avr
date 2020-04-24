//works

#define KB_PORT_SET DDRB
#define KB_PORT_OUT PORTB
#define KB_PORT_IN  PINB

#define F_CPU 1000000UL
#define ENDCHAR 0x80
#include <avr/io.h>
#include <util/delay.h>
#include "lcd4.h"
#include "keypad.h"

int main(void){
  unsigned char key,count = 0;
  char str[] = "I am working";
  
  //usart_init();
  InitLCD();
  _delay_ms(1000);

  SendString(str, 1, 2);// plain string
  
  SendCommand(0xC0);
  
  while(1){
    key = keypad();

    if(key != 'X'){
      SendData(key);
      count++;
      if(count > 15){
        count = 0;
        SendString("                ", 2, 0);
        SendCommand(0xC0);
      }
    }
    _delay_ms(50);
  }//end of while(1)
}//end of main()

