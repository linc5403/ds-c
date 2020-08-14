/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : test
 * @created     : Friday Aug 14, 2020 13:53:10 CST
 */

#include <stdio.h>

#include "LinkedStack.h"

int main() {
    Stack* s = initStack();

    for (int i = 0; i < 10; i++) {
        push(s, i);
    }
    while(!isEmpty(s)) {
        printf("%3d", pop(s));
    }
    printf("\n");
}

