/*********************************************
  prog3-4.c
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

struct list *create_list()
{
    return NULL;
}

struct element *create_element(int value)
{
    return NULL;
}

void print_list(struct list *list)
{
}

void insert_front(struct list *list, struct element *elem)
{
}

void insert_rear(struct list *list, struct element *elem)
{
}

void delete_front(struct list *list)
{
}

void delete_rear(struct list *list)
{
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
