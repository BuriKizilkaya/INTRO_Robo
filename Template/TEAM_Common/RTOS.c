/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_CONFIG_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "Application.h"
#include "LED.h"

static void BlinkyTask(void* pvParameters) {
	for (;;) {
		EVNT_HandleEvent(APP_EventHandler, TRUE);
		LED1_Neg();
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void RTOS_Init(void) {
	/*! \todo Create tasks here */
	if (xTaskCreate(BlinkyTask,
					"Blinky",
					configMINIMAL_STACK_SIZE,
					(void*) NULL,
					tskIDLE_PRIORITY,
					(xTaskHandle*) NULL) != pdPASS) {
		for (;;) {}
	} // end task create: Blinky


	// Start Scheduler
	vTaskStartScheduler();
}

void RTOS_Deinit(void) {
	/* nothing needed for now */
}

#endif /* PL_CONFIG_HAS_RTOS */
