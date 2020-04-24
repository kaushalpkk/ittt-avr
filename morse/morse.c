 //works

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>
#include <util/delay.h>
#include "mcode.h"
#include "didat.h"
#include "lcd4.h"
#include "stringf.h"
#include "others.h"

unsigned int rep, letts;     //for looping display, looping count
//in conversion of ascii to mcode 
unsigned int text, c, d;  //for text input frm kbd
unsigned int mditdat;
char ready[] = "*****READY!*****";  //display
char kbdata[60];        //stores the data frm keybd to this string
char proc[] = "  Processing..";  //display
char readya[] = "Press enter to";  //display dat text.. 14 char
char readyb[] = "transmit codes..";  //display dat text ..16 char
char morsedat[60];


int main(void) {

    InitLCD();

    gettimed();  //get value for adc for "timed"

for(rep=0;rep<2;rep++){
    SendString(ready, 1, 0);// displays ready !!
    delayms(700);
    SendCommand(0x01);
    delayms(700);
    }

    getdata();

    SendCommand(0x01);      //clears off the screen...
    
    SendString(proc, 1, 0); // plain string displays "processing"     

    tomcodes();
    
    text = 666;

    delayms(800);

    SendCommand(0x01);

    SendString(readya, 1, 1); // plain string displays "Press enter to"

    SendString(readyb, 2, 0); // plain string displays "transmit codes.."
    
while(text != '\n'){
    text = kbgetchar();

    return(text);
}

letts = 0;

while(1) {

        if (morsedat[d] == 0x00){
            wordspc();
        }
         
        if (morsedat[d] == 0x80){
            charspc();
        }

mditdat = morsedat[d] & 0x80;

        if (mditdat == 0x80){
            datout();
        }
     else{
        ditout();
    } 
  }    
return(0);
}
