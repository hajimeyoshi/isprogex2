/*********************************************
  prog8-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "sort-common.h"

void selection_sort(struct data data[], int num);

void selection_sort(struct data data[], int num)
{
    int i,j;
    struct data *min;
    struct data temp;

    for(i = 0; i < num - 1; i++){
        min = &data[num - 1];
        for(j = num - 1; j > i; j--){
            if(min->key > data[j-1].key){
                min = &data[j-1];
            }
        }
        temp = data[i];
        data[i] = *min;
        *min = temp;
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
    selection_sort(data, num);
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
    selection_sort(data, num);
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
