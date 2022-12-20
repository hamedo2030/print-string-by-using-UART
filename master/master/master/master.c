/*
 * master.c
 *
 * Created: 12/19/2022 7:57:12 AM
 *  Author: mostafa_hamedo
 */ 

#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"

int main(void)
{
	UART_vInit(9600) ; //Initialized UART
	_delay_ms(350); //Wait LCD Initialized AT Receiver controller 
	UART_vsend_string("HELLO MY FRIENDS");
    while(1)
    {
        //TODO:: Please write your application code 
    }
}