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
struct element *merge_sort1(struct element *list, int num);
struct element *merge_list(struct element *left, struct element *right);
struct element *merge_sort(struct element *top)
{
    int num = 0;
    struct element *p;
    p = top;
    while (p != NULL)
    {
        p = p->next;
        num++;
    }
    return merge_sort1(top, num);
}

struct element *merge_list(struct element *left, struct element *right)
{
    struct element top;
    struct element *rear = &top;
    while (left != NULL && right != NULL)
    {
        if (left->data.key <= right->data.key)
        {
            rear->next = right;
            rear = left;
            left = left->next;
        }
        else
        {
            rear->next = right;
            rear = right;
            right = right->next;
        }
    }
    if (left != NULL)
        rear->next = left;
    else if (right != NULL)
        rear->next = right;
    return top.next;
}

// マージソート
struct element *merge_sort1(struct element *list, int num)
{
    if (num == 1)
    {
        list->next = NULL;
        return list;
    }
    else
    {
        int m = num / 2;
        struct element *right = list;
        for (int i = 0; i < m; i++)
            right = right->next;
        return merge_list(merge_sort1(list, m), merge_sort1(right, num - m));
    }
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {15, 'j'}};
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
