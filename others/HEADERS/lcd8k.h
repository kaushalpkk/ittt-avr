//8bit mode...

#define PORT PORTC
#define DDR DDRC
#define PIN PINC

#define PORT2 PORTD
#define DDR2 DDRD

#define enable 5 
#define rw 6
#define rs 7

#define inp(x) x
#define outp(x,y) y=x
#define sbi(y,x) y|=_BV(x)
#define cbi(y,x) y&=~_BV(x)

DDR  = 0xFF;
DDR2 = OxFF;

//TO INITIALISE lcd

void initlcd(void)
{

    outp(0x00, PORT);               // all low
    outp(0xff, DDR);                // all output
    _delay_ms(50);                      // wait 50 mSec
    outp(0x03, PORT);
    _delay_ms(5);
    outp(0x03, PORT);
    _delay_ms(5);
    outp(0x03, PORT);
    _delay_ms(5);
    outp(0x02, PORT);
    _delay_ms(5);
    
    sendcmd(0x38);  // 8bit - 2 line - 5x7
    sendcmd(0x08);  //Display off Cursor off
                    //(clearing display without clearing DDRAM content)
    sendcmd(0x0c);
    sendcmd(0x01);  //Clear Display (also clear DDRAM content)
    sendcmd(0x06);  //ENTRY MODE ?????????????
}
     

//to send command directly using a function....
sendcmd(unsigned char comm){
     PORT = comm;
     cbi (PORT2 , rs);
     cbi (PORT2 , rw);
     clock();
     lcdbusy();
return();
}

//uncalculated delay for BF setting..

void lcdbusy(){
    unsigned char i, j;
      for (i=0;i<50;i++)
         for(j=0;j<75;j++)
}

//clock pulse..enable-disable

static void clock(void){
    sbi(PORT2 , enable)
    tick();
    cbi(PORT2 , enable)

//small delay..

static inline void Tick(void){
    asm("nop\n\tnop"::);
}


// send data to lcd 

senddata(unsigned char text1){
     PORT = text1;
     sbi (PORT2 , rs);
     cbi (PORT2 , rw);
     clock();
     lcdbusy();
return();
}

/*



void SendString(char *pt, int line, int position)
{
    if (line == 1)
        SendCommand(0x80 + position);
    else
        SendCommand(0xc0 + position);
    while (*pt)
        SendData(*pt++);
}