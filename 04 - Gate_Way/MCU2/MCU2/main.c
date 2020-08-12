/*
 * MCU1.c
 *
 * Created: 11/30/2019 5:40:57 PM
 * Author : mosad
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#define F_CPU 8000000

// global variables
uint8_t _data ;

void usart_int (uint32_t B_R , uint32_t f_oc) {
	 uint32_t x = 0 ;
	 UCSRB = 0x98 ;
	 UCSRC = 0x86 ;
	 x = f_oc / 16 ;  x = x / B_R ; x = x - 1;
	 UBRRL = x ;
}
// master mode : 
void spi_inialize(){
	DDRB =((1 << 4) | (1 << 5) |(1 << 7) ); 	//congigure them as output
	DDRB &= ~ (1 << 6);
	SPCR = ((1<<SPE)|(1<<MSTR)|(1<<SPR0) );
}
void spi_send(uint8_t sent_data){
	PORTB &= ~(1 << 4); // initiate the transmission
	SPDR = sent_data ;
	while(!(SPSR & (1 << SPIF)));
	PORTB |= (1 << 4); // initiate the transmission
}

int main(void)
{
	sei();
	usart_int(9600 , 8000000);
	spi_inialize();
	DDRD |= (1 << 7);
    /* Replace with your application code */
    while (1) 
    {
    }
}
ISR (USART_RXC_vect){
    _data = UDR ;
	spi_send(_data);
}

