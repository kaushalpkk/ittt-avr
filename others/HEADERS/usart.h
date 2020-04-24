//works
/* FUNCTIONS USED...
include avr/io.h header...

usart_init() - to initialise USART.. see function for specs..

usart_getch() - to get data frm Rx..

usart_puts(unsigned char *stringptr) - to send data frm Tx as a charecter string

usart_putch(unsigned char send)     - to send charecter frm "send" variable

void puthex( unsigned char data )   - to send charecter frm "DATA" variable

*/
//#define F_CPU 1000000
//At 1MHz 4800 is max baud rate

#define USART_BAUDRATE 2400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1) // frm datasheet

void usart_init(){
   
  UCSRB |= (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
// ( 1 << rxen) ... the bitis shifted rxen times... ie.. the rxen has the number of times to shift
//      #def rxen 4 ... so 1 is shiftd 4 times and the value is set ..
//similarly in all regisster s !!

  UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes
//using UCSRC

//usart baud rate regs...
  UBRRL = BAUD_PRESCALE; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
  UBRRH = (BAUD_PRESCALE >> 8); // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
}
void usart_putch(unsigned char send){

  while ((UCSRA & (1 << UDRE)) == 0) {}; // Do nothing until UDR is ready for more data to be written to it
  UDR = send; // Send the byte 
}
unsigned char usart_getch(){

  while ((UCSRA & (1 << RXC)) == 0) {}; // Do nothing until data have been recieved and is ready to be read from UDR
  return(UDR); // return the byte
}
void usart_puts(unsigned char *stringptr){

   while (*stringptr != NULL)
   {
      usart_putch(*stringptr);
      stringptr++;
   }
}

void puthex( unsigned char data ){  //user function to put hex val

  unsigned char ascii[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  usart_putch(ascii[(data >> 4) & 0x0F]);   //rightshift to print 1st char.. lower nibble
  usart_putch(ascii[data & 0x0F]); // send higher nibble..
}

