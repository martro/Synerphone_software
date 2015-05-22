#include "atkeyboard.h"
#include "string.h"
#include "stdlib.h"
#include "HD44780.h"

unsigned char volatile dane = 0, nowy = 0, i = 0;

volatile unsigned char pressed, released, toggle;

// procedura obs³ugi przerwania zewnêtrzneg
#if ATKbdClk == PD2
#define USE_INT0
ISR(INT0_vect)
#elif ATKbdClk == PD3
#define USE_INT1
ISR(INT1_vect)
#endif
{
	switch (i) {
	case 0:
		dane = 0;
		i++;
		pressed = 1;
		break;
	case 1:
		if (ATKbdGetDta())
			dane |= 0x01;
		i++;
		break;
	case 2:
		if (ATKbdGetDta())
			dane |= 0x02;
		i++;
		break;
	case 3:
		if (ATKbdGetDta())
			dane |= 0x04;
		i++;
		break;
	case 4:
		if (ATKbdGetDta())
			dane |= 0x08;
		i++;
		break;
	case 5:
		if (ATKbdGetDta())
			dane |= 0x10;
		i++;
		break;
	case 6:
		if (ATKbdGetDta())
			dane |= 0x20;
		i++;
		break;
	case 7:
		if (ATKbdGetDta())
			dane |= 0x40;
		i++;
		break;
	case 8:
		if (ATKbdGetDta())
			dane |= 0x80;
		i++;
		break;
	case 9:
		i++;
		break;
	case 10:
		nowy = 1;
		mode=1;
		i = 0;
		if (dane == 240) {
			toggle ^= 1;
			keyboard_ready = 1;
		} else
			keyboard_int = dane;

		getcommand();

		break;
	}

}

// funkcja inicjalizuj¹ca porty oraz przerwania
// wykorzystywane przy obs³udze klawiatury.
void initATkbd(void) {
	ATKbdDtaIn(); // linia DATA pracuje jako wejœcie
	ATKbdSetDta(); // w³aczenie rezystora podci¹gajacego linii DATA
	ATKbdClkIn(); // linia CLK pracuje jako wejœcie
	ATKbdSetClk(); // w³aczenie rezystora podci¹gaj¹cego lini CLK

#ifdef USE_INT0
	GICR |= (1 << INT0);  // zezwolenie na przerwanie INT0
	MCUCR |= (1 << ISC01); // przerwanie INT0 wyzwalane zboczem opadaj¹cym
#endif

#ifdef USE_INT1
	GICR |= (1 << INT1);  // zezwolenie na przerwanie INT1
	MCUCR |= (1 << ISC11);// przerwanie INT1 wyzwalane zboczem opadaj¹cym
#endif

	sei();
	// globalne odblokowanie przerwañ
}

// funkcja odczytujaca kod naciœniêtego klawisza
unsigned char getATkbd(void) {
	while (!nowy)
		; // oczekiwanie na odebranie nowego znaku
	nowy = 0; // zerowanie flagi odebrania znaku
	return dane;
}

void getcommand(void) {
	unsigned char bufor[2];
	bufor[1] = '\0';


	if (pressed && keyboard_ready) {
		keyboard_ready = 0;

		bufor[0] = pgm_read_byte(&scancodes[keyboard_int]);

		if (keyboard_int == 88)
			CAPS ^= 1;

		if (keyboard_int==005)// F1 key pressed
		{
			/*for (i=0; i<5;i++)
			{
				USART_Transmit('x');
				_delay_ms(100);
			}*/

			ready_to_send=1;
			//USART_Transmit_string(to_send);


			bufor[0]='\0';
		}

		if (CAPS) {
			if (bufor[0] >= 97 && bufor[0] <= 122)
				bufor[0] = bufor[0] - 32;
			if (bufor[0] == '=')
				bufor[0] = '+';
			if (keyboard_int == 82)
				bufor[0] = '\"';
		}
		pressed = 0;

		if (bufor == 13)
			bufor[0] = '\0';

		if (keyboard_int == 102 && strlen(to_send))
			to_send[strlen(to_send) - 1] = '\0';
		strcat(to_send, bufor);
		lcd_display();
	}
}

