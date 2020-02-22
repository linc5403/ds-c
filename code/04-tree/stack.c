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

int higherPriority(StrStack* stack) {
    Node* head = stack->head;
    if (head == NULL) {
        // 空栈，返回0
        return 0;
    }

    if (head->next == NULL) {
        // 只有一个节点，返回0
        return 0;
    }

    char* top = head->val;
    char* sec = head->next->val;

    // 只有当top的运算符是*和/，下一个节点是+或-的时候才返回1
    if ((top[0] == '*' || top[0] == '/') && (sec[0] == '+' || sec[0] == '-')) {
        return 1;
    }
    return 0;
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
