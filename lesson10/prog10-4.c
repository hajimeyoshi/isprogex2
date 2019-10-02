/*********************************************
  prog10-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap-common.h"

void shift_down(struct data data[], int num, int index);
void heap_sort(struct data data[], int num);

void heap_sort(struct data data[], int num);

void shift_up(struct data data[], int num, int index)
{
    if (index >= num) {
        return;
    }

    struct data start = data[index];
    int parent = index / 2;
    while (index > 0 && data[parent].key > start.key) {
        data[index] = data[parent];
        index = parent;
        parent = index / 2;
    }
    data[index] = start;
}

void shift_down(struct data data[], int num, int index)
{
    struct data start = data[index];

    while (index <= num / 2) {
        int left = index * 2;
        int right = index * 2 + 1;

        int min = left;
        if (right <= num && data[left].key > data[right].key) {
            min = right;
        }

        if (start.key <= data[min].key) {
            break;
        }
        
        data[index] = data[min];
        index = min;
    }
    data[index] = start;
}

void swap (struct data *x,struct data *y) {
  struct data temp;    

  temp = *x;
  *x = *y;
  *y = temp;
}

void heap_sort(struct data data[], int num)
{
    int i;
    for(i = num/2; i >= 1; i--){
        shift_down(data,num,i);
    }
    for(i = num; i >= 2; i--){
        swap(&data[1],&data[i]);
        shift_down(data,i-1,1);
    }
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        { -1, '_' },
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]) - 1;

    print(data, num);
    heap_sort(data, num);
    print(data, num);

    assert(is_sorted(data, num));

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
