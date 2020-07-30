/*
===============================================================================
 Name        : Blinky.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

	LPC_GPIO0->FIODIR |= (1 << 22); // Set P0.22 - to be OUTPUT
	volatile static uint32_t i;
	while (1)
	{
		LPC_GPIO0->FIOSET = (1 << 22); // Turn ON
		for (i = 0; i <= 1000000; i++);
		LPC_GPIO0->FIOCLR = (1 << 22); //turn off
		for (i = 0; i <= 1000000; i++);
	}

    // Force the counter to be placed into memory
   /* volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }*/
    return 0 ;
}
