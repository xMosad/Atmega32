/*
 * I2C_drive.c
 *
 * Created: 11/27/2019 12:20:41 AM
 * Author: mosad
 */ 
#include "I2C_drive.h"

 
void I2C_master_intialize(uint32_t f ){
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero 
	TWBR = ((F_OSC/f)-16)/2;  /* must be > 10 for stable operation */
}

void I2C_slave_intialize(uint32_t f , uint8_t slave_address ,GENERAL_CALL_t mode){
	TWCR |= (1 << 2); //enable module
	TWSR = 0x00 ; //set prescaller bits to zero
	TWAR = (slave_address << 1); // the address 
	TWCR = ((1<<TWINT) | (1 << TWEN) | (1 <<TWEA) | (1 <<TWIE));
	TWBR = ((F_OSC/f)-16)/2;  /* must be > 10 for stable operation */
	if (mode == enable_general_call){TWAR |= (1<< 0);}
	else if(mode == disable_general_call){TWAR &= ~(1<< 0);}	
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
void I2C_WRITE(uint8_t _data){
	TWDR = _data ;
	TWCR = (1 << 7) | (1<<2); //clearing the flag to start operation of i2c- enable module
	while ((TWCR & (1 << 7)) == 0 );
}

// to recieve data
uint8_t I2C_READ(){
   TWCR = (1 << 7) | (1 << 2)  ; //clearing the flag to start operation of i2c - enable module
   while ((TWCR & (1 << 7)) == 0 );
   uint8_t val = TWDR ;
   return val ;
}

