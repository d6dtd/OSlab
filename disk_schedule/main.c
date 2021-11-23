//
// Created by mt on 11/23/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#define REQ_COUNT 10

int req[REQ_COUNT];
int count = 100;
int seed = 0;
//int (*schedule)();

void f(int (*schedule)()) {
    disk_init(count);
	srand(seed);
    req[0] = rand() % count + 1;
    request(req[0]);
    printf("正在运行：%d\n", req[0]);
    printf("请求：   ");
    for (int i = 1; i < REQ_COUNT; ++i) {
        req[i] = (rand() % count + 1);
        request(req[i]);
        printf("%d ", req[i]);
    }
    printf("\n");

    int pre_now = FCFS();
    int res = 0;
    printf("执行顺序：(%d) ", pre_now);
    for (int i = 1; i < REQ_COUNT; ++i) {
        int now = schedule();
        printf("%d ", now);
        res += ABS(now - pre_now);
        pre_now = now;
    }
    printf("\n平均移动磁道数%0.2f\n\n", (float )res / REQ_COUNT);
    disk_trunc();
}

int main(int argc, char* argv[]) {
	if(argc == 2){
		seed = argv[1][0]-'0';
	}
    printf("先来先服务算法\n");
    f(FCFS);
    printf("最短寻道时间优先算法\n");
    f(SSTF);
    printf("扫描算法\n");
    f(SCAN);
    printf("循环扫描算法\n");
    f(CSCAN);
}
