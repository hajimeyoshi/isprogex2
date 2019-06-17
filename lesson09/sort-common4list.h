/*
  sort-common4list.h
*/

#ifndef SORT_COMMON4LIST_H
#define SORT_COMMON4LIST_H

#include <stdio.h>
#include "sort-common.h"

struct element {
    struct data data;
    struct element *next;
};

extern struct element *create_list(struct data data[], int num);
extern void print_list(struct element *data);
extern int is_sorted_list(struct element *top);

#endif /* SORT_COMMON4LIST_H */
