/*********************************************
  prog4-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct element {
    int value;
    struct element *prev;
    struct element *next;
};

struct list {
    struct element *top;
    struct element *rear;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);
void print_reverse_list(struct list *list);

struct list *create_list()
{
  struct list *e = (struct list*)malloc(sizeof(struct list));
  e->top = NULL;
  e->rear = NULL;
  return e;
}

struct element *create_element(int value)
{
  struct element *e = (struct element*)malloc(sizeof(struct element));
  e->value = value;
  e->prev = NULL;
  e->next = NULL;
  return e;
}

void print_list(struct list *list)
{
  struct element *p;
  p = list->top;
  while(p != NULL){
    printf("%d ",p->value);
    p = p->next;
  }
  printf("\n");
}

void print_reverse_list(struct list *list)
{
  struct element *p;
  p = list->rear;
  while(p != NULL){
    printf("%d ",p->value);
    p = p->prev;
  }
  printf("\n");
}

/*=============================================*/

void test1()
{
    struct list *list = create_list();
    
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);

    list->top = e1;
    e1->next = e2;
    e1->prev = NULL;
    e2->next = NULL;
    e2->prev = e1;
    list->rear = e2;
    
    assert(list->top->value == 10);
    assert(list->top->next->value == 20);
    assert(list->rear->value == 20);
    assert(list->rear->prev->value == 10);

    print_list(list);
    printf("----\n");
    print_reverse_list(list);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct list *list = create_list();
    
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);
    struct element *e3 = create_element(30);

    list->top = e1;
    e1->next = e2;
    e1->prev = NULL;
    e2->next = e3;
    e2->prev = e1;
    e3->next = NULL;
    e3->prev = e2;
    list->rear = e3;
    
    assert(list->top->value == 10);
    assert(list->top->next->value == 20);
    assert(list->top->next->next->value == 30);
    assert(list->rear->value == 30);
    assert(list->rear->prev->value == 20);
    assert(list->rear->prev->prev->value == 10);

    print_list(list);
    printf("----\n");
    print_reverse_list(list);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();

    return 0;
}
