#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int length = 15; // the number of notes
int tempo = 50;
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };

//int length = 15; // the number of notes
//int tempo = 30;
//char notes[] = "CbgCbeRCcgaC ";
//int beats[]  = { 2, 2, 2, 1, 2, 2, 4, 2, 2, 2, 1, 1, 1 }; 


void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}
void delayus(uint16_t millis) {
  while ( millis ) {
    _delay_us(1);
    millis--;
  }
}


void playTone(int tone, int duration) {
  long i;
  for (i = 0; i < duration * 1000L; i += tone * 2) {
    PORTB = 0xFF;
    delayus(tone);
    PORTB = 0x00;
    delayus(tone);
  }
}

void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  int i;
  // play the tone corresponding to the note name
  for (i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i]/16, duration);/////////2,4,8,16
    }
  }
}


int main(void){
  int i;
  DDRB = 0xFF;
  while(1){
    for (i = 0; i < length; i++) {
      if (notes[i] == ' ') {
        delayms(beats[i] * tempo); // rest
      } else {
        playNote(notes[i], beats[i] * tempo);
      }

      // pause between notes
      delayms(tempo / 2); 
    }
  }
}

