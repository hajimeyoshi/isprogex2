/*********************************************
  prog4-5.c
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
void print_list(struct list *list, struct element *pos);

void insert_front(struct list *list, struct element *elem);
void insert_after(struct list *list, struct element *pos, struct element *elem);
void delete(struct list *list, struct element *pos);

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

void print_list(struct list *list, struct element *pos)
{
  struct element *p;
  p = list->top;
  while(p != list->top){
    printf("%d ",p->value);
    p = p->next;
  }
}

void insert_front(struct list *list, struct element *elem)
{
  struct element *p;
  elem->next = list->top;
  list->top = elem;
  while(p->next != list->top){
    p = p->next;
  }
  p->next = elem;
}

void insert_after(struct list *list, struct element *pos, struct element *elem)
{
}

void delete(struct list *list, struct element *pos)
{
}

/*=============================================*/

int main()
{
    return 0;
}
