/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : LinkedQueue
 * @created     : Friday Aug 14, 2020 15:33:16 CST
 */

#ifndef LINKEDQUEUE_H

#define LINKEDQUEUE_H
#include "LinkedList.h"

typedef Node Queue;

Queue* initQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);


#endif /* end of include guard LINKEDQUEUE_H */

