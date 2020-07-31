/*
===============================================================================
 Name        : Pushbutton_led.c
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

//  insert other include files here

//  insert other definitions and declarations here

int getPinState(int pinNumber);		// Method prototypes

int main(void)
{

  LPC_GPIO1->FIODIR &= ~(1 << 28); 	// Set buttons as input
  LPC_GPIO1->FIODIR |= (1 << 29); 	// Set LEDs as output
  LPC_GPIO1->FIOPIN |= (1 << 29); // Turn both LEDS on

  while (1)
  {
    if (getPinState(28))			// Check button pressed
    {
      // Turn LED off
       LPC_GPIO1->FIOSET = (1 << 29);
    }
    else
    {
      // Turn LED on
      LPC_GPIO1->FIOCLR = (1 << 29);
    }
  }
}

int getPinState(int pinNumber)
{

  int pinBlockState = LPC_GPIO1->FIOPIN; // Read current state of pins
  // Read the value of 'pinNumber'
  int pinState = (pinBlockState & (1 << pinNumber)) ? 1 : 0;
  return pinState;											// Return the value of pinState
}
