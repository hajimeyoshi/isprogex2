/*********************************************
  prog9-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "sort-common.h"

void quick_sort(struct data data[], int num);

void quick_sort(struct data data[], int num)
{
    if (num < 2)
    {
        return;
    }

    struct data pivot;

    if (data[0].key < data[num / 2].key)
        if (data[num / 2].key < data[num - 1].key)
            pivot = data[num / 2];
        else if (data[num - 1].key < data[0].key)
            pivot = data[0];
        else
            pivot = data[num - 1];
    else if (data[num - 1].key < data[num / 2].key)
        pivot = data[num / 2];
    else if (data[0].key < data[num - 1].key)
        pivot = data[0];
    else
        pivot = data[num - 1];

    int i, j;
    for (i = 0, j = num - 1;; i++, j--)
    {
        while (data[i].key < pivot.key)
            i++;
        while (data[j].key > pivot.key)
            j--;

        if (i >= j)
            break;

        struct data temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    quick_sort(data, i);           // *1
    quick_sort(data + i, num - i); // *2
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    quick_sort(data, num);
    print(data, num);

    assert(is_sorted(data, num));

    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[] = {
        {0, 'a'}, {27, 'b'}, {5, 'c'}, {192, 'd'}, {11, 'e'}, {1, 'f'}, {23, 'g'}, {48, 'h'}, {10, 'i'}, {15, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    quick_sort(data, num);
    print(data, num);

    assert(is_sorted(data, num));

    printf("Success: %s\n", __func__);
}
int main()
{
    test1();
    test2();
    return 0;
}
