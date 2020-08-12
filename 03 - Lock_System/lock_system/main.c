/*
 * lock_system.c
 *
 * Created: 4/2/2020 7:46:59 AM
 * Author : abdelrhman mosad 
 * It is a simple lock system that takes the password from the user and check whether the pass was
   correct or not to let him into the system if the pass was correct 
 */ 

#include "lcd_drive.h"
#include "keypad4x4.h"

/************************************************************************************************************
*                                       prototype                                                           *
************************************************************************************************************/
void lcd_begin();
void take_pass();
uint8_t check_pass();
void pass_correct();
void pass_wrong();
/************************************************************************************************************
*                                       global variables                                                          *
************************************************************************************************************/
uint8_t entered_pass[6] ;  // store the entered password
uint8_t old_pass[6] = "123456"; // system password
uint8_t wrong_tries = 0; // number or tries to enter the pass
int main(void)
{
    keyPad_intil();
	Lcd_Init();
	lcd_begin();
	take_pass();
    while (1) 
    {
		uint8_t read = keypad_scane();
		if (read == '='){
			uint8_t check = check_pass();
			if (check == 1){pass_correct();}
			if (check == 0){pass_wrong();}	
		}	 		
	}
				 
				 
   
}
/************************************************************************************************************
* Description : display the startup sequence first showing "welcome" and wait for the user to press any key 
                then show the loading sequence which is only for the show only used once before the while loop
* Parameters  : none
* Return type : void                                                                           
************************************************************************************************************/
void lcd_begin(){
	//intialize some lcd commands
	send_command(_LCD_CLEAR);
	_delay_ms(10);
	send_command(_LCD_BLINK_CURSOR_OFF);
	_delay_ms(10);
	
	//the opening to the system
	Lcd_Out(1 , 4 , "welcome");
	_delay_ms(10);
	Lcd_Out(2 , 2 , "press any key");
	keypad_scane(); // will stay here until you press any button 
	_delay_ms(100);
	send_command(_LCD_CLEAR);
	_delay_ms(10);
	Lcd_Out(1 , 1 , "loading .");
	int i = 0 ;
	/* for loading  */
	/* this part is only a show it has no actual meaning in the code */
	while( i < 3){
		for(int j = 0 ; j < 4 ; j++){
			Lcd_Chr(1 , 10+j , '.');
			_delay_ms(200);
		}
		Lcd_Out(1 , 10, "     ");
		i++;
	}
}

/************************************************************************************************************
* Description : the function take the entered pass from the user and store it in the entered_pass array 
                it will store all the keys except for = and c if clear button was clicked it will clear 
				the last entered character
* Parameters  : none
* Return type : void
************************************************************************************************************/
void take_pass(){
	 send_command(_LCD_CLEAR);
	 _delay_ms(10);
	 Lcd_Out(1 , 1 , "enter the pass : -");
	 for (int i = 0 ; i < 6 ; i++){
		 uint8_t read_value = keypad_scane();
		 if ( !((read_value == 'c') || (read_value == '=')) ){
			entered_pass[i] = read_value ;
			Lcd_Chr(2 , 2+i , entered_pass[i]);
			_delay_ms(100);
			Lcd_Chr(2 , 2+i , '*');
		 }
		 else if (read_value == 'c'){
			Lcd_Chr(2 , 1+i , ' '); 
			i = i - 2 ;
		 }
		
		 
	 }
}

/************************************************************************************************************
* Description : will check if the enetered pass was correct or wrong if it was correct return 1 if not 
                return 0 
* Parameters  : none
* Return type : uibt8_t 
************************************************************************************************************/
uint8_t check_pass(){
	 int i = 0 ;
	 while(old_pass[i] == entered_pass [i]){
		 i++;
		 if( i == 6){return 1 ;}
	 }
	 return 0 ;
}

/************************************************************************************************************
* Description : if the password was correct will enter the system through that function 
* Parameters  : none
* Return type : void
************************************************************************************************************/
void pass_correct(){
	send_command(_LCD_CLEAR);
	_delay_ms(10);
	Lcd_Out(1 , 2 , "hello  to");
	Lcd_Out(2 , 2 , "the system");
	while(1){}
}

/************************************************************************************************************
* Description : if the password was wrong will let you to try again for three times then freeze the system
* Parameters  : none
* Return type : void
************************************************************************************************************/	
void pass_wrong(){
	send_command(_LCD_CLEAR);
	_delay_ms(10);
	Lcd_Out(1 , 2 , "wrong pass");
	Lcd_Out(2 , 2 , "try again");
	wrong_tries ++ ;
	// to limit the user for max three tries 
	if (wrong_tries == 3){
		send_command(_LCD_CLEAR);
		_delay_ms(10);
		Lcd_Out(1 , 2 , "sorry cant");
		Lcd_Out(2 , 2 , "try again");
		_delay_ms(2000);
		while(1){} //freeze system 
	 }
	else {take_pass();}	
}