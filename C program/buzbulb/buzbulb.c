/*
 * buzbulb.c
 *
 *  Created on: Nov. 18, 2020
 *      Author: sunny
 */

#include <iobb.h>
#include <stdio.h>

int bulbPin = 30; //declaring port 9 pin 30 for bulb output
int port9 = 9; //port 9
int buzzerPin = 8; //declaring port 8 pin 8 as buzzer output
int port8 = 8; //port8


int speed = 30; //speed of vehicle

int threshold = 20; //maximum speed

int main(void)
{
  iolib_init();   //iolib initialization
  iolib_setdir(port8, buzzerPin, DigitalOut);  //setting port8 pin 8 as output pin
  iolib_setdir(port9, bulbPin, DigitalOut);  //setting port9 pin 30 as output pin
  while(1)
   {
        if(speed > threshold) //checking if speed>max speed
        {
    printf("BUZZER ON \n"); //print buzzer on
    pin_high(port8, buzzerPin); //setting port8 pin high
    iolib_delay_ms(300);  //delay
    pin_low(port8, buzzerPin); ////setting port8 pin low
    iolib_delay_ms(300); //delay

    printf("BULB FLASH \n");  //print buzzer on
    pin_high(port9, bulbPin);  //setting port9 pin high
    iolib_delay_ms(300);
    pin_low(port9, bulbPin); //setting port9 pin low
    iolib_delay_ms(300);

        }
    else
    {
    pin_low(port8, buzzerPin);   //setting port8 pin low
    printf("BUZZER OFF \n");
    pin_low(port9, bulbPin);   //setting port9 pin low
    printf("BULB OFF \n");
        }

  }
  iolib_free(); //freeing library
  return(0);
}






