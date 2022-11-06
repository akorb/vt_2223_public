#include <stdio.h>
#include "source_machine.h"

void printMachineState(machine_state_t machineState) {
    printf("Final state:\n"
           " ip: %u\n"
           "  A: %i\n"
           "  L: %i\n", machineState.ip, machineState.accumulator, machineState.loop_counter);
}