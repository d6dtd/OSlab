//
// Created by mt on 11/23/2021.
//
#include "disk.h"
#include <malloc.h>

void disk_init(int count){
    head = malloc(sizeof(struct track));
    head->next = NULL;
    tail = head;
    now_num = 1;
    flag = OUTWARD;
    track_count = count;
}

void disk_trunc(){
    struct track* p = head, *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

void request(int num){
    tail->next = malloc(sizeof(struct track));
    tail = tail->next;
    tail->num = num;
    tail->next = NULL;
}

void exec(struct track* pre){
    if (!pre) return;
    struct track* p = pre->next;
    if (!p) return;
    if (p == tail) {
        tail = pre;
    }

    now_num = p->num;
    pre->next = p->next;
    free(p);
}


int FCFS(){
    struct track* p = head->next;
    if(!p) return -1;
    now_num = p->num;
    head->next = p->next;
    free(p);
    return now_num;
}

int SSTF(){
    struct track* p = head, *q = head->next, *pre_res = NULL;
    int min_dis = track_count;

    while (q) {
        if (ABS(q->num - now_num) < min_dis) {
            pre_res = p;
            min_dis = ABS(q->num - now_num);
        }

        p = p->next;
        q = q->next;
    }

    exec(pre_res);

    return now_num;
}

int SCAN(){
    struct track* p = head, *q = head->next;
    struct track *out_res = NULL, *in_res = NULL;
    int min_out_dis = track_count, min_in_dis = track_count;

    while (q) {
        if (q->num > now_num && q->num - now_num < min_out_dis) {
            out_res = p;
            min_out_dis = q->num - now_num;
        }
        if (q->num < now_num && now_num - q->num < min_in_dis) {
            in_res = p;
            min_in_dis = now_num - q->num;
        }

        p = p->next;
        q = q->next;
    }
    if (flag == OUTWARD){
        if (out_res != NULL){
            exec(out_res);
        }else{
            flag = INWARD;
            exec(in_res);
        }
    } else if (flag == INWARD){
        if (in_res != NULL){
            exec(in_res);
        }else{
            flag = OUTWARD;
            exec(out_res);
        }
    }
    return now_num;
}

int CSCAN(){
    struct track* p = head, *q = head->next;
    struct track *out_res = NULL, *in_res = NULL;
    int min_out_dis = track_count, min_in_dis = now_num;

    while (q) {
        if (q->num > now_num && q->num < min_out_dis) {
            out_res = p;
            min_out_dis = q->num;
        }

        if (q->num < min_in_dis) {
            in_res = p;
            min_in_dis = q->num;
        }

        p = p->next;
        q = q->next;
    }

    if (out_res == NULL){
        exec(in_res);
    }else{
        exec(out_res);
    }

    return now_num;
}