/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : LinkedList
 * @created     : Friday Aug 14, 2020 13:35:03 CST
 */

#ifndef LINKEDLIST_H

#define LINKEDLIST_H

typedef struct node {
    int elem;
    struct node* pNext;
} Node;

Node* init();
void insert(Node* pl, int pos, int value);
int del(Node* pl, int pos);

#endif /* end of include guard LINKEDLIST_H */

