/*
 * ============================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/25/2020 11:47:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

#ifndef _LIST_H_
#define _LIST_H_

typedef struct node {
    int val;
    struct node* next;
    struct node* pre;
    char sorted;
} Node;

typedef struct {
    Node* head;
}List;



List* init_list(void);
void insert_after_position(List* l, int val, Node* p);
void insert_before_position(List* l, int val, Node* p);
void insert_at_head(List* l, int val);
void insert_at_tail(List* l, int val);
void swap_nodes(List* l, Node* a, Node* b);
void swap_adj_nodes(List* l, Node* a, Node* b);
void print_list(List* l);
void reverse_print_list(List* l);

#endif
