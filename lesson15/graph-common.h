/*
  graph-common.h
*/

#ifndef GRAPH_COMMON_H
#define GRAPH_COMMON_H

#include <stdio.h>

#define MAX_VERTEX_NUM 30

struct adjacence {
    int no;
    struct adjacence *next;
};

struct vertex {
    int no;
    char label;
    struct adjacence *adj;
};

struct graph {
    struct vertex *vertex[MAX_VERTEX_NUM];
    int matrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vertex_num;
    int edge_num;
};

extern struct graph *create_graph();
extern void print_matrix(struct graph *graph);
extern void print_list(struct graph *graph);
extern void print_trajectory(struct vertex **vertex);

#endif /* GRAPH_COMMON_H */
