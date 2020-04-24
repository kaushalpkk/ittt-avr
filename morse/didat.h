#define F_CPU 1000000UL

unsigned int rep, letts, timed;     //for looping display, looping count
//in conversion of ascii to mcode 
unsigned int text, c, d;  //for text input frm kbd
unsigned int mditdat;
char kbdata[60];        //stores the data frm keybd to this string
char morsedat[60];

//#include <avr/pgmspace.h> //to store data in flash memory..
#include <avr/io.h>
#include <util/delay.h>

#define PORTX PORTA
#define inp(x) x
#define outp(x,y) y=x
#define sbi(y,x) y|=_BV(x)
#define cbi(y,x) y&=~_BV(x) //  (assign portname,pinno)

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}

void ditout(void){      // dit sound . 

    sbi(PORTX,2);
    delayms(timed);
    cbi(PORTX,2);
    morsedat[d] = morsedat[d] << 1;
}

void datout(void){      //dat sound _

    sbi(PORTX,2);
    delayms(3 * timed);
    cbi(PORTX,2);
    morsedat[d] = morsedat[d] << 1;
}

void charspc(void){     //charspc  for dit timed delay

    delayms(2 * timed);
    d++;
    
}

void wordspc(void){     //wordspc for word delay 5 dit length..

    delayms(4 * timed);
    d++;
}