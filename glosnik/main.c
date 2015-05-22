#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <math.h>

#define C1 119
#define D1 106
#define E1 95
#define F1 89
#define G1 80
#define A1 71
#define H1 63
#define C2 60

volatile int Licznik=0;
int LiczImp = C1;
unsigned char Tablica[120];


void setTablica();
void on();
void off();

int main(void)
{
	int Gama[] = {C1,C2,E1,F1,G1,A1,H1,C2};
	int i;

	DDRD |= (1<<PD5)
			|(1<<PD6);
	PORTD |= (1<<PD5)
			|(1<<PD6);

	TCCR1A |= (1<<COM1A1) // clear OC1A on compare match, set at BOTTOM
				|(1<<WGM10); // Fast PWM 8-Bit (WGM10, WGM11, WGM12)
	TCCR1B |= (1<<WGM12)
			|(1<<CS10); // prescaler x8
	OCR1A = 128;
	TIMSK |= (1<<OCIE1A);
	sei();
	setTablica();


	for(;;){
		for(i=0;i<2;i++){
			on();
			LiczImp = Gama[i];
			setTablica();
			_delay_ms(125);
			off();
		}

	}
}

ISR (TIMER1_COMPA_vect)
{
	Licznik++;
	OCR1A = Tablica[Licznik-1];
	if(Licznik >= LiczImp){
		Licznik = 0;
	}
}

ISR (BADISR_vect){}

void setTablica()
{
	PORTB |= (1<<PB0);
	int i;
	float temp, fLiczImp=LiczImp;
	for(i=0;i<LiczImp;i++){
		temp = sin(2*M_PI*(i/fLiczImp))*256;
		Tablica[i] = (int)temp;
	}
	PORTB &= ~(1<<PB0);
}

void on()
{
	TCCR1A |= (1<<COM1A1);
}

void off()
{
	TCCR1A &= ~(1<<COM1A1);
}
