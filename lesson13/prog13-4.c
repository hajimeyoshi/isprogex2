/*********************************************
  prog13-4.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree-common.h"

void traverse_dfs_inorder(struct node *node, struct queue *queue);

int is_binary_search_tree(struct tree *tree);

struct data *search(struct tree *tree, int key);
int insert(struct tree *tree, struct data data);
int delete (struct tree *tree, int key);

void traverse_dfs_inorder(struct node *node, struct queue *queue)
{
    if (node == NULL)
    {
        return;
    }
    traverse_dfs_inorder(node->left, queue);
    enqueue(queue, node);
    traverse_dfs_inorder(node->right, queue);
}

int is_binary_search_tree(struct tree *tree)
{
    struct queue *queue = create_queue(MAX_NODE_NUM);
    int pre;
    int n;
    traverse_dfs_inorder(tree->root, queue);
    pre = dequeue(queue)->data->key;
    while (queue->rear - queue->top != 0)
    {
        n = dequeue(queue)->data->key;
        if (pre > n)
        {
            return 0;
        }
    }
    return 1;
}

struct data *search(struct tree *tree, int key)
{
    struct node *p;
    p = tree->root;
    while (p != NULL)
    {
        if (p->data->key == key)
        {
            return p->data;
        }
        if (p->data->key > key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return NULL;
}

int insert(struct tree *tree, struct data data)
{
    if (search(tree, data.key) != NULL)
    {
        return 0;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = (struct data *)malloc(sizeof(struct data));
    *(new->data) = data;
    new->left == NULL;
    new->right == NULL;
    struct node *p;

    p = tree->root;
    while (p != NULL)
    {
        if (p->data->key > data.key)
        {
            if (p->left == NULL)
            {
                p->left == new;
                return 1;
            }
            p = p->left;
        }
        else
        {
            if (p->right == NULL)
            {
                p->right == new;
                return 1;
            }
            p = p->right;
        }
    }
}

int delete (struct tree *tree, int key)
{
    if (search(tree, key) == NULL)
    {
        return 0;
    }
    struct node *taparent;
    struct node *target;
    struct node *chparent;
    struct node *child;
    target = tree->root;
    if (target->data->key == key)
    {
        if (target->left == NULL)
        {
            tree->root = target->right;
            return 1;
        }
        else
        {
            chparent = target;
            child = target->left;
            while (child->right != NULL)
            {
                chparent = child;
                child = child->right;
            }
            tree->root = child;
            chparent->right = NULL;
        }
    }
    taparent = target;
    while (target != NULL)
    {
        if (taparent->data->key == key)
        {
            if (target->left == NULL)
            {
                taparent = target->right;
                return 1;
            }
            else
            {
                chparent = target;
                child = target->left;
                while (child->right != NULL)
                {
                    chparent = child;
                    child = child->right;
                }
                tree->root = child;
                chparent->right = NULL;
            }
        }
        else if (target->data->key > key)
        {
            taparent = target;
            target = target->left;
        }
        else
        {
            taparent = target;
            target = target->right;
        }
    }
    return NULL;
}

/*=============================================*/

void test1()
{
    struct data data[] = {
        {21, 'a'}, {33, 'b'}, {31, 'c'}, {14, 'd'}, {20, 'e'}, {1, 'f'}, {24, 'g'}, {12, 'h'}, {10, 'i'}, {17, 'j'}};
    int num = sizeof(data) / sizeof(data[0]);

    struct tree *tree = create_tree();
    int i;
    for (i = 0; i < num; i++)
    {
        insert(tree, data[i]);
    }

    assert(is_binary_search_tree(tree));
    assert(search(tree, 12)->value = 'h');

    print(tree);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
