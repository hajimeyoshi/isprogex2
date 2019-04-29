/*********************************************
  prog4-3.c
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
    int size;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);
void print_reverse_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

int size_of_list(struct list *list);
struct element *get_from_list(struct list *list, int index);

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

int size_of_list(struct list *list)
{
    return 0;
}

struct element *get_from_list(struct list *list, int index)
{
    return NULL;
}

/*=============================================*/

int main()
{
    return 0;
}
