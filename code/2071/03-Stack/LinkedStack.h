/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : LinkedStack
 * @created     : Friday Aug 14, 2020 13:50:49 CST
 */

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include "LinkedList.h"

typedef Node Stack;

Stack* initStack();
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
int isEmpty(Stack* s);

#endif /* end of include guard LINKEDSTACK_H */
