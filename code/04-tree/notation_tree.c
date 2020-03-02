/*
 * ============================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 01:08:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "tree.h"

int main() {
    // char *INPUT[] =  { "1", "+", "2", "-", "3", "+", "4", "-", "5"};
    char *INPUT[] =  { "3", "+", "4", "*", "2", "-", "5", "*", "3"};
    unsigned int input_len = sizeof(INPUT) / sizeof(INPUT[0]);

    // 中缀转为后缀
    StrStack* post = middle2post(INPUT, input_len);
    display_stack(post);
    
    // 后缀转为树
    BinaryTree* tree = create_tree();
    while(! is_empty(post)) {
        insert(tree, pop(post));
    }

    printf("================中缀表达式==============\n");
    display_tree(tree->root);
    printf("\n");

    printf("================后缀表达式==============\n");
    display_tree_post(tree->root);
    printf("\n");

    printf("================树图（右旋90度）==============\n");
    print_tree(tree);
    printf("\n");
    int i = count_node(tree->root);
    printf("tree has %d nodes\n", i);
    return 0;
}