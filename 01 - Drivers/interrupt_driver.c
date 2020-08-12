/*
 * interrupt_driver.c
 *
 * Created: 10/23/2019 7:53:31 PM
 *  Author: mosad
 */ 
#include "interrupt_driver.h"

void enable_interrupt(INTERUUPTS name ){
	switch(name){
		case TIMER0_OF        : TIMER_INTERRUPT |= (1<<0); break; 
		case TIMER0_OC        : TIMER_INTERRUPT |= (1<<1); break; 
		case TIMER1_OF        : TIMER_INTERRUPT |= (1<<2); break; 
		case TIMER1_OCB       : TIMER_INTERRUPT |= (1<<3); break; 
		case TIMER1_OCA       : TIMER_INTERRUPT |= (1<<4); break; 
		//case TIMER1_ic      : TIMER_INTERRUPT |= (1<<5); break; 
		case TIMER2_OF        : TIMER_INTERRUPT |= (1<<6); break; 
		case TIMER2_OC        : TIMER_INTERRUPT |= (1<<7); break; 
		case EXTERNAL_INT0    : EXTERNAL_INTERRUPT |= (1 << 6); break;
		case EXTERNAL_INT1    : EXTERNAL_INTERRUPT |= (1 << 7); break;
		case EXTERNAL_INT2    : EXTERNAL_INTERRUPT |= (1 << 5); break;
		case RX_COMPLETE      : UART_REG |= ( 1 << 7); break ;
		case TX_COMPLETE      : UART_REG |= ( 1 << 6); break ;
		case UART_REG_EMPTY   : UART_REG |= ( 1 << 5); break ;
		case SPI_INT          : SPI_REG |= (1 << 7) ; break ;
	}
	
}
void disable_interrupt(INTERUUPTS name){
	switch(name){
		case TIMER0_OF     : TIMER_INTERRUPT &= ~(1<<0); break;
		case TIMER0_OC     : TIMER_INTERRUPT &= ~(1<<1); break;
		case TIMER1_OF     : TIMER_INTERRUPT &= ~(1<<2); break;
		case TIMER1_OCB    : TIMER_INTERRUPT &= ~(1<<3); break;
		case TIMER1_OCA    : TIMER_INTERRUPT &= ~(1<<4); break;
		//case TIMER1_ic   : TIMER_INTERRUPT |= (1<<5); break;
		case TIMER2_OF     : TIMER_INTERRUPT &= ~(1<<6); break;
		case TIMER2_OC     : TIMER_INTERRUPT &= ~(1<<7); break;
		case EXTERNAL_INT0 : EXTERNAL_INTERRUPT &= ~(1 << 6); break;
		case EXTERNAL_INT1 : EXTERNAL_INTERRUPT &= ~(1 << 7); break;
		case EXTERNAL_INT2 : EXTERNAL_INTERRUPT &= ~(1 << 5); break;
	}
}
void edge_select(INTERUUPTS name , INTERRUPT_SENSE sense){
	if(name == EXTERNAL_INT0){
		switch(sense){
			case LOW_LEVEL     :MCUCR &= ~(1 << 0);  MCUCR &= ~(1 << 1); break;
			case CHANGE_LEVEL  :MCUCR |= (1 << 0);  MCUCR &= ~(1 << 1); break;
			case NEGATIVE_EDGE :MCUCR &= ~(1 << 0);  MCUCR |= (1 << 1); break;
			case POSITIVE_EDGE :MCUCR |= (1 << 0);  MCUCR |= (1 << 1); break;
		}
	}
	if(name == EXTERNAL_INT1){
		switch(sense){
			case LOW_LEVEL     :MCUCR &= ~(1 << 2);  MCUCR &= ~(1 << 3); break;
			case CHANGE_LEVEL  :MCUCR |= (1 << 2);  MCUCR &= ~(1 << 3); break;
			case NEGATIVE_EDGE :MCUCR &= ~(1 << 2);  MCUCR |= (1 << 3); break;
			case POSITIVE_EDGE :MCUCR |= (1 << 2);  MCUCR |= (1 << 3); break;
		}
	}
	if(name == EXTERNAL_INT2){
		switch(sense){
			case NEGATIVE_EDGE :MCUCSR &= ~(1 << 0);  break;
			case POSITIVE_EDGE :MCUCSR |= (1 << 0);   break;
		}
	}
}