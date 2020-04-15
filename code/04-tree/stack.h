/*
 * ============================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 12:44:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

#ifndef _STRING_STACK_H_
#define _STRING_STACK_H_

typedef struct node {
    char* val;
    struct node* next;
} Node;

typedef struct strStack {
    Node* head;
} StrStack;

StrStack* init_stack(void);
void push(StrStack* s, char* val);
char* pop(StrStack* s);
int is_empty(StrStack* s);
char* peep(StrStack* s);
void free_stack(StrStack* s);
void display_stack(StrStack* s);


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  higherPriority
 *  Description:  stack中栈顶操作符比下面的操作符优先级高则返回1，否则返回0
 * ============================================================================
 */
int higherPriority(char* curr, StrStack* stack);
StrStack* middle2post(char* input[], unsigned int input_len);

#endif
