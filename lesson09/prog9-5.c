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

void quick_sort(struct data data[], int num)
{
    /* Copied from prog9-1.c */
}

void merge_sort(struct data data[], int num)
{
    /* Copied from prog9-2.c */
}

void shell_sort(struct data data[], int num)
{
    /* Copied from prog9-4.c */
} 

int main()
{
    measure("QUICK SORT", quick_sort);
    measure("MERGE SORT", merge_sort);
    measure("SHELL SORT", shell_sort);

    return 0;
}
