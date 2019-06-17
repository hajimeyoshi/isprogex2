/*********************************************
  prog9-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort-common.h"
#include "sort-common4list.h"

struct element *merge_sort(struct element *top);

struct element *merge_sort(struct element *top)
{
    return NULL;
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        { 21, 'a' }, { 33, 'b' }, { 31, 'c' }, { 14, 'd' }, { 20, 'e' },
        {  1, 'f' }, { 24, 'g' }, { 12, 'h' }, { 10, 'i' }, { 15, 'j' }
    };
    int num = sizeof(data) / sizeof(data[0]);

    struct element *top = create_list(data, num);

    print_list(top);
    struct element *result = merge_sort(top);
    print_list(result);

    assert(is_sorted_list(top));

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
