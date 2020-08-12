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
void I2C_intialize(){
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero
	TWAR = 0x3D;
	TWCR = ((1<<TWINT) | (1 << TWEN) | (1 <<TWEA) | (1 <<TWIE));
	TWBR = 0x47;
}

void usart_int (uint32_t B_R , uint32_t f_oc) {
	 uint32_t x = 0 ;
	 UCSRB = 0x18 ;
	 UCSRC = 0x86 ;
	 x = f_oc / 16 ;  x = x / B_R ; x = x - 1;
	 UBRRL = x ;
}
// this function is to send one character
void send_char(uint8_t _data){
	while (!(UCSRA & (1 << 5))) {}
	UDR = _data ;
}

int main(void)
{
	usart_int(9600 ,8000000 );
	I2C_intialize();
	DDRC &= ~(1 << 2);
	DDRC |= (1 << 3);
	sei();
    /* Replace with your application code */
    while (1) 
    {
		if (!(PINC & (1 << 2))){
			_delay_ms(600);
			send_char('o');
		}
    }
}
ISR(TWI_vect){
	
	uint8_t x = TWDR ;
	if (x == 's'){
		PORTC ^= (1 << 3);
		_delay_ms(100);
	}
	 TWCR |= (1 << 7);
}

