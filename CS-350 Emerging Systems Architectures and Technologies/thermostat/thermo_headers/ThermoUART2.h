// If this header file isn't included already, we must include it
#ifndef THERMOUART2_H_
#define THERMOUART2_H_

// Include standard input/output header file
#include <stdio.h>

// Include the driver header file for UART2
#include <ti/drivers/UART2.h>

// Include some of our custom thermostat header files
#include "ThermoTasks.h"
#include "ThermoMath.h"

// Include the driver configs
#include "ti_drivers_config.h"

// Holds our UART2 parameters
UART2_Params uart2_params;

// Holds the handle we use to hold our reference to our open UART2 driver
UART2_Handle thermo_uart2;

// Bytes we have read
size_t bytesRead;

// Bytes we have written
size_t bytesWritten;

// Status of the UART2 read/write operation
int32_t status;

// Function to display the ambient temperature, heat set point, heat on/off value, and seconds since board reset
void uart2_display() {
    // Because this function is executed every second, we can increment seconds here
    seconds += 1;

    // Holds the string which formats our data
    char data_string[] = "<%02d,%02d,%d,%04d>\n\r";
    // Our output buffer the size of the data string
    char output[sizeof(data_string)];

    // Stores the formatted string in our output buffer
    snprintf(output, sizeof(output), data_string, temperature, set_point, heat, seconds);

    // Writes the data to UART2
    status = UART2_write(thermo_uart2, &output, sizeof(output), &bytesWritten);
}

// Initialization function for UARt2
task init_UART2(uint32_t baudRate, UART2_Mode readMode, UART2_Mode writeMode) {
    // Initialize our UART2 parameters with default values
    UART2_Params_init(&uart2_params);

    // Set our baud rate to the one provided to the function
    uart2_params.baudRate = baudRate;

    // Set the read mode to the read mode provided to the function
    uart2_params.readMode = readMode;

    // Set the write mode to the one provided by the function
    uart2_params.writeMode = writeMode;

    // Open the UART2 driver into our handle as defined above
    thermo_uart2 = UART2_open(CONFIG_UART2_0, &uart2_params);

    // Create a task for our UART2 display function
    task UART2_Display;

    // It's not a state machine, it doesn't matter what we put here
    UART2_Display.state = 0;

    // It will be executed every 1s (or 1000ms or 100000µs)
    UART2_Display.period = convert_ms_us(1000);

    // Set the elapsed time of the task to its period initially
    UART2_Display.elapsed_time = UART2_Display.period;

    // It doesn't actually have a tick function
    UART2_Display.tick = NULL;

    // However, it has a display function! Point to it!
    UART2_Display.display = &uart2_display;

    // Return the UART2 task structure
    return UART2_Display;
}

// Function which writes a given formatted string to the UART2 output
void uart2_write(char formatted_string[]) {
    // Output buffer the size of the provided string
    char output[sizeof(formatted_string)];

    // Formats the string and stores it into the buffer
    snprintf(output, sizeof(output), formatted_string);

    // Write the data to UART2
    status = UART2_write(thermo_uart2, &output, sizeof(output), &bytesWritten);
}

#endif /* THERMOUART2_H_ */
