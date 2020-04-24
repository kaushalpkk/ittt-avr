// Remember to include avr313.xcl as your linker file. (Modified for AT90S8515)

#include <pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#include "io8515.h"

#include "serial.h"
#include "gpr.h"
#include "kb.h"


void main(void)
{
    unsigned char key;
    
    init_uart();    // Initializes the UART transmit buffer
    init_kb();        // Initialize keyboard reception

    while(1)
    {
        key=getchar();
        putchar(key);
        delay(100);
    }
}

