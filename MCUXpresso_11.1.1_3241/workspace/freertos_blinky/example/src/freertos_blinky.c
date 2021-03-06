/*
 * @brief FreeRTOS Blinky example
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2014
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/*****************************************************************************
 * Private functions
 ****************************************************************************/
xQueueHandle xQueue; //queue ihandler
/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
	/* Initial LED1  is off */
	Board_LED_Set(1,false);
	/* Initial LED2 state is off */
	Board_LED_Set(2, false);
}
/* LED1 toggle thread */
static void vTaskreceive(void *pvParameters)
{
	int x;
	while (1)
	{
		xQueueReceive(xQueue, &a, 1000); //receive queue
		Board_LED_Set(x, 0); //first led on

		vTaskDelay(configTICK_RATE_HZ); //delay of 1ms
		Board_LED_Set(x, 1); //led off
		vTaskDelay(configTICK_RATE_HZ); //delay of 1ms
	}
}


void vTasksend(void *pvParameters)  //send to queue
{
	int led1 = *(int*) pvParameters;
	while (1)
	{

		xQueueSendToBack(xQueue, &led1, 0); //enter at back
	}
}
/*static void vLEDTask1(void *pvParameters)
{

	while (1)
	{
		Board_LED_Set(0, 0); //led 0 off
		vTaskDelay(configTICK_RATE_HZ); //delay
		Board_LED_Set(0, 1); //led 0 on
		vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	}
}
/*static void vLEDTask2(void *pvParameters)
{
	vTaskDelay(configTICK_RATE_HZ + configTICK_RATE_HZ / 2); //delay

	while (1)
	{
		Board_LED_Set(1, 0); //led 1 off
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(1, 1); //led 1 on

		/* About a 7Hz on/off toggle rate*/
	//	vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	//}
//}*/
/*static void vLEDTask3(void *pvParameters)
{
	vTaskDelay(3 * configTICK_RATE_HZ);
	while (1)
	{

		Board_LED_Set(2, 0); //led 2 off
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(2, 1); //led 2 on

		/* About a 7Hz on/off toggle rate*/
	//	vTaskDelay(3 * configTICK_RATE_HZ + configTICK_RATE_HZ / 2);
	//}
//}

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/**
 * @brief	main routine for FreeRTOS blinky example
 * @return	Nothing, function should not exit
 */
int main(void)
{
	prvSetupHardware();
	xQueue=xQueueCreate(3,sizeof(int)); //queue iisicreated
	/* LED1 toggle thread */
	xTaskCreate(vTasksend, (signed char *) "LED1",
			configMINIMAL_STACK_SIZE,(void*),(tskIDLE_PRIORITY + 1UL),
			(xTaskHandle *) NULL);
	xTaskCreate(vTasksend, (signed char *) "LED2",
			configMINIMAL_STACK_SIZE,(void*) ,(tskIDLE_PRIORITY + 1UL),
			(xTaskHandle *) NULL);
	xTaskCreate(vTasksend, (signed char *) "LED3",
			configMINIMAL_STACK_SIZE,(void*) , (tskIDLE_PRIORITY + 1UL),
			(xTaskHandle *) NULL);
	xTaskCreate(vTaskreceive, (signed char *) "vTaskreceive",
			configMINIMAL_STACK_SIZE, (void*) NULL, (tskIDLE_PRIORITY +2UL),
			(xTaskHandle *) iNULL);


	/*xTaskCreate(vLEDTask1, (signed char* ) "vTaskLed1",
			configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 3UL),
			(xTaskHandle *) NULL);

	/* LED2 toggle thread */
	/*xTaskCreate(vLEDTask2, (signed char* ) "vTaskLed2",
			configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 2UL),
			(xTaskHandle *) NULL);

	xTaskCreate(vLEDTask3, (signed char* ) "vTaskLed3",
			configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1UL),
			(xTaskHandle *) NULL);*/

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
