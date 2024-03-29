/**
 *
 * @file    service_task.h
 * @brief   Public definitions for the keeping the device running.
 *
 */

#ifndef SERVICE_TASK_H
#define SERVICE_TASK_H
/*
***************************************************************************************************
* EXTERNAL DEFINES
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL TYPES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL VARIABLES DECLARATIONS
***************************************************************************************************
*/

/*
***************************************************************************************************
* EXTERNAL FUNCTIONS DECLARATIONS
***************************************************************************************************
*/
/** @brief Initialize the FreeRTOS tasks and attributes */
void init_service_task(void);

#endif /* SERVICE_TASK_H */
