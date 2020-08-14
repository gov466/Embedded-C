//Defining the headers
#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

xSemaphoreHandle xMutex;

//Clearing the LEDs
void clearLEDs(void)
	{
	Board_LED_Set(0, true);
	Board_LED_Set(1, true);
	Board_LED_Set(2, true);
	}

//Seting up the hardware
static void prvSetupHardware(void)
	{
	SystemCoreClockUpdate();
	Board_Init();
	//At the start all the leds are off
	clearLEDs();
	}



static void blinkLED( void *pvParameters )
	{
	 int ledNum = ( int * ) pvParameters;
	 while(1)
		 {
		 xSemaphoreTake( xMutex, portMAX_DELAY );
		 		  {
		 		  Board_LED_Set(ledNum, 0);
		 		  // printf("red on \n");
		 		  vTaskDelay( 1000 );
		 		  Board_LED_Set(ledNum, 1);
		 		  // printf("red off \n");
		 		  vTaskDelay( 1000 );
		 		  }
		 xSemaphoreGive( xMutex );
		 vTaskDelay(4000);
		 }
	}




int main( void )
	{
	prvSetupHardware();
	SystemCoreClockUpdate();
	clearLEDs();

	xMutex = xSemaphoreCreateMutex();
	 if( xMutex != NULL )
		 {

		 xTaskCreate( blinkLED,   "redLED", 100, 0, 1, NULL );

		 xTaskCreate( blinkLED, "greenLED", 100, 1, 2, NULL );

		 xTaskCreate( blinkLED,  "blueLED", 100, 2, 3, NULL );

		 vTaskStartScheduler();
		 }


	}
