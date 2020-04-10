/*
 * ============================================================================
 *
 *       Filename:  recentCount.c
 *
 *    Description:  leetcode
 *                  https://leetcode-cn.com/problems/number-of-recent-calls/
 *
 *        Version:  1.0
 *        Created:  04/10/2020 01:19:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pNext;
} Node;

typedef struct {
    Node* head; // 这是一个链表，用来表示队列
    Node* tail;
    int len; // 这是队列的长度
} RecentCounter;

// 入队列将新的元素放到队尾，出队列从head取
void enQueue(RecentCounter* queue, int elem);
int deQueue(RecentCounter* queue);
int peek(RecentCounter* queue);

RecentCounter* recentCounterCreate(void);
int recentCounterPing(RecentCounter* obj, int t);
void recentCounterFree(RecentCounter* obj);

RecentCounter* recentCounterCreate() {
    RecentCounter* p = (RecentCounter*)malloc(sizeof(RecentCounter));
    p->head = p->tail = NULL;
    p->len = 0;
    return p;
}

void enQueue(RecentCounter* queue, int elem) {
    Node* pnewNode = (Node*) malloc(sizeof(Node));
    pnewNode->data = elem;
    pnewNode->pNext = NULL;
    if (queue->tail == NULL) {
        queue->tail = pnewNode;
        queue->head = pnewNode;
    } else {
        queue->tail->pNext = pnewNode;
        queue->tail = pnewNode;
    }
    queue->len++;
}

int deQueue(RecentCounter* queue) {
    // 我们认为deQueue的操作一定在队列中有元素的时候才会发生
    Node* temp = queue->head;
    queue->head = temp->pNext;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    queue->len--;
    int r = temp->data;
    free(temp);
    return r;
}

int peek(RecentCounter* queue) {
    // peek不可能发生在空队列上
    return queue->head->data;
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  recentCounterPing
 *  Description:  入参t，返回从t倒退3000ms中该函数被调用的次数
 * ============================================================================
 */
int recentCounterPing(RecentCounter* obj, int t) {
    // t 放入队列
    enQueue(obj, t);
    while( peek(obj) < (t-3000) ) {
        deQueue(obj);
    }
    return obj->len;

    /*
    int headData = peek(obj);
    if (headData < t - 3000) {
        deQueue(obj);
    }
    */
    
    // 传入t，希望你计算从 t-3000到t的过程中被调用了多少次
    // 看你的那个队列里面尾部的值是否在符合规范的范围
    // 不符合，则尾部出队列，可能有循环
    // 符合，说明整个队列都符合，return 队列长度+1
    
}

void recentCounterFree(RecentCounter* obj) {
    //释放申请的资源？？malloc
    while(obj->len > 0)
        deQueue(obj);
    free(obj);
}
