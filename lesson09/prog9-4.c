/*********************************************
  prog9-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "sort-common.h"

void shell_sort(struct data data[], int num);

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
                struct data temp = data[j-h];
                data[j-h] = data[j];
                data[j] = temp;

                j -= h;
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
    shell_sort(data, num);
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
    shell_sort(data, num);
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
