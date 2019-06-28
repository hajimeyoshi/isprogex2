/*********************************************
  prog9-5.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort-common.h"
#include "measurement.h"
#define MAX 1000

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

void merge_sort(struct data data[], int num)
{
    mergesort(data, 0, 9);
}

void shell_sort(struct data data[], int num)
{
    int i, j, h;

    for (h = 1; h <= num / 9; h = 3 * h + 1)
        ; // 間隔hを決める
    for (; h > 0; h /= 3)
    { // hを狭めていく
        for (i = h; i < num; i++)
        {
            j = i;
            while ((j > h - 1) && (data[j - h].key > data[j].key))
            {
                struct data temp = data[j - h];
                data[j - h] = data[j];
                data[j] = temp;

                j -= h;
            }
        }
    }
}

int main()
{
    measure("QUICK SORT", quick_sort);
    measure("MERGE SORT", merge_sort);
    measure("SHELL SORT", shell_sort);

    return 0;
}
