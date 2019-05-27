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
    struct stack *new;
    
    new = (struct stack *)malloc(sizeof(struct stack));
    new->top = NULL;
    new->size = 0;
    return new;
}

struct element *create_element(int value)
{
    struct element *e;

    e = (struct element*)malloc(sizeof(struct element));
    e->value = value;
    e->next = NULL;
    return e;
}

void print_stack(struct stack *stack)
{
    struct element *p;

    printf("Stack contain ");
    p = stack->top;
    while(p != NULL){
        printf("%d",p->value);
        p = p->next;
    }
    printf("\n");
}

int size_of_stack(struct stack *stack)
{
    struct element *p;
    int num;

    num = 0;
    p = stack->top;
    while(p != NULL){
        num++;
        p = p->next;
    }
    return num;
}

void push(struct stack *stack, struct element *elem)
{
    elem->next = stack->top;
    stack->top = elem;
    stack->size++;
}

struct element *pop(struct stack *stack)
{
    struct element *e;

    e = stack->top;
    if(e != NULL){
        stack->top = stack->top->next;
        stack->size--;
    }
    return e;
}

struct element *peek(struct stack *stack)
{
    return stack->top;
}

int is_empty(struct stack *stack)
{
    if(stack->size == 0){
        return 1;
    }else{
        return 0;
    }
}

/*=============================================*/

void test1()
{
    struct stack *stack = create_stack();
    int i;
    struct element *e = create_element(10);

    push(stack,e);
    assert(stack->top->value == 10);
    assert(size_of_stack(stack) == 1);

    printf("Success: %s\n", __func__);
}

void test2()
{
    struct stack *stack = create_stack();
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);
    struct element *p;

    push(stack,e1);
    push(stack,e2);
    print_stack(stack);
    p = pop(stack);
    assert(p->value == 20);
    
    pop(stack);
    print_stack(stack);
    assert(pop(stack) == NULL);

    printf("Success: %s\n", __func__);
}

void test3()
{
    struct stack *stack = create_stack();
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);
    struct element *p;
    struct element *pk;

    push(stack,e1);
    push(stack,e2);
    print_stack(stack);
    p = pop(stack);
    assert(p->value == 20);
    
    pk = peek(stack);
    print_stack(stack);
    assert(pk->value == 10);

    printf("Success: %s\n", __func__);
}

void test4()
{
    struct stack *stack = create_stack();
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);
    struct element *p;

    push(stack,e1);
    push(stack,e2);
    print_stack(stack);
    p = pop(stack);
    assert(is_empty(stack) == 0);
    
    pop(stack);
    print_stack(stack);
    assert(is_empty(stack) == 1);

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
