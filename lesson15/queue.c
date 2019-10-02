/*
  queue.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue *create_queue(int size)
{
    struct queue *queue = (struct queue *)malloc(sizeof(struct queue));
    if (queue == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        queue->value = (int *)calloc(size, sizeof(int));
        queue->top = 0;
        queue->rear = 0;
    }
    return queue;
}

void enqueue(struct queue *queue, int value)
{
    queue->value[queue->rear] = value;
    queue->rear++;
}

int dequeue(struct queue *queue)
{
    if (queue->rear - queue->top == 0) {
        return -1;
    } else {
        int value = queue->value[queue->top];
        queue->top++;
        return value;
    }
}

int peek(struct queue *queue)
{
    if (queue->rear - queue->top == 0) {
        return -1;
    } else {
        int value = queue->value[queue->top];
        return value;
    }
}

int is_empty_queue(struct queue *queue)
{
    if (queue->rear - queue->top == 0) {
        return 1;
    } else {
        return 0;
    }
}

