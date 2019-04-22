/*********************************************
  prog3-1.c
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

struct list {
    struct element *top;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

struct list *create_list()
{
  struct list *e = (struct list*)malloc(sizeof(struct list));
  *e->top = NULL;
  return e;
}

struct element *create_element(int value)
{
  struct element *e = (struct element*)malloc(sizeof(struct element));
  *e->value = value;
    return NULL;
}

void print_list(struct list *list)
{
}

/*=============================================*/

void test1()
{
    struct list *list = create_list();

    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);

    list->top = e1;
    e1->next = e2;
    e2->next = NULL;

    assert(list->top->value == 10);
    assert(list->top->next->value == 20);

    print_list(list);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
