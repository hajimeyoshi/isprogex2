/*********************************************
  prog6-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_MAX_SIZE 30

struct queue {
    int data[QUEUE_MAX_SIZE];
    int top;
    int rear;
};

struct queue *create_queue();
void print_quque(struct queue *queue);
int size_of_queue(struct queue *queue);

struct queue *create_queue()
{
    return NULL;
}

void print_queue(struct queue *queue)
{
}

int size_of_queue(struct queue *queue)
{
    return 0;
}

/*=============================================*/

void test1()
{
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);

    queue->data[0] = 10;
    queue->rear = 1;
    assert(queue->data[0] == 10);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);    

    queue->data[1] = 20;
    queue->rear = 2;
    assert(queue->data[0] == 10);
    assert(queue->data[1] == 20);
    assert(size_of_queue(queue) == 2);
    print_queue(queue);

    queue->top = 1;
    assert(queue->data[1] == 20);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
