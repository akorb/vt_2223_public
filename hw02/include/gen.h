#ifndef VT2223_GEN_H
#define VT2223_GEN_H

int myrand(int s);

int get_random_opc(const int ps[5]);

void init(instruction_t* buf, int size, const int prob[5], int seed, int* rA, int* rL);

#endif //VT2223_GEN_H
