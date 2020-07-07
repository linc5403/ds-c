/*
 * ============================================================================
 *
 *       Filename:  circleList.c
 *
 *    Description:  循环链表的示例
 *
 *        Version:  1.0
 *        Created:  07/07/2020 10:04:48 AM
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
} Node, CircleList;

CircleList* init(void);
void addAtHead(CircleList* l, int value);
void addAtTail(CircleList* l, int value);
void print(CircleList* l);
void print2(CircleList* l);
Node* getTail(CircleList* l);

int main() {
    CircleList* l = init();
    addAtHead(l, 100);
    addAtHead(l, 200);
    addAtHead(l, 300);
    addAtHead(l, 400);
    print(l);
    return 0;
}

CircleList* init(void) {
    CircleList* l = malloc(sizeof(CircleList));
    l->elem = 0; // 表头的elem表示该循环链表里面有多少个元素
    l->next = NULL;
    return l;
}

Node* getTail(CircleList* l) {
    Node* p = l->next;
    if (p == NULL)
        return NULL;
    while(p->next != l->next)
        p = p->next;
    return p;
}

void addAtHead(CircleList* l, int value) {
    Node* tail = getTail(l);
    Node* new = malloc(sizeof(Node));
    new->elem = value;
    // 1. new 指向现有的0元素
    new->next = l->next;
    // 2. l 指向new
    l->next = new;
    // 3. tail 指向new
    if (tail == NULL) {
        // 现在是空链表，新增元素是第0个元素
        new->next = new;
    } else {
        tail->next = new;
    }
    // 4. l->elem++;
    l->elem++;
}

void addAtTail(CircleList* l, int value);
void print(CircleList* l) {
    CircleList* p = l->next;
    for (int i = 0; i < l->elem; i++) {
        printf("%4d", p->elem);
        p = p->next;
    }
    printf("\n");
}

void print2(CircleList* l) {
    // 当第二次遇到0号元素的时候表示打印结束
    // 当打印完最后一个元素的时候结束
    CircleList* p = l->next;
    if (p == NULL)
        return;
    /*
    do {
        printf("%4d", p->elem);
    } while((p = p->next) && (p->next != l->next));
    */
    while (p->next != l->next) {
        printf("%4d", p->elem);
        p = p->next;
    }
    printf("%4d", p->elem);
    printf("\n");
}
