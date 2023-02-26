// If this header file isn't included already, then we have to include it
#ifndef THERMO_HEADERS_THERMOTIMER_H_
#define THERMO_HEADERS_THERMOTIMER_H_

// Include the driver header file for the hardware timer
#include <ti/drivers/Timer.h>

// Include the driver configs
#include "ti_drivers_config.h"

// Holds the timer flag which will be toggled when the timer ends
volatile unsigned char TimerFlag = 0;

// Holds the parameters for our timer
Timer_Params timer_params;

// Holds the handle we use to reference the timer
Timer_Handle thermo_timer;

// The callback function which will be executed upon timer execution
void thermoTimerCallback(Timer_Handle handle, int_fast16_t status) {
    // We toggle the timer flag here which is used in our main thread
    TimerFlag = 1;
}

// Initialization function for the hardware timer
void init_Timer(uint32_t period, Timer_PeriodUnits periodUnits, Timer_Mode timerMode) {
    // We have to call Timer_init() in order to use the driver methods
    Timer_init();

    // Initialize the timer parameters with default values
    Timer_Params_init(&timer_params);

    // Set the timer period using the period provided as a function parameter
    timer_params.period = period;

    // Set the timer period units to the units provided as a function parameter
    timer_params.periodUnits = periodUnits;

    // Set the timer mode as provided by the function parameters
    timer_params.timerMode = timerMode;

    // Set the timer callback function to the one defined above
    timer_params.timerCallback = thermoTimerCallback;

    // Open the timer into our timer handle
    thermo_timer = Timer_open(CONFIG_TIMER_0, &timer_params);

    // Start the timer!
    Timer_start(thermo_timer);
}

#endif /* THERMO_HEADERS_THERMOTIMER_H_ */
