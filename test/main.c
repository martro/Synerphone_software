/*
 * main.c
 *
 *  Created on: 02-04-2015
 *      Author: Marcin
 */

#include <avr/io.h>
#include <util/delay.h>
#include "HD44780.h"
#include "atkeyboard.h"
#include "globals.h"
#include "string.h"
#include "scancodes.h"
#include "usart.h"
#include "LED.h"
#include "gsm.h"
#include "lcd.h"
#include "menu.h"
#include "adc.h"
#include "string.h"
#include <math.h>

int main(void) {
	MCUCSR |=(1<<JTD);
	MCUCSR |=(1<<JTD);
	//extern volatile unsigned char received[40];
	//extern volatile unsigned char to_send[40];

	strcpy(LCD_top,"                ");
	strcpy(LCD_bottom,"                ");
	LEDs_init();
	LCD_Initalize();
	initATkbd();
	USART_Init(51); //9600 at 8MHz
	_delay_ms(2000); //wait for all devices to boot
	_delay_ms(2000);
	_delay_ms(2000);
	_delay_ms(2000);
	USART_Transmit_string("\r\n");
	_delay_ms(2000);

	sei();
	init_adc();

	strcpy(to_send, "AT\n");

	char tekst[4];

	int i=0;

	while (1)
	{
	strcpy(to_send, "AT+CMGF=1\r\n");
	USART_Transmit_string(to_send);
	_delay_ms(3000);
	LED_Red_ON();
	strcpy(to_send, "AT+CMGS=\"+48691928877\"\r\n");
	USART_Transmit_string(to_send);
	_delay_ms(2000);
	LED_Red_OFF();
	strcpy(to_send,"dupa");
	itoa(i,tekst,10);
	strcat(to_send,tekst);
	strcat(to_send, "\x1A\r\n");
	USART_Transmit_string(to_send);
	_delay_ms(8000);
	i++;

	//USART_Transmit('a');

	_delay_ms(2000);

	lcd_display(LCD_top,LCD_bottom);
	}

}
