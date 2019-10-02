/*********************************************
  prog10-2.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heaptree-common.h"
#include "queue.h"

int is_complete_binary_tree(struct tree *tree);
int is_heap_tree(struct tree *tree);

int is_complete_binary_tree(struct tree *tree)
{
    struct queue *queue = traverse_bfs(tree);

    int flag = 0;
    int i;
    for (i = 0; i < size_of_queue(queue); i++)
    {
        struct node *node = get_in_queue(queue, i);
        if (node->value != -1 && flag == 1)
        {
            return 0;
        }
        if (node->value == -1)
        {
            flag = 1;
        }
    }
    return 1;
}

int is_heap_tree(struct tree *tree)
{
    struct queue *queue = traverse_bfs(tree);

    int flag = 0;
    int i;
    for (i = 0; i < size_of_queue(queue); i++)
    {
        struct node *node = get_in_queue(queue, i);
        if (node->value != -1 && flag == 1)
        {
            return 0;
        }
        if (node->value == -1)
        {
            flag = 1;
        }
        if (node->left != NULL)
        {
            if (node->left->value != -1)
            {
                if (node->value >= node->left->value)
                {
                    return 0;
                }
            }
        }
        if (node->right != NULL)
        {
            if (node->right->value != -1)
            {
                if (node->value >= node->right->value)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}

/*=============================================*/

void test1()
{
    struct tree *new = create_tree();
    struct node *node1 = create_node(1);
    struct node *node2 = create_node(2);
    struct node *node3 = create_node(3);
    struct node *node4 = create_node(4);
    struct node *node5 = create_node(5);

    new->root = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    print_tree(new);
    assert(is_heap_tree(new) == 1);
    printf("Success: %s\n", __func__);
}

void test2()
{
    struct tree *new = create_tree();
    struct node *node1 = create_node(1);
    struct node *node2 = create_node(10);
    struct node *node3 = create_node(3);
    struct node *node4 = create_node(4);
    struct node *node5 = create_node(5);

    new->root = node1;
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    print_tree(new);
    assert(is_heap_tree(new) == 0);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();
    test2();

    return 0;
}
