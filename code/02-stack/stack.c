/*
 * ============================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2020 10:11:08 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack* init_stack(void) {
    Stack* head = malloc(sizeof(Stack));
    head->next = NULL;
    return head;
}


void free_stack(Stack* head) {
    Stack* t;
    while(head->next != NULL) {
        t = head->next;
        free(head);
        head = t;
    }
    free(head);
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  push
 *  Description:  将元素elem压栈
 *       Return:  成功-1；失败-0
 * ============================================================================
 */
int push(Stack* head, int elem) {
    Stack *new_node = malloc(sizeof(Stack));
    if (new_node == NULL) {
        // 分配内存失败
        return 0;
    }
    new_node->elem = elem;
    new_node->next = head->next;
    head->next = new_node;
    return 1;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  pop
 *  Description:  弹出栈顶节点, 返回该节点的元素值
 *                注意栈为空时应报错 
 * ============================================================================
 */
int pop(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    Stack* t = head->next;
    head->next = t->next;
    int elem = t->elem;
    free(t);
    return elem;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  top
 *  Description:  返回栈顶节点元素的值
 *                注意栈为空时应报错
 * ============================================================================
 */
int top(Stack* head) {
    if (is_empty(head)) {
        printf("stack is empty\n");
        return INT_MIN;
    }
    return head->next->elem;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  is_empty
 *  Description:  
 *       Return: 1: 为空； 0: 不为空  
 * ============================================================================
 */
int is_empty(Stack* head) {
    return (head->next == NULL)?1:0;
}

