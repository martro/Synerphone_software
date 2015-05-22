#ifndef USART_H_
#define USART_H_

/*str 159 datasheet AtMega*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "HD44780.h"
#include <string.h>
#include <stdlib.h>
#include "globals.h"

/*Funkcje z datasheet*/
void USART_Init(unsigned int ubrr);
void USART_Transmit(unsigned char data);
void USART_Transmit_string(unsigned char*);
unsigned char USART_Receive(void);
ISR(USART_RXC_vect);

#endif /* USART_H_ */
