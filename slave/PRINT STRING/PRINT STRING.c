/*
 * PRINT_STRING.c
 *
 * Created: 12/19/2022 7:44:24 AM
 *  Author:mostafa_hamedo 
 */ 


#include <avr/io.h>
#define  F_CPU 8000000
#include <util/delay.h>
#include "UART.h"
#include "std_macros.h"

int main(void)
{	
	
	Lcd_Init();
	UART_vInit(9600);
	char data ;
    while(1)
    {
		// Receive data and display on LCD
        data=UART_u8receive_data();
        Lcd_send_char(data);
		
	   
	   
    }
}