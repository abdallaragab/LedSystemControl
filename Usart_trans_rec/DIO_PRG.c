/*
 * DIO_PRG.c
 *
 *  Created on: Jul 6, 2020
 *      Author: a-m-m
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_int.h"
#include  "DIO_conf.h"
#include  "DIO_PRIV.h"

//DIO_PIN31_DIRECTION
//initilaize pin directions
void DIO_INIT() {
	DDRA = BIT_CONC(DIO_direction_PIN0, DIO_direction_PIN1, DIO_direction_PIN2,
			DIO_direction_PIN3, DIO_direction_PIN4, DIO_direction_PIN5,
			DIO_direction_PIN6, DIO_direction_PIN7);
	DDRB = BIT_CONC(DIO_direction_PIN8, DIO_direction_PIN9, DIO_direction_PIN10,
			DIO_direction_PIN11, DIO_direction_PIN12, DIO_direction_PIN13,
			DIO_direction_PIN14, DIO_direction_PIN15);
	DDRC = BIT_CONC(DIO_direction_PIN16, DIO_direction_PIN17,
			DIO_direction_PIN18, DIO_direction_PIN19, DIO_direction_PIN20,
			DIO_direction_PIN21, DIO_direction_PIN22, DIO_direction_PIN23);
	DDRD = BIT_CONC(DIO_direction_PIN24, DIO_direction_PIN25,
			DIO_direction_PIN26, DIO_direction_PIN27, DIO_direction_PIN28,
			DIO_direction_PIN29, DIO_direction_PIN30, DIO_direction_PIN31);

}

void DIO_SET_PULLUP(u8 copy_pin_num) {
	if ((copy_pin_num <= PORTA_END) && (copy_pin_num >= PORTA_START)) {
		SET_BIT(PORTA, copy_pin_num);
	} else if ((copy_pin_num <= PORTB_END) && (copy_pin_num >= PORTB_START)) {
		SET_BIT(PORTB, (copy_pin_num-PORTA_SIZE));
	} else if ((copy_pin_num <= PORTC_END) && (copy_pin_num >= PORTC_START)) {
		SET_BIT(PORTC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
	} else if ((copy_pin_num >= PORTD_START) && (copy_pin_num <= PORTD_END)) {
		SET_BIT(PORTD, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));
	}
}

void DIO_DISABLE_PULLUP(u8 copy_pin_num) {
	if ((copy_pin_num <= PORTA_END) && (copy_pin_num >= PORTA_START)) {
		CLR_BIT(PORTA, copy_pin_num);

	} else if ((copy_pin_num <= PORTB_END) && (copy_pin_num >= PORTB_START)) {
		CLR_BIT(PORTB, (copy_pin_num-PORTA_SIZE));
	} else if ((copy_pin_num <= PORTC_END) && (copy_pin_num >= PORTC_START)) {
		CLR_BIT(PORTC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
	} else if ((copy_pin_num >= PORTD_START) && (copy_pin_num <= PORTD_END)) {
		CLR_BIT(PORTD, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));
	}
}

u8 DIO_u8_GET_PIN_value(u8 copy_pin_num) {
	u8 temp_pin_state;
	if ((copy_pin_num <= PORTA_END) && (copy_pin_num >= PORTA_START)) {
		temp_pin_state = GET_BIT(PINA, copy_pin_num);
		if (temp_pin_state == DIO_u8_HIGH)
			return DIO_u8_HIGH;
		else if (temp_pin_state == DIO_u8_LOW)
			return DIO_u8_LOW;
		else
			return NO_value_found;

	} else if ((copy_pin_num <= PORTB_END) && (copy_pin_num >= PORTB_START)) {
		temp_pin_state = GET_BIT(PINB, (copy_pin_num-PORTA_SIZE));
		if (temp_pin_state == DIO_u8_HIGH)
			return DIO_u8_HIGH;
		else if (temp_pin_state == DIO_u8_LOW)
			return DIO_u8_LOW;
		else
			return NO_value_found;
	} else if ((copy_pin_num <= PORTC_END) && (copy_pin_num >= PORTC_START)) {
		temp_pin_state = GET_BIT(PINC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
		if (temp_pin_state == DIO_u8_HIGH)
			return DIO_u8_HIGH;
		else if (temp_pin_state == DIO_u8_LOW)
			return DIO_u8_LOW;
		else
			return NO_value_found;
	} else if ((copy_pin_num >= PORTD_START) && (copy_pin_num <= PORTD_END)) {
		temp_pin_state = GET_BIT(PIND,
				(copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));
		if (temp_pin_state == DIO_u8_HIGH)
			return DIO_u8_HIGH;
		else if (temp_pin_state == DIO_u8_LOW)
			return DIO_u8_LOW;
		else
			return NO_value_found;
	} else {
		return NO_value_found;
	}
}

void DIO_SET_PIN_DIRECTION(u8 copy_pin_num, u8 copy_pin_direction) {

	if ((copy_pin_num <= PORTA_END) && (copy_pin_num >= PORTA_START)) {
		if (copy_pin_direction == DIO_u8_OUTPUT)
			SET_BIT(DDRA, copy_pin_num);

		else if (copy_pin_direction == DIO_u8_INPUT)
			CLR_BIT(DDRA, copy_pin_num);
	} else if ((copy_pin_num <= PORTB_END) && (copy_pin_num >= PORTB_START)) {
		if (copy_pin_direction == DIO_u8_OUTPUT)
			SET_BIT(DDRB, (copy_pin_num-PORTA_SIZE));

		else if (copy_pin_direction == DIO_u8_INPUT)
			CLR_BIT(DDRB, (copy_pin_num-PORTA_SIZE));
	} else if ((copy_pin_num <= PORTC_END) && (copy_pin_num >= PORTC_START)) {
		if (copy_pin_direction == DIO_u8_OUTPUT)
			SET_BIT(DDRC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
		else if (copy_pin_direction == DIO_u8_INPUT)
			CLR_BIT(DDRC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
	} else if ((copy_pin_num >= PORTD_START) && (copy_pin_num <= PORTD_END)) {
		if (copy_pin_direction == DIO_u8_OUTPUT)
			SET_BIT(DDRC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));

		else if (copy_pin_direction == DIO_u8_INPUT)
			CLR_BIT(DDRC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));

	}
}

void DIO_SET_PIN_value(u8 copy_pin_num, u8 copy_pin_value) {

	if ((copy_pin_num <= PORTA_END) && (copy_pin_num >= PORTA_START)) {
		if(copy_pin_value==DIO_u8_HIGH)
			SET_BIT(PORTA, copy_pin_num);
		else if(copy_pin_value==DIO_u8_LOW)
			CLR_BIT(PORTA, copy_pin_num);

	} else if ((copy_pin_num <= PORTB_END) && (copy_pin_num >= PORTB_START)) {
		if(copy_pin_value==DIO_u8_HIGH)
		SET_BIT(PORTB, (copy_pin_num-PORTA_SIZE));
		else if(copy_pin_value==DIO_u8_LOW)
			CLR_BIT(PORTB, (copy_pin_num-PORTA_SIZE));

	} else if ((copy_pin_num <= PORTC_END) && (copy_pin_num >= PORTC_START)) {
		if(copy_pin_value==DIO_u8_HIGH)
		SET_BIT(PORTC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));
		else if(copy_pin_value==DIO_u8_LOW)
			CLR_BIT(PORTC, (copy_pin_num-PORTA_SIZE-PORTB_SIZE));

	} else if ((copy_pin_num >= PORTD_START) && (copy_pin_num <= PORTD_END)) {
		if(copy_pin_value==DIO_u8_HIGH)
		SET_BIT(PORTD, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));
		else if(copy_pin_value==DIO_u8_LOW)
			CLR_BIT(PORTD, (copy_pin_num-PORTA_SIZE-PORTB_SIZE-PORTC_SIZE));

	}
}

