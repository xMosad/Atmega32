/*
 * keypad4x4.c
 *
 * Created: 4/2/2020 3:38:45 AM
 *  Author: mosad
 */ 
#include "keypad4x4.h"


void keyPad_intil(){
	DDRx  = 0x0f; 
	PORTx = 0;
}

uint8_t getChar(void){
	//setting row one and check on the columns 
	 SET_BIT(PORTx , 0); clearbits(1,2,3);
	 if(COLOUM1 ){while(COLOUM1 ); return '7' ;}
	 if(COLOUM2 ){while(COLOUM2 ); return '8' ;}
	 if(COLOUM3 ){while(COLOUM3 ); return '9' ;}
	 if(COLOUM4 ){while(COLOUM4 ); return '/' ;}
	 _delay_ms(10);	
	 
	 //setting row two and check on the columns 
	 SET_BIT(PORTx , 1); clearbits(0,2,3);
	 if(COLOUM1 ){while(COLOUM1  ); return '4' ;}
	 if(COLOUM2 ){while(COLOUM2  ); return '5' ;}
	 if(COLOUM3 ){while(COLOUM3  ); return '6' ;}
	 if(COLOUM4 ){while(COLOUM4  ); return '*' ;}
	 _delay_ms(10);
	 
	 //setting row three and check on the columns 
	 SET_BIT(PORTx , 2); clearbits(1,0,3);
	 if(COLOUM1 ){while(COLOUM1 ); return '1' ;}
	 if(COLOUM2 ){while(COLOUM2 ); return '2' ;}
	 if(COLOUM3 ){while(COLOUM3 ); return '3' ;}
	 if(COLOUM4 ){while(COLOUM4 ); return '-' ;}
	 _delay_ms(10);
	 
	 //setting row four and check on the columns 
	 SET_BIT(PORTx , 3); clearbits(1,2,0);
	 if(COLOUM1 ){while(COLOUM1 ); return 'c' ;}
	 if(COLOUM2 ){while(COLOUM2 ); return '0' ;}
	 if(COLOUM3 ){while(COLOUM3 ); return '=' ;}
	 if(COLOUM4 ){while(COLOUM4 ); return '+' ;}
	 _delay_ms(10); 
	
	return 'n' ;
}

void clearbits(uint8_t bit1 , uint8_t bit2 , uint8_t bit3){
	CLR_BIT (PORTx , bit1);
	CLR_BIT (PORTx , bit2);
	CLR_BIT (PORTx , bit3);
}

//the function is to scan constantly on the keypad
uint8_t keypad_scane (void) {
	uint8_t value = 'n' ;
	while(value == 'n'){
		value =  getChar();
	}
	return value ;
}
