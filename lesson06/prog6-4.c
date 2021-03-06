/*********************************************
  prog6-4.c
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
void print_queue(struct queue *queue);
int size_of_queue(struct queue *queue);

int enqueue(struct queue *queue, int value);
int dequeue(struct queue *queue);
int peek(struct queue *queue);
int is_empty(struct queue *queue);

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

int enqueue(struct queue *queue, int value)
{
    if(queue->rear < QUEUE_MAX_SIZE){
        queue->data[queue->rear] = value;
        queue->rear++;
        return 1;
    }else{
        return 0;
    }
}

int dequeue(struct queue *queue)
{
    int num;
    if(is_empty(queue)){
        return -1;
    }else{
        num = queue->data[queue->top];
        queue->top++;
        return num;
    }
}

int peek(struct queue *queue)
{
    if(is_empty(queue)){
        return -1;
    }else{
        return queue->top;
    }
}

int is_empty(struct queue *queue)
{
    if(queue->top == queue->rear){
        return 1;
    }else{
        return 0;
    }
}

/*=============================================*/

void test1()
{
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);

    enqueue(queue,50);
    assert(queue->data[0] == 50);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);    

    enqueue(queue,100);
    assert(queue->data[0] == 50);
    assert(queue->data[1] == 100);
    assert(size_of_queue(queue) == 2);
    print_queue(queue);

    printf("dequeue: %d\n",dequeue(queue));
    assert(queue->data[1] == 100);
    assert(size_of_queue(queue) == 1);
    print_queue(queue);

    printf("Success: %s\n", __func__);
}

void test2()
{
    int i;
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);
    
    for(i = 0; i < QUEUE_MAX_SIZE; i++){
        enqueue(queue,i);
    }
    assert(size_of_queue(queue) == QUEUE_MAX_SIZE);
    assert(enqueue(queue,30) == 0);

    printf("Success: %s\n", __func__);
}

void test3()
{
    int i;
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);
    assert(dequeue(queue) == -1);

    printf("Success: %s\n", __func__);
}

void test4()
{
    int i;
    struct queue *queue = create_queue();
    
    assert(size_of_queue(queue) == 0);
    print_queue(queue);
    assert(peek(queue) == -1);

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

