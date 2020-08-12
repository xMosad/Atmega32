
/*
 * F_meter.c
 *
 * Created: 10/21/2019 12:49:28 PM
 * Author : mosad
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "lcd_drive.h"

volatile uint8_t value ;
volatile uint8_t counter ;
volatile uint16_t f ;
uint8_t f_str [10];

//functuins declaration
void int_timer1_timer();
void int_timer0_counter();

int main(void)
{
	int_timer1_timer();
	int_timer0_counter() ; 
	Lcd_Init();
	Lcd_Out(1 , 2 , "F = ");
	Lcd_Out(2 , 8 , "HZ");
    /* Replace with your application code */
    while (1) 
    {
		
			
    }
}

void int_timer1_timer(){
	TCCR1A = 0x00 ;
	TCCR1B = 0x04 ;
	TCNT1 = 34286 ;

	TIMSK |= (1 << 2); // enable interrupt for timer1
	sei();			   // enable interrupts globally
}
void int_timer0_counter(){
	PORTB |= (1 << 0);
	TCCR0 = 0x06 ;

	TIMSK |= (1 << 0); // enable interrupt for timer0
	sei();			   // enable interrupts globally

}
ISR (TIMER1_OVF_vect){	
	value = (volatile uint8_t)TCNT0 ;
	f = (value) + 256 * counter ;
	itoa(f , f_str , 10);
	Lcd_Out(2 , 2 , f_str );
	f = 0 ;
	counter = 0 ;
	value = 0;
	TCNT1 = 34286 ;
	TCNT0 = 0 ;
	TIFR |= (1 << 0);

	//TIMSK &= ~(1 << 2); // disable interrupt for timer1
}
ISR (TIMER0_OVF_vect){
	counter++ ;	
}

