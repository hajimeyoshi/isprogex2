/*
  sort-check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "sort-common.h"
#include "sort-common4list.h"

void print(struct data data[], int num)
{
    if (num == 0) {
        printf("No element\n");
        return;
    }

    int i;
    for (i = 0; i < num; i++) {
        printf(" %d:%c", data[i].key, data[i].value);
    }
    printf("\n");
}

int is_sorted(struct data data[], int num)
{
    int i;
    for (i = 0; i < num - 1; i++) {
        if (data[i].key > data[i+1].key) {
            return 0;
        }
    }
    return 1;
}

struct element *create_list(struct data data[], int num)
{
    struct element *top;
    struct element *rear;
    
    if (num == 0) {
        return NULL;
    }

    int i;
    for (i = 0; i< num; i++) {
        struct element *elem = (struct element *)malloc(sizeof(struct element));
        if (elem == NULL) {
            fprintf(stderr, "Not enough memory\n");
            return NULL;
        } else {
            elem->data.key = data[i].key;
            elem->data.value = data[i].value;
            elem->next = NULL;
            if (i == 0) {
                top = elem;
                rear = top;
            } else {
                rear->next = elem;
                rear = elem;
            }
        }
    }
    return top;
}

void print_list(struct element *top)
{
    if (top == NULL) {
        printf("No element\n");
        return;
    }

    struct element *cur = top;
    while (cur != NULL) {
        printf(" %d:%c", cur->data.key, cur->data.value);
        cur = cur->next;
    }
    printf("\n");
}

int is_sorted_list(struct element *top)
{
    if (top == NULL || top->next == NULL) {
        return 1;
    }

    struct element *cur = top;
    while (cur->next != NULL) {
        if (cur->data.key > cur->next->data.key) {
            return 0;
        }
        cur = cur->next;
    }
    return 1;
}
