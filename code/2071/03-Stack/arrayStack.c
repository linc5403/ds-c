/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : arrayStack
 * @created     : Friday Aug 14, 2020 10:16:30 CST
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int capacity;
    int* head;
} Stack;

Stack* init() {
    Stack* s = malloc(sizeof(Stack));
    s->capacity = 10;
    s->top = 0;
    s->head = malloc(sizeof(int) * s->capacity);
    return s;
}

void push(Stack* s, int value) {
    s->head[s->top] = value;
    s->top++;
}

int pop(Stack* s) {
    s->top--;
    return s->head[s->top];
}

int peek(Stack* s) {
    return s->head[s->top-1];
}

int isEmpty(Stack* s) {
    return s->top == 0;
}

int main() {
    Stack* s = init();
    for (int i = 0; i < 10; i++) {
        push(s, i);
    }
    while(!isEmpty(s)) {
        printf("%3d", pop(s));
    }
    printf("\n");
}
