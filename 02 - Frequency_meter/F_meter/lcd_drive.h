/*
 * lcd_drive.h
 *
 * Created: 2/11/2020 8:52:51 AM
 *  Author: mosad
 */ 


#ifndef LCD_DRIVE_H_
#define LCD_DRIVE_H_

#define LCD_DATA PORTD         // port d is selected as LCD data port

//#define ctrl PORTD              //  port D is selected as LCD command port
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#define en 0                  
#define rs 1                  





// commands
#define  _LCD_CLEAR  0x01
#define  _LCD_RETURN_HOME 0x02
#define _CHARACTER_ENTERY_MODE 0x06
#define  _LCD_CURSOR_OFF 
#define  _LCD_UNDERLINE_ON 0x0F
#define  _LCD_MOVE_CURSOR_LEFT 0x10
#define  _LCD_MOVE_CURSOR_RIGHT 0x14
#define  _LCD_TURN_OFF 0x09
#define  _LCD_TURN_ON 0x0D
#define _LCD_FIRST_address 0x80
#define _LCD_BLINK_CURSOR_OFF 0x0C



// functions declarations
void send_enable(void);
void send_command( char command);
void send_data (char Data);
void Lcd_Chr_Cp(char out_char);
void Lcd_Out_Cp(char *text);
void Lcd_Chr(char row, char column, char out_char);
void Lcd_Init();
void Lcd_Out(char row, char column, char *text);




#endif /* LCD_DRIVE_H_ */