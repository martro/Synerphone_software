/*
 * menu.c
 *
 *  Created on: 19 maj 2015
 *      Author: Marcin
 */

#include "menu.h"

void menu(void)
{
	lcd_display("|TRYB SERWISOWY|","|##############|");



	while(1)
	{
		if (keyboard_int==90)
			lcd_display("aaa","bbb");
		else
			lcd_display("ccc","ddd");
	}
}
