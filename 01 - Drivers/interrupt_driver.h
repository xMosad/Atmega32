/*
 * interrupt_driver.h
 *
 * Created: 10/23/2019 7:54:32 PM
 *  Author: mosad
 */ 


#ifndef INTERRUPT_DRIVER_H_
#define INTERRUPT_DRIVER_H_

#include <avr/interrupt.h>
#include <avr/io.h>

#define TIMER_INTERRUPT TIMSK
#define EXTERNAL_INTERRUPT GICR 
#define UART_REG UCSRB
#define SPI_REG SPCR

typedef enum interrupts {
	TIMER0_OF,
	TIMER0_OC,
	TIMER1_OF,
	TIMER1_OCA,
	TIMER1_OCB,
	TIMER2_OF,
	TIMER2_OC,
	EXTERNAL_INT0,
	EXTERNAL_INT1,
	EXTERNAL_INT2,
	RX_COMPLETE,
	TX_COMPLETE,
	UART_REG_EMPTY,
	SPI_INT
}INTERUUPTS;

typedef enum interrupt_sense {
	LOW_LEVEL,
	CHANGE_LEVEL,
	NEGATIVE_EDGE,
	POSITIVE_EDGE
}INTERRUPT_SENSE;

//functions prototypes
void edge_select(INTERUUPTS name , INTERRUPT_SENSE sense); 
void enable_interrupt(INTERUUPTS name )	;
void disable_interrupt(INTERUUPTS name);



#endif /* INTERRUPT_DRIVER_H_ */