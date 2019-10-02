/*********************************************
  prog12-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraytable-common.h"
#define DATA_SIZE 20

struct data *search_binary(struct table *table, int key);
int insert_binary(struct table *table, struct data data);
int delete_binary(struct table *table, int key);

struct data *search_binary(struct table *table, int key)
{
    int lowid, midid, highid;

    highid = table->num - 1;
    lowid = 0;
    while (lowid <= highid)
    {
        midid = (lowid + highid) / 2;
        if (table->data[midid]->key == key)
        {
            return table->data[midid];
        }
        else if (table->data[midid]->key < key)
        {
            lowid = midid + 1;
        }
        else
        {
            highid = midid - 1;
        }
    }
    return NULL;
}

int insert_binary(struct table *table, struct data data)
{
    if (table->size <= table->num)
    {
        return 0;
    }
    int i;
    struct data *p = (struct data *)calloc(1, sizeof(struct data));
    *p = data;

    if(search_binary(table,data.key) != NULL){
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
    

int delete_binary(struct table *table, int key)
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
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);
    sort(data, num);
    struct table *table = create_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_binary(table, data[i]);
    }
    print(table);

    assert(search_binary(table, 1)->value == 'a');

    print(table);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[] = {
        {1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}, {6, 'f'}, {7, 'g'}, {8, 'h'}, {9, 'i'}, {10, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    struct table *table = create_table(DATA_SIZE);
    int i;
    for (i = 0; i < num; i++)
    {
        insert_binary(table, data[i]);
    }

    delete_binary(table,1);
    print(table);
    assert(search_binary(table, 1) == NULL);

    print(table);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    return 0;
}