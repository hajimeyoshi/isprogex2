 /*********************************************
  prog7-3.c
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
int size_of_stack(struct stack *stack);

void push(struct stack *stack, struct element *elem);
struct element *pop(struct stack *stack);
int peek(struct stack *stack);
int is_empty(struct stack *stack);
int kind(char ch);
int check(char *text);

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
    return stack->size;
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

int peek(struct stack *stack)
{
    return stack->top->value;
}

int is_empty(struct stack *stack)
{
    if(stack->size == 0){
        return 1;
    }else{
        return 0;
    }
}

int kind(char ch)
{
    int code;
    switch (ch){
    case '(':
      code = 1;
      break;
    case ')':
      code = 2;
      break;
    case '{':
      code = 3;
      break;
    case '}':
      code = 4;
      break;
    case '[':
      code = 5;
      break;
    case ']':
      code = 6;
      break;
    default:
      code = 0; // 括弧以外の文字
      break;
    }
    return code;
}
int check(char *text)
{
    int pin;
    int pt;
    struct stack *brackets = create_stack();
    pt = 0;

    while(text[pt] != '\0'){
        pin = kind(text[pt]);
        if(pin != 0){
            if(pin % 2){
                push(brackets,create_element(pin));
            }else if(!is_empty(brackets) && pin == peek(brackets) + 1){
                pop(brackets);
            }else{
                printf("対応する開き括弧がありません\n");
                return 0;
            }
        }
        pt++;
    }
    if(!is_empty(brackets)){
        printf("対応する閉じ括弧がありません\n");
        return 0;
    }
    return 1;
}

/*=============================================*/

void test1()
{
    assert(check("{ a [ ( xyz) ] }"));

    printf("Success: %s\n", __func__);
}

void test2()
{
    assert(check("{{( )}}"));

    printf("Success: %s\n", __func__);
}

void test3()
{
    assert(!check("{"));

    printf("Success: %s\n", __func__);
}

void test4()
{
    assert(!check("{{{}}}}"));

    printf("Success: %s\n", __func__);
}

void test5()
{
    assert(!check("{{ ]}"));

    printf("Success: %s\n", __func__);
}

void test6()
{
    assert(check("{{[a],[b]},{c,d}}"));

    printf("Success: %s\n", __func__);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
