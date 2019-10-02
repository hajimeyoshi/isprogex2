/*********************************************
  prog13-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list-common.h"

struct data *search_list(struct list *list, int key);
int insert_list(struct list *list, struct data data);
int delete_list(struct list *list, int key);

struct data *search_list(struct list *list, int key)
{
    int i;
    struct element *p;
    p = list->top;
    while(p != NULL){
        if(p->data->key == key){
            return p->data;
        }
        p = p->next;
    }
    return NULL;
}

int insert_list(struct list *list, struct data data)
{
    if(search_list(list,data.key) != NULL){
        return 0;
    }else{
        struct element *new = (struct element*)malloc(sizeof(struct element));
        new->data = (struct data*)malloc(sizeof(struct data));
        *(new->data) = data;
        new->next = list->top;
        list->top = new;
        return 1;
    }
    return 0;
}

int delete_list(struct list *list, int key)
{
    int i;
    struct element *prev;
    prev = list->top;
    if(prev == NULL){
        return 0;
    }
    if(prev->data->key == key){
        list->top = prev->next;
        return 1;
    }
    while(prev->next != NULL){
        if(prev->next->data->key == key){
            prev->next = prev->next->next;
            return 1;
        }
        prev = prev->next;
    }
    return 0;
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    struct list *list = create_list();
    int i;
    for (i = 0; i < num; i++) {
        insert_list(list, data[i]);
    }

    assert(search_list(list, 1)->value == 'f');

    print(list);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    struct list *list = create_list();
    int i;
    for (i = 0; i < num; i++) {
        insert_list(list, data[i]);
    }
    print(list);
    delete_list(list,1);
    assert(search_list(list, 1) == NULL);

    print(list);
    printf("Success: %s\n", __func__);
}


int main()
{
    test1();
    test2();

    return 0;
}
