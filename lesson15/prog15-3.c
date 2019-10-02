/*********************************************
  prog14-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph-common.h"
#include "queue.h"

struct vertex *add_vertex(struct graph *graph, char label);
void add_edge(struct graph *graph, struct vertex *src, struct vertex *dst);
int get_vertex_num(struct graph *graph);
int get_edge_num(struct graph *graph);
struct vertex **visit_bfs(struct graph *graph, struct vertex *start);

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

struct vertex **visit_bfs(struct graph *graph, struct vertex *start)
{
    return NULL;
}

/*=============================================*/

int main()
{
    return 0;
}
