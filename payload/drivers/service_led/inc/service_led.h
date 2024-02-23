#ifndef LED_H
#define LED_H
/**
 *
 * @file service_led.h
 * @brief Drivers to control the two status led in the MSP430FR5994 board
 *
 */
#include <stdbool.h>

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
/** @brief Enumerator with the valid values for the user LEDs */
typedef enum
{
    LED_GREEN,
    LED_RED
} led_select_t;

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

/**
 * @brief Initialize the gpo for the user LEDs
 */
void led_init(void);

/**
 * @brief Set the selected user led in a certain state
 * @param [in] select LED to be set
 * @param [in] state new state for the LED
 */
void led_set(const led_select_t select, const bool state);

/**
 * @brief Toogle the state of the selected user LED
 * @param [in] select LED to be toggled
 */
void led_toggle(const led_select_t select);

#endif /* LED_H */
