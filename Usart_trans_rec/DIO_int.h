/*
 * DIO_int.h
 *
 *  Created on: Jul 5, 2020
 *      Author: a-m-m
 */

#ifndef  _DIO_INT_H_
#define _DIO_INT_H_
#include "BIT_MATHS.h"
#include "STD_TYPES.h"
   #define DIO_U8_PIN_0		0
   #define DIO_U8_PIN_1 	1
   #define DIO_U8_PIN_2 	2
   #define DIO_U8_PIN_3 	3
   #define DIO_U8_PIN_4 	4
   #define DIO_U8_PIN_5 	5
   #define DIO_U8_PIN_6 	6
   #define DIO_U8_PIN_7 	7
   #define DIO_U8_PIN_8 	8
   #define DIO_U8_PIN_9 	9
   #define DIO_U8_PIN_10 	10
   #define DIO_U8_PIN_11 	11
   #define DIO_U8_PIN_12 	12
   #define DIO_U8_PIN_13 	13
   #define DIO_U8_PIN_14 	14
   #define DIO_U8_PIN_15 	15
   #define DIO_U8_PIN_16 	16
   #define DIO_U8_PIN_17 	17
   #define DIO_U8_PIN_18 	18
   #define DIO_U8_PIN_19 	19
   #define DIO_U8_PIN_20 	20
   #define DIO_U8_PIN_21 	21
   #define DIO_U8_PIN_22 	22
   #define DIO_U8_PIN_23 	23
   #define DIO_U8_PIN_24 	24
   #define DIO_U8_PIN_25 	25
   #define DIO_U8_PIN_26 	26
   #define DIO_U8_PIN_27 	27
   #define DIO_U8_PIN_28 	28
   #define DIO_U8_PIN_29 	29
   #define DIO_U8_PIN_30 	30
   #define DIO_U8_PIN_31 	31


#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0

#define DIO_u8_INPUT  0
#define DIO_u8_OUTPUT 1

#define NO_value_found 0b11111111

void DIO_SET_PULLUP(u8 copy_pin_num);
void DIO_DISABLE_PULLUP(u8 copy_pin_num);


u8 DIO_u8_GET_PIN_value(u8 copy_pin_num);

void DIO_SET_PIN_DIRECTION (u8 copy_pin_num,u8 copy_pin_direction);

void DIO_SET_PIN_value(u8 copy_pin_num,u8 copy_pin_value);

void DIO_INIT();

#endif
