// If this header file is not included already, include it
#ifndef THERMO_HEADERS_THERMOI2C_H_
#define THERMO_HEADERS_THERMOI2C_H_

// Include our I2C driver header file
#include <ti/drivers/I2C.h>

// Include our custom header files
#include "ThermoTasks.h"
#include "ThermoUART2.h"
#include "ThermoMath.h"

/* This code seems sketchy to me, but it was provided
 * by the university.
 *
 * It basically stores possible locations where the
 * temp sensor might be, and further on in the code we
 * explore these locations to find it.
 */
static const struct Sensor {
    uint8_t address;
    uint8_t result_reg;
    char *id;
} sensors[3] = {
    { 0x48, 0x0000, "11X" },
    { 0x49, 0x0000, "116" },
    { 0x41, 0x0001, "006" }
};

// Our I2C parameters variable
I2C_Params I2C_params;

// Our handle which we use to reference the I2C driver
I2C_Handle thermo_I2C;

/* This is the write buffer, where we store
 * information to be written to a peripheral
 * via the I2C driver
 * (the temp sensor)
 */
uint8_t txBuffer[1];

/* This is the read buffer, which stores the
 * data we read from the peripheral via the
 * I2C driver
 * (the temp sensor)
 */
uint8_t rxBuffer[2];

// This holds transactions we use to communicate via the I2C driver
I2C_Transaction I2C_transaction;

// This function reads the current temperature from the sensor
void tmp_read() {
    // Set the number of bytes to be read from the sensor
    I2C_transaction.readCount = 2;

    // If the transfer is successful, we can continue
    if (I2C_transfer(thermo_I2C, &I2C_transaction)) {
        /* Do weird bitwise operations with the bytes we read
         * and then multiply the result by an unknown constant
         */
        temperature = (rxBuffer[0] << 8) | (rxBuffer[1]);
        temperature *= 0.0078125;

        // More weird bitewise operations???
        if (rxBuffer[0] & 0x80) {
            temperature |= 0xF000;
        }
    } else {
        /* If the transfer is unsuccessful, set temperature
         * to NULL and write an error via UART2.
         */
        temperature = NULL;
        uart2_write("ERROR: Could not read temperature from sensor!\n");

        // Then loop so we don't continue executing any more code
        while (1) {};
    }
}

// Our state machine tick function for the temperature sensor
unsigned char TMP_Tick(unsigned char state) {
    // state 0 = init
    // state 1 = reading temperature

    // Begin the switch statement for our state transitions
    switch (state) {

    // Case initial state
    case 0:
        // Transition to state 1
        state = 1;
        break;

    // Case state 1
    case 1:
        /* We constantly remain in
         * state 1 because we are always
         * reading the temperature. No need
         * to transition to another state here
         */
        break;

    /* In the unlikely event we are in an
     * undefined state, transition to the
     * initial state and start over
     */
    default:
        state = 0;

    }

    // Begin the switch statement for our state actions
    switch (state) {

    // Case initial state
    case 0:
        // The initial state has no actions
        break;

    // Case state 1
    case 1:
        // Read the temperature
        tmp_read();
        break;

    // If we find ourselves in an undefined state, revert to initial state
    default:
        state = 0;

    }

    // Finally, return the current state
    return state;
}

// Initialization function for the I2C driver
task init_I2C(I2C_BitRate bitRate) {
    // Calling I2C_init() is required to perform further actions
    I2C_init();

    // Initialize our I2C parameters
    I2C_Params_init(&I2C_params);

    // Set the bit rate to the bit rate passed into the init function
    I2C_params.bitRate = bitRate;

    // Open the driver into our thermo_I2C handle
    thermo_I2C = I2C_open(CONFIG_I2C_0, &I2C_params);

    // If the handle is NULL, we have a problem
    if (thermo_I2C == NULL) {
        // Display an error via UART2
        uart2_write("ERROR: I2C failed to initialize!\n");

        // Loop endlessly to prevent further code execution
        while (1) {};
    }

    // Tell the transaction where our write buffer is
    I2C_transaction.writeBuf = txBuffer;

    // Tell it how many bytes we will write
    I2C_transaction.writeCount = 1;

    // Tell it also where our read buffer is
    I2C_transaction.readBuf = rxBuffer;

    // Finally, tell it how many bytes to read
    I2C_transaction.readCount = 0;

    // Bool to determine if we've found the location of the sensor
    bool found = false;

    // Store our index for our for loop
    char i;

    // Loop through the sensor location struct to find the sensor
    for (i = 0; i < 3; ++i) {
        I2C_transaction.slaveAddress = sensors[i].address;
        txBuffer[0] = sensors[i].result_reg;

        if (I2C_transfer(thermo_I2C, &I2C_transaction)) {
            found = true;
            break;
        }
    }

    // If it wasn't found in the end, we have a big problem
    if (!found) {
        // Display an error via UART2
        uart2_write("ERROR: Failed to find a temperature sensor!\n");

        // Loop endlessly to prevent further code execution
        while (1) {};
    }

    // Set the transaction write count to 0 bytes
    I2C_transaction.writeCount = 0;

    // Create a task for our temp sensor state machine
    task TMP_Sensor;

    // Set its initial state to 0
    TMP_Sensor.state = 0;

    // Set the period for the task to every 500ms
    // It's represented in µs so convert it using our
    // handy custom thermostat math header file
    TMP_Sensor.period = convert_ms_us(500);

    // Set its elapsed time to its period
    TMP_Sensor.elapsed_time = TMP_Sensor.period;

    // Set its tick function to our temp state machine
    TMP_Sensor.tick = &TMP_Tick;

    // It doesn't have a display function
    TMP_Sensor.display = NULL;

    // Return the temp sensor task
    return TMP_Sensor;
}

#endif /* THERMO_HEADERS_THERMOI2C_H_ */
