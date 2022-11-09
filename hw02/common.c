#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

/**
 * argv[1-5]: probabilities
 * argv[6]:   seed
 * argv[7]:   code size
 */
int main(int argc, const char* argv[]) {
    if (argc != 8) {
        printf("Expected args: 7, given args: %i\n", argc - 1);
        return EXIT_FAILURE;
    }

    int prob[] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])};
    int seed = atoi(argv[6]);
    int codeSize = atoi(argv[7]);
    instruction_t code[codeSize];
    init(code, codeSize, prob, seed, &machineState.accumulator, &machineState.loop_counter);

    clock_t begin = clock();
    main_loop(code, codeSize);
    clock_t end = clock();

#ifdef NDEBUG
    // Print taken time
    double msecs = (double)(end - begin) / (CLOCKS_PER_SEC / 1000);
    printf("%lf\n", msecs);
#else
    (void)begin;
    (void)end;
    printMachineState();
#endif

    return EXIT_SUCCESS;
}
