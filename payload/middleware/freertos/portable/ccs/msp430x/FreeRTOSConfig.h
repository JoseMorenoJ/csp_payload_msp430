#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*
 * -----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------
 */

#define configMAX_PRIORITIES                    (2)
#define configIDLE_SHOULD_YIELD                 1
#define configCHECK_FOR_STACK_OVERFLOW          2
#define configSUPPORT_STATIC_ALLOCATION         1
#define configSUPPORT_DYNAMIC_ALLOCATION        0
#define configUSE_PREEMPTION                    1
#define configUSE_16_BIT_TICKS                  1
#define configUSE_RECURSIVE_MUTEXES             1
#define configUSE_MUTEXES                       1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define INCLUDE_vTaskDelay                      1


#ifdef __LARGE_DATA_MODEL__
#  define configMINIMAL_STACK_SIZE              ((unsigned short)80)
#else
#  define configMINIMAL_STACK_SIZE              ((unsigned short)120)
#endif


/* The MSP430X port uses a callback function to configure its tick interrupt.
This allows the application to choose the tick interrupt source.
configTICK_VECTOR must also be set in FreeRTOSConfig.h to the correct interrupt
vector for the chosen tick interrupt source.  This implementation of
vApplicationSetupTimerInterrupt() generates the tick from timer A0, so in this
case configTICK_VECTOR is set to TIMER0_A0_VECTOR. */
#define configTICK_VECTOR                       TIMER0_A0_VECTOR

#define configASSERT(x)                         if ((x) == 0) { taskDISABLE_INTERRUPTS(); for( ;; ); }

#define configDELAY_MS(x)                       vTaskDelay(x)

#define configDEFAULT_TASK_PRIO                 (tskIDLE_PRIORITY + 1)


#endif /* FREERTOS_CONFIG_H */
