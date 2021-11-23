//
// Created by mt on 11/22/2021.
//

#ifndef C_MY_MEMORY_H
#define C_MY_MEMORY_H
#include "common.h"

#define MEMORY_SIZE 640

struct free_partition{
    int address;
    int size;
    struct free_partition* next;
};
struct free_partition* head;

void memory_init();
int allocate_first(int size);
bool release_first(int index, int size);
int allocate_best(int size);
bool release_best(int index, int size);
#endif //C_MY_MEMORY_H
