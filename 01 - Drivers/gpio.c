/*
 * gpio.c
 *
 * Created: 7/24/2020 2:15:39 AM
 *  Author: mosad
 */ 
#include "gpio.h"


void gpio_set_pin_value(port_t port , pins_t pin , uint8_t value){
	if (value == HIGH){
		switch (port){
			case porta :
			SET_BIT (PORTA , pin);
			break;
			case portb :
			SET_BIT (PORTB , pin);
			break;
			case portc :
			SET_BIT (PORTC , pin);
			break;
			case portd :
			SET_BIT (PORTD , pin);
			break;
			default:
			break;
		}
	}
	else if (value == LOW){
		switch (port){
			case porta :
			CLEAR_BIT (PORTA , pin);
			break;
			case portb :
			CLEAR_BIT (PORTB , pin);
			break;
			case portc :
			CLEAR_BIT (PORTC , pin);
			break;
			case portd :
			CLEAR_BIT (PORTD , pin);
			break;
			default:
			break;
		}
	}
	else{
		
	}
		
	
}

void gpio_set_pin_dirction(port_t port, pins_t pin , uint8_t dirc ){
	if (dirc == OUTPUT){
		switch (port){
			case porta :
			SET_BIT (DDRA , pin);
			break;
			case portb :
			SET_BIT (DDRB , pin);
			break;
			case portc :
			SET_BIT (DDRC , pin);
			break;
			case portd :
			SET_BIT (DDRD , pin);
			break;
			default:
			break;
		}
	}
	else if (dirc == INPUT){
		switch (port){
			case porta :
			CLEAR_BIT (DDRA , pin);
			break;
			case portb :
			CLEAR_BIT (DDRB , pin);
			break;
			case portc :
			CLEAR_BIT (DDRC , pin);
			break;
			case portd :
			CLEAR_BIT (DDRD , pin);
			break;
			default:
			break;
		}
	}
	else{
		
	}
}

void gpio_set_port_value(port_t port , uint8_t value){
	switch (port){
		case porta :
			PORTA = value ;
			break;
		case portb :
			PORTB = value ;
			break;
		case portc :
			PORTC = value ;
			break;
		case portd :
			PORTD = value ;
			break;
		default:
			break;
	}
}

void gpio_set_port_direction(port_t port , uint8_t dirc){
	if (dirc == OUTPUT){
		switch (port){
			case porta :
				SET_REG(DDRA);
				break;
			case portb :
				SET_REG(DDRB);
				break;
			case portc :
				SET_REG(DDRC);
				break;
			case portd :
				SET_REG(DDRD);
				break;
			default:
				break;
		}
	}
	else if (dirc == INPUT){
		switch (port){
			case porta :
				CLEAR_REG(DDRA);
				break;
			case portb :
				CLEAR_REG(DDRB);
				break;
			case portc :
				CLEAR_REG(DDRC);
				break;
			case portd :
				CLEAR_REG(DDRD);
				break;
			default:
				break;
		}
	}
	else {
		
	}
}
	
uint8_t gpio_get_pin_value(port_t port , pins_t pin){
	uint8_t value ;
	switch (port){
		case porta :
			value = GIT_BIT(PINA, pin);
			break;
		case portb :
			value = GIT_BIT(PINB, pin);
			break;
		case portc :
			value = GIT_BIT(PINC, pin);
			break;
		case portd :
			value = GIT_BIT(PIND, pin);
			break;
		default:
			break;
	}
	return value ;
}	



