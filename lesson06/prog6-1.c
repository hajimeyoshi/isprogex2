/*********************************************
  prog6-1.c
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

struct stack *create_stack()
{
    struct stack *new;

    new = (struct stack *)malloc(sizeof(struct stack));
    new->top = 0;
    return new;
}

void print_stack(struct stack *stack)
{
    int i;

    printf("stack contain: ");
    for(i = 0; i < stack->top; i++){
        printf("%d ",stack->data[i]);
    }
    printf("\n");
}

int size_of_stack(struct stack *stack)
{
    return stack->top;
}

/*=============================================*/

void test1()
{
    struct stack *stack = create_stack();

    assert(size_of_stack(stack) == 0);
    print_stack(stack);

    stack->data[0] = 10;
    stack->top = 1;
    assert(stack->data[0] == 10);
    assert(size_of_stack(stack) == 1);
    print_stack(stack);

    stack->data[1] = 20;
    stack->top = 2;
    assert(stack->data[0] == 10);
    assert(stack->data[1] == 20);
    assert(size_of_stack(stack) == 2);
    print_stack(stack);

    stack->top = 1;
    assert(stack->data[0] == 10);
    assert(size_of_stack(stack) == 1);
    print_stack(stack);

    printf("Success: %s\n", __func__);
}

void test2()
{
    struct stack *stack = create_stack();

    stack->data[0] = 10;
    stack->top = 1;
    assert(stack->data[0] == 10);
    assert(size_of_stack(stack) == 1);

    stack->data[1] = 20;
    stack->top = 2;
    assert(stack->data[0] == 10);
    assert(stack->data[1] == 20);
    assert(size_of_stack(stack) == 2);

    stack->data[2] = 30;
    stack->top = 3;
    assert(stack->data[0] == 10);
    assert(stack->data[1] == 20);
    assert(stack->data[2] == 30);
    assert(size_of_stack(stack) == 3);

    print_stack(stack);
    printf("Success: %s\n", __func__);
}

void test3()
{
    struct stack *stack = create_stack();

    stack->data[0] = 10;
    stack->top = 1;
    assert(stack->data[0] == 10);
    assert(size_of_stack(stack) == 1);

    stack->data[1] = 20;
    stack->top = 2;
    assert(stack->data[0] == 10);
    assert(stack->data[1] == 20);
    assert(size_of_stack(stack) == 2);

    stack->top = 1;
    assert(stack->data[0] == 10);
    assert(size_of_stack(stack) == 1);

    print_stack(stack);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();

    return 0;
}
