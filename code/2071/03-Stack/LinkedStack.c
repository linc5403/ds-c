/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : Stack
 * @created     : Friday Aug 14, 2020 13:38:48 CST
 */

#include <stdlib.h>
#include <stdio.h>

#include "LinkedList.h"
#include "LinkedStack.h"

Stack* initStack() {
    return init();
}

void push(Stack* s, int value) {
    insert(s, 0, value);
}

int pop(Stack* s) {
    return del(s, 0);
}

int peek(Stack* s) {
    return s->pNext->elem;
}

int isEmpty(Stack* s) {
    return (s->pNext == NULL);
}
