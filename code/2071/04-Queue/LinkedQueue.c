/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : LinkedQueue
 * @created     : Friday Aug 14, 2020 15:33:28 CST
 */

#include <stdlib.h>

#include "LinkedQueue.h"

Queue* initQueue() {
    return init();
}

void enqueue(Queue* q, int value) {
    insert(q, q->elem, value);
}

int dequeue(Queue* q) {
    return del(q, 0);
}

int isEmpty(Queue* q) {
    // return q->elem == 0;
    return q->pNext == NULL;
}
