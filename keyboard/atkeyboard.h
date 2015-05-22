#include <avr/io.h>
#include <avr/interrupt.h>
//
#define ATKbdPort PORTD
#define ATKbdPin  PIND
#define ATKbdDir  DDRD
//
#define ATKbdClk  PD2
//
#define ATKbdDta  PD0
//
#define ATKbdGetDta() (ATKbdPin & (1 << ATKbdDta))
#define ATKbdGetClk() (ATKbdPin & (1 << ATKbdClk))
//
#define ATKbdSetDta() ATKbdPort |= (1 << ATKbdDta)
#define ATKbdClrDta() ATKbdPort &= ~(1 << ATKbdDta)
//
#define ATKbdSetClk() ATKbdPort |= (1 << ATKbdClk)
#define ATKbdClrClk() ATKbdPort &= ~(1 << ATKbdClk)

#define ATKbdDtaOut() ATKbdDir |= (1 << ATKbdDta)
#define ATKbdDtaIn()  ATKbdDir &= ~(1 << ATKbdDta)

#define ATKbdClkOut() ATKbdDir |= (1 << ATKbdClk)
#define ATKbdClkIn()  ATKbdDir &= ~(1 << ATKbdClk)

unsigned char getATkbd(void);
void initATkbd(void);
