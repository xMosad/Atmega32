/*
 * Timer_drive.h
 *
 * Created: 10/21/2019 2:56:14 PM
 *  Author: Mosad
 */ 


#ifndef TIMER_DRIVE_H_
#define TIMER_DRIVE_H_
#include <avr/io.h>

#define T0 TCCR0 // control register for timer 0
#define T1_A TCCR1A	// control register for timer 1
#define T1_B TCCR1B	 // control register for timer 1
#define T2 TCCR2  // control register for timer 2

// the counting registers 
#define TIMER0_VALUE TCNT0	 
#define TIMER1_VALUE TCNT1
#define TIMER2_VALUE TCNT2

// for prescale and counter mode
typedef enum prescaler{
	PRESCALER_1,
	PRESCALER_8,
	PRESCALER_32,
	PRESCALER_64,
	PRESCALER_128,
	PRESCALER_256,
	PRESCALER_1024,
	COUNTER_NEGATIVE,
	COUNTER_POSITEVE
}PRESCALER;

// modes of timer
typedef enum mode{
	NORMAL_MODE,
	CTC_MODE,
	CTC_MODE_ICR,
	CTC_MODE_OCR
}MODE;

// functions prototypes
void timer0_int(MODE mode , PRESCALER ps);
void timer1_int(MODE mode , PRESCALER ps);
void timer2_int(MODE mode , PRESCALER ps);

#endif /* TIMER_DRIVE_H_ */