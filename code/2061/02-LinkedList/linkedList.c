/*
 * ============================================================================
 *
 *       Filename:  linkedList.c
 *
 *    Description:  链表的示例
 *
 *        Version:  1.0
 *        Created:  07/06/2020 02:00:34 PM
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

typedef struct node {
    int elem;
    struct node *next;
} Node, LinkedList;

LinkedList* initLinkedList(void);
Node* find(LinkedList* l, int pos);
void insertLinkedList(LinkedList* l,int value, int pos);
void deleteLinkedList(LinkedList* l, int pos);
Node* search(LinkedList* l, int value);
void modify(LinkedList* l, int pos, int value);
void printLinkedList(LinkedList* l);

int main() {
    LinkedList* head = initLinkedList();    
    insertLinkedList(head, 100, 0);
    insertLinkedList(head, 200, 1);
    insertLinkedList(head, 300, 2);
    insertLinkedList(head, 400, 3);
    printLinkedList(head);
    return 0;
}

LinkedList* initLinkedList() {
    Node* head = malloc(sizeof(Node));
    head->elem = 0; // head里面的elem表示链表中有多少个元素
    head->next = NULL;
    return head;
}

void insertLinkedList(LinkedList* l,int value, int pos) {
    if (pos > l->elem || pos < 0) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }

    Node* pNew = malloc(sizeof(Node));
    pNew->elem = value;

    Node* pre;
    if (pos == 0) {
        // 插入的位置是0
        pre = l;
    } else {
        pre = find(l, pos-1);
    }

    pNew->next = pre->next;
    pre->next = pNew;

    l->elem++;
}

// 在l中查找第pos个节点，并返回
Node* find(LinkedList* l, int pos) {
    Node* t = l->next;
    while(pos > 0) {
        t = t->next;
        pos--;
    }
    return t;
}

void printLinkedList(LinkedList* l) {
    Node* temp = l->next;
    while(temp != NULL) {
        printf("%4d", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

void deleteLinkedList(LinkedList* l, int pos) {
    if (pos >= l->elem || pos < 0) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }

    Node* pre;
    if (pos == 0) {
        pre = l;
    } else {
        pre = find(l, pos-1);
    }

    pre->next = pre->next->next;
    l->elem--;
}

Node* search(LinkedList* l, int value) {
    Node* t = l->next;
    while(t != NULL) {
        if (t->elem == value)
            return t;
        t = t->next;
    }
    return NULL;
}

void modify(LinkedList* l, int pos, int value) {
    if (pos < 0 || pos >= l->elem) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }
    Node* t = find(l, pos);
    t->elem = value;
}
