#include "FreeRTOS.h"
#include "task.h"
#include "driverlib.h"
#include "led.h"

void vApplicationSetupTimerInterrupt(void)
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

static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

/* configSUPPORT_STATIC_ALLOCATION is set to 1, so the application must provide an
 implementation of vApplicationGetIdleTaskMemory() to provide the memory that is
 used by the Idle task. */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
    /* If the buffers to be provided to the Idle task are declared inside this
     function then they must be declared static - otherwise they will be allocated on
     the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
     state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
     Note that, as the array is necessarily of type StackType_t,
     configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

static volatile char *fs_task_name; // to avoid optimisations
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    fs_task_name = pcTaskName;
    (void)fs_task_name;
    configASSERT(false);
}
