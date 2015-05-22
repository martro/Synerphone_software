#include <global.h>

/**
 * Funkcja pomocnicza. Czeka, aż na szynie zegarowej pojawi się "0".
 * Sprawdzenie ograniczoną ilość razy zapobiega zapętleniu.
 */
uint8_t ps2_waitForClear(uint8_t *clkPort, uint8_t clkPin) {
  uint8_t attempt = 0;
  for(attempt=0; attempt<12; attempt++) {
    _delay_us(10);
    if(bit_is_clear(PIN(*clkPort),clkPin)) {
      return 1;
    }
  }

  return 0;
}

/**
 * Funkcja pomocnicza. Czeka, aż na szynie zegarowej pojawi się "0".
 * Oczekuje dłużej, niż std, ponieważ przy wysyłaniu bajtu czas oczekiwania na "0"
 * w dwóch momentach może być dłuższy aż do 10ms
 * Sprawdzenie ograniczoną ilość razy zapobiega zapętleniu.
 */
uint8_t ps2_longWaitForClear(uint8_t *clkPort, uint8_t clkPin) {
  uint8_t attempt, h;
  for(attempt=0; attempt<240; attempt++) {
    for(h=0; h<10; h++ ) {
      _delay_us(10);
      if(bit_is_clear(PIN(*clkPort),clkPin)) {
	return 1;
      }
    }
  }

  return 0;
}


/**
 * Funkcja pomocnicza. Czeka, aż na szynie zegarowej pojawi się "1".
 * Sprawdzenie ograniczoną ilość razy zapobiega zapętleniu.
 */
uint8_t ps2_waitForSet(uint8_t *clkPort, uint8_t clkPin) {
  uint8_t attempt = 0;
  for(attempt=0; attempt<12; attempt++) {
    _delay_us(10);
    if(bit_is_set(PIN(*clkPort),clkPin)) {
      return 1;
    }
  }

  return 0;
}

uint8_t ps2_read(uint8_t *dataPort, uint8_t dataPin, uint8_t *clkPort, uint8_t clkPin) {
  uint8_t data = 0;
  uint8_t i;
  uint8_t parity = 0;

  DDR(*dataPort) &= ~_BV(dataPin);
  DDR(*clkPort) &= ~_BV(clkPin);
  *dataPort |= _BV(dataPin);
  *clkPort |= _BV(clkPin);
 
   if(!ps2_longWaitForClear(clkPort, clkPin)) return 0;
  //bit startu
   if(!bit_is_clear(PIN(*dataPort),dataPin))
     return 0;
   if(!ps2_waitForSet(clkPort, clkPin)) return 0;


  for(i=0;i<8;i++) {
    if(!ps2_waitForClear(clkPort, clkPin)) return 0;
    data = data >> 1;

    if(!bit_is_clear(PIN(*dataPort),dataPin))
      data |= 128;
    else
      parity ++;

    if(!ps2_waitForSet(clkPort, clkPin)) return 0;
  }

  if(!ps2_waitForClear(clkPort, clkPin)) return 0;
  if(bit_is_clear(PIN(*clkPort),dataPin) != parity%2)
    return 0;
  if(!ps2_waitForSet(clkPort, clkPin)) return 0;

  if(!ps2_waitForClear(clkPort, clkPin)) return 0;
   if(!bit_is_set(PIN(*dataPort),dataPin))
     return 0;
  if(!ps2_waitForSet(clkPort, clkPin)) return 0;


  DDR(*dataPort) |= _BV(dataPin);
  DDR(*clkPort) |= _BV(clkPin);
  *dataPort |= _BV(dataPin);
  *clkPort &= ~_BV(clkPin);

return data;
}


uint8_t ps2_write(uint8_t *dataPort, uint8_t dataPin, uint8_t *clkPort, uint8_t clkPin, uint8_t data) {
  uint8_t i;
  uint8_t parity = 0;

//   DDR(*dataPort) |= _BV(dataPin);
//   DDR(*clkPort) |= _BV(clkPin);
//   *dataPort |= _BV(dataPin);
//   *clkPort |= _BV(clkPin);
// 

  DDR(*clkPort) |= _BV(clkPin);
  DDR(*dataPort) |= _BV(dataPin);

  *dataPort |= _BV(dataPin);
  *clkPort &= ~_BV(clkPin);

 
  _delay_us(150);
  
  *dataPort &= ~_BV(dataPin);
  *clkPort |= _BV(clkPin);


  DDR(*clkPort) &= ~_BV(clkPin);
  *clkPort |= _BV(clkPin);
// ^^^ sekwencja "a" i bit startu


  if(!ps2_longWaitForClear(clkPort, clkPin)) return 1;

  for(i=0; i<8; i++) {

    if(!bit_is_clear(data,0)) {
      *dataPort |= _BV(dataPin);
    } else {
      *dataPort &= ~_BV(dataPin);
      parity ++;
    }

    if(!ps2_waitForSet(clkPort, clkPin)) return 4;
    if(!ps2_waitForClear(clkPort, clkPin)) return 5;

    data = data >> 1;
  }

  //parity bit
  if(parity%2)
    *dataPort &= ~_BV(dataPin);
  else
    *dataPort |= _BV(dataPin);

  if(!ps2_waitForSet(clkPort, clkPin)) return 6;
  if(!ps2_waitForClear(clkPort, clkPin)) return 7;

  *dataPort |= _BV(dataPin);

  DDR(*dataPort) &= ~_BV(dataPin);
  *dataPort |= _BV(dataPin);

  if(!ps2_waitForSet(clkPort, clkPin)) return 8;

//ack
  if(!ps2_waitForClear(clkPort, clkPin)) return 11;
  if(!ps2_waitForSet(dataPort, dataPin)) return 10;

   
  DDR(*dataPort) |= _BV(dataPin);
  DDR(*clkPort) |= _BV(clkPin);
  *dataPort |= _BV(dataPin);
  *clkPort &= ~_BV(clkPin);

return 0;
}

