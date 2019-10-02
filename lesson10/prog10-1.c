/*********************************************
  prog10-1.c
    Student ID: 
    Name:
**********************************************/

#include <stdio.h>
#include <assert.h>
#include "heaptree-common.h"


/*=============================================*/

void test1()
{
    struct tree *new = create_tree();
    struct node *node1 = create_node(10);
    struct node *node2 = create_node(20);
    struct node *node3 = create_node(30);

    new->root = node1;
    node1->left = node2;
    node1->right = node3;
    print_tree(new);
    printf("Success: %s\n", __func__);
}

int main()
{
    test1();

    return 0;
}
