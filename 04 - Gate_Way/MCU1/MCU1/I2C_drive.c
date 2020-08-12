/*
 * I2C_drive.c
 *
 * Created: 11/27/2019 12:20:41 AM
 * Author: mosad
 * Description :This is a driver for the I2C module includes five functions 
   the driver is to use the Avr as a master when using the driver you must use 
   the I2C_intialize() function before anything 
 */ 
#include "I2C_drive.h"

void I2C_intialize(){
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero
	TWCR = ((1<<TWINT) | (1 << TWEN) | (1 <<TWEA));
	 
}

// to recieve data
unsigned char I2C_READ(){
   TWCR = (1 << 7) | (1 << 2)  ; //clearing the flag to start operation of i2c - enable module
   while ((TWCR & (1 << 7)) == 0 );
   unsigned char val = TWDR ;
   return val ;
}

