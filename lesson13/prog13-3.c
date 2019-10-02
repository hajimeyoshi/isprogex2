/*********************************************
  prog13-3.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree-common.h"

void traverse_dfs_inorder(struct node *node, struct queue *queue);

int is_binary_search_tree(struct tree *tree);

struct tree *create_testtree();

void traverse_dfs_inorder(struct node *node, struct queue *queue)
{
    if(node == NULL){
        return;
    }
    traverse_dfs_inorder(node->left,queue);
    enqueue(queue,node);
    traverse_dfs_inorder(node->right,queue);
}

int is_binary_search_tree(struct tree *tree)
{
    struct queue *queue = create_queue(MAX_NODE_NUM);
    int pre;
    int n;
    traverse_dfs_inorder(tree->root,queue);
    pre = dequeue(queue)->data->key;
    while(queue->rear - queue->top != 0){
        n = dequeue(queue)->data->key;
        if(pre > n){
            return 0;
        }
    }
    return 1;
}

/*=============================================*/

struct tree *create_testtree()
{
    struct tree *tree = create_tree();

    struct node *n1 = create_node(15, 'j');
    tree->root = n1;

    struct node *n2 = create_node(12, 'h');
    struct node *n3 = create_node(21, 'a');
    n1->left = n2;
    n1->right = n3;

    struct node *n4 = create_node(10, 'i');
    struct node *n5 = create_node(14, 'd');
    n2->left = n4;
    n2->right = n5;

    struct node *n6 = create_node(1, 'f');
    n4->left = n6;

    struct node *n7 = create_node(20, 'e');
    struct node *n8 = create_node(31, 'c');
    n3->left = n7;
    n3->right = n8;

    struct node *n9 = create_node(24, 'g');
    struct node *n10 = create_node(33, 'b');
    n8->left = n9;
    n8->right = n10;
    
    return tree;
}

void test1()
{
    struct tree *tree = create_testtree();

    struct queue *queue = create_queue(MAX_NODE_NUM);

    assert(is_binary_search_tree(tree) == 1);
    
    print(tree);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    return 0;
}
