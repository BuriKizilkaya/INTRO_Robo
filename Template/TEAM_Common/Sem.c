/**
 * \file
 * \brief Semaphore usage
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Module using semaphores.
 */

/**
 * \file
 * \brief Semaphore usage
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * Module using semaphores.
 */

#include "Platform.h" /* interface to the platform */
#if PL_CONFIG_HAS_SEMAPHORE
#include "FRTOS1.h"
#include "Sem.h"
#include "LED.h"
#include "Shell.h"
#include "CLS1.h"
#include "UTIL1.h"

static xSemaphoreHandle sem = NULL;
static TaskHandle_t MasterTaskHandle;
static TaskHandle_t SlaveTaskHandle;
static int comArray[10];

static void vSlaveTask(void *pvParameters) {
  /*! \todo Implement functionality */
	for(;;){
		xSemaphoreTake(sem, portMAX_DELAY);
		int i;
		for(i= 0; i < sizeof(comArray)/sizeof(int); i++){
			CLS1_SendNum16s(comArray[i], CLS1_GetStdio()->stdOut);
		}
		//vTaskDelay(pdMS_TO_TICKS(100));
	}
}

/* The master fill the array. Then can work the slave with the data */
static void vMasterTask(void *pvParameters) {
	for (;;) {
		int i;
		for (i = 0; i < sizeof(comArray) / sizeof(int); i++) {
			comArray[i] = i;
		}
		xSemaphoreGive(sem);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
  /*! \todo send semaphore from master task to slave task */

}

void SEM_Deinit(void) {
	vTaskDelete(MasterTaskHandle);
	vTaskDelete(SlaveTaskHandle);
}

/*! \brief Initializes module */
void SEM_Init(void) {
	sem = xSemaphoreCreateBinary();
	if(sem == NULL){
		SHELL_SendString("Semaphore isn't created");
	}


	//Create MasterTask for the Semaphore-Communication
	if (xTaskCreate(vMasterTask,
					"MasterTask",
					500/sizeof(StackType_t),
					(void*) NULL,
					tskIDLE_PRIORITY,
					&MasterTaskHandle) != pdPASS) {
		for (;;) {
		}
	} // end task: MasterTask

	//Create SlaveTask for the Semaphore-Communication
	if (xTaskCreate(vSlaveTask,
					"SlaveTask",
					500/sizeof(StackType_t),
					(void*) NULL,
					tskIDLE_PRIORITY,
					&SlaveTaskHandle) != pdPASS) {
		for (;;) {
		}
	} // end task: SlaveTask
}
#endif /* PL_CONFIG_HAS_SEMAPHORE */
