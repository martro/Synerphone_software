#include "atkeyboard.h"

unsigned char volatile dane = 0, nowy = 0, i = 0;

// procedura obs�ugi przerwania zewn�trzneg
#if ATKbdClk == PD2
  #define USE_INT0
  ISR(INT0_vect)
#elif ATKbdClk == PD3
  #define USE_INT1
  ISR(INT1_vect)
#endif
{
switch(i){
  case 0 :
  dane = 0;
  i++;
  break;
  case 1 :
  if(ATKbdGetDta()) dane |= 0x01;
  i++;
  break;
  case 2 :
  if(ATKbdGetDta()) dane |= 0x02;
  i++;
  break;
  case 3 :
  if(ATKbdGetDta()) dane |= 0x04;
  i++;
  break;
  case 4 :
  if(ATKbdGetDta()) dane |= 0x08;
  i++;
  break;
  case 5 :
  if(ATKbdGetDta()) dane |= 0x10;
  i++;
  break;
  case 6 :
  if(ATKbdGetDta()) dane |= 0x20;
  i++;
  break;
  case 7 :
  if(ATKbdGetDta()) dane |= 0x40;
  i++;
  break;
  case 8 :
  if(ATKbdGetDta()) dane |= 0x80;
  i++;
  break;
  case 9 :
  i++;
  break;
  case 10 :
  nowy = 1;
  i = 0;
  break;
  }
}

// funkcja inicjalizuj�ca porty oraz przerwania
// wykorzystywane przy obs�udze klawiatury.
void initATkbd(void)
{
ATKbdDtaIn(); // linia DATA pracuje jako wej�cie
ATKbdSetDta();// w�aczenie rezystora podci�gajacego linii DATA
ATKbdClkIn(); // linia CLK pracuje jako wej�cie
ATKbdSetClk();// w�aczenie rezystora podci�gaj�cego lini CLK

#ifdef USE_INT0
  GICR |= (1 << INT0);  // zezwolenie na przerwanie INT0
  MCUCR |= (1 << ISC01); // przerwanie INT0 wyzwalane zboczem opadaj�cym
#endif

#ifdef USE_INT1
  GICR |= (1 << INT1);  // zezwolenie na przerwanie INT1
  MCUCR |= (1 << ISC11); // przerwanie INT1 wyzwalane zboczem opadaj�cym
#endif

sei(); // globalne odblokowanie przerwa�
}

// funkcja odczytujaca kod naci�ni�tego klawisza
unsigned char getATkbd(void)
{
while(!nowy); // oczekiwanie na odebranie nowego znaku
nowy = 0; // zerowanie flagi odebrania znaku
return dane;
}




