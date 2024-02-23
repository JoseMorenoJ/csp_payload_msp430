/**
 *
 * @file    service_task.c
 * @brief   Task taking care of indicating the status of the device.
 *
 */

#include "service_led.h "
#include "task.h"

/***************************************************************************************************
 * EXTERNAL VARIABLES
 **************************************************************************************************/

/***************************************************************************************************
 * PRIVATE MACROS AND DEFINES
 **************************************************************************************************/
// Define the service task attributes
#define SERVICE_TASK_STACK_SZ (configMINIMAL_STACK_SIZE + 20)
static TaskHandle_t h_led_task = NULL;

/***************************************************************************************************
 * PRIVATE TYPE DEFINITIONS
 **************************************************************************************************/

/***************************************************************************************************
 * STATIC VARIABLES
 **************************************************************************************************/

/***************************************************************************************************
 * STATIC DECLARATIONS
 **************************************************************************************************/
static void service_task(void *arg);

/***************************************************************************************************
 * PUBLIC DEFINITIONS
 **************************************************************************************************/

void init_service_task(void)
{
    // create task attributes
    BaseType_t res = xTaskCreate(service_task,
                                 "service_task",
                                 SERVICE_TASK_STACK_SZ,
                                 NULL,
                                 configDEFAULT_TASK_PRIO,
                                 &h_led_task);
    configASSERT(h_led_task);
}

/***************************************************************************************************
 * STATIC DEFINITIONS
 **************************************************************************************************/

static void service_task(void *arg)
{
    (void)arg;

    // Switch on the red LED
    led_set(LED_RED, true);

    print2uart("Start main loop.\n");
    while (true)
    {
        // Blink the status leds
        led_toggle(LED_RED);
        led_toggle(LED_GREEN);

        // Do service stuff
        vTaskDelay(10);

        // Blink the status leds
        led_toggle(LED_RED);
        led_toggle(LED_GREEN);

        // Delay
        vTaskDelay(SERVICE_TASK_DELAY);
    }
}

static void blink_leds(void)
{
    // Toggle the LEDs
    led_toggle(LED_RED);
    led_toggle(LED_GREEN);
}
