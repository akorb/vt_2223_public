#include <stdio.h>
#include <stdlib.h>
#include "source_machine.h"

static int halt_machine = 0;

void main_loop(const instruction_t *code, int size, machine_state_t machineState) {
    (void)size;

    instruction_t inst;
    while (!halt_machine) {
        inst = code[machineState.ip];
        switch (inst) {
            case HALT:
                halt(&machineState);
                halt_machine = 1;
                break;
            case CLRA:
                clrA(&machineState);
                break;
            case INC3A:
                inc3A(&machineState);
                break;
            case DECA:
                decA(&machineState);
                break;
            case SETL:
                setL(&machineState);
                break;
            case BACK7:
                back7(&machineState);
                break;
            default:
                puts("Should not happen!");
                exit(1);
        }
    }
}
