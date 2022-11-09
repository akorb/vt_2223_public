#include "source_machine.h"

machine_state_t machineState = {0};

#define DISPATCH(INC)                               \
        do {                                        \
            if (INC == 1) {                         \
                machineState.ip++;                  \
            }                                       \
            inst = code[machineState.ip];           \
            goto *dispatch[inst];                   \
        } while (0)


void main_loop(const instruction_t *code, int size) {
    (void)size;

    void *dispatch[] = {&&halt, &&clrA, &&inc3A, &&decA, &&setL, &&back7};

    instruction_t inst;
    DISPATCH(0);

clrA:
    machineState.accumulator = 0;
    DISPATCH(1);

inc3A:
    machineState.accumulator += 3;
    DISPATCH(1);

decA:
    machineState.accumulator--;
    DISPATCH(1);

setL:
    machineState.loop_counter = machineState.accumulator;
    DISPATCH(1);

back7:
    machineState.loop_counter--;
    if (machineState.loop_counter >= 0) {
        machineState.ip -= 6;
    } else {
        machineState.ip++;
    }
    DISPATCH(0);

halt:
    machineState.ip++;
}
