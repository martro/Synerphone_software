/*
 * lcd.c
 *
 *  Created on: 6 kwi 2015
 *      Author: Marcin
 */
#include "lcd.h"

void lcd_display(char* top, char* bottom) {
	LCD_GoTo(0, 0);
	LCD_WriteText(top);
	LCD_GoTo(0, 1);
	LCD_WriteText(bottom);
}

void mode_1(void) { //commands from keyboard (sending)

	unsigned char keyboard_str[4];
	unsigned char to_send_size_string[4];
	unsigned char i;

	itoa(keyboard_int, keyboard_str, 10); //convert keyboard key number to string
	keyboard_str[3] = '\0';

	if (strlen(to_send) >= 16)
		for (i = 0; i < 16; i++)
			LCD_top[i] = to_send[strlen(to_send) - 16 + i];
	else {
		strcpy(LCD_top, to_send);
		for (i = strlen(LCD_top); i < 16; i++)
			strcat(LCD_top, " ");
	}

	if (CAPS)
		strcpy(LCD_bottom, "CAPS");
	else
		strcpy(LCD_bottom, "    ");

	strcat(LCD_bottom, " [");

	for (i = 0; i < (3 - strlen(keyboard_str)); i++)
		strcat(LCD_bottom, "0");

	strcat(LCD_bottom, keyboard_str);
	strcat(LCD_bottom, "] ");

	itoa(strlen(to_send), to_send_size_string, 10);

	if (strlen(to_send) < 10)
		strcat(LCD_bottom, " ");

	strcat(LCD_bottom, to_send_size_string);

	if (toggle) {
		strcat(LCD_bottom, " <<");
		PORTC |= (1 << PC2);
		PORTC &= ~(1 << PC3);
	} else {
		strcat(LCD_bottom, " >>");
		PORTC &= ~(1 << PC2);
		PORTC |= (1 << PC3);
	}
}

void mode_2(void) //display replies from GSM
{
	unsigned char i;
	LCD_bottom[0] = '\0';
	unsigned char str[4];

	for (i = strlen(usart_received); i < 16; i++) {
		strcat(LCD_bottom, " ");

		if (strlen(to_send) >= 16)
			for (i = 0; i < 16; i++)
				LCD_bottom[i] = usart_received[strlen(usart_received) - 16 + i];
		else {
			strcpy(LCD_bottom, usart_received);
			for (i = 0; i < strlen(usart_received); i++) {

				LCD_bottom[i]=usart_received[i];

				if (usart_received[i] == 13)
					LCD_bottom[i] = '!';
				if (usart_received[i] == 10)
					LCD_bottom[i] = '@';
			}

			for (i = strlen(LCD_bottom); i < 16; i++)
				strcat(LCD_bottom, " ");

			itoa(strlen(usart_received), str, 10); //convert keyboard key number to string
			str[3] = '\0';
			strcpy(LCD_top,str);
		}

	}
}
