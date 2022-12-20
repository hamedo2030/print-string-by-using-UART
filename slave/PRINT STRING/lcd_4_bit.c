/*
 * lcd_4_bit.c
 *
 * Created: 10/13/2022 4:15:58 AM
 *  Author: happy
 */ 
#include "lcd_4_bit.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_Drives.h"






// enable mode -------------------

void enable_mode (void)
{
	DIO_write_pin(control_port,EN,1);
	_delay_ms(5);
	DIO_write_pin(control_port,EN,0);
	_delay_ms(5);
}

// send command

void Lcd_send_cmd(char cmd)
{
	//DIO_write_port(data_port,cmd);
	write_high_nibble(data_port,cmd>>4);
	DIO_write_pin(control_port,RS,0);
	enable_mode();
	_delay_ms(2);
	
	write_high_nibble(data_port,cmd);
	DIO_write_pin(control_port,RS,0);
	enable_mode();
	_delay_ms(2);
}

// Send_character-------------------

void Lcd_send_char(char data)
{
	//DIO_write_port(data_port,data);
	write_high_nibble(data_port,data>>4);
	DIO_write_pin(control_port,RS,1);
	enable_mode();
	_delay_ms(1);
	
	write_high_nibble(data_port,data);
	DIO_write_pin(control_port,RS,1);
	enable_mode();
	_delay_ms(1);
	
}

// lcd_clear_screen

void Lcd_clear_screen(void)
{
	
	Lcd_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	
}


// Lcd_initiliation ...........................

void Lcd_Init(void)
{
	_delay_ms(200);

	
	DIO_set_pin_direction(data_port,4,1);
	DIO_set_pin_direction(data_port,5,1);
	DIO_set_pin_direction(data_port,6,1);
	DIO_set_pin_direction(data_port,7,1);
	
	
	DIO_set_pin_direction(control_port,EN,1);
	DIO_set_pin_direction(control_port,RS,1);
	DIO_set_pin_direction(control_port,RW,1);

	
	
	DIO_write_pin(control_port,RW,0);
	
	
	Lcd_send_cmd(RETURN_HOME); //return home
	_delay_ms(10);
	Lcd_send_cmd(0x28); //4bit mode
	_delay_ms(1);
	
	
	Lcd_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	Lcd_send_cmd(CLR_SCREEN);
	//Lcd_clear_screen();
	_delay_ms(10);
	Lcd_send_cmd(ENTERY_MODE);
	_delay_ms(1);
	
}

// send_string -------------------
void Lcd_send_string(char *data)
{
	while((*data)!='\0')
	{
		Lcd_send_char(*data);
		data++;
	}
}

// move_cursor -----------------------

void Lcd_move_cursor(char row , char coloumn )
{
	char data ;
	if(row<1 || row>4|| coloumn<1 || coloumn>20)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+coloumn-1 ;
	}
	else if(row==2)
	{
		data=0xc0+coloumn-1;
	}
	else if(row==3)
	{
		data=0x90+coloumn-1;
	}
	else if(row==4)
	{
		data=0xd0+coloumn-1;
	}
	
	
	
	
	Lcd_send_cmd(data);
	_delay_ms(1);
	
}
