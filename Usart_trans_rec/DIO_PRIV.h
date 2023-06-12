/*
 * DIO_PRIV.h
 *
 *  Created on: Jul 6, 2020
 *      Author: a-m-m
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define PORTA_START 0
#define PORTA_END 	7
#define PORTA_SIZE	8

#define PORTB_START 8
#define PORTB_END 	15
#define PORTB_SIZE	8

#define PORTC_START 16
#define PORTC_END 	23
#define PORTC_SIZE	8

#define PORTD_START 24
#define PORTD_END 	31
#define PORTD_SIZE	8

#define PORTA *(volatile u8 *)(0x3B)
#define PINA  *(volatile u8 *)(0x39)
#define DDRA  *(volatile u8 *)(0x3A)


#define PORTB *(volatile u8 *)(0x38)
#define PINB  *(volatile u8 *)(0x36)
#define DDRB  *(volatile u8 *)(0x37)


#define PORTC *(volatile u8 *)(0x35)
#define PINC  *(volatile u8 *)(0x33)
#define DDRC  *(volatile u8 *)(0x34)


#define PORTD *(volatile u8 *)(0x32)
#define PIND  *(volatile u8 *)(0x30)
#define DDRD  *(volatile u8 *)(0x31)


#endif /* DIO_PRIV_H_ */
