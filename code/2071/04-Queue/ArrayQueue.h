/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : ArrayQueue
 * @created     : Friday Aug 14, 2020 14:30:49 CST
 */

#ifndef ARRAYQUEUE_H

#define ARRAYQUEUE_H

typedef struct queue {
    int* data;
    int head;
    int tail;
} Queue;

Queue* initQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
int peek(Queue* q);


#endif /* end of include guard ARRAYQUEUE_H */

