/*********************************************
  prog6-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 30

struct stack {
    int data[STACK_SIZE];
    int top;
};

struct stack *create_stack();
void print_stack(struct stack *stack);
int size_of_stack(struct stack *stack);

int push(struct stack *stack, int value);
int pop(struct stack *stack);
int peek(struct stack *stack);
int is_empty(struct stack *stack);

struct stack *create_stack()
{
    return NULL;
}

void print_stack(struct stack *stack)
{
}

int size_of_stack(struct stack *stack)
{
    return 0;
}

int push(struct stack *stack, int value)
{
    return 0;
}

int pop(struct stack *stack)
{
    return -1;
}

int peek(struct stack *stack)
{
    return -1;
}

int is_empty(struct stack *stack)
{
    return 0;
}

/*=============================================*/

int main()
{
    return 0;
}
