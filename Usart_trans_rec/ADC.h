/*
 * ADC.h
 *
 *  Created on: Mar 20, 2020
 *      Author: abdullah rajab
 */

#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#define ADMUX 	*(volatile u8 *)(0x27)
#define ADCSRA 	*(volatile u8 *)(0x26)
#define ADCL 	*(volatile u8 *)(0x24)
#define ADCH 	*(volatile u8 *)(0x25)
#define SFIOR 	*(volatile u8 *)(0x50)

//AMUX BITS------------------
//Analog Channel and Gain Selection Bits
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
//ADC Left Adjust Result
#define ADLAR 5
//Reference Selection Bits
#define REFS0 6
#define REFS1 7



//Register A – ADCSRA BITS
//ADC Prescaler Select Bits
 #define ADPS0	0
 #define ADPS1	1
 #define ADPS2	2
//ADC Interrupt Enable
 #define ADIE   3
//ADC Interrupt Flag
 #define ADIF	4
//ADC Auto Trigger Enable
 #define ADATE  5
//ADC Start Conversion
 #define ADSC   6
//ADC Enable
 #define ADEN   7


//ADCH BITS
#define ADCH0	0
#define ADCH1	1
#define ADCH2	2
#define ADCH3	3
#define ADCH4	4
#define ADCH5	5
#define ADCH6	6
#define ADCH7	7

//ADCL BITS
#define ADCL0	0
#define ADCL1	1
#define ADCL2	2
#define ADCL3	3
#define ADCL4	4
#define ADCL5	5
#define ADCL6	6
#define ADCL7	7



//SFIOR BITS
#define ADTS0   5
#define ADTS1	6
#define ADTS2	7

typedef enum
{
	ADC_AREF,
	ADC_AVCC,
	ADC_Internal
	}ADC_V_REF;

	typedef enum
	{
		ADC_ADC0,
		ADC_ADC1,
		ADC_ADC2,
		ADC_ADC3,
		ADC_ADC4,
		ADC_ADC5,
		ADC_ADC6,
		ADC_ADC7,
		}ADC_inPIN_single;


typedef enum
{
	ADC_prescaler2,
	ADC_prescaler4,
	ADC_prescaler8,
	ADC_prescaler16,
	ADC_prescaler32,
	ADC_prescaler64,
	ADC_prescaler128,
}ADC_PRESCALER;

typedef enum
{
	ADC_Free_run,
	ADC_Analog_comprator,
	ADC_EXT_Interrupt,
	ADC_Timer0_compare,
	ADC_Timer0_OVF,
	ADC_Timer_compareB,
	ADC_Timer1_OVF,
	ADC_Timer1_captureEVE
}ADC_Auto_Trigger_mode;

void ADC_INIT(ADC_PRESCALER cpy_adcPRE,ADC_V_REF cpy_V_ref);

u16 ADC_AnalogRead(ADC_inPIN_single cpy_input);

void ADC_Auto_Trigger();

void ADC_OFF();

#endif /* ADC_H_ */
