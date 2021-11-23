//
// Created by mt on 11/23/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "disk.h"
#define REQ_COUNT 10

int req[REQ_COUNT];
int count = 100;

//int (*schedule)();

void f(int (*schedule)() ) {
    disk_init(count);

    req[0] = rand() % count + 1;
    request(req[0]);
    printf("����ִ�У�%d\n", req[0]);
    printf("����    ");
    for (int i = 1; i < REQ_COUNT; ++i) {
        req[i] = (rand() % count + 1);
        request(req[i]);
        printf("%d ", req[i]);
    }
    printf("\n");

    int pre_now = FCFS();
    int res = 0;
    printf("��ͷ�ƶ�˳��(%d) ", pre_now);
    for (int i = 1; i < REQ_COUNT; ++i) {
        int now = schedule();
        printf("%d ", now);
        res += ABS(now - pre_now);
        pre_now = now;
    }
    printf("\nƽ���ƶ��ŵ���%0.2f\n\n", (float )res / REQ_COUNT);
    disk_trunc();
}

int main() {
    printf("�����ȷ����㷨��\n");
    f(FCFS);
    printf("���Ѱ��ʱ�������㷨��\n");
    f(SSTF);
    printf("ɨ���㷨��\n");
    f(SCAN);
    printf("ѭ��ɨ���㷨��\n");
    f(CSCAN);
}