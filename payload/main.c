/**
 *  main.c
 */

#include <stdio.h>
#include <stdbool.h>

// #include "FreeRTOS.h"
// #include "task.h"
#include "driverlib.h"
#include "dbg_print.h"
#include "led.h"

// #include "portmacro.h"

// Timer counter
uint32_t g_count;

// LED task definitions
#define LED_TASK_STACK_SZ (configMINIMAL_STACK_SIZE + 20)
// static StackType_t led_task_stack[LED_TASK_STACK_SZ];
// static StaticTask_t led_task_buf;
// static TaskHandle_t h_led_task = NULL;

// Static declarations
static void set_all_gpio_out_off(void);
// static void init_led_task(void);
static void init_timer_ms(void);
static void led_task(void *arg);
static void delay_ms(int msecs);

int main(void)
{
    // Default all outputs off
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
    led_init_gpos();

    // Init the led task
    // init_led_task();

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PMM_unlockLPM5();

    // vTaskStartScheduler();

    // Enable global interrupt
    __enable_interrupt();
    init_timer_ms();
    led_task(NULL);

    while (1)
    {
    }
}

// static void init_led_task(void)
// {
//     // create task attributes
//     BaseType_t res = xTaskCreate(led_task,
//                                  "led_task",
//                                  LED_TASK_STACK_SZ,
//                                  NULL,
//                                  configDEFAULT_TASK_PRIO,
//                                  &h_led_task);
//     configASSERT(h_led_task);
// }

static void led_task(void *arg)
{
    (void)arg;

    // Switch on the red LED
    // print2uart("Switch on red LED.\n");
    led_set(LED_RED, true);

    // print2uart("Start main loop.\n");
    while (true)
    {
        // print2uart("In the loop.\n");

        // Toggle the LEDs
        led_toggle(LED_RED);
        led_toggle(LED_GREEN);

        // Delay
        delay_ms(1000);
    }
}

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

void toggle_both_leds(void)
{
    // Toggle the LEDs
    led_toggle(LED_RED);
    led_toggle(LED_GREEN);
}

static void init_timer_ms(void)
{
    // configure FreeRTOS tick at 1ms

    Timer_A_stop(TA0_BASE);
    Timer_A_clear(TA0_BASE);

    Timer_A_initUpModeParam param =
        {
            .clockSource = TIMER_A_CLOCKSOURCE_SMCLK,
            .clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_64,
            .timerPeriod = 250,
            .timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE,
            .captureCompareInterruptEnable_CCR0_CCIE = TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE,
            .timerClear = TIMER_A_DO_CLEAR,
            .startTimer = false};

    Timer_A_initUpMode(TA0_BASE, &param);
    Timer_A_clearTimerInterrupt(TA0_BASE);
    Timer_A_startCounter(TA0_BASE, TIMER_A_UP_MODE);
}

// Timer A0 interrupt
/*
 * Tick ISR for preemptive scheduler.  We can use a naked attribute as
 * the context is saved at the start of vPortYieldFromTick().  The tick
 * count is incremented after the context is saved.
 */
__attribute__((interrupt(TIMER0_A0_VECTOR))) void timer_ms_isr(void);
__attribute__((interrupt(TIMER0_A0_VECTOR))) void timer_ms_isr(void)
{
    // Timer interrupt is triggered
    g_count++; // Increment Over-Flow Counter
}

static void delay_ms(int msecs)
{
    // Reset Over-Flow counter
    g_count = 0;
    // Start Timer, Compare value for Up Mode to get 1ms delay per loop
    // Total count = TACCR0 + 1. Hence we need to subtract 1.
    Timer_A_setCompareValue(TA0_BASE, TA0CCR0, msecs - 1);

    while (g_count <= msecs)
        ;
}
/*-----------------------------------------------------------*/
