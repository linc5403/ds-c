/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : ArrayQueue
 * @created     : Friday Aug 14, 2020 14:30:34 CST
 */

#include <stdlib.h>

#include "ArrayQueue.h"

Queue* initQueue() {
    Queue * q = malloc(sizeof(Queue));
    q->head = q->tail = 0;
    q->data = malloc(sizeof(int) * 10);
    return q;
}

void enqueue(Queue* q, int value) {
    q->data[q->tail] = value;
    q->tail++;
}

int dequeue(Queue* q) {
    int ret = q->data[q->head];
    q->head++;
    return ret;
}

int isEmpty(Queue* q) {
    return q->head == q->tail;
}

int peek(Queue* q) {
    return q->data[q->head];
}
