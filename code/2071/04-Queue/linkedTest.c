/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : arrayTest
 * @created     : Friday Aug 14, 2020 14:36:56 CST
 */

#include "LinkedQueue.h"

#include <stdio.h>

int main() {
    Queue* q = initQueue();

    for (int i = 0; i < 10; i++) {
        enqueue(q, i);
    }
    while(!isEmpty(q)) {
        printf("%3d", dequeue(q));
    }
    printf("\n");

}
