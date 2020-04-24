//works

/*functions used..

VARIABLE^ = keypad();

RETURNS THE VALUE TO "keypressed" variable 

*/
#define KB_PORT_OUT PORTC   //... change port config for diff MCUs..
#define KB_PORT_IN  PINC
#define KB_PORT_SET DDRC

unsigned char keypad(void){
  unsigned char tmp, keypressed = 'X', i;

  KB_PORT_SET = 0x0F; //upper nibble input lower output
  
  for(i=0; i<4; i++){

    KB_PORT_OUT = ~(0x01 << i);
    _delay_ms(1); //delay for port o/p settling
      
    tmp = KB_PORT_IN;
    
    if((tmp & 0xF0) != 0xF0){
      switch (tmp){ //generating key characetr to display on LCD
        case (0x77): keypressed = '0';break;
        case (0x7B): keypressed = '1';break;
        case (0x7D): keypressed = '2';break;
        case (0x7E): keypressed = '3';break;
        case (0xB7): keypressed = '4';break;
        case (0xBB): keypressed = '5';break;
        case (0xBD): keypressed = '6';break;
        case (0xBE): keypressed = '7';break;
        case (0xD7): keypressed = '8';break;
        case (0xDB): keypressed = '9';break;
        case (0xDD): keypressed = 'A';break;
        case (0xDE): keypressed = 'B';break;
        case (0xE7): keypressed = 'C';break;
        case (0xEB): keypressed = 'D';break;
        case (0xED): keypressed = 'E';break;
        case (0xEE): keypressed = 'F';break;
        default : keypressed = 'X';
      }//end of switch
      while((KB_PORT_IN & 0xF0) != 0xF0){
        //_delay_ms(20);        
        //tmp = PINB;
        //usart_putch(tmp);
      }//end of while
    }//end of if
  }//end of for
  return(keypressed);
}//end of keypad()

