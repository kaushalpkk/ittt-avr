// Keyboard communication routines

#ifndef __KB_INCLUDED
#define __KB_INCLUDED

#include "io8515.h"
#include "pindefs.h"

#define ISC00 0
#define ISC01 1

void init_kb(void);
interrupt [INT0_vect] void INT0_interrupt(void);
void decode(unsigned char sc);
void put_kbbuff(unsigned char c);
int getchar(void);
#endif

