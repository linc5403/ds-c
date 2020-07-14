/*
 * ============================================================================
 *
 *       Filename:  queue.c
 *
 *    Description:  队列的示例
 *
 *        Version:  1.0
 *        Created:  07/08/2020 10:55:10 AM
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
#include <stdbool.h>

typedef struct node {
    int elem;
    struct node *next;
} Node, LinkedList, Queue;

LinkedList* initLinkedList(void);
Node* find(LinkedList* l, int pos);
void insertLinkedList(LinkedList* l,int value, int pos);
void deleteLinkedList(LinkedList* l, int pos);
Node* search(LinkedList* l, int value);
void modify(LinkedList* l, int pos, int value);
void printLinkedList(LinkedList* l);

void enqueue(Queue* q, int value);
int dequeue(Queue* q);
bool isEmpty(Queue* q);

int main() {
    Queue* q = initLinkedList();    
    for (int i = 0; i < 10; i++)
        enqueue(q, i);
    // printLinkedList(q);
    while(!isEmpty(q)) {
        int v = dequeue(q);
        printf("%4d", v);
    }
    printf("\n");
    
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

void enqueue(Queue* q, int value) {
    // q->elem表示这个队列的长度
    insertLinkedList(q, value, q->elem);
}

int dequeue(Queue* q) {
    int r = q->next->elem;
    deleteLinkedList(q, 0);
    return r;
}

bool isEmpty(Queue* q) {
    // return q->elem == 0;
    return q->next == NULL;
}
