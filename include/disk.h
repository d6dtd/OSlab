//
// Created by mt on 11/23/2021.
//

#ifndef C_DISK_H
#define C_DISK_H
#include "common.h"

#define OUTWARD 1
#define INWARD 0

struct track{
    int num;
    struct track* next;
};

int track_count;
int now_num;
bool flag;

struct track* head;
struct track* tail;

void disk_init(int count);
void disk_trunc();
void request(int num);
void exec(struct track* pre);
int FCFS();
int SSTF();
int SCAN();
int CSCAN();

#endif //C_DISK_H
