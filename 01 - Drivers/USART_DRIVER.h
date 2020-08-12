/*
 * USART_DRIVER.h
 *
 * Created: 10/26/2019 12:33:36 AM
 *  Author: mosad
 */ 


#ifndef USART_DRIVER_H_
#define USART_DRIVER_H_

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h> 

typedef enum {
	ENABLE_INTRUPRTS,
	DISAPLE_INTRUPRTS
	}INTERRUPT;
	
typedef enum {
	ENABLE_PARITY_ODD,
	ENABLE_PARITY_EVEN,
	DISABLE_PARITY
}PARITY; 

typedef enum{
	ENABLE_RECIEVER,
	ENABLE_TRANSMITTER,
	ENABLE_BOTH
}R_T;
typedef enum {
	ONE_STOP, 
	TWO_STOP
	}STOP_BITS;	


//functions prototypes
/*
   *the function intialize the uart module
   * parameters : baud rate , oscillator frequency , intrerrupt enable or disable , parity enable or choose an even or odd parity
                 enbale receiver or transmitter or both , number of stop bits
   *return : nothing 
*/

void usart_int (uint32_t B_R , uint32_t f_oc , INTERRUPT e_d , PARITY parity , R_T rec_trans , STOP_BITS num);

/*
	* to send a character
	* parameters : one parameter from type uint8_t ( the character)
	* return : nothing
*/
void send_char(uint8_t _data);

/*
	* to receive one character
	* parameters : non
	* return : the received character
*/
uint8_t recieve_char();

/*
	* to  send a string 
	* parameters : a pointer from type uint8_t
	* return : nothing
*/
void send_string(uint8_t * text);

/*
	* to recieve a string 
	* parameters : a pointer from type uint8_t
	* return : nothing
*/
void recieve_string(uint8_t * text);



#endif /* USART_DRIVER_H_ */