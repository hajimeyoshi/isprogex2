/*********************************************
  prog6-5.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define QUEUE_SIZE 30

struct queue {
    int data[QUEUE_SIZE];
    int top;
    int rear;
    int num;
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
    new->num = 0;

    return new;
}

void print_queue(struct queue *queue)
{
    int i;

    printf("Queue contain: ");
    for(i = 0; i < queue->num; i++){
        printf("%d ",queue->data[(queue->top + i)% QUEUE_SIZE]);
    }
    printf("\n");
}

int size_of_queue(struct queue *queue)
{
    return queue->num;
}

int enqueue(struct queue *queue, int value)
{
   if(queue->num < QUEUE_SIZE){
        queue->data[queue->rear] = value;
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        queue->num++;
        return 1;
    }else{
        return 0;
    }
}

int dequeue(struct queue *queue)
{
    int num;
    if(queue->num > 0){
        num = queue->data[queue->top];
        queue->top = (queue->top + 1) % QUEUE_SIZE;
        queue->num--;
        return num;
    }else{
        return -1;
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
    if(queue->num == 0){
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
    
    for(i = 0; i < QUEUE_SIZE; i++){
        enqueue(queue,i);
    }
    assert(size_of_queue(queue) == QUEUE_SIZE);
    assert(dequeue(queue) == 0);
    assert(enqueue(queue,30) == 1);
    print_queue(queue);

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
