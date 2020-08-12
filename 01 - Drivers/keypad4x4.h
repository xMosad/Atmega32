/*
 * keypad4x4.h
 *
 * Created: 4/2/2020 3:39:33 AM
 *  Author: mosad
 */ 


#ifndef KEYPAD4X4_H_
#define KEYPAD4X4_H_

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>


#define PORTx PORTD //port register
#define DDRx DDRD   //ddr register
#define PINx PIND   //pin register

#define  COLOUM1 (PINx & (1 << 4))
#define  COLOUM2 (PINx & (1 << 5))
#define  COLOUM3 (PINx & (1 << 6))
#define  COLOUM4 (PINx & (1 << 7))


#define SET_BIT(VAR,BITNO) (VAR) |=  (1 << (BITNO))  // this macro set a bit in a given register
#define CLR_BIT(VAR,BITNO) (VAR) &= ~(1 << (BITNO))  // this macro clear a bit in a given register

/************************************************************************************************************
* Description : clear three bits only used in the keypad4x4.c
* Parameters  : the three pins numbers
* Return type : void
************************************************************************************************************/
void clearbits(uint8_t bit1 , uint8_t bit2 , uint8_t bit3);

/************************************************************************************************************
* Description : initialize the keypad by setting the lower for bits as output and the upper bits input
* Parameters  : none
* Return type : void
************************************************************************************************************/
void keyPad_intil();

/************************************************************************************************************
* Description : this function scan the keypad and return the pressed key if no key was pressed will 
                return 'n' used only in the keypad4x4.c
* Parameters  : none
* Return type : uint8_t
************************************************************************************************************/
uint8_t getChar(void);

/************************************************************************************************************
* Description : this function will return only if a key was pressed otherwise will keep scaneing 
* Parameters  : none
* Return type : uint8_t 
************************************************************************************************************/
uint8_t keypad_scane (void);

#endif /* KEYPAD4X4_H_ */