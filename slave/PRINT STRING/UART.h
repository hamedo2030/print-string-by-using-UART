/*
 * UART.h
 *
 * Created: 10/22/2022 12:05:39 PM
 *  Author: happy
 */ 


#ifndef UART_H_
#define UART_H_

void UART_vInit(unsigned long baud) ;
void UART_vsend_data(unsigned char data);
unsigned char UART_u8receive_data(void);
void UART_vsend_string(unsigned char * ptr);





#endif /* UART_H_ */