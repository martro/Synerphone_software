#ifndef __PS2_H
#define __PS2_H

/**
 * Obsługa protokołu PS/2.
 * NIE nadaje się do zastosowań time-critical.
 * wersja 1
 * 
 * slis@edap.pl
 * http://edap.pl/
 */


/**
 * Odczytuje kolejny bajt danych z urządzenia. 
 * @param dataPort - Port mikrokontrolera, do którego podłączona jest szyna danych-DATA (np PORTB)
 * @param dataPin - Pin portu mikrokontrolera, do którego podłączona jest szyna danych-DATA (np PB0)
 * @param clkPort - Port mikrokontrolera, do którego podłączona jest szyna zegara-CLK (np PORTB)
 * @param dataPin - Pin portu mikrokontrolera, do którego podłączona jest szyna zegara-CLK (np PB1)
 * @return Wartość odczytanego bajtu, lub 0 jeśli wystąpił błąd
 */
uint8_t ps2_read(uint8_t *dataPort, uint8_t dataPin, uint8_t *clkPort, uint8_t clkPin);

/**
 * Przesyła bajt danych do urządzenia
 * @param dataPort - Port mikrokontrolera, do którego podłączona jest szyna danych-DATA (np PORTB)
 * @param dataPin - Pin portu mikrokontrolera, do którego podłączona jest szyna danych-DATA (np PB0)
 * @param clkPort - Port mikrokontrolera, do którego podłączona jest szyna zegara-CLK (np PORTB)
 * @param dataPin - Pin portu mikrokontrolera, do którego podłączona jest szyna zegara-CLK (np PB1)
 * @param data - Wartość bajtu do przesłania
 * @return 0-transmisja ok, lub kod błędu
 */
uint8_t ps2_write(uint8_t *dataPort, uint8_t dataPin, uint8_t *clkPort, uint8_t clkPin, uint8_t data);

#endif 
