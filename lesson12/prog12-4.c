/*********************************************
  prog12-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraytable-common.h"

#define DATA_SIZE 19
struct data *search_open(struct table *table, int key);
int insert_open(struct table *table, struct data data);
int delete_open(struct table *table, int key);

int hash(int key, int size)
{
    return key % 31;
}

int rehash(int hkey, int size)
{
    return (hkey + 1) % size;
}

struct data *search_open(struct table *table, int key)
{
    int h;
    h = hash(key, table->size);
    if (table->data[h] != NULL)
    {
      return table->data[h];
    }
    return NULL;
}

int insert_open(struct table *table, struct data data)
{
    int h;
    struct data *new = (struct data *)calloc(1, sizeof(struct data));
    *new = data;

    h = hash(data.key, table->size);
    if (table->data[h] == NULL)
    {
        table->data[h] = new;
        table->num++;
        return 1;
    }
    else
    {
        while (table->data[h] != NULL)
        {
            h = rehash(h, table->size);
        }
        table->data[h] = new;
        table->num++;
        return 1;
    }

    return 0;
}

int delete_open(struct table *table, int key)
{
    /* int h;
    h = hash(key, table->size);
    if (table->data[h] != NULL)
    {
        struct data *p;
        table->data[h] == NULL;
        table->num--;
        return 1;
    }
    return 0;*/

    int i;
    for (i = 0; i < table->size; i++)
    {
        if (table->data[i] != NULL)
        {
            if (table->data[i]->key == key)
            {
                int j;
                for(j = i; j < table->num; j++){
                    table->data[j] = table->data[j+1];
                }
                table->num--;
                return 1;
            }
        }
    }
    return 0;
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    struct table *table = create_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_open(table, data[i]);
    }
    print(table);
    delete_open(table,21);
    print(table);
    assert(search_open(table, 21) == NULL);
    
    printf("Success: %s\n", __func__);
}


int main()
{
    test1();
    return 0;
}
