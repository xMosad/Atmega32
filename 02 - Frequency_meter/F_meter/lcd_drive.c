/*
 * lcd_drive.c
 *
 * Created: 2/11/2020 8:52:20 AM
 *  Author:mosad
 */ 

#include "lcd_drive.h"


// to activate the enable to send commands or data
void send_enable(void) {
	PORTC |= (1 << en);
	_delay_us(2);
	PORTC &= ~(1 << en);
	_delay_us(2);
}
// to send commands
void send_command(  char command){
	PORTC &= ~(1 << rs);
	LCD_DATA = 0 ;
	LCD_DATA = command ;
	send_enable();
}
//to send the data
void send_data (char Data){
	PORTC |= (1 << rs);
	LCD_DATA = 0 ;
	LCD_DATA = Data ;
	send_enable();
}
// The intializing function to set the display to operate
void Lcd_Init(){
	DDRC |=(1<<rs);
	DDRC |=(1<<en);
	DDRD = 0XFF ;
	PORTC &= ~(1 << rs);
	PORTC &= ~(1 << en);
	LCD_DATA = 0x00;
	/////////////////////////////
	_delay_ms(20);
	LCD_DATA = 0x00;
	send_command(0x38);
	send_enable();

	_delay_ms(7);
	LCD_DATA = 0x00;
	send_command(0x38);
	send_enable();
	
	_delay_ms(120);
	LCD_DATA = 0x00;
	send_command(0x38);
	send_enable();
	///////////////////////////////////
	send_command(_LCD_CLEAR);
	_delay_ms(10);
	send_command(_LCD_RETURN_HOME);
	_delay_ms(10);
	send_command(_CHARACTER_ENTERY_MODE);
	_delay_ms(10);
	send_command(_LCD_TURN_ON);
	_delay_ms(10);
	send_command(_LCD_MOVE_CURSOR_LEFT);
	_delay_ms(10);
	send_command(0x56);
	_delay_ms(10);
	send_command(_LCD_FIRST_address);
	_delay_ms(10);
}
// to show a characater on the display
void Lcd_Chr(char row, char column, char out_char){
	row-- ;
	column--;
	send_command((0x80 + 0x40 * row)+ column );
	_delay_ms(1);
	send_data(out_char);
	_delay_ms(1);
}

// to show strings
void Lcd_Out(char row, char column, char *text){
	row-- ;
	column--;
	send_command((0x80 + 0x40 * row)+ column );
	_delay_ms(1);
	while(*text){
		send_data(*text++);
		_delay_ms(10);
	}

}

// to print the character at  current cursor position
void Lcd_Chr_Cp(char out_char){
	send_data(out_char);
	_delay_ms(10);

}

// to print string at  current cursor position
void Lcd_Out_Cp(char *text){
	while(*text){
		send_data(*text++);
		_delay_ms(100);
	}
}
