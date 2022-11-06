#include <stdio.h>
#include "source_machine.h"
#include "gen.h"

extern machine_state_t machineState;
extern void main_loop(const instruction_t *code, int size);

void printMachineState(void) {
    printf("Final state:\n"
           " ip: %u\n"
           "  A: %i\n"
           "  L: %i\n", machineState.ip, machineState.accumulator, machineState.loop_counter);
}

int main(void) {
    int prob[] = {0, 1, 0, 0, 0};
    int32_t zero = 0;
    instruction_t code[10000];
    init(code, 10000, prob, 1, &machineState.accumulator, &machineState.loop_counter);

    main_loop(code, 10000);

    printMachineState();
    return 0;
}
