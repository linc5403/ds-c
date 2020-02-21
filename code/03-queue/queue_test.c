/*
 * ============================================================================
 *
 *       Filename:  queue_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/21/2020 03:38:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    Queue* q = init_queue();
    for (int i = 0; i < 10; i++) {
        enqueue(q, i);
    }

    while (!is_empty(q)) {
        int r = dequeue(q);
        printf("%5d", r);
    }
    printf("\n");

    destroy_queue(q);
    return 0;
}
