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
	TWBR = 0x47;
}

//to send start condition
void I2C_START(){
	TWCR = (1 << 7) | (1 << 5)| (1 << 2); //clearing the flag - send start - enable module 
	while ((TWCR & (1 << 7)) == 0 );
}
//to send stop function
void I2C_STOP(){
	TWCR = (1 << 7) | (1 << 4)| (1 << 2); //clearing the flag - send stop - enable module
	//while ((TWCR & (1 << 7)) == 0 );
}
// to send data
void I2C_WRITE(unsigned char _data){
	TWDR = _data ;
	TWCR = (1 << 7) | (1<<2); //clearing the flag to start operation of i2c- enable module
	while ((TWCR & (1 << 7)) == 0 );
}
// to recieve data
unsigned char I2C_READ(){
   TWCR = (1 << 7) | (1 << 2)  ; //clearing the flag to start operation of i2c - enable module
   while ((TWCR & (1 << 7)) == 0 );
   unsigned char val = TWDR ;
   return val ;
}

