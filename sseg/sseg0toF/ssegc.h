
/*

---a---
|      |
f      b
|___g__|
|      |
e      c
|___d__| .h


PORT = msb{ hgfedcba }lsb

*/

#define F_CPU 1000000UL
//#define F_CPU   11059200UL

#include <avr/io.h>

unsigned char segs[16] = {
0x3F,   //      0
0x06,   //      1
0x5B,   //      2
0x4F,   //      3
0x66,   //      4
0x6D,   //      5
0x7D,   //      6
0x07,   //      7   
0x7f,   //      8
0x6F,   //      9
0x77,   //      a
0x7C,   //      b       
0x39,   //      c
0x5E,   //      d
0x7B,   //      e
0x71};  //      f
