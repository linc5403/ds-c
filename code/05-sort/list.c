/*
 * ============================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  链表的实现
 *
 *        Version:  1.0
 *        Created:  02/25/2020 11:47:33 AM
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

#include "list.h"

List* init_list(void) {
    List* plist = malloc(sizeof(List));
    return plist;
}


/*---------------------------------------------------------------------------
 *  新增加一个节点，其值是val，位置在p之后
 *---------------------------------------------------------------------------*/
void insert_after_position(List* l, int val, Node* p) {
}

/*---------------------------------------------------------------------------
 *  新增加一个节点，其值是val，位置在p之前
 *---------------------------------------------------------------------------*/
void insert_before_position(List* l, int val, Node* p);

void insert_at_head(List* l, int val) {
    Node* head = l->head;
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->sorted = 0;
    if (head == NULL) {
        new_node->pre = NULL;
        new_node->next = NULL;
        l->head = new_node;
    } else {
        new_node->pre = NULL;
        new_node->next = head;
        l->head = new_node;
    }
    return;
}

void insert_at_tail(List* l, int val) {
    Node* head = l->head;
    Node* new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->sorted = 0;

    if (head == NULL) {
        new_node->pre = NULL;
        new_node->next = NULL;
        l->head = new_node;
    } else {
        while(head->next != NULL) {
            head = head->next;
        }
        head->next = new_node;
        new_node->pre = head;
        new_node->next = NULL;
    }
    return;
}


/*---------------------------------------------------------------------------
 *  交换first和second两个节点的顺序
 *---------------------------------------------------------------------------*/

void swap_nodes(List* l, Node* a, Node* b) {
    Node* a_pre = a->pre;
    Node* a_next = a->next;
    Node* b_pre = b->pre;
    Node* b_next = b->next;

    if (a_next == b) {
        swap_adj_nodes(l, a, b);
    } else if (b_next == a) {
        swap_adj_nodes(l, b, a);
    } else {
        // a和b不相邻
        if (a_pre == NULL) {
            // a是head节点
            l->head = b;
            b->pre = NULL;
            b_pre->next = a;
        } else if (b_pre == NULL) {
            l->head = a;
            a->pre = NULL;
            a_pre->next = b;
        } else {
            a_pre->next = b;
            b_pre->next = a;
            a->pre = b_pre;
            b->pre = a_pre;
        }
        b->next = a_next;
        a->next = b_next;
        if (b_next) {
            b_next->pre = a;
        }
        if (a_next) {
            a_next->pre = b;
        }
    }
}

void swap_adj_nodes(List* l, Node* first, Node* second) {
    Node* first_pre = first->pre;
    Node* sec_next = second->next;

    // first_pre的next应指向second
    if (first_pre != NULL) {
        first_pre->next = second;
        second->next = first;
        first->next = sec_next;
    } else {
        // first节点是head节点
        l->head = second;
        second->next = first;
        first->next = sec_next;
    }
    
    if (sec_next) {
        sec_next->pre = first;
    }
    first->pre = second;
    second->pre = first_pre;
}

void reverse_print_list(List* l) {
    int i = 0;
    Node* h = l->head;
    if (h == NULL) {
        printf("empty list!\n");
    } else {
        while(h->next) {
            h = h->next;
        }
        while(h) {
            printf("%4d", h->val);
            h = h->pre;
            i++;
            if (i == 20) {
                break;
            }
        }
        printf("\n");
    }
}


void print_list(List* l) {
    int i = 0;
    Node* h = l->head;
    if (h == NULL) {
        printf("empty list!\n");
    } else {
        while(h) {
            i++;
            printf("%4d", h->val);
            h = h->next;
            if (i%10 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }
}
