/*
 * main.c
 *
 *  Created on: Jul 6, 2020
 *      Author: a-m-m
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_conf.h"
#include "DIO_int.h"
#include "avr/delay.h"
#include "USART_INT.h"
#include "DIO_PRIV.h"
#include "ADC.h"

#define F_CPU 8000000


void main() {

	DIO_INIT();

	USART_Init(51);

	//sending part
/*
	for (int i = 0; i < 8; ++i) {
		DIO_SET_PULLUP(i);
	}
	while(1){
		u8 data_SENDINIG = PINA;

		USART_Transmit(data_SENDINIG);
		_delay_ms(200);

	}*/



	 //receiving part
	while (1) {

		 u8 dat;
		 dat= USART_Receive();
		 u8 pin_number=((dat&0xf0)>>4);
		 u8 pin_value=(dat&1);
		 DIO_SET_PIN_value(pin_number,pin_value);

		_delay_ms(200);

	}


}


