/*********************************************
  prog8-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "sort-common.h"

void insertion_sort(struct data data[], int num);

void insertion_sort(struct data data[], int num)
{
    int i,j;
    struct data temp;

    for(i = 1; i < num; i++){
        j = i;
        while((j > 0) && (data[j].key < data[j-1].key)){
            temp = data[j];
            data[j] = data[j-1];
            data[j-1] = temp;
            j--;
        }
    }
} 

/*=============================================*/

void test1()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    insertion_sort(data, num);
    print(data, num);

    assert(is_sorted(data, num));

    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' },
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    print(data, num);
    insertion_sort(data, num);
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
