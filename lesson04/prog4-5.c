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
void print_list(struct list *list);

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

void print_list(struct list *list)
{
  struct element *p;
  p = list->top;
  do{
    printf("%d ",p->value);
    p = p->next;
  }while(p != list->top);
}

void insert_front(struct list *list, struct element *elem)
{
  struct element *p;
  if(list->top == NULL){
    list->top = elem;
    elem->next = elem;
  }else{
    p = list->top;
    while(p->next != list->top){
      p = p->next;
    }
    p->next = elem;
    elem->next = list->top;
    list->top = elem;
    p = list->top;
    
  }
}

void insert_after(struct list *list, struct element *pos, struct element *elem)
{
  if(pos != NULL){
    elem->next = pos->next;
    pos->next = elem;
  }else if(list->top == NULL){
    insert_front(list,elem);
  }
}

void delete(struct list *list, struct element *pos)
{
  struct element *p;
  if(list->top != NULL){
    if(pos != NULL){
      p = list->top;
      while(p->next != pos){
	p = p->next;
      }
      p->next = pos->next;
      if(pos == list->top){
	list->top = NULL;
      }
    }
  }
}

/*=============================================*/

void test1()
{
  struct list *list = create_list();
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);
    
  insert_front(list,e1);
  insert_front(list,e2);
  insert_front(list,e3);
  insert_front(list,e4);

  assert(list->top->value == 60);
  assert(list->top->next->value == 50);
  assert(list->top->next->next->value == 20);
  assert(list->top->next->next->next->value == 10);

  print_list(list);
  printf("Success: %s\n", __func__);
}

void test2()
{
  struct element *p;
  struct list *list = create_list();
  int index;
  index = 2;
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);
    
  insert_front(list,e1);
  insert_after(list,list->top,e2);
  insert_after(list,list->top->next,e3);
  insert_after(list,list->top->next->next,e4);


  assert(list->top->value == 10);
  assert(list->top->next->value == 20);
  assert(list->top->next->next->value == 50);
  assert(list->top->next->next->next->value == 60);

  print_list(list);
  printf("top of element: %d\n",list->top->value);
  printf("Success: %s\n", __func__);
}

void test3()
{
  struct element *p;
  struct list *list = create_list();
  int index;
  index = 2;
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);
    
  insert_front(list,e1);
  insert_after(list,list->top,e2);
  insert_after(list,list->top->next,e3);
  insert_after(list,list->top->next->next,e4);
  
  delete(list,list->top->next);

  assert(list->top->value == 10);
  assert(list->top->next->value == 50);
  assert(list->top->next->next->value == 60);

  print_list(list);
  printf("top of element: %d\n",list->top->value);
  printf("Success: %s\n", __func__);
}


int main()
{
  test1();
  test2();
  test3();
  return 0;
}

