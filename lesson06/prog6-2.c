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

int push(struct stack *stack, int value)
{
    if(stack->top < STACK_SIZE){
        stack->data[stack->top] = value;
        stack->top++;
        return 1;
    }else{
        return 0;
    }
}

int pop(struct stack *stack)
{
    int num;

    if(stack->top > 0){
        num = stack->data[stack->top-1];
        stack->top--;
        return num;
    }else{
        return -1;
    }
}

int peek(struct stack *stack)
{
    int num;

    if(stack->top > 0){
        num = stack->data[stack->top-1];
        return num;
    }else{
        return -1;
    }
}

int is_empty(struct stack *stack)
{
    if(stack->top > 0){
        return 0;
    }else{
        return 1;
    }
}

/*=============================================*/

void test1()
{
    struct stack *stack = create_stack();
    int i;
    assert(push(stack,1) == 1);
    assert(size_of_stack(stack) == 1);

    for(i = 1; i < STACK_SIZE; i++){
        push(stack,i+1);
    }
    assert(push(stack,31) == 0);
    print_stack(stack);

    printf("Success: %s\n", __func__);
}

void test2()
{
    struct stack *stack = create_stack();
    int i;

    for(i = 0; i < 5; i++){
        push(stack,i+1);
    }
    print_stack(stack);
    assert(pop(stack) == 5);
    
    for(i = 0; i < 4; i++){
        pop(stack);
    }
    print_stack(stack);
    assert(pop(stack) == -1);

    printf("Success: %s\n", __func__);
}

void test3()
{
    struct stack *stack = create_stack();
    int i;

    for(i = 0; i < 5; i++){
        push(stack,i+1);
    }
    print_stack(stack);
    assert(peek(stack) == 5);
    printf("peek of stack is %d\n",peek(stack));
    
    for(i = 0; i < 5; i++){
        pop(stack);
    }
    print_stack(stack);
    assert(peek(stack) == -1);
    printf("stack is empty\n");

    printf("Success: %s\n", __func__);
}

void test4()
{
    struct stack *stack = create_stack();
    int i;

    for(i = 0; i < 5; i++){
        push(stack,i+1);
    }
    print_stack(stack);
    assert(is_empty(stack) == 0);
    printf("stack is not empty\n");
    
    for(i = 0; i < 5; i++){
        pop(stack);
    }
    print_stack(stack);
    assert(is_empty(stack) == 1);
    printf("stack is empty\n");

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();
    test4();

    return 0;
}

