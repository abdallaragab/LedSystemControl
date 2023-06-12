/*
 * ADC.c
 *
 *  Created on: Mar 20, 2020
 *      Author: abdullah
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "ADC.h"
#include "util/delay.h"
#include "avr/interrupt.h"

/*
ISR(ADC_vect)

{
	A;
}
*/

void ADC_INIT(ADC_PRESCALER cpy_adcPRE,ADC_V_REF cpy_V_ref)
{
	//set V referance for conviersion
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADIE);
	if(cpy_V_ref==ADC_AREF)
	{
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);

	}
	else if(cpy_V_ref==ADC_AVCC)
	{
		CLR_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
	}
	else if(cpy_V_ref==ADC_Internal)
	{
			SET_BIT(ADMUX,REFS0);
			SET_BIT(ADMUX,REFS1);
	}
	/*
	//set adc pin
	if(cpy_input==ADC_ADC0)
	{
		CLR_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
	}
	else if(cpy_input==ADC_ADC1)
	{
		SET_BIT(ADMUX,MUX0);
		CLR_BIT(ADMUX,MUX1);
		CLR_BIT(ADMUX,MUX2);
		CLR_BIT(ADMUX,MUX3);
		CLR_BIT(ADMUX,MUX4);
	}
	else if(cpy_input==ADC_ADC2)
		{
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
	else if(cpy_input==ADC_ADC3)
		{
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
	else if(cpy_input==ADC_ADC4)
		{
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
	else if(cpy_input==ADC_ADC5)
		{
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
	else if(cpy_input==ADC_ADC6)
		{
			CLR_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
	else if(cpy_input==ADC_ADC7)
		{
			SET_BIT(ADMUX,MUX0);
			SET_BIT(ADMUX,MUX1);
			SET_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
		*/

	if (cpy_adcPRE==ADC_prescaler2)
	{
		CLR_BIT(ADCSRA,ADPS0);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);

	}
	else if (cpy_adcPRE==ADC_prescaler4)
	{
		CLR_BIT(ADCSRA,ADPS0);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS2);
	}
	else if (cpy_adcPRE==ADC_prescaler8)
	{
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			CLR_BIT(ADCSRA,ADPS2);
	}
	else if (cpy_adcPRE==ADC_prescaler16)
		{
			CLR_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
		}
	else if (cpy_adcPRE==ADC_prescaler32)
		{
			SET_BIT(ADCSRA,ADPS0);
			CLR_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
		}
	else if (cpy_adcPRE==ADC_prescaler64)
		{
			CLR_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
		}
	else if (cpy_adcPRE==ADC_prescaler128)
		{
			SET_BIT(ADCSRA,ADPS0);
			SET_BIT(ADCSRA,ADPS1);
			SET_BIT(ADCSRA,ADPS2);
		}

}



u16 ADC_AnalogRead(ADC_inPIN_single cpy_input)
{

	u16 temp_an=0;
	u8  state_9bit=9 ,state_8bit=8 ;
	u8  ADLAR_RIGHT = 0;
	u8	ADLAR_LEFT =1;

	SET_BIT(ADCSRA,ADEN);
	//set adc pin
		if(cpy_input==ADC_ADC0)
		{
			CLR_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
		else if(cpy_input==ADC_ADC1)
		{
			SET_BIT(ADMUX,MUX0);
			CLR_BIT(ADMUX,MUX1);
			CLR_BIT(ADMUX,MUX2);
			CLR_BIT(ADMUX,MUX3);
			CLR_BIT(ADMUX,MUX4);
		}
		else if(cpy_input==ADC_ADC2)
			{
				CLR_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}
		else if(cpy_input==ADC_ADC3)
			{
				SET_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				CLR_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}
		else if(cpy_input==ADC_ADC4)
			{
				CLR_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}
		else if(cpy_input==ADC_ADC5)
			{
				SET_BIT(ADMUX,MUX0);
				CLR_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}
		else if(cpy_input==ADC_ADC6)
			{
				CLR_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}
		else if(cpy_input==ADC_ADC7)
			{
				SET_BIT(ADMUX,MUX0);
				SET_BIT(ADMUX,MUX1);
				SET_BIT(ADMUX,MUX2);
				CLR_BIT(ADMUX,MUX3);
				CLR_BIT(ADMUX,MUX4);
			}


		SET_BIT(ADCSRA,ADSC);

		while(GET_BIT(ADCSRA,ADSC)==1)
		{

		}
		if((GET_BIT(ADMUX,ADLAR))==ADLAR_RIGHT)
		{
			temp_an=ADCL|(ADCH<<8);

		}

		else if((GET_BIT(ADMUX,ADLAR)==ADLAR_LEFT))
		{
			temp_an=(ADCL1<<1)|(ADCL0)|(ADCH<<2);
		}

		// temp_an=ADCL|(GET_BIT(ADCH,ADCH0)<<state_8bit)|(GET_BIT(ADCH,ADCH1)<<state_9bit);
		//CLR_BIT(ADCSRA,ADEN);

		return temp_an;

}

void ADC_OFF()
{
	CLR_BIT(ADCSRA,ADEN);
}




