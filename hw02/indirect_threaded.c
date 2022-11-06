#include "source_machine.h"
#include "gen.h"

static machine_state_t machineState = {0};

#define DISPATCH(INC) if (INC == 1) { machineState.ip++; } inst = code[machineState.ip]; goto *dispatch[inst];


void main_loop(const instruction_t *code) {
    void *dispatch[] = {&&halt, &&clrA, &&inc3A, &&decA, &&setL, &&back7};
    instruction_t inst;

    DISPATCH(0);

halt:
    machineState.ip++;
    goto exit;

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
        machineState.ip -= 7;
    } else {
        machineState.ip++;
    }
    DISPATCH(0);

exit:
    printMachineState(machineState);
}

int main(void) {
    int prob[] = {0, 1, 0, 0, 0};
    int32_t zero = 0;
    instruction_t code[10000];
    init(code, 10000, prob, 1, &zero, &zero);

    main_loop(code);

    return 0;
}
