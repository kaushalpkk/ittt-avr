//works

//#include <stdio.h>
#define F_CPU 1000000
#define USART_BAUDRATE 2400

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd4.h"
 
int main(void)
{
    char str[] = "I am working.";
    uint8_t i = 0;
    uint8_t noise;
    uint16_t in,in2;
    
    //initialise, do check
    //DDRB |= (1 << PB1);
    DDRB = 0x00;                //set as outputs...
    InitLCD();
    _delay_ms(1000);
    SendString(str, 1, 1);
    
    //the main loop
    while(1)
    {
        //PORTB |= (1 << PB1);
        PORTB = 0xFF;           //use pullups...
        //wait for trigger
        while ((PINB & 0x01) != 0);
        PORTB |= (1 << PB1);    
 
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
                if ((in2 & 0x4000) != 0){
                    SendInt(0, 1, i);
                        _delay_ms(2);
                }
                else
                    SendInt(1, 1, i);
                        _delay_ms(2);
            //break into logic blocks
            if (i == 1 || i == 2 || i == 7)
                SendInt(' ', 1, 1);
            
                in2 <<= 1;
            }       
            _delay_ms(2000);
            SendCommand(0x01);
            _delay_ms(200);
        }
    }
}
