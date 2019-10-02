/*********************************************
  prog10-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap-common.h"

int is_heap(struct data data[], int num);

int is_heap(struct data data[], int num)
{
    int flag = 0;
    int i;
    for (i = 1; i <= num / 2; i++)
    {
        int left = data[2 * i].key;
        int right = data[2 * i + 1].key;

        if (data[i].key >= left)
        {
            return 0;
        }

        if (data[i].key >= right)
        {
            return 0;
        }
    }
    return 1;
}

/*=============================================*/

void test1()
{
    struct data *new;
    int i;
    new = (struct data *)malloc(7*sizeof(struct data));
    new[1].key = 1; 
    new[2].key = 2; 
    new[3].key = 6; 
    new[4].key = 5; 
    new[5].key = 7; 
    new[6].key = 8; 
    for(i = 1; i <= 6; i++){
        printf("%d\n",new[i].key);
    }
    assert(is_heap(new,6) == 1);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data *new;
    int i;
    new = (struct data *)malloc(7*sizeof(struct data));
    new[1].key = 1; 
    new[2].key = 6; 
    new[3].key = 6; 
    new[4].key = 5; 
    new[5].key = 7; 
    new[6].key = 8; 
    for(i = 1; i <= 6; i++){
        printf("%d\n",new[i].key);
    }
    assert(is_heap(new,6) == 0);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();

    return 0;
}
