#include "source_machine.h"

/*
 * This interpretation of "super events"
 * deviates from the one actually meant in the lecture.
 * The lecture means something like:
 *
 * switch (mergeOpCodes(inst1, inst2) {
 *     case Inc3A_ClrA:
 *         clrA(&machineState);
 *         break;
 * }
 */

void main_loop(const instruction_t *code, int size, machine_state_t machineState) {
    (void)size;

    int halt_machine = 0;
    instruction_t inst;
    while (!halt_machine) {
        if (code[machineState.ip] == INC3A && code[machineState.ip + 1] == INC3A) {
            if (code[machineState.ip + 2] == INC3A) {
                machineState.accumulator += 9;
                machineState.ip += 3;
            }
            else {
                machineState.accumulator += 6;
                machineState.ip += 2;
            }
        } else {
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
}
