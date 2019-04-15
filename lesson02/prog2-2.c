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
  if(num != 0)
    return sum;
  else
    return 0;
}


int *reverse(int *data, int num)
{
  int i;
  int *data2 = (int*)calloc(num,sizeof(int));
  if(num != 0){
    for(i = 0; i < num; i++){
      *(data2+i) = *(data+num-i-1);
    }
    return data2;
  }else{
    return NULL;
  }
}    

/*=============================================*/

void test1()
{
    int data[10] = { 10, 20, 30, 40,50,60,70,80,90,100 };;
    int num = 6;

    assert(get(data, num, 0) == 10);
    assert(get(data, num, 1) == 20);
    assert(get(data, num, 2) == 30);
    assert(get(data, num, 3) == 40);

    print(data, num);
    printf("Success: %s\n", __func__);
}

void test2()
{
  int data[10] = { 10, 20, 30, 40,50,60,70,80,90,100 };;
    int num = 6;
    int index = 5;

    assert(get(data, num,index) == 60);

    print(data, num);
    printf("%d",data[index]);
    printf("Success: %s\n", __func__);
}

void test3()
{
    int data[10] = { 10, 20, 30, 40,50,60,70,80,90,100 };
    int num = 4;
    int total;
    assert((total = sum(data, num)) == 100);

    print(data, num);
    printf("%d",total);
    printf("Success: %s\n", __func__);
}

void test4()
{
  int data[10] = { 10, 20, 30, 40,50,60,70,80,90,100 };
    int num = 4;
    
    int *data2 = reverse(data, num);
    print(data,num);
    printf("\n");
    print(data2,num);
    /*
    assert(get(data2, num, 0) == 10);
    assert(get(data2, num, 1) == 20);
    assert(get(data2, num, 2) == 30);
    assert(get(data2, num, 3) == 40);
    */
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    
    return 0;
}
