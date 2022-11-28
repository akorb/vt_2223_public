#include "source_machine.h"

void main_loop(const instruction_t *code, int size, machine_state_t machineState) {
    (void)size;

    int halt_machine = 0;
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
        }
    }
}
