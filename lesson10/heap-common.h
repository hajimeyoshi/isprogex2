/*
  heap-common.h
*/

#ifndef HEAP_COMMON_H
#define HEAP_COMMON_H

#include <stdio.h>

#define HEAP_SIZE 100

struct data {
    int key;
    char value;
};

extern void print(struct data data[], int num);
extern int is_sorted(struct data data[], int num);

#endif /* HEAP_COMMON_H */
