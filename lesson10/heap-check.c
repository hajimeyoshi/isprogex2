/*
  heap-check.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap-common.h"
#include "heaptree-common.h"
#include "queue.h"

struct tree *create_tree()
{
    struct tree *tree = (struct tree *)malloc(sizeof(struct tree));
    if (tree == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        tree->root = NULL;
    }
    return tree;
}

struct node *create_node(int value)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node == NULL) {
        fprintf(stderr, "Not enough memory\n");
    } else {
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void print_node(struct node *node, int indent)
{
    printf("\n");
    if (node->left != NULL) {
        int s;
        for (s = 0; s < indent; s++) {
            printf(" ");
        }
        printf("%d(L)", node->left->value);
        print_node(node->left, indent + 2);
    }

    if (node->right != NULL) {
        int s;
        for (s = 0; s < indent; s++) {
            printf(" ");
        }
        printf("%d(R)", node->right->value);
        print_node(node->right, indent + 2);
    }
}

void print_tree(struct tree *tree)
{
    if (tree->root == NULL) {
        printf("No node\n");
        return;
    }

    printf("%d", tree->root->value);
    print_node(tree->root, 2);
}

struct queue *traverse_bfs(struct tree *tree)
{
    if (tree->root == NULL) {
        return 0;
    }

    struct node *dummy = create_node(-1);
    struct queue *queue = create_queue(MAX_NODE_NUM);
    struct queue *seq = create_queue(MAX_NODE_NUM);

    enqueue(queue, tree->root);
    while (!is_empty_queue(queue)) {
        struct node *node = dequeue(queue);
        enqueue(seq, node);

        if (node != dummy) {
            if (node->left != NULL) {
                enqueue(queue, node->left);
            } else {
                enqueue(queue, dummy);
            }
            if (node->right != NULL){
                enqueue(queue, node->right);
            } else {
                enqueue(queue, dummy);
            }
        }
    }
    return seq;
}

void print_bfs(struct tree *tree)
{
    struct queue *seq = traverse_bfs(tree);
    int num = size_of_queue(seq);

    int i;
    for (i = 0; i < num; i++) {
        struct node *node = get_in_queue(seq, i);    
        printf(" %d", node->value);
    }
    printf("\n");
}

void print(struct data data[], int num)
{
    if (num == 0) {
        printf("No element\n");
        return;
    }

    int i;
    for (i = 1; i <= num; i++) {
        printf(" %d:%c", data[i].key, data[i].value);
    }
    printf("\n");
}

int is_sorted(struct data data[], int num)
{
    int i;
    for (i = 1; i < num; i++) {
        if (data[i].key < data[i+1].key) {
            return 0;
        }
    }
    return 1;
}
