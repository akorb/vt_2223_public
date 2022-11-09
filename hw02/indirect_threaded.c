#include "source_machine.h"

machine_state_t machineState = {0};

#define DISPATCH()                                      \
        do {                                            \
            instruction_t inst = code[machineState.ip]; \
            goto *dispatch[inst];                       \
        } while (0)


void main_loop(const instruction_t *code, int size) {
    (void)size;

    void *dispatch[] = {&&halt, &&clrA, &&inc3A, &&decA, &&setL, &&back7};

    DISPATCH();

clrA:
    clrA(&machineState);
    DISPATCH();

inc3A:
    inc3A(&machineState);
    DISPATCH();

decA:
    decA(&machineState);
    DISPATCH();

setL:
    setL(&machineState);
    DISPATCH();

back7:
    back7(&machineState);
    DISPATCH();

halt:
    halt(&machineState);
}
