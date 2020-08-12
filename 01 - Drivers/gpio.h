/*
 * gpio.h
 *
 * Created: 7/24/2020 2:16:09 AM
 *  Author: mosad
 */ 


#ifndef GPIO_H_
#define GPIO_H_


#include <avr/io.h>
#include "macros.h"
#include "types.h"

#define INPUT 0 
#define OUTPUT 1

#define HIGH 1
#define LOW  0

typedef enum {
	pin0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}pins_t;

typedef enum {
	porta = 0,
	portb,
	portc,
	portd
	}port_t;



void gpio_set_pin_value(port_t port , pins_t pin , uint8_t value);
void gpio_set_pin_dirction(port_t port, pins_t pin , uint8_t dirc );
void gpio_set_port_value(port_t port , uint8_t value);
void gpio_set_port_direction(port_t port , uint8_t dirc);
uint8_t gpio_get_pin_value(port_t port , pins_t pin);



#endif /* GPIO_H_ */