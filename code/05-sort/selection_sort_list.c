/*
 * ============================================================================
 *
 *       Filename:  insert_sort_list.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/13/2020 02:49:42 PM
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
#include <time.h>

typedef struct node {
    int elem;
    struct node* pNext;
} Node;


Node* create_empty_list(void);
void add_at_head(Node* head, int elem);
void add_after_node(Node* pre, int elem);
void delete_node(Node* head, Node* pDelete);
void print_list(Node* head);
void insert_sort(Node* head);

// 拥有一共单独的头节点，但是这里面不放数据，只是指向真的数据节点
Node* create_empty_list(void) {
    Node* pHead = (Node*) malloc(sizeof(Node));
    pHead->pNext = NULL;
    return pHead;
}

void add_at_head(Node* head, int elem) {
    Node* pNode = (Node*) malloc(sizeof(Node));
    pNode->pNext = head->pNext;
    pNode->elem = elem;
    head->pNext = pNode;
}

void print_list(Node* head) {
    if (head->pNext == NULL) {
        printf("空链表，没法打印\n");
        return;
    }
    Node * pTemp = head->pNext;
    while(pTemp != NULL) {
        printf("%4d", pTemp->elem);
    }
    printf("\n");
}

void insert_sort(Node* head) {
    Node* ps = head->pNext;
    while(ps != NULL) {
        // 将ps放到合适的位置
        // 1. 判断ps的elem应该放到哪里去
        // 新建一共节点，把这个elem放进去
        // 2. 删除ps这个节点
    }
}


