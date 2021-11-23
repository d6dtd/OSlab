//
// Created by mt on 11/22/2021.
//
#include "my_memory.h"
#include <malloc.h>
#include <stdio.h>
void memory_init(){
    head = malloc(sizeof(struct free_partition));
    head->address = -1;
    head->size = -1;
    struct free_partition* p = malloc(sizeof(struct free_partition));
    p->address = 0;
    p->size = MEMORY_SIZE;
    p->next = NULL;
    head->next = p;
}
void memory_trunc(){
    struct free_partition *p = head, *q = head->next;
    while (q) {
        free(p);
        p = q;
        q = q->next;
    }
    free(p);
}

int allocate_first(int size){
    struct free_partition *p = head, *q = head->next;
    int index;
    while(q){
        if(q->size > size){
            q->size -= size;
            index = q->address;
            q->address += size;
            return index;
        }else if (q->size == size){
            p->next = q->next;
            index = q->address;
            free(q);
            return index;
        }
        p = p->next;
        q = q->next;
    }
    return -1;
}

bool release_first(int index, int size){
    struct free_partition *p = head, *q = head->next;
    while(q){
        if(q->address >= index + size){
            if (p->address + p->size == index) {
                p->size += size;
            } else {
                p->next = malloc(sizeof(struct free_partition));
                p = p->next;
                p->address = index;
                p->size = size;
            }
            if (p->address + p->size == q->address){
                p->size += q->size;
                p->next = q->next;
                free(q);
            } else {
                p->next = q;
            }
            return true;
        }

        p = p->next;
        q = q->next;
    }
    return false;
}

int allocate_best(int size){
    struct free_partition *p = head, *q = head->next;
    int index;
    while(q){
        if(q->size > size){
            q->size -= size;
            index = q->address;
            q->address += size;
            return index;
        }else if (q->size == size){
            p->next = q->next;
            index = q->address;
            free(q);
            return index;
        }
        p = p->next;
        q = q->next;
    }
    return -1;
}

bool release_best(int index, int size){
    struct free_partition *p = head, *q = head->next, *node = NULL;
    int flag = 0;

    // 如果可以连接，切下来赋给node
    while(q){
        if (index + size == q->address) {
            if (flag == 0) {
                flag = 1;
                node = q;
                q = q->next;
                p->next = q;
                node->address = index;
                node->size += size;
            } else {
                p->next = q->next;
                node->size += q->size;
                free(q);
                q = p->next;
            }
            continue;
        }
        if (q->address + q->size == index){
            if (flag == 0) {
                flag = 1;
                node = q;
                q = q->next;
                p->next = q;
                node->size += size;
            } else {
                node->address = q->address;
                node->size += q->size;
                p->next = q->next;
                free(q);
                q = p->next;
            }
            continue;
        }

        p = p->next;
        q = q->next;
    }

    // 如果不能连接，创建新结点
    if (flag == 0){
        node = malloc(sizeof(struct free_partition));
        node->size = size;
        node->address = index;
    }

    p = head;
    q = head->next;

    while(q){
        if (q->size > node->size || q->size == node->size && q->address > node->address) {
            p->next = node;
            node->next = q;

            return true;
        }

        p = p->next;
        q = q->next;
    }
    p->next = node;
    node->next = NULL;
    return true;
}