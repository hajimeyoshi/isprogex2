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
    struct queue *new;
    
    new = (struct queue *)malloc(sizeof(struct queue));
    new->top = 0;
    new->rear = 0;

    return new;
}

void print_queue(struct queue *queue)
{
    int i;

    printf("Queue contain: ");
    for(i = queue->top; i < queue->rear; i++){
        printf("%d ",queue->data[i]);
    }
    printf("\n");
}

int size_of_queue(struct queue *queue)
{
    return queue->rear - queue->top;
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

void test2()
{
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);

    queue->data[0] = 50;
    queue->rear = 1;
    assert(queue->data[0] == 50);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);    

    queue->data[1] = 100;
    queue->rear = 2;
    assert(queue->data[0] == 50);
    assert(queue->data[1] == 100);
    assert(size_of_queue(queue) == 2);
    print_queue(queue);

    queue->top = 1;
    assert(queue->data[1] == 100);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);

    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    return 0;
}
