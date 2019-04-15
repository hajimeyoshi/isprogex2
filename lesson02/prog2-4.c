/*********************************************
  prog2-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct data {
    char key;
    int value;
};

void print(struct data *data[], int num);
void plus(struct data *data[], int num, int value);

void print(struct data *data[], int num)
{
  int i;
  struct data *ptr;
  ptr = data;
  for(i = 0; i < num; i++){
    printf("%c %d \n",ptr->key,ptr->value);
    ptr++;
  }
}

void plus(struct data *data[], int num, int value)
{
  int i;
  struct data *ptr;
  ptr = data;
  for(i = 0; i < num; i++){
    ptr->value += value;
    ptr++;
  }
}

/*=============================================*/
void test1()
{
    struct data data[4] = {{ 'a', 10 }, { 'b', 20 }, { 'c', 30 }, { 'd', 40 }};
    struct data *ptr;
    ptr = data;
    int num = 4;
    print(ptr, num);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct data data[4] = {
        { 'a', 10 }, { 'b', 20 }, { 'c', 30 }, { 'd', 40 }
    };
    struct data *ptr;
    ptr = data;
    int num = 4;
    
    plus(ptr, num, 4);
    assert(data[2].value == 34);
    
    print(ptr, num);
    printf("Success: %s\n", __func__);
}

int main()
{
  test1();
  test2();
    return 0;
}
