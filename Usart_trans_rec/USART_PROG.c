/*
 * USART_PROG.c
 *
 *  Created on: Jul 16, 2020
 *      Author: a-m-m abdullah ragab
 */
#include  "STD_TYPES.h"
#include  "BIT_MATHS.h"
#include "USART_INT.h"

#include 	"USART_PRIV.h"

void USART_Init(unsigned int baud) {
	/* Set baud rate */
	UBRRH = (u8) (baud >> 8);
	UBRRL = (u8) baud;
	/* Enable receiver and transmitter */
	UCSRB = (1 << RXEN) | (1 << TXEN);
	/* Set frame format: 8data, 2stop bit */
	UCSRC = (1 << URSEL) | (1 << USBS) | (3 << UCSZ0);
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
