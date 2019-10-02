/*********************************************
  prog15-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph-common.h"

struct vertex *add_vertex(struct graph *graph, char label);
void add_edge(struct graph *graph, struct vertex *src, struct vertex *dst);
int get_vertex_num(struct graph *graph);
int get_edge_num(struct graph *graph);

struct vertex *add_vertex(struct graph *graph, char label)
{
    return NULL;
}

void add_edge(struct graph *graph, struct vertex *src, struct vertex *dst)
{
}

int get_vertex_num(struct graph *graph)
{
    return 0;
}

int get_edge_num(struct graph *graph)
{
    return 0;
}

/*=============================================*/

void test1()
{
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
