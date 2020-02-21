#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue* init_queue(void) {
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(Queue* q, int elem) {
    // q->head q->tail elem放到队列的尾
    Node* new_node = malloc(sizeof(Node));
    // 应该判断malloc是否成功
    new_node->elem = elem;
    new_node->next = NULL;
    if (q->tail) {
        // 如果q->tail不是空，表示这个队列里面有元素
        q->tail->next = new_node;
        q->tail = new_node;
    } else {
        // 否则表示当前队列是空的
        q->head = new_node;
        q->tail = new_node;
    }
}

int dequeue(Queue* q) {
    // head出队列，q->     head->next
    // 如果队列中只有一个节点，那么tail应该指向NULL

    if (q->head == NULL) {
        printf("error, queue is empty!\n");
        exit(-1);
    }

    int r;
    // if (q->head->next == NULL)
    if (q->head == q->tail) {
        r = q->head->elem;
        free(q->head);
        q->head = NULL;
        q->tail = NULL;
    } else {
        // 不止一个元素，所以只需要将第一个节点出队列即可
        Node* t = q->head;
        q->head = q->head->next;
        r = t->elem;
        free(t);
    }
    return r;
}

int is_empty(Queue* q) {
    return (q->head == NULL);
}


void destroy_queue(Queue* q){
    Node* head = q->head;
    while(head) {
        Node* t = head->next;
        free(head);
        head = t;
    }
    free(q);
}
