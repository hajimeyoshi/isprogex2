/*********************************************
  prog8-5.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort-common.h"
#include "measurement.h"

void bubble_sort(struct data data[], int num)
{
    int i,j;
    struct data temp;

    for(i = 0;i < num -1; i++){
        for(j = num - 1; j > i; j--){
            if(data[j].key < data[j-1].key){
                temp = data[j];
                data[j] = data[j-1];
                data[j-1] = temp;
            }
        }
    }
} 

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

void insertion_sort(struct data data[], int num)
{
    /* Code copied from prog8-4.c */
} 

int main()
{
    measure("BUBBLE SORT", bubble_sort);
    measure("SELECTION SORT", selection_sort);
    measure("INSERION SORT", insertion_sort);

    return 0;
}
