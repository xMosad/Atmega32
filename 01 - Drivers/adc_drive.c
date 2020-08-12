/*
 * adc_drive.c
 *
 * Created: 5/21/2020 3:02:53 PM
 *  Author: mosad
 */
#include "adc_drive.h" 
/************************************************************************************************************
* Description : initialize the ADC module in free running mood and you can choose the reference voltage for
                the ADC module and the prescaler  
* Parameters  : the reference voltage (VREF_t) refer to the enum in adc_drive.h and the prescaler (PRESCALER_t)
* Return type : void
************************************************************************************************************/
void adc_init(VREF_t vref , PRESCALER_t prescaler){
	
	ADCSRA |= (1 << 7); //enable adc
	ADCSRA |= (1 << 6) ; // start conversion 
	// choosing the v ref 
	if (vref == AVCC){
		ADMUX |= (1 << 6);
		ADMUX &= ~(1 << 7);
	}
	else if (vref == INTERNAL){
		ADMUX |= (1 << 7);
		ADMUX |= (1 << 6);
	}
	else if (vref == AREF){
		ADMUX &= ~(1 << 7);
		ADMUX &= ~(1 << 6);
	}
	
	//choosing a prescaller 
	switch (prescaler) {
		case PRESCALER_2 : ADCSRA |= 0x01 ; break ; 
		case PRESCALER_4 : ADCSRA |= 0x02 ; break ; 
		case PRESCALER_8 : ADCSRA |= 0x03 ; break ; 
		case PRESCALER_16 : ADCSRA |= 0x04 ; break ; 
		case PRESCALER_32 : ADCSRA |= 0x05 ; break ; 
		case PRESCALER_64 : ADCSRA |= 0x06 ; break ;
		case PRESCALER_128 : ADCSRA |= 0x07 ; break ;  
	}
	DDRA = 0x00;
}

/************************************************************************************************************
* Description : select the channel
* Parameters  : the channel (CHANNEL_t)
* Return type : void
************************************************************************************************************/
void select_channel (CHANNEL_t channel){
	switch (channel) {
		case ADCO_CHANNEL : ADMUX &=~ ((1<<0) |(1<<1)|(1<<2));            break;
		case ADC1_CHANNEL : ADMUX |= (1 << 0); ADMUX &=~ ((1<<1)|(1<<2)); break;
		case ADC2_CHANNEL : ADMUX |= (1 << 1); ADMUX &=~ ((1<<0)|(1<<2)); break;
		case ADC3_CHANNEL : ADMUX &= ~(1 << 2); ADMUX |= ((1<<0)|(1<<1)); break;
		case ADC4_CHANNEL : ADMUX |= (1 << 2); ADMUX &=~ ((1<<1)|(1<<0)); break;
		case ADC5_CHANNEL : ADMUX &= ~(1 << 1); ADMUX |= ((1<<2)|(1<<0)); break;
		case ADC6_CHANNEL : ADMUX &= ~(1 << 0); ADMUX |= ((1<<1)|(1<<2)); break;
		case ADC7_CHANNEL : ADMUX |= ((1<<0) |(1<<1)|(1<<2));             break;
	}
}

/************************************************************************************************************
* Description : read the value of the adc for a specific channel from 0 to 1024 
* Parameters  : the channel (CHANNEL_t)
* Return type : int (the value of the adc register)
************************************************************************************************************/
uint16_t adc_read_1024(CHANNEL_t channel){
	// choose the channel
	ADMUX &= ~(1 << 5);
	select_channel(channel);
	ADCSRA |= (1 << 6) ; // start conversion 
	while ( !(ADCSRA & (1<<4))){} // wait for the conversion to complete 
	ADCSRA |= (1 << 4);	
	return ADC ; // return the value of the adc	
}

/************************************************************************************************************
* Description : read the value of the adc for a specific channel from 0 to 255 
* Parameters  : the channel (CHANNEL_t)
* Return type : int (the value of the adc register)
************************************************************************************************************/
uint8_t adc_read_255(CHANNEL_t channel){
	// choose the channel
	ADMUX |= (1 << 5);
	select_channel(channel);
	ADCSRA |= (1 << 6) ; // start conversion
	while ( !(ADCSRA & (1<<4))){} // wait for the conversion to complete
	ADCSRA |= (1 << 4);
	return ADCH ; // return the value of the adc
}


