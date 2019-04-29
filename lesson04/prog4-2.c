/*********************************************
  prog4-2.c
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

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

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

void insert_front(struct list *list, struct element *elem)
{  
  elem->next = list->top;
  if(elem->next == NULL){
      list->rear = elem;
  }else{
      elem->next->prev = elem;
  }
  elem->prev = NULL;
  list->top = elem;
}

void insert_rear(struct list *list, struct element *elem)
{  
  if(list->top == NULL){
    insert_front(list,elem);
  }else{
    list->rear->next = elem;
    elem->prev = list->rear;
    list->rear = elem;
    elem->next = NULL;
  }
}

void delete_front(struct list *list)
{
  
  if(list->top != NULL){
    list->top = list->top->next;
  }
  if(list->top == NULL){
      list->rear = NULL;
  }else{
      list->top->prev = NULL;
  }
  
}

void delete_rear(struct list *list)
{
  if(list->top != NULL){
    if(list->top->next == NULL){
      delete_front(list);
    }else{
      list->rear = list->rear->prev;
      list->rear->next = NULL;
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
