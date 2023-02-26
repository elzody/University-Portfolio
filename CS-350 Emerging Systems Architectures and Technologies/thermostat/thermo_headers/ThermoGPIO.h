/* If we haven't already included
 * this file, we include it
 */
#ifndef THERMOGPIO_H_
#define THERMOGPIO_H_

/* Include some of our custom
 * thermostat header files
 */
#include "ThermoTasks.h"
#include "ThermoMath.h"

// Include board drivers and driver configs
#include <ti/drivers/GPIO.h>
#include "ti_drivers_config.h"

/* This state machine captures
 * button presses every 200ms
 * and also controls when the
 * heat should be turned on/off
 */
unsigned char Btn_Tick(unsigned char state) {
    // state 0 = init
    // state 1 = heat on
    // state 2 = heat off

    /* If button 0 on the microcontroller is
     * pressed, we decrement the heat set point.
     *
     * If button 1 is pressed, increment the
     * heat set point.
     */
    if (GPIO_read(CONFIG_GPIO_BUTTON_0)) {
        set_point -= 1;
    } else if (GPIO_read(CONFIG_GPIO_BUTTON_1)) {
        set_point += 1;
    }

    /* Begin our switch statement to
     * capture our state transitions
     */
    switch (state) {

    // Case initial state
    case 0:
        // Move to state 1
        state = 1;
        break;

    // Case heat currently on
    case 1:
        /* If the current temperature
         * captured by the temp sensor is
         * less than the current heat set point,
         * transition to state 2 which turns off
         * the heat
         */
        if (temperature < set_point) {
            state = 2;
        }

        break;

    // Case heat currently off
    case 2:
        /* If the temperature as captured
         * by the temp sensor is greater than
         * the current heat set point value,
         * then we transition to state 1
         * which turns on the heat
         */
        if (temperature > set_point) {
            state = 1;
        }

        break;

    /* In the unlikely event that
     * no proper state is the current state,
     * just reset to the initial state and
     * start over
     */
    default:
        state = 0;

    }

    /* Begin our switch statement
     * for our state actions
     */
    switch (state) {

    // Case initial state
    case 0:
        // We do nothing in the initial state
        break;

    // Case heat currently on
    case 1:
        /* When the heat is on, turn on our
         * red LED and set the heat variable to 1
         */
        GPIO_write(CONFIG_GPIO_LED_0, 1);
        heat = 1;

        break;

    // Case heat currently off
    case 2:
        /* When the heat is off, turn off our
         * red LED and set the heat variable to 0
         */
        GPIO_write(CONFIG_GPIO_LED_0, 0);
        heat = 0;

        break;

    /* In the unlikely event that we are
     * in an undefined state, transition back
     * to the inital state and start over
     */
    default:
        state = 0;

    }

    // Return the current state
    return state;
}

// GPIO initialization function
task init_GPIO() {
    // Calling GPIO_init() is mandatory!!
    GPIO_init();

    // Set our config for our red LED and button 0
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(CONFIG_GPIO_BUTTON_0, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);

    // If there's more than one button, set its config as button 1
    if (CONFIG_GPIO_BUTTON_0 != CONFIG_GPIO_BUTTON_1) {
        GPIO_setConfig(CONFIG_GPIO_BUTTON_1, GPIO_CFG_IN_PU | GPIO_CFG_IN_INT_FALLING);
    }

    // Create a task to hold our state machine
    task GPIO_Btn;

    // Set its initial state to 0 (the actual initial state)
    GPIO_Btn.state = 0;

    /* Set its period to 200ms
     * (the period is actually
     * represented in terms of
     * microseconds so we use our
     * handy custom header file to
     * convert between the two
     */
    GPIO_Btn.period = convert_ms_us(200);

    // Set its initial elapsed time to its period
    GPIO_Btn.elapsed_time = GPIO_Btn.period;

    // Set its tick function to our state machine
    GPIO_Btn.tick = &Btn_Tick;

    // It doesn't have a display function
    GPIO_Btn.display = NULL;

    // Return the task struct for the GPIO state machine
    return GPIO_Btn;
}

#endif /* THERMOGPIO_H_ */
