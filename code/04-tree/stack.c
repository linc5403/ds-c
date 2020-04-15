/*
 * ============================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 12:44:17 PM
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

#include "stack.h"
#include "util.h"

StrStack* init_stack(void) {
    StrStack* h = malloc(sizeof(StrStack));
    h->head = NULL;
    return h;
}

void push(StrStack* s, char* val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = s->head;
    s->head = new_node;
}

char* pop(StrStack* s) {
    Node* t = s->head;
    s->head = t->next;
    char* t_s = t->val;
    free(t);
    return t_s;
}

int is_empty(StrStack* stack) {
    return (stack->head == NULL);
}

char* peep(StrStack* stack) {
    if (stack->head) {
        return stack->head->val;
    } else {
        return NULL;
    }
}

int higherPriority(char* curr, StrStack* stack) {
    Node* head = stack->head;
    if (head == NULL) {
        // 空栈，返回0
        return 0;
    }

    char* top = peep(stack);

    // 只有当curr的运算符是*和/，top是+或-的时候才返回0
    if ((curr[0] == '*' || curr[0] == '/') && (top[0] == '+' || top[0] == '-')) {
        return 0;
    }
    return 1;
}

void free_stack(StrStack* s) {
    while (! is_empty(s)) {
        pop(s);
    }
    free(s);
}


void display_stack(StrStack* s) {
    Node* t = s->head;
    while(t) {
        printf("%s ", t->val);
        t = t->next;
    }
    printf("\n");
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
            // 入后缀表达式栈
            push(post, input[i]);
        } else {
            // 操作符需要判断是否比栈里面的优先级高
            // 如果栈里面的元素优先级更高需要将栈里的元素弹出到后缀栈
            while( higherPriority(input[i], operator) ) {
                char* out = pop(operator);
                push(post, out);
            }
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

