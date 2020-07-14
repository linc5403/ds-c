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
Node* find_positon(Node* head, Node* node);

void delete_node(Node* head, Node* pDelete) {
    Node* pTemp = head;
    while(pTemp->pNext != NULL && pTemp->pNext != pDelete) {
        pTemp = pTemp->pNext;
    }
    pTemp->pNext = pDelete->pNext;
    free(pDelete);
}

void add_after_node(Node* pre, int elem) {
    Node* pNode = (Node*) malloc(sizeof(Node));
    pNode->pNext = pre->pNext;
    pNode->elem = elem;
    pre->pNext = pNode;
}

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
        pTemp = pTemp->pNext;
    }
    printf("\n");
}

// 给出一共链表，和一共节点，找到这个节点在该链表中的正确排序位置
Node*  find_positon(Node* head, Node* node){
    int data = node->elem;
    Node* pos = head;
    while(pos->pNext != NULL && pos->pNext->elem <= data && pos->pNext != node) {
        pos = pos->pNext;
    }
    return pos;
}

void insert_sort(Node* head) {
    Node* ps = head->pNext;
    while(ps != NULL) {
        Node* pos = find_positon(head, ps);
        Node* pTemp = ps->pNext;
        if (pos->pNext == ps) {
            // 表示当前的位置就是正确的排序位置，不用插入
        } else {
            // 需要将ps的值插入到合适的位置
            add_after_node(pos, ps->elem);
            delete_node(head, ps);
        }
        ps = pTemp;
    }
}

#define SIZE 10

int main(void) {
    Node* head = create_empty_list();
    srand(time(NULL));
    // int a[] = {  96  ,51  ,46  ,66  ,81  ,96  ,47  ,16  ,74  ,51 };

    for(int i = 0; i < SIZE; i++) {
        // add_at_head(head, a[i]);
        add_at_head(head, rand()%100);
    }

    print_list(head);

    insert_sort(head);

    print_list(head);
}
