//
// Created by mt on 11/22/2021.
//
#include "my_memory.h"
#include <stdio.h>
#define WORKER_NUM 8
bool release_best(int index, int size);
int work[WORKER_NUM+1];
int work_size[WORKER_NUM+1] = {0, 130, 60, 100, 200, 140, 60, 50, 60};

void check(){
    printf("��ҵ���������\n");
    for (int i = 0; i <= WORKER_NUM; ++i) {
        if (work[i] != -1){
            printf("��ҵ%d���ڹ�������ַΪ%d���ѷ���%dKB�ռ�\n", i, work[i], work_size[i]);
        }
    }
    printf("\n�����ڴ�����������\n");
    struct free_partition *p = head->next;
    while(p){
        printf("%3d-%3d free\n", p->address, p->address + p->size - 1);
        p = p->next;
    }
    printf("\n");
}

void first(){
    work[1] = allocate_first(work_size[1]);
    check();
    work[2] = allocate_first(work_size[2]);
    check();
    work[3] = allocate_first(work_size[3]);
    check();
    work[2] = release_first(work[2], work_size[2]);
    work[2] = -1;
    check();
    work[4] = allocate_first(work_size[4]);
    check();
    work[3] = release_first(work[3], work_size[3]);
    work[3] = -1;
    check();
    work[1] = release_first(work[1], work_size[1]);
    work[1] = -1;
    check();
    work[5] = allocate_first(work_size[5]);
    check();
    work[6] = allocate_first(work_size[6]);
    check();
    work[7] = allocate_first(work_size[7]);
    check();
    work[8] = allocate_first(work_size[8]);
    check();
//    work[0] = allocate_first(1000);
//    check();
}

void best(){
    work[1] = allocate_best(work_size[1]);
    check();
    work[2] = allocate_best(work_size[2]);
    check();
    work[3] = allocate_best(work_size[3]);
    check();
    work[2] = release_best(work[2], work_size[2]);
    work[2] = -1;
    check();
    work[4] = allocate_best(work_size[4]);
    check();
    work[3] = release_best(work[3], work_size[3]);
    work[3] = -1;
    check();
    work[1] = release_best(work[1], work_size[1]);
    work[1] = -1;
    check();
    work[5] = allocate_best(work_size[5]);
    check();
    work[6] = allocate_best(work_size[6]);
    check();
    work[7] = allocate_best(work_size[7]);
    check();
    work[8] = allocate_best(work_size[8]);
    check();
//    work[0] = allocate_best(1000);
//    check();
}

void init(){
    memory_init();
    for (int i = 0; i <= WORKER_NUM; ++i) {
        work[i] = -1;
    }
}
int main(){
    init();
    // first();
    best();
}