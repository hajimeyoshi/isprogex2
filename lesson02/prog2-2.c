/*********************************************
  prog2-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print(int *data, int num);
int get(int *data, int num, int index);
int sum(int *data, int num);
int *reverse(int *data, int num);

void print(int *data, int num)
{
  int i;
  for(i = 0; i < num; i++){
    printf("%d ",*(data+i));
  }
}

int get(int *data, int num, int index)
{
  if (num > index){
    return *(data+index);
  }else
    return -1;
}

int sum(int *data, int num)
{
  int i;
  int sum = 0;
  for(i = 0; i < num; i++)
    sum += *(data+i);
  if(sum > 0)
    return sum;
  else
    return -1;
}

int *reverse(int *data, int num)
{
    return NULL;
}    

/*=============================================*/

int main()
{
    return 0;
}
