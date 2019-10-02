/*********************************************
  prog15-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph-common.h"
#include "stack.h"

struct vertex *add_vertex(struct graph *graph, char label);
void add_edge(struct graph *graph, struct vertex *src, struct vertex *dst);
struct vertex **visit_dfs(struct graph *graph, struct vertex *start);
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

struct vertex **visit_dfs(struct graph *graph, struct vertex *start)
{
    return NULL;
}

/*=============================================*/

int main()
{
    return 0;
}
