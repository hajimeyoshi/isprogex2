/*********************************************
  prog12-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraytable-common.h"

#define DATA_SIZE 20

struct data *search_array(struct table *table, int key);
int insert_array(struct table *table, struct data data);
int delete_array(struct table *table, int key);

struct data *search_array(struct table *table, int key)
{
    int i;
    for (i = 0; i < table->size; i++)
    {
        if (table->data[i] != NULL)
        {
            if (table->data[i]->key == key)
            {
                return table->data[i];
            }
        }
    }
    return NULL;
}

int insert_array(struct table *table, struct data data)
{
    if (table->size <= table->num)
    {
        return 0;
    }
    int i;
    struct data *p = (struct data *)calloc(1, sizeof(struct data));
    *p = data;

    if(search_array(table,data.key) != NULL){
        return 0;
    }
    for (i = 0; i < table->size; i++)
    {
        if (table->data[i] == NULL)
        {
            table->data[i] = p;
            table->num = table->num + 1;
            return 1;
        }
    }
    return 0;
}

int delete_array(struct table *table, int key)
{
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
        insert_array(table, data[i]);
    }

    assert(search_array(table, 1)->value == 'f');

    print(table);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    struct table *table = create_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_array(table, data[i]);
    }

    delete_array(table,21);
    assert(search_array(table, 21) == NULL);

    print(table);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    return 0;
}
