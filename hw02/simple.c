#include <stdio.h>
#include <stdlib.h>
#include "source_machine.h"
#include "gen.h"

static machine_state_t machineState = { 0 };
static int halt_machine = 0;

void halt() {
    halt_machine = 1;
    machineState.ip++;
}

void clrA() {
    machineState.accumulator = 0;
    machineState.ip++;
}

void inc3A() {
    machineState.accumulator += 3;
    machineState.ip++;
}

void decA() {
    machineState.accumulator--;
    machineState.ip++;
}

void setL() {
    machineState.loop_counter = machineState.accumulator;
    machineState.ip++;
}

void back7() {
    machineState.loop_counter--;
    if (machineState.loop_counter >= 0) {
        machineState.ip -= 7;
    } else {
        machineState.ip++;
    }
}

int main_loop(const char* code) {
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

int main() {
    int prob[] = {0, 1, 0, 0, 0};
    int32_t zero = 0;
    char code[10000];
    init(code, 10000, prob, 1, &zero, &zero);

    main_loop(code);

    printf("Final state:\n"
           "ip: %u\n"
           "A: %i\n"
           "L: %i\n", machineState.ip, machineState.accumulator, machineState.loop_counter);
    return 0;
}
