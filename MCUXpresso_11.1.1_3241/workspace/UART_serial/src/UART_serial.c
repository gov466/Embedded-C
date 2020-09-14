/*
 ===============================================================================
 Name        : UART_serial.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif
#include "uart.h"
void delay(int);
int main(void)
{
	UART0_Init(9600);
	while (1)
	{
		UART0_PrintString("Tenet_Technetronics\r\n");
		delay(100);
	}
	return 0;
}
void delay(int a)
{
	int i, j;
	for (i = 0; i < 500000; i++)
	{
		for (j = 0; j < a; j++);
	}
}

