#ifndef VT2223_SOURCE_MACHINE_H
#define VT2223_SOURCE_MACHINE_H

#include <stdint.h>

typedef struct {
    uint32_t ip;
    int32_t accumulator;
    int32_t loop_counter;
} machine_state_t;

void printMachineState(machine_state_t machineState);

enum instruction {
    HALT = 0,
    CLRA = 1,
    INC3A = 2,
    DECA = 3,
    SETL = 4,
    BACK7 = 5,
};

typedef uint8_t instruction_t;

#endif //VT2223_SOURCE_MACHINE_H
