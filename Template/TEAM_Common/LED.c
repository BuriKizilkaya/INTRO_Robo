/**
 * \file
 * \brief LED driver
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This is a generic module to drive one or multiple LEDs.
 */

#include "Platform.h"
#if PL_CONFIG_HAS_LEDS
#include "LED.h"

#if PL_CONFIG_HAS_SHELL
#include "Shell.h"
#if PL_CONFIG_HAS_SHELL_QUEUE
#include "ShellQueue.h"
#endif

#endif

#if PL_CONFIG_HAS_RTOS
#include "FRTOS1.h"
#endif

#if PL_CONFIG_HAS_RTOS
static void BlinkyTask(void* pvParameters) {
	for (;;) {
		LED1_Neg();
		//SQUEUE_SendString((unsigned char*)"Hello!");
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}
#endif

void LED_Deinit(void) {
  LED1_Off();
  LED2_Off();
  LED3_Off();
#if PL_CONFIG_NOF_LEDS>=4
  #error "only 3 LEDs supported"
#endif
}

void LED_Init(void) {
  LED1_Off();
  LED2_Off();
  LED3_Off();

#if 1//PL_CONFIG_HAS_RTOS
  if (xTaskCreate(BlinkyTask,
				  "Blinky",
				  configMINIMAL_STACK_SIZE,
				  (void*) NULL,
				  tskIDLE_PRIORITY,
				  (xTaskHandle*) NULL) != pdPASS) {
		for (;;) {
		}
  	} // end task: Blinky
#endif

}

#endif /* PL_CONFIG_HAS_LEDS */
