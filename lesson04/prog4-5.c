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
    return NULL;
}

struct element *create_element(int value)
{
    return NULL;
}

void print_list(struct list *list, struct element *pos)
{
}

void insert_front(struct list *list, struct element *elem)
{
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
