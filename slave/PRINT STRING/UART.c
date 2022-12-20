/*
 * UART.c
 *
 * Created: 10/22/2022 12:05:18 PM
 *  Author: happy
 */ 
#include <avr/io.h>
#define  F_CPU 8000000
#include <util/delay.h>
#include "UART.h"
#include "std_macros.h"

void UART_vInit(unsigned long baud)
{
	// choose baud rate that will be used by sender and receiver 
	
	unsigned short UBRR ;
	
	
	UBRR=(F_CPU/(16*baud))-1;
	UBRRH=(unsigned char )(UBRR>>8);
	UBRRL=(unsigned char )UBRR ;
	
	// enable USART sender and receiver 
	
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	
	// polarity mode :odd
	// stop bit mode : 2 stop bit 
	// character size : 8 bit  
	UCSRC=(1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
	//UCSRC=(1<<URSEL)|(1<<UPM1)|(1<<UPM0)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0);
}

void UART_vsend_data(unsigned char data)
{
	while(READ_BIT(UCSRA,UDRE)==0);
	// wait until UDRE IS empty
	UDR=data;
	
}

unsigned char UART_u8receive_data(void)
{
	while(READ_BIT(UCSRA,RXC)==0);
	// wait until RXC received all  data 
	// THEN READ DATA 
	return UDR ;
}

void UART_vsend_string(unsigned char * ptr)
{
	
	while(*ptr!=0)
	{
	UART_vsend_data(*ptr);
	ptr++;
	_delay_ms(100);
	}
	
}
