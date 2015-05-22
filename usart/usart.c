#include "usart.h"

void USART_Init(unsigned int ubrr) /*Jako ubrr wchodzi MYUBRR, który jest podany w nocie*/
{
    /* Set baud rate */
    UBRRH = (unsigned char)(ubrr>>8);
    UBRRL = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSRB = (1<<RXEN)|(1<<TXEN)|(1 << RXCIE ); //w³¹czenie przerwania
    /* Set frame format: 8data, 2stop bit */
    UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);


}

void USART_Transmit( unsigned char data )
{
    /* Wait for empty transmit buffer */
    while ( !( UCSRA & (1<<UDRE)) )
        ;
    /* Put data into buffer, sends the data */
    UDR = data;
}

unsigned char USART_Receive( void )
{
    /* Wait for data to be received */
    while ( !(UCSRA & (1<<RXC)) )
        ;
    /* Get and return received data from buffer */
    return UDR;
}

//Przerwanie na RXC
ISR ( USART_RXC_vect )
{
	extern char RX_Buffer;
	extern char GotByte;

	extern char buffer_test[10];
	extern char index_test;

	char ReceivedByte;


    ReceivedByte = USART_Receive();
    buffer_test[index_test]=ReceivedByte;
    index_test++;
    if (index_test==9)
    	index_test=0;


    USART_Transmit(ReceivedByte);

	char tekst[100];
	itoa(ADC,tekst,10);

    RX_Buffer = ReceivedByte;
    GotByte = 1;
}

