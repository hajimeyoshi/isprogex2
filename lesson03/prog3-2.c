/*********************************************
  prog3-2.c
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

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

struct list *create_list()
{
  struct list *e = (struct list*)malloc(sizeof(struct list));
  e->top = NULL;
  return e;
}

struct element *create_element(int value)
{
  struct element *e = (struct element*)malloc(sizeof(struct element));
  e->value = value;
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
}

void insert_front(struct list *list, struct element *elem)
{
  elem->next = list->top;
  list->top = elem;
}

void insert_rear(struct list *list, struct element *elem)
{
  if(list->top == NULL){
    elem->next = list->top;
    list->top = elem;
  }else{
    struct element *p;
    p = list->top;
    while(p->next != NULL){
      p = p->next;
    }
    p->next = elem;
  }
}

void delete_front(struct list *list)
{
  if(list->top != NULL){
    list->top = list->top->next;
  }
}

void delete_rear(struct list *list)
{
  if(list->top != NULL){
    if(list->top->next == NULL){
      list->top = list->top->next;
    }else{
      struct element *p;
      p = list->top;
      while(p->next->next != NULL){
        p = p->next;
      }
      p->next = NULL;
    }
  }
}

/*=============================================*/

void test1()
{
    struct list *list = create_list();

    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);

    insert_front(list, e1);
    insert_front(list, e2);

    assert(list->top->value == 20);
    assert(list->top->next->value == 10);

    print_list(list);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct list *list = create_list();
    
    struct element *e1 = create_element(10);
    struct element *e2 = create_element(20);
    struct element *e3 = create_element(50);
    struct element *e4 = create_element(60);
    
    insert_rear(list,e1);
    insert_rear(list,e2);
    insert_rear(list,e3);
    insert_rear(list,e4);
    
    assert(list->top->value == 10);
    assert(list->top->next->value == 20);
    assert(list->top->next->next->value == 50);
    assert(list->top->next->next->next->value == 60);

    print_list(list);
    printf("Success: %s\n", __func__);
}

void test3()
{
  struct list *list = create_list();
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);

  insert_rear(list,e1);
  insert_rear(list,e2);
  insert_rear(list,e3);
  insert_rear(list,e4);

  delete_front(list);
  assert(list->top->value == 20);
  assert(list->top->next->value == 50);
  assert(list->top->next->next->value == 60);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test4()
{
  struct list *list = create_list();
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);

  insert_rear(list,e1);
  insert_rear(list,e2);
  insert_rear(list,e3);
  insert_rear(list,e4);

  delete_rear(list);
  assert(list->top->value == 10);
  assert(list->top->next->value == 20);
  assert(list->top->next->next->value == 50);
  assert(list->top->next->next->next == NULL);

  print_list(list);
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
