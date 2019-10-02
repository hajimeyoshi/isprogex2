/*
  heaptree-common.h
*/

#ifndef HEAPTREE_COMMON_H
#define HEAPTREE_COMMON_H

#include <stdio.h>

#define MAX_NODE_NUM 30

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

extern struct tree *create_tree();
extern struct node *create_node(int value);
extern void print_tree(struct tree *tree);

extern struct queue *traverse_bfs(struct tree *tree);
extern void print_bfs(struct tree *tree);

#endif /* HEAPTREE_COMMON_H */
