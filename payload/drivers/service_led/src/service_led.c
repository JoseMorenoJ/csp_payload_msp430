/*
 * led.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Pepe
 */
#include <assert.h>

#include "service_led.h"
#include "driverlib.h"

/** @brief Return the Port and Pin HW values for the selected user LED */
static void get_port_pin(uint8_t *const port, uint16_t *const pin, const led_select_t select);

void led_init(void)
{
    // Set P1.0 to output direction
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);

    // Set P1.1 to output direction
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN1);
}

void led_set(const led_select_t select, const bool state)
{
    uint8_t port = 0;
    uint16_t pin = 0;
    get_port_pin(&port, &pin, select);

    if (state)
    {
        GPIO_setOutputHighOnPin(port, pin);
    }
    else
    {
        GPIO_setOutputLowOnPin(port, pin);
    }
}

void led_toggle(const led_select_t select)
{
    uint8_t port = 0;
    uint16_t pin = 0;
    get_port_pin(&port, &pin, select);

    GPIO_toggleOutputOnPin(port, pin);
}

static void get_port_pin(uint8_t *const port, uint16_t *const pin, const led_select_t select)
{
    if (LED_GREEN == select)
    {
        *port = GPIO_PORT_P1;
        *pin = GPIO_PIN1;
    }
    else if (LED_RED == select)
    {
        *port = GPIO_PORT_P1;
        *pin = GPIO_PIN0;
    }
    else
    {
        assert(false);
    }
}
