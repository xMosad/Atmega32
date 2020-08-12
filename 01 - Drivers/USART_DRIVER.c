/*
 * USART_DRIVER.c
 *
 * Created: 10/26/2019 12:33:07 AM
 *  Author: mosad
 */
 #include "USART_DRIVER.h"



 void usart_int (uint32_t B_R , uint32_t f_oc , INTERRUPT e_d , PARITY parity , R_T rec_trans , STOP_BITS num) {
	uint32_t x = 0 ;
     UCSRB = 0x18 ;
	 UCSRC = 0x86 ;
	 x = f_oc / 16 ;  x = x / B_R ; x = x - 1;
	 UBRRL = x ;
	 
	 /*       enable or disable interrupt          */ 
	 if( e_d == ENABLE_INTRUPRTS){
		 UCSRB |= (1 << 7 ); //enable receive complete interrupt
		 //UCSRB |= (1 << 6 ); //enable transmit complete interrupt
	 }
	 else if(e_d == DISAPLE_INTRUPRTS){
		 UCSRB &= ~(1 << 7 ); //disable receive complete interrupt
		 UCSRB &= ~(1 << 6 ); //disable transmit complete interrupt
	 }
	 
	 /*        enable odd or even parity or disble                   */
	 if (parity == ENABLE_PARITY_ODD){
		UCSRC |= ( 1 << 5);
		UCSRC |= ( 1 << 4);
	  }
	  else if (parity == ENABLE_PARITY_EVEN ){
		  UCSRC |= ( 1 << 5);
		  UCSRC &= ~( 1 << 4);
	  }
	  else if(parity == DISABLE_PARITY){
		  UCSRC &= ~( 1 << 5);
		  UCSRC &= ~( 1 << 4);
	  }
	  
	  /*         enable or disable receiver and transimmter       */
	  if (rec_trans == ENABLE_RECIEVER){UCSRB |= ( 1<< 4 );}
	  else if (rec_trans == ENABLE_TRANSMITTER){UCSRB |= ( 1<< 3 );}
	  else if (rec_trans == ENABLE_BOTH){UCSRB |= ( 1<< 4 ); UCSRB |= ( 1<< 3 ); }	
		  
	 /*         determine number of stop bits              */
	 if ( num == ONE_STOP) { UCSRC &= ~(1 << 3);}	    
	 else if ( num == TWO_STOP) { UCSRC |= (1 << 3);}	  
 }

// this function is to send one character 
void send_char(uint8_t _data){

	 while (!(UCSRA & (1 << 5))) {}
	 UDR = _data ;
}

// this function is to recieve one character
uint8_t recieve_char(){
	int _data = 0 ;
	 while (!(UCSRA & (1 << 7))) {}
	 _data = UDR ;
	 return _data ;
}

// to send a string (more than a character) it can send more than one word
// to use the function you send the streng in the form "test" (for examble)
void send_string(uint8_t * text){
	 while (!(*text == '\0')){
		 send_char(*text);
		 text++;
	 }
}

/*to recieve a string limted to one word the recieve oberation is finished by 
  entering space*/ 
// to use the funcion you must define an array to hold the string
void recieve_string(uint8_t * text){
		*text = recieve_char() ;
		while(!(*text == ' ')){
			text++;
			*text = recieve_char();
		}
		*text = '\0' ;
}
/*ISR(USART_RXC_vect)
{
	
}*/







