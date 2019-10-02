/*
  stack.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack *create_stack(int size)
{
    struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
    if (stack == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        stack->value = (int *)calloc(size, sizeof(int));
        stack->top = 0;
    }
    return stack;
}

void push(struct stack *stack, int value)
{
    stack->value[stack->top] = value;
    stack->top++;
}

int pop(struct stack *stack)
{
    if (stack->top == 0) {
        return -1;
    } else {
        int value = stack->value[stack->top - 1];
        stack->top--;
        return value;
    }
}

int peek(struct stack *stack)
{
    if (stack->top == 0) {
        return -1;
    } else {
        int value = stack->value[stack->top - 1];
        return value;
    }
}

int is_empty_stack(struct stack *stack)
{
    if (stack->top == 0) {
        return 1;
    } else {
        return 0;
    }
}
