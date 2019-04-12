/*********************************************
  prog2-3.c
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

void print(struct data data[], int num);
struct data *get(struct data data[], int num, int index);

void print(struct data data[], int num)
{
}

struct data *get(struct data data[], int num, int index)
{
    return NULL;
}

/*=============================================*/

void test1()
{
    struct data data[4] = {
        { 'a', 10 }, { 'b', 20 }, { 'c', 30 }, { 'd', 40 }
    };
    int num = sizeof(data) / sizeof(data[0]);

    assert(get(data, num, 1)->value == 20);

    print(data, num);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
