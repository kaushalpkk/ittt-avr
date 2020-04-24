//works
#define F_CPU 1000000
//At 1MHz 4800 is max baud rate

#define USART_BAUDRATE 2400
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#include <avr/io.h>
#include <util/delay.h>

void usart_init(){
   
  UCSRB |= (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
  UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes

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

   while (*stringptr != 0x00)
   {
      usart_putch(*stringptr);
      stringptr++;
   }
}

void puthex( unsigned char data ){

  unsigned char ascii[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  usart_putch(ascii[(data >> 4) & 0x0F]);
  usart_putch(ascii[data & 0x0F]);
}

int main (void){

  unsigned char ReceivedByte;
  unsigned char str[] = "I am working.";

  usart_init();
  _delay_ms(100);
  _delay_ms(100);
  _delay_ms(100);
  _delay_ms(100);

  usart_puts(str);
  usart_putch(0x0D);
  usart_putch(0x0A);

  while(1) // Loop forever
  {
    ReceivedByte = usart_getch();
	usart_putch(ReceivedByte);
	usart_putch(' ');
	puthex(ReceivedByte);
	usart_putch(0x0D);
	usart_putch(0x0A);
   }
}

