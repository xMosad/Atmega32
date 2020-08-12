/*
 * Timer_drive.c
 *
 * Created: 10/21/2019 2:55:42 PM
 *  Author: Mosad
 */
#include "Timer_drive.h" 

void timer0_int(MODE mode , PRESCALER ps){
	T0 = 0x01 ;
	if( mode == CTC_MODE){ T0 |= (1 << 3); }
	if(ps == PRESCALER_8){T0 &= ~(1 << 2); T0|=(1 << 1); T0&= ~(1 << 0);}
	else if(ps == PRESCALER_64){T0 &= ~(1 << 2); T0|=(1 << 1); T0|= (1 << 0);}
	else if(ps == PRESCALER_256){T0 |= (1 << 2); T0 &= ~(1 << 1); T0 &= ~(1 << 0);}
	else if(ps == PRESCALER_1024){T0 |= (1 << 2); T0 &= ~(1 << 1); T0 |= (1 << 0);}
	else if(ps == COUNTER_NEGATIVE){T0 |= (1 << 2); T0 |= (1 << 1); T0 &= ~(1 << 0);}
	else if(ps == COUNTER_POSITEVE){T0 |= (1 << 2); T0 |= (1 << 1); T0 |= (1 << 0);}
	
}

void timer1_int(MODE mode , PRESCALER ps){
	T1_A = 0x00 ;
	T1_B = 0x01 ;
	if( mode == CTC_MODE_ICR){ T1_B |= (1 << 3); T1_B &= ~(1 << 4); }
	else if ( mode == CTC_MODE_OCR){ T1_B |= (1 << 3); T1_B |= (1 << 4); } 

	if(ps == PRESCALER_8){T1_B &= ~(1 << 2); T1_B|=(1 << 1); T1_B &= ~(1 << 0);}
	else if(ps == PRESCALER_64){T1_B &= ~(1 << 2); T1_B |=(1 << 1); T1_B|= (1 << 0);}
	else if(ps == PRESCALER_256){T1_B |= (1 << 2); T1_B &= ~(1 << 1); T1_B &= ~(1 << 0);}
	else if(ps == PRESCALER_1024){T1_B |= (1 << 2); T1_B &= ~(1 << 1); T1_B |= (1 << 0);}
	else if(ps == COUNTER_NEGATIVE){T0 |= (1 << 2); T0 |= (1 << 1); T0 &= ~(1 << 0);}
	else if(ps == COUNTER_POSITEVE){T0 |= (1 << 2); T0 |= (1 << 1); T0 |= (1 << 0);}
} 

void timer2_int(MODE mode , PRESCALER ps){
	T2 = 0x01 ;
	if( mode == CTC_MODE){ T2 |= (1 << 3); }
	if(ps == PRESCALER_8){T2 &= ~(1 << 2); T2|=(1 << 1); T2&= ~(1 << 0);}
	else if(ps == PRESCALER_32){T2 &= ~(1 << 2); T2|=(1 << 1); T2|= (1 << 0);}
	else if(ps == PRESCALER_64){T2 |= (1 << 2); T2 &= ~(1 << 1); T2 &= ~(1 << 0);}
	else if(ps == PRESCALER_128){T2 |= (1 << 2); T2 &= ~(1 << 1); T2 |= (1 << 0);}
	else if(ps == PRESCALER_256){T2 |= (1 << 2); T2 |= (1 << 1); T2 &= ~(1 << 0);}
	else if(ps == PRESCALER_1024){T2 |= (1 << 2); T2 |= (1 << 1); T2 |= (1 << 0);}	
}



