/*
 * adc_drive.h
 *
 * Created: 5/21/2020 3:03:30 PM
 *  Author: mosad
 */ 


#ifndef ADC_DRIVE_H_
#define ADC_DRIVE_H_

#include <avr/io.h>

// adc reference
typedef enum {
	AREF,
	AVCC,
	INTERNAL
	}VREF_t;

// prescaler 
typedef enum {
	PRESCALER_2,
	PRESCALER_4,
	PRESCALER_8,
	PRESCALER_16,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128
	}PRESCALER_t;

//adc channels
typedef enum{
	ADCO_CHANNEL,
	ADC1_CHANNEL,
	ADC2_CHANNEL,
	ADC3_CHANNEL,
	ADC4_CHANNEL,
	ADC5_CHANNEL,
	ADC6_CHANNEL,
	ADC7_CHANNEL
	}CHANNEL_t;
	
void adc_init(VREF_t vref , PRESCALER_t prescaler);
void select_channel (CHANNEL_t channel);
uint16_t adc_read_1024(CHANNEL_t channel);
uint8_t adc_read_255(CHANNEL_t channel);			




#endif /* ADC_DRIVE_H_ */