/*********************************************
  prog3-5.c
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
    struct element *rear;
    int size;
};

struct list *create_list();
struct element *create_element(int value);
void print_list(struct list *list);

void insert_front(struct list *list, struct element *elem);
void insert_rear(struct list *list, struct element *elem);
void delete_front(struct list *list);
void delete_rear(struct list *list);

int size_of_list(struct list *list);
struct element *get_from_list(struct list *list, int index);

void insert_at(struct list *list, int index, struct element *elem);
void delete_at(struct list *list, int index);
struct list *append(struct list *first, struct list *second);

struct list *create_list()
{
  struct list *e = (struct list*)malloc(sizeof(struct list));
  e->top = NULL;
  e->rear = NULL;
  e->size = size_of_list(e);
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
  printf("\n");
}

void insert_front(struct list *list, struct element *elem)
{
  if(list->size == 0){
      list->rear = elem;
  }  
  elem->next = list->top;
  list->top = elem;
  list->size = size_of_list(list);
}

void insert_rear(struct list *list, struct element *elem)
{  
  if(list->top == NULL){
    insert_front(list,elem);
  }else{
    list->rear->next = elem;
    list->rear = elem;
  }
  list->size = size_of_list(list);
}

void delete_front(struct list *list)
{
  
  if(list->top != NULL){
    list->top = list->top->next;
  }
  if(list->top == NULL){
      list->rear = NULL;
  }
  list->size = size_of_list(list);
}

void delete_rear(struct list *list)
{
  if(list->top != NULL){
    if(list->top->next == NULL){
      delete_front(list);
    }else{
      struct element *p;
      p = list->top;
      while(p->next->next != NULL){
        p = p->next;
      }
      p->next = NULL;
      list->rear = p;
    }
  }
  list->size = size_of_list(list);
}

int size_of_list(struct list *list)
{
  int num = 0;
  struct element *p;
  p = list->top;
  while(p != NULL){
    p = p->next;
    num++; 
  }
  return num;
}

struct element *get_from_list(struct list *list, int index)
{
  int i;
  struct element *p;
  if(list->size <= index){
    return NULL;
  }

  p = list->top;
  for(i = 0; i < index; i++){
    p = p->next;
  }
  return p;
}

void insert_at(struct list *list, int index, struct element *elem)
{
  int i;
  struct element *p;
  if(list->size > index){
      if(index == 0){
          elem->next = list->top;
          list->top = elem;
          if(elem->next == NULL){
              list->rear = elem;
          }
      }else{
        p = list->top;
        for(i = 0; i < index-1; i++){
          p = p->next;
        }
        elem->next = p->next;
        p->next = elem;
      }
      list->size = size_of_list(list);
   }
}
    
void delete_at(struct list *list, int index)
{
  int i;
  struct element *p;
  if(list->size > index){
    if(index == 0){
      list->top = list->top->next;
      if(list->top == NULL){
        list->rear = NULL;
      }
    }else{
      p = list->top;
      for(i = 0; i < index-1; i++){
        p = p->next;
      }
      if(p->next == list->rear){
        list->rear = p;
      }
      p->next = p->next->next;
    }
    list->size = size_of_list(list);
  }
}
    
struct list *append(struct list *first, struct list *second)
{  
  if(first->top == NULL){
    first->rear = second->rear;
    first->top = second->top;
    }else{
      first->rear->next = second->top;
      first->rear = second->rear;
    }
  first->size = size_of_list(first);
  return first;
}

/*=============================================*/

void test1()
{
  struct list *list = create_list();
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);
    
  insert_rear(list,e1);
  insert_at(list,0,e2);
  insert_at(list,1,e3);
  insert_at(list,1,e4);

  assert(list->top->value == 20);
  assert(list->top->next->value == 60);
  assert(list->top->next->next->value == 50);
  assert(list->top->next->next->next->value == 10);

  print_list(list);
  printf("number of element: %d\n",list->size);
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
    
  insert_rear(list,e1);
  insert_rear(list,e2);
  insert_rear(list,e3);
  insert_rear(list,e4);

  delete_at(list,0);
  delete_at(list,2);

  assert(list->top->value == 20);
  assert(list->top->next->value == 50);

  print_list(list);
  printf("top of element: %d\n",list->top->value);
  printf("rear of element: %d\n",list->rear->value);
  printf("Success: %s\n", __func__);
}

void test3()
{
  struct element *p;
  struct list *list1 = create_list();
  struct list *list2 = create_list();
  struct list *list3;
  int index;
  index = 4;
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(30);
  struct element *e4 = create_element(40);
  struct element *e5 = create_element(50);
  struct element *e6 = create_element(60);
  struct element *e7 = create_element(70);
  struct element *e8 = create_element(80);
    
  insert_rear(list1,e1);
  insert_rear(list1,e2);
  insert_rear(list1,e3);
  insert_rear(list1,e4);

  insert_rear(list2,e5);
  insert_rear(list2,e6);
  insert_rear(list2,e7);
  insert_rear(list2,e8);
    
  list3 = append(list1,list2);
  
  assert(list3->top->value == 10);
  assert(list3->top->next->value == 20);
  assert(list3->top->next->next->value == 30);
  assert(list3->top->next->next->next->value == 40);
  assert(list3->top->next->next->next->next->value == 50);
  assert(list3->top->next->next->next->next->next->value == 60);
  assert(list3->top->next->next->next->next->next->next->value == 70);
  assert(list3->top->next->next->next->next->next->next->next->value == 80);

  print_list(list3);
  printf("Success: %s\n", __func__);
}

void test4()
{
  struct element *p;
  struct list *list = create_list();
  int index;
  index = 2;
    
  struct element *e1 = create_element(10);
  struct element *e2 = create_element(20);
  struct element *e3 = create_element(50);
  struct element *e4 = create_element(60);
    
  insert_rear(list,e1);
  insert_rear(list,e2);
  insert_rear(list,e3);
  insert_rear(list,e4);

  delete_at(list,0);
  delete_at(list,2);
  delete_at(list,0);
  delete_at(list,0);

  assert(list->top == NULL);

  print_list(list);
  printf("top of element: %s\n",list->top);
  printf("rear of element: %s\n",list->rear);
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
