// If this header file isn't included already, then we must include it
#ifndef THERMO_HEADERS_THERMOTASKS_H_
#define THERMO_HEADERS_THERMOTASKS_H_

// Typedef which defines the structure of our tasks
typedef struct task {
    // Holds the task state
    unsigned char state;

    // Holds the task period, represented in µs
    unsigned int period;

    // Holds the task's elapsed time, also in µs
    unsigned int elapsed_time;

    // Holds a pointer to its tick function
    unsigned char (*tick)(unsigned char);

    // Holds a pointer to its display function
    void (*display)();
} task;

#endif /* THERMO_HEADERS_THERMOTASKS_H_ */
