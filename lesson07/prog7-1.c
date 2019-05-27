/*********************************************
  prog7-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct element {
    int value;
    struct element *next;
};

struct stack {
    struct element *top;
    int size;
};

struct stack *create_stack();
struct element *create_element(int value);
void print_stack(struct stack *stack);
int size_of_stack(struct stack *stack);

void push(struct stack *stack, struct element *elem);
struct element *pop(struct stack *stack);
struct element *peek(struct stack *stack);
int is_empty(struct stack *stack);

struct stack *create_stack()
{
    return NULL;
}

struct element *create_element(int value)
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

void push(struct stack *stack, struct element *elem)
{
}

struct element *pop(struct stack *stack)
{
    return NULL;
}

struct element *peek(struct stack *stack)
{
    return NULL;
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
