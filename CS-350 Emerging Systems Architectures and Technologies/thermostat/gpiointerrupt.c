/* Standard header includes */
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

/* Holds the temperature value from
 * the temp sensor on the board.
 */
volatile int temperature = 0;

/* Point at which the heat turns on/off.
 * Represented in degrees Celsius, and
 * can be increased/decreased via the
 * buttons on the microcontroller.
 */
volatile int set_point = 0;

/* An int value indicating the
 * current status of the heat.
 */
volatile int heat = 1;

/* The time, in seconds, the board
 * has been on for. Incremented every
 * 10 ticks, as 10 ticks represent 1s.
 */
int seconds = 0;

/* Thermostat custom header file includes.
 * These are included after the global
 * variables above because they reference them.
 */
#include "thermo_headers/ThermoTasks.h"
#include "thermo_headers/ThermoGPIO.h"
#include "thermo_headers/ThermoUART2.h"
#include "thermo_headers/ThermoTimer.h"
#include "thermo_headers/ThermoMath.h"
#include "thermo_headers/ThermoI2C.h"

// Array to hold our tasks
task tasks[3];

// Global to hold timer period (1000000µs or 1000ms or 1s)
unsigned int timer_period = 100000;

// Our primary tick function which implements the task scheduler
void Tick() {

    // Variable to hold index for the for loop
    int i;

    /* Loop through the tasks in the task array, and execute them
     * when necessary
     */
    for (i = 0; i < sizeof(tasks) / sizeof(tasks[0]); i++) {

        /* If the current task's elapsed time meets its period,
         * then we should execute the task's tick function.
         */
        if (tasks[i].elapsed_time >= tasks[i].period) {

            // If the task has a tick function, execute it.
            if (tasks[i].tick != NULL) {

                /* Set the task's state to the state
                 * returned from executing its tick
                 * function
                 */
                tasks[i].state = tasks[i].tick(tasks[i].state);
            }

            // If the task has a display function, execute it.
            if (tasks[i].display != NULL) {
                tasks[i].display();
            }

            /* Finally, reset the elapsed time of the task
             * so that it will be executed again at its
             * specified period/interval
             */
            tasks[i].elapsed_time = 0;
        }

        /* If the task is not ready to be executed,
         * i.e. its elapsed time has not met its
         * period, then we increment its elapsed
         * time by the timer period.
         */
        tasks[i].elapsed_time += timer_period;
    }
}

// Main program execution thread
void *mainThread(void *arg0)
{
    /* Initialize the UART2 driver
     * and store its resulting task
     *
     * params: (int) baud rate, (int) read mode, (int) write mode
     */
    task uart2_task = init_UART2(115200, UART2_Mode_BLOCKING, UART2_Mode_BLOCKING);

    /* Initialize the GPIO driver
     * and store its resulting task
     */
    task btn_task = init_GPIO();

    /* Initialize the I2C driver to
     * communicate with the temp sensor
     * and store its resulting task
     *
     * params: (int) I2C bit rate
     */
    task tmp_task = init_I2C(I2C_400kHz);

    /* Assign each of the tasks to an
     * element in the tasks array
     */
    tasks[0] = btn_task;
    tasks[1] = tmp_task;
    tasks[2] = uart2_task;

    /* Initialize the hardware timer
     *
     * params:(uint) timer period, (int) timer period units, (int) timer callback mode
     */
    init_Timer(timer_period, Timer_PERIOD_US, Timer_CONTINUOUS_CALLBACK);

    // Begin an infinite loop
    while (1) {
        /* The timer flag below will be
         * set to 1 when the timer ends;
         * until then, we simply do nothing
         */
        TimerFlag = 0;
        while (!TimerFlag) {};

        // Execute our primary tick function
        Tick();
    }
}
