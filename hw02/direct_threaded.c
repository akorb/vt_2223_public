#include "source_machine.h"

#define DISPATCH()                                  \
        do {                                        \
            goto *predecoded_code[machineState.ip]; \
        } while (0)

void main_loop(const instruction_t *code, int size, machine_state_t machineState) {
    void *dispatch[] = {&&halt, &&clrA, &&inc3A, &&decA, &&setL, &&back7};

    void *predecoded_code[size];
    for (int i = 0; i < size; i++) {
        predecoded_code[i] = dispatch[code[i]];
    }

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
