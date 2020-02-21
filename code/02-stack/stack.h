/*
 * ============================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2020 10:11:20 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

#ifndef _STACK_H_
#define _STACK_H_

typedef struct stack{
    int elem;
    struct stack *next;
} Stack;

Stack* init_statck(void);
void free_stack(Stack* head);
int push(Stack* head, int elem);
int pop(Stack* head);
int top(Stack* head);
int is_full(Stack* head);
int is_empty(Stack* head);

#endif
