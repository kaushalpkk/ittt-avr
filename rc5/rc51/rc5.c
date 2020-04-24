//works

//#include <stdio.h>
#define F_CPU 1000000
#define USART_BAUDRATE 2400

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "usart.h"
 
int main(void)
{
    unsigned char str[] = "I am working.";
    uint8_t i = 0;
    uint8_t noise;
    uint16_t in,in2;
    
    //initialise, do check
    //DDRB |= (1 << PB1);
    DDRB = 0x00;                //set port b as input..
    usart_init();
    _delay_ms(1000);
    usart_puts(str);
    
    //the main loop
    while(1)
    {
        //PORTB |= (1 << PB1);
        PORTB = 0xFF;   //pullups for port b...
        //wait for trigger
        while ((PINB & 0x01) != 0);     //while 1st bit = 1..
        PORTB |= (1 << PB1);    //
 
        //clear sample variable
        in = 0;
        for (i = 0; i < 14; i++)
        {
            //sample the data
            if ((PINB & 0x01) != 0)
                in |= 0x0001;
         
            //shift the variable
            in <<= 1;
                
            //and wait for the next sample
            _delay_ms(1);
            _delay_us(700);
        }
        
        //noise: bit 0: 1; bit 1: 0; bit 2: 0
        noise = 0;
         
        if (((in & 0x4000) == 0) && ((in & 0x2000) != 0) && ((in & 0x1000) != 0))
            noise = 1;
            
        //print our captured data
        if (noise == 0)
        {
            in2 = in;
            for (i = 0; i < 14; i++)
            {
            //data stored inverted (as from receiver)
                if ((in2 & 0x4000) != 0)
                    usart_putch('0');
                else
                    usart_putch('1');
            //break into logic blocks
            if (i == 1 || i == 2 || i == 7)
                usart_putch(' ');
            
                in2 <<= 1;
            }       
            usart_putch(0x0D);
            usart_putch(0x0A);
            _delay_ms(1000);
        }
    }
}
