/*********************************************
  prog2-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print(int data[], int num);
int get(int data[], int num, int index);
int sum(int data[], int num);

void print(int data[], int num){
  int i;
  for(i = 0; i < num; i++){
    printf("%d ",data[i]);
  }
}

int get(int data[], int num, int index)
{
  if (num > index){
    return data[index];
  }else
    return -1;
}

int sum(int data[], int num)
{
  int i;
  int sum = 0;
  for(i = 0; i < num; i++)
    sum += data[i];
  if(num != 0)
    return sum;
  else
    return 0;
}

/*=============================================*/

void test1()
{
    int data[4] = { 10, 20, 30, 40 };
    int num = sizeof(data) / sizeof(data[0]);

    assert(get(data, num, 0) == 10);
    assert(get(data, num, 1) == 20);
    assert(get(data, num, 2) == 30);
    assert(get(data, num, 3) == 40);

    print(data, num);
    printf("Success: %s\n", __func__);
}

void test2()
{
    int data[4] = { 10, 20, 30, 40 };;
    int index = 3;
    int num = sizeof(data) / sizeof(data[0]);

    assert(get(data, num, index) == 40);

    printf("%d",data[index]);
    printf("Success: %s\n", __func__);
}

void test3()
{
  int data[4] = {10,20,30,40};;
    int num = sizeof(data) / sizeof(data[0]);
    int total;
    assert((total = sum(data, num)) == 100);

    print(data, num);
    printf("%d",total);
    printf("Success: %s\n", __func__);
}
int main()
{
    test1();
    test2();
    test3();

    return 0;
}
