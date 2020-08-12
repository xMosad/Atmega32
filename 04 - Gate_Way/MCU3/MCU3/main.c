/*
 * MCU3.c
 *
 * Created: 11/30/2019 6:25:05 PM
 * Author : Mosad
 */ 

#include "I2C_drive.h"
#include <avr/interrupt.h>
#include <stdint.h>
#include <util/delay.h>
#define F_CPU 8000000
// slave mode :
void spi_inialize(){
	DDRB &= ~(1 << 4); 	//congigure them as input
	DDRB &= ~(1 << 5);	 
	DDRB &= ~(1 << 7);
	DDRB |=  (1 << 6);
	SPCR |= ((1<<7)|(1<<SPE)|(1<<SPR0) ); //enable module and interrupt 
	SPCR &= ~ (1 << MSTR); // slave mode	
}
void I2C_MC1(){
	I2C_START();
	I2C_WRITE(0x3C);
	I2C_WRITE('s');
	I2C_STOP();
}
int main(void)
{
	DDRC |= (1 << 2);
	sei();
	spi_inialize();
	I2C_intialize();
    /* Replace with your application code */
    while (1) 
    {
    }
}
ISR(SPI_STC_vect){
	uint8_t _data = SPDR ;
	if(_data == 'o'){
		PORTC ^= (1 << 2);
		I2C_MC1();
	}
}

