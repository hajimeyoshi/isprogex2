/*
  queue.h
*/

#ifndef STACK_H
#define STACK_H

#include <stdio.h>

struct stack {
    int *value;
    int top;
};

extern struct stack *create_stack(int size);
extern void push(struct stack *stack, int id_num);
extern int pop(struct stack *stack);
extern int peek(struct stack *stack);
extern int is_empty_stack(struct stack *stack);

#endif /* STACK_H */

