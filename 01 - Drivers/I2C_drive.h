/*
 * I2C_drive.h
 *
 * Created: 11/27/2019 12:21:31 AM
 *  Author: mosad
  * Description :This is a driver for the I2C module includes five functions
    the driver is to use the Avr as a master when using the driver you must use
    the I2C_intialize() function before anything
 */ 


#ifndef I2C_DRIVE_H_
#define I2C_DRIVE_H_

#define F_OSC 8000000 //the frequancy of the crystal
#include <avr/io.h>
#include <stdint.h>

typedef enum{
	enable_general_call,
	disable_general_call	
}GENERAL_CALL_t;

//functions proto type

/* * the function is to initialize the i2c module in master mode
   * required parameters : the SCL frequancy
   * return type : void
   * notice that the default f_cpu here is 8000000 and you can change it 
     from line12 the F_OSC constant 
*/
void I2C_master_intialize(uint32_t f);

 /* the function is to initialize the i2c module in slave mode
   * required parameters : the SCL frequancy , the slave adrres
   * return type : void
   * notice that the default f_cpu here is 8000000 and you can change it 
     from line12 the F_OSC constant
 */

void I2C_slave_intialize(uint32_t f , uint8_t slave_address ,GENERAL_CALL_t mode);

/* * the function is to send a start condition in master mode
   * required parameters : void
   * return type : void
*/
void I2C_START();

/* * the function is to send a stop condition in master mode
   * required parameters : void
   * return type : void
*/
void I2C_STOP();

/* * the function is to send the data in byte format 
   * required parameters : 8-bit data 
   * return type : void
*/
void I2C_WRITE(uint8_t _data);

/* * the function is to recieve the data in byte format 
   * required parameters : void
   * return type : uint8_t
*/
uint8_t I2C_READ();


#endif /* I2C_DRIVE_H_ */