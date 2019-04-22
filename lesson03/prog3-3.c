/*********************************************
  prog3-3.c
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
    int size;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rearm(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

int size_of_list(struct list *list);
struct element *get_from_list(struct list *list, int index);

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
