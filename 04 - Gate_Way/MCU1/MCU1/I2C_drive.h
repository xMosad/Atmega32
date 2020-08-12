/*
 * I2C_drive.h
 *
 * Created: 11/27/2019 12:21:31 AM
 *  Author: mosad
 */ 


#ifndef I2C_DRIVE_H_
#define I2C_DRIVE_H_

#include <avr/io.h>

//functions proto type
void I2C_intialize();
void I2C_START();
void I2C_STOP();
void I2C_WRITE(unsigned char _data);
unsigned char I2C_READ();


#endif /* I2C_DRIVE_H_ */