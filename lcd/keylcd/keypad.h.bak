//works
/*
#define KB_PORT_OUT PORTB
#define KB_PORT_IN  PINB
#define KB_PORT_SET DDRB
*/
unsigned char keypad(void){
  unsigned char tmp, keypressed = 'X', i;

  KB_PORT_SET = 0x0F; //upper nibble input lower output
  
  for(i=0; i<4; i++){

    KB_PORT_OUT = ~(0x01 << i);
    _delay_ms(1); //delay for port o/p settling
      
    tmp = KB_PORT_IN;
    
    if((tmp & 0xF0) != 0xF0){
      switch (tmp){ //generating key characetr to display on LCD
        case (0xee): keypressed = '0';break;
        case (0xed): keypressed = '1';break;
        case (0xeb): keypressed = '2';break;
        case (0xe7): keypressed = '3';break;
        case (0xde): keypressed = '4';break;
        case (0xdd): keypressed = '5';break;
        case (0xdb): keypressed = '6';break;
        case (0xd7): keypressed = '7';break;
        case (0xbe): keypressed = '8';break;
        case (0xbd): keypressed = '9';break;
        case (0xbb): keypressed = 'A';break;
        case (0xb7): keypressed = 'B';break;
        case (0x7e): keypressed = 'C';break;
        case (0x7d): keypressed = 'D';break;
        case (0x7b): keypressed = 'E';break;
        case (0x77): keypressed = 'F';break;
        default : keypressed = 'X';
      }//end of switch
      while((KB_PORT_IN & 0xF0) != 0xF0){
        //_delay_ms(20);
        //tmp = PINB;
        //usart_putch(tmp);
      }
    }//end of if
  }//end of for
  return(keypressed);
}//end of keypad()

