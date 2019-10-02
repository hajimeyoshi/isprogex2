/*********************************************
  prog12-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "chaintable-common.h"

#define DATA_SIZE 20
struct chain_data *search_chain(struct chain_table *table, int key);
int insert_chain(struct chain_table *table, struct chain_data data);
int delete_chain(struct chain_table *table, int key);

int hash(int key, int size)
{
    return key % 7;
}

struct chain_data *search_chain(struct chain_table *table, int key)
{
    int h;
    h = hash(key, table->size);
    if (table->data[h] != NULL)
    {
        struct chain_data *p;
        p = table->data[h];
        while (p->next != NULL)
        {
            if (p->key == key)
            {
                return p;
            }
            p = p->next;
        }
    }
    return NULL;
}

int insert_chain(struct chain_table *table, struct chain_data data)
{
    int h;
    struct chain_data *new = (struct chain_data *)calloc(1, sizeof(struct chain_data));
    *new = data;

    h = hash(data.key, table->size);
    if (table->data[h] != NULL)
    {
        struct chain_data *p;
        p = table->data[h];
        while (p->next != NULL)
        {
            if (p->key == data.key)
            {
                return 0;
            }
            p = p->next;
        }
        p->next = new;
        new->next == NULL;
        table->num++;
        return 1;
    }else{
        table->data[h] = new;
        new->next = NULL;
        table->num++;
        return 1;
    }
    return 0;
}

int delete_chain(struct chain_table *table, int key)
{
    int h;
    h = hash(key, table->size);
    if (table->data[h] != NULL)
    {
        struct chain_data *p;
        p = table->data[h];
        if(p->key == key){
            table->data[h] = p->next;
            return 1;
        }
        while (p->next != NULL)
        {
            if (p->next->key == key)
            {
                p->next = p->next->next;
                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

/*=============================================*/

void test1()
{
    struct chain_data data[] = {
        {21, 'a',NULL}, {33, 'b',NULL}, {31, 'c',NULL}, {14, 'd',NULL}, {20, 'e',NULL}, {1, 'f',NULL}, {24, 'g',NULL}, {12, 'h',NULL}, {10, 'i',NULL}, {15, 'j',NULL}};
    int num = sizeof(data) / sizeof(data[0]);

    struct chain_table *table = create_chain_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_chain(table, data[i]);
    }

    assert(search_chain(table, 1)->value == 'f');
    print_chain(table);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct chain_data data[] = {
        {21, 'a',NULL}, {33, 'b',NULL}, {31, 'c',NULL}, {14, 'd',NULL}, {20, 'e',NULL}, {1, 'f',NULL}, {24, 'g',NULL}, {12, 'h',NULL}, {10, 'i',NULL}, {15, 'j',NULL}};
    int num = sizeof(data) / sizeof(data[0]);

    struct chain_table *table = create_chain_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_chain(table, data[i]);
    }
    print_chain(table);
    delete_chain(table,21);
    assert(search_chain(table, 21) == NULL);
    print_chain(table);
    printf("Success: %s\n", __func__);
}

void test3()
{
    struct chain_data data[] = {
        {21, 'a',NULL}, {33, 'b',NULL}, {31, 'c',NULL}, {14, 'd',NULL}, {20, 'e',NULL}, {1, 'f',NULL}, {24, 'g',NULL}, {12, 'h',NULL}, {10, 'i',NULL}, {15, 'j',NULL}};
    int num = sizeof(data) / sizeof(data[0]);

    struct chain_table *table = create_chain_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_chain(table, data[i]);
    }
    print_chain(table);
    delete_chain(table,14);
    assert(search_chain(table, 14) == NULL);
    print_chain(table);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
