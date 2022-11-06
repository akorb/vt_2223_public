#ifndef VT2223_GEN_H
#define VT2223_GEN_H

int myrand(int s);

int get_random_opc(int ps[5]);

void init(char* buf, int size, int prob[5], int seed, int* rA, int* rL);

#endif //VT2223_GEN_H
