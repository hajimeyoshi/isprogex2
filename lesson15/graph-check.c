/*
  graph-check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "graph-common.h"

struct graph *create_graph()
{
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    if (graph == NULL) {
        fprintf(stderr, "Not enough memory\n");
        return NULL;
    }

    int i, j;
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        graph->vertex[i] = NULL;

        for (j = 0; j < MAX_VERTEX_NUM; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    graph->vertex_num = 0;
    graph->edge_num = 0;
    return graph;
}

void print_matrix(struct graph *graph)
{
    if (graph->vertex_num == 0) {
        printf("No vertex\n");
        return;
    }

    int i, j;
    for (i = 0; i < graph->vertex_num; i++) {
        for (j = 0; j < graph->vertex_num; j++) {
            printf(" %d", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void print_list(struct graph *graph)
{
    if (graph->vertex_num == 0) {
        printf("No vertex\n");
        return;
    }

    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        struct vertex *v = graph->vertex[i];
        printf(" %d :", v->no);
        struct adjacence *adj = v->adj;
        while (adj != NULL) {
            v = graph->vertex[adj->no];
            printf(" -> %d", v->no);
            adj = adj->next;
        }
        printf("\n");
    }
}

void print_trajectory(struct vertex **vertex)
{
    if (vertex[0] == NULL) {
        printf("No vertex\n");
        return;
    }

    printf(" %d", vertex[0]->no);
    int i;
    for (i = 1; i < MAX_VERTEX_NUM; i++) {
        if (vertex[i] != NULL) {
            printf(" -> %d", vertex[i]->no);
        }
    }
    printf("\n");
}
