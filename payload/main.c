/**
 *
 * @file    main.c
 * @brief   Entry point for the CSP payload based on a MSP430FR5994
 *
 */

#include <msp430.h>

#include "driverlib.h"
#include "service_led.h"
#include "dbg_print.h"
#include "service_task.h"
#include "FreeRTOS.h"
#include "task.h"

/***************************************************************************************************
 * EXTERNAL VARIABLES
 **************************************************************************************************/

/***************************************************************************************************
 * PRIVATE MACROS AND DEFINES
 **************************************************************************************************/

/***************************************************************************************************
 * PRIVATE TYPE DEFINITIONS
 **************************************************************************************************/

/***************************************************************************************************
 * STATIC VARIABLES
 **************************************************************************************************/

/***************************************************************************************************
 * STATIC DECLARATIONS
 **************************************************************************************************/
// Static declarations
static void set_all_gpio_out_off(void);

/***************************************************************************************************
 * PUBLIC DEFINITIONS
 **************************************************************************************************/
int main(void)
{
    // deinit GPIO
    set_all_gpio_out_off();

    // disable watch dog timer
    WDT_A_hold(WDT_A_BASE);

    // Set clock to 16MHz
    FRAMCtl_A_configureWaitStateControl(FRAMCTL_A_ACCESS_TIME_CYCLES_1);
    CS_setDCOFreq(CS_DCORSEL_1, CS_DCOFSEL_4);
    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);

    // Initialize debug uart
    dbg_print_uart_init();

    // Initialize user led driver
    led_init();

    // Init the led task
    init_service_task();

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();

    // Start FreeRTOS scheduler
    vTaskStartScheduler();

    // Enable global interrupt
    __enable_interrupt();

    while (1)
    {
    }
}

/***************************************************************************************************
 * STATIC DEFINITIONS
 **************************************************************************************************/
static void set_all_gpio_out_off(void)
{
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN_ALL16);
    GPIO_setAsOutputPin(GPIO_PORT_PJ, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN_ALL16);
    GPIO_setOutputLowOnPin(GPIO_PORT_PJ, GPIO_PIN_ALL16);
}
