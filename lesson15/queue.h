/*
  queue.h
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

struct queue {
    int *value;
    int top;
    int rear;
};

extern struct queue *create_queue(int size);
extern void enqueue(struct queue *queue, int value);
extern int dequeue(struct queue *queue);
extern int peek(struct queue *queue);
extern int is_empty_queue(struct queue *queue);

#endif /* QUEUE_H */
