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
#include "util.h"

char *INPUT[] =  { "1", "+", "2", "-", "3", "+", "4", "-", "5"};
// char *INPUT[] =  { "3", "+", "4", "*", "2", "-", "5", "*", "3"};

StrStack* middle2post(char** input, unsigned int input_len);

int main() {
    unsigned int input_len = sizeof(INPUT) / sizeof(INPUT[0]);
    // 中缀转为后缀
    StrStack* post = middle2post(INPUT, input_len);
    display_stack(post);
    // 后缀转为树
    BinaryTree* tree = create_tree();
    while(! is_empty(post)) {
        insert(tree, pop(post));
    }

    display_tree(tree->root);
    printf("\n");

    return 0;
}



/* 
 * ===  FUNCTION  =============================================================
 *         Name:  middle2post
 *  Description:  中缀表达式转后缀表达式
 * ============================================================================
 */
StrStack* middle2post(char* input[], unsigned int input_len) {
    StrStack* operator = init_stack();
    StrStack* post = init_stack();
    for (int i = 0; i < input_len; i++) {
        if (is_operand(input[i])) {
            // 操作数的处理
            // 1. 入后缀表达式栈
            push(post, input[i]);
            // 2. 如果操作符栈里面的top元素优先级比下面一个元素高，则将该操作符出栈并防到post栈中
            if (higherPriority(operator)) {
                char* t = pop(operator);
                push(post, t);
            }
        } else {
            // 操作符直接入operator栈
            push(operator, input[i]);
        }
    }
    // 将operator中的所有元素弹出到post栈中
    while(!is_empty(operator)) {
        char* t = pop(operator);
        push(post, t);
    }

    // 释放operator栈
    free_stack(operator);
    return post;
}




