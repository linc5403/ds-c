/*
 * ============================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  提供链表的接口实现 - 创建，插入节点，打印链表
 *
 *        Version:  1.0
 *        Created:  03/01/2020 02:05:35 PM
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

// 插入排序
struct ListNode* insertionSortList(struct ListNode* head) {
    // 空链表
    if (head == NULL) {
        return head;
    }
    // 只有一个节点
    if (head->next == NULL) {
        return head;
    }
    // 两个及以上节点
    struct ListNode* p = head;

    while (p->next != NULL) {
        if (p->val > p->next->val) {
            struct ListNode* t = p->next;
            p->next = t->next;
            // 把t放到合适的位置
            // 从head开始，找到一个节点，这个节点的值比t小，这个节点的next比t大
            // 那么，把t放到这个节点的后面
            if (head->val > t->val) {
                t->next = head;
                head = t;
            } else {
                struct ListNode* i = head;
                while (i->next->val <= t->val) {
                    i = i->next;
                }
                t->next = i->next;
                i->next = t;
            }
        }
        else {
            p = p->next;
        }
    }
    return head;
}

// 初始化链表
struct ListNode* init_list(void) {
    return NULL;
}

// 插入节点
struct ListNode* insert_at_head(struct ListNode* l, int val) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = val;
    // l == NULL
    if (l == NULL) {
        new_node->next = NULL;
        return new_node;
    }

    // l != NULL;
    new_node->next = l;
    return new_node;
}

// 打印链表
void print_list(struct ListNode* l) {
    if (l == NULL) {
        printf("l is empty!\n");
        return;
    }

    do {
        printf("%4d", l->val);
        l = l->next;
    } while(l != NULL);

    printf("\n");
}
