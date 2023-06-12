/*
 * USART_INT.h
 *
 *  Created on: Jul 16, 2020
 *      Author: a-m-m abdullah ragab
 */

#ifndef USART_INT_H_
#define USART_INT_H_

void USART_Init( unsigned int baud );

void USART_Transmit( unsigned char data );

unsigned char USART_Receive( void );


#endif /* USART_INT_H_ */
