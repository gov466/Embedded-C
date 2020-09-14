/*
 * uart.h
 *
 *  Created on: Sep. 2, 2020
 *      Author: govind
 */
#ifndef UART_H_
#define UART_H_
// ***********************
// Function to set up UART
void UART0_Init(int baudrate);
void UART1_Init(int baudrate);
void UART2_Init(int baudrate);
void UART3_Init(int baudrate);
// ***********************
// Function to send character over UART
void UART0_Sendchar(char c);
void UART1_Sendchar(char c);
void UART2_Sendchar(char c);
void UART3_Sendchar(char c);
// ***********************
// Function to get character from UART
char UART0_Getchar();
char UART1_Getchar();
char UART2_Getchar();
char UART3_Getchar();
// ***********************
// Function to prints the string out over the UART
void UART0_PrintString(char *pcString);
void UART1_PrintString(char *pcString);
void UART2_PrintString(char *pcString);
void UART3_PrintString(char *pcString);

#endif /*UART_H_*/

