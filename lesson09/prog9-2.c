/*********************************************
  prog9-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort-common.h"
#define MAX 1000

void merge_sort(struct data data[], int num);
void mergesort(struct data array[], int left, int right);
void merge_sort(struct data data[], int num)
{
    mergesort(data, 0, 9);
}

void mergesort(struct data array[], int left, int right)
{
    int i, j, k, mid;
    struct data work[MAX]; // 作業用配列
    if (left < right)
    {
        mid = (left + right) / 2;         // 真ん中
        mergesort(array, left, mid);      // 左を整列
        mergesort(array, mid + 1, right); // 右を整列
        for (i = mid; i >= left; i--)
        {
            work[i] = array[i];
        } // 左半分
        for (j = mid + 1; j <= right; j++)
        {
            work[right - (j - (mid + 1))] = array[j]; // 右半分を逆順
        }
        i = left;
        j = right;
        for (k = left; k <= right; k++)
        {
            if (work[i].key < work[j].key)
            {
                array[k] = work[i++];
            }
            else
            {
                array[k] = work[j--];
            }
        }
    }
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    merge_sort(data, num);
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
    merge_sort(data, num);
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
