/*
 * lcd_4_bit.h
 *
 * Created: 10/13/2022 4:16:29 AM
 *  Author: mostafa_hamedo
 */ 


#ifndef LCD_4_BIT_H_
#define LCD_4_BIT_H_



#include "DIO_Drives.h"
#include "std_macros.h"

// command ....................

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTERY_MODE 0x06
#define FOUR_BITS 0x28
//control pin .......................

#define RS 0
#define RW 1
#define EN 2
#define control_port 'C'


// data_port .........
#define data_port 'C'

//--------------------------

void enable_mode (void);
void Lcd_send_cmd(char cmd);
void Lcd_send_char(char data);
void Lcd_clear_screen(void);
void Lcd_Init(void);
void Lcd_send_string(char *data);
void Lcd_move_cursor(char row , char coloumn );



#endif /* LCD_4_BIT_H_ */