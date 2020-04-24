//works
/*
#define KB_PORT_OUT PORTB
#define KB_PORT_IN  PINB
#define KB_PORT_SET DDRB
*/

char fkey[] = "., ,, ', ?, !, 1";
char ekey[] = "a, b, c, A, B, C";
char dkey[] = "d, e, f, D, E, F";
char ckey[] = "g, h, i, G, H, I";
char bkey[] = "j, k, l, J, K, L";
char akey[] = "m, n, o, M, N, O";
char 9key[] = "p, q, r, s, P, Q, R, S";
char 8key[] = "t, u, v, T, U, V";
char 7key[] = "w, x, y, z, W, X, Y, Z";
char 6key[] = " , 0";
//char 5key[] = "., ,, ', ?, !, 1";
//char 4key[] = "., ,, ', ?, !, 1";
//char 3key[] = "., ,, ', ?, !, 1";
//char 2key[] = "., ,, ', ?, !, 1";
//char 1key[] = "., ,, ', ?, !, 1";
//char 0key[] = "., ,, ', ?, !, 1";

unsigned char keypad(void){
  unsigned char tmp, keypressed = 'X', i;

  KB_PORT_SET = 0x0F; //upper nibble input lower output
  
  for(i=0; i<4; i++){

    KB_PORT_OUT = ~(0x01 << i);
    _delay_ms(1); //delay for port o/p settling
      
    tmp = KB_PORT_IN;
    
    if((tmp & 0xF0) != 0xF0){
      switch (tmp){ //generating key characetr to display on LCD
        case (0xee): keypressed = 'F';break;
        case (0xed): keypressed = 'E';break;
        case (0xeb): keypressed = 'D';break;
        case (0xe7): keypressed = 'C';break;
        case (0xde): keypressed = 'B';break;
        case (0xdd): keypressed = 'A';break;
        case (0xdb): keypressed = '9';break;
        case (0xd7): keypressed = '8';break;
        case (0xbe): keypressed = '7';break;
        case (0xbd): keypressed = '6';break;
        case (0xbb): keypressed = '5';break;
        case (0xb7): keypressed = '4';break;
        case (0x7e): keypressed = '3';break;
        case (0x7d): keypressed = '2';break;
        case (0x7b): keypressed = '1';break;
        case (0x77): keypressed = '0';break;
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

