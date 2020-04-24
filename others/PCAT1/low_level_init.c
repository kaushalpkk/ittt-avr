#include <ina90.h>
#include <io8515.h>

int __low_level_init(void)
{
    UBRR = 12;          // 19200bps @ 4 MHz
    UCR  = 0x08;        // RX enable, TX enable
    GIMSK= 0x40;        // Enable INT0 interrupt
    
    _SEI();
    return 1;
}

