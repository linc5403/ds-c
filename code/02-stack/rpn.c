/*
 * ============================================================================
 *
 *       Filename:  rpn.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2020 11:00:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

char *INPUT[] =  { "4", "13", "5", "/", "+" };

int evalRPN(char ** tokens, int tokensSize);
int is_operand(char* a);

int main() {
    unsigned int inputSize = sizeof(INPUT) / sizeof(INPUT[0]);
    int result = evalRPN(INPUT, inputSize);
    printf("result is %d\n", result);
    return 0;
}

int evalRPN(char ** tokens, int tokensSize){
    Stack* head = init_statck();
    for (int i = 0; i < tokensSize; i++) {
        if (is_operand(tokens[i])) {
            // 是操作数, 入栈
            int t = atoi(tokens[i]);
            push(head, t);
        } else {
            // 是操作符
            // 出栈计算并入栈
            int a1 = pop(head);
            int a0 = pop(head);
            int r = 0;
            switch (tokens[i][0]) {
                case '+':
                    r = a0 + a1;
                    break;
                case '-':
                    r = a0 - a1;
                    break;
                case '*':
                    r = a0 * a1;
                    break;
                case '/':
                    r = a0 / a1;
                    break;
                default:
                    printf("error\n");
                    exit(-1);
            }
            push(head, r);
        }
    }
    int result = pop(head);
    free_stack(head);
    return result;
}


/* 是操作数则返回1，是操作符则返回0 */
int is_operand(char* a) {
    if (strlen(a) > 1)
        return 1;
    switch (a[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 0;
        default:
            return 1;

    }
}
