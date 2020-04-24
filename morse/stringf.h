
unsigned int text, c=0, d=0, addr;  //for text input frm kbd
unsigned int rep=0, letts=0, count= 0;     //for looping display, looping count
//in conversion of ascii to mcode 
unsigned int mditdat;
char kbdata[60];        //stores the data frm keybd to this string
char morsedat[60];

//function to read kybd, disp each char in lcd and
// save each char in a string
unsigned char getdata(void){
    while (text != '\n'){
              //to send to lcd.... SendCommand(text);        // change dis <<<<<<<<<   writes d letter to LCD ie senddata();
        kbdata[c] = text;    //    save each of letter to a string
        letts++;
    }
return(0);
}


/*function to convert each letter frm the string to morse coded string
and save it as a new string called as morsedat... 
*/


unsigned int tomcodes(void){
    c = 0;
    d = 0;
    count = 0;
        while(count < letts){
            addr = kbdata[c] - 10;//offset of ascii;
            morsedat[d] = marray[addr];
            d++;
            c++;
            count++;
        }
return(0);
}

int kbgetchar(){
//returns the read value to text.... variable

return(0);
}

int gettimed(){


return(0);
}
