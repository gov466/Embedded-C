#include "board.h"
#include "FreeRTOS.h"
#include "task.h"

/* Sets up system hardware */
static void prvSetupHardware(void)
{
	SystemCoreClockUpdate();
	Board_Init();
	Board_Buttons_Init();

	/* Initial LED0 state is off */
	Board_LED_Set(0, false);
	Board_LED_Set(1, false);
	Board_LED_Set(2, false);

}

static void vLEDTask(void *pvParameters)
{

	while (1)
	{

		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(2, true); //blue on
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(2, false); //blue off
		vTaskDelay(configTICK_RATE_HZ);

		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(1, true); //green on
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(1, false); //green off
		vTaskDelay(configTICK_RATE_HZ);

		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(0, true); //red on
		vTaskDelay(configTICK_RATE_HZ);
		Board_LED_Set(0, false); //red off
		vTaskDelay(configTICK_RATE_HZ);
	}
}

//*****Driver Code*****//

int main(void)
{
	prvSetupHardware();

	/* LED1 toggle thread */
	xTaskCreate(vLEDTask, (signed char* ) "vTaskLed1", configMINIMAL_STACK_SIZE,
			NULL, (tskIDLE_PRIORITY + 1UL), (xTaskHandle *) NULL);
	/* LED2 toggle thread */
	xTaskCreate(vLEDTask, (signed char* ) "vTaskLed1", configMINIMAL_STACK_SIZE,
			NULL, (tskIDLE_PRIORITY + 1UL), (xTaskHandle *) NULL);
	/* LED3 toggle thread */
	xTaskCreate(vLEDTask, (signed char* ) "vTaskLed1", configMINIMAL_STACK_SIZE,
			NULL, (tskIDLE_PRIORITY + 1UL), (xTaskHandle *) NULL);

	/* Start the scheduler */
	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

/**
 * @}
 */
