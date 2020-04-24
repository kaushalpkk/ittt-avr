/* FUNCTIONS USED..

delayms(number)

Delay(number)
*/

void delayms(uint16_t millis) {
  while ( millis ) {
    _delay_ms(1);
    millis--;
  }
}

void Delay(uint32_t count)
{
    while(count)count--;
}