/*
 * gsm.c
 *
 *  Created on: 6 kwi 2015
 *      Author: Marcin
 */
#include "gsm.h"
#include "usart.h"
#include "string.h"

void send_sms(unsigned char* number, unsigned char* text)
{
	unsigned char buffer[40];
	unsigned char i;

	strcpy(buffer,"AT+CMGF=1\0");

	for(i=0; i<strlen(buffer);i++)
		USART_Transmit(buffer[i]);
	_delay_ms(100);

	strcpy(buffer,"AT CMGS=\"");
	strcat(buffer,"+48691928877");
	strcat(buffer,"\"\rdupa\032\0");

	for(i=0; i<strlen(buffer);i++)
		USART_Transmit(buffer[i]);
}
