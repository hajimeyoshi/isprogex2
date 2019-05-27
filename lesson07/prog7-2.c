/*********************************************
  prog7-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct element {
    int value;
    struct element *next;
};

struct queue {
    struct element *top;
    struct element *rear;
    int size;
};

struct queue *create_queue();
struct element *create_element(int value);
void print_queue(struct queue *queue);
int size_of_queue(struct queue *queue);

void enqueue(struct queue *queue, struct element *elem);
struct element *dequeue(struct queue *queue);
struct element *peek(struct queue *queue);
int is_empty(struct queue *queue);

struct queue *create_queue()
{
    struct queue *new;
    
    new = (struct queue *)malloc(sizeof(struct queue));
    new->top = NULL;
    new->rear = NULL;
    new->size = 0;

    return new;
}

struct element *create_element(int value)
{
    struct element *new;
    
    new = (struct element *)malloc(sizeof(struct element));
    new->value = value;
    new->next = NULL;

    return new;
}

void print_queue(struct queue *queue)
{
    struct element *p;

    printf("Queue contain ");
    p = queue->top;
    while(p != NULL){
        printf("%d",p->value);
        p = p->next;
    }
    printf("\n");
}

int size_of_queue(struct queue *queue)
{
    struct element *p;
    int num;

    num = 0;
    p = queue->top;
    while(p != NULL){
        num++;
        p = p->next;
    }
    return num;
}

void enqueue(struct queue *queue, struct element *elem)
{
    if(queue->top == NULL){
        queue->top = elem;
    }else{
        queue->rear->next = elem;
    }
    queue->rear = elem;
    queue->size++;
}

struct element *dequeue(struct queue *queue)
{
    struct element *e;

    e = queue->top;
    if(e != NULL){
        queue->top = queue->top->next;
        queue->size--;
    }
    return e;
}

struct element *peek(struct queue *queue)
{
    return queue->top;
}

int is_empty(struct queue *queue)
{
    if(queue->size == 0){
        return 1;
    }else{
        return 0;
    }
}

/*=============================================*/

void test1()
{
    struct queue *queue = create_queue();
    assert(is_empty(queue));

    enqueue(queue, create_element(10));
    assert(queue->top->value == 10);
    assert(peek(queue)->value == 10);
    assert(!is_empty(queue));
    assert(size_of_queue(queue) == 1);

    print_queue(queue);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct queue *queue = create_queue();

    enqueue(queue, create_element(10));
    enqueue(queue, create_element(20));
    assert(queue->top->value == 10);
    assert(queue->top->next->value == 20);
    assert(peek(queue)->value == 10);
    assert(!is_empty(queue));
    assert(size_of_queue(queue) == 2);

    print_queue(queue);
    printf("Success: %s\n", __func__);
}

void test3()
{
    struct queue *queue = create_queue();

    enqueue(queue, create_element(10));
    enqueue(queue, create_element(20));

    assert(dequeue(queue)->value == 10);
    assert(queue->top->value == 20);
    assert(peek(queue)->value == 20);
    assert(size_of_queue(queue) == 1);

    print_queue(queue);
    printf("Success: %s\n", __func__);
}

void test4()
{
    struct queue *queue = create_queue();

    enqueue(queue, create_element(10));
    enqueue(queue, create_element(20));

    dequeue(queue);

    enqueue(queue, create_element(30));
    assert(queue->top->value == 20);
    assert(queue->top->next->value == 30);
    assert(peek(queue)->value == 20);
    assert(size_of_queue(queue) == 2);

    print_queue(queue);
    printf("Success: %s\n", __func__);
}

void test5()
{
    struct queue *queue = create_queue();

    enqueue(queue, create_element(10));
    enqueue(queue, create_element(20));

    dequeue(queue);
    dequeue(queue);
    assert(is_empty(queue));

    assert(peek(queue) == NULL);
    assert(dequeue(queue) == NULL);

    print_queue(queue);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}
