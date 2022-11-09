#ifndef VT2223_SOURCE_MACHINE_H
#define VT2223_SOURCE_MACHINE_H

#include <stdint.h>

typedef struct {
    uint32_t ip;
    int32_t accumulator;
    int32_t loop_counter;
} machine_state_t;

enum instruction {
    HALT = 0,
    CLRA = 1,
    INC3A = 2,
    DECA = 3,
    SETL = 4,
    BACK7 = 5,
};

static inline void halt(machine_state_t *machineState) {
    machineState->ip++;
}

static inline void clrA(machine_state_t *machineState) {
    machineState->accumulator = 0;
    machineState->ip++;
}

static inline void inc3A(machine_state_t *machineState) {
    machineState->accumulator += 3;
    machineState->ip++;
}

static inline void decA(machine_state_t *machineState) {
    machineState->accumulator--;
    machineState->ip++;
}

static inline void setL(machine_state_t *machineState) {
    machineState->loop_counter = machineState->accumulator;
    machineState->ip++;
}

static inline void back7(machine_state_t *machineState) {
    machineState->loop_counter--;
    if (machineState->loop_counter >= 0) {
        machineState->ip -= 6;
    } else {
        machineState->ip++;
    }
}

typedef uint8_t instruction_t;

#endif //VT2223_SOURCE_MACHINE_H
