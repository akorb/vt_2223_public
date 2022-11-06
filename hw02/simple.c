#include <stdio.h>
#include <stdlib.h>
#include "source_machine.h"

machine_state_t machineState = { 0 };
static int halt_machine = 0;

void halt(void) {
    halt_machine = 1;
    machineState.ip++;
}

void clrA(void) {
    machineState.accumulator = 0;
    machineState.ip++;
}

void inc3A(void) {
    machineState.accumulator += 3;
    machineState.ip++;
}

void decA(void) {
    machineState.accumulator--;
    machineState.ip++;
}

void setL(void) {
    machineState.loop_counter = machineState.accumulator;
    machineState.ip++;
}

void back7(void) {
    machineState.loop_counter--;
    if (machineState.loop_counter > 0) {
        machineState.ip -= 6;
    } else {
        machineState.ip++;
    }
}

void main_loop(const instruction_t *code, int size) {
    (void)size;

    instruction_t inst;
    while (!halt_machine) {
        inst = code[machineState.ip];
        switch (inst) {
            case HALT:
                halt();
                break;
            case CLRA:
                clrA();
                break;
            case INC3A:
                inc3A();
                break;
            case DECA:
                decA();
                break;
            case SETL:
                setL();
                break;
            case BACK7:
                back7();
                break;
            default:
                puts("Should not happen!");
                exit(1);
        }
    }
}
