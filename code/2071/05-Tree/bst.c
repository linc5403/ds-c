/*
 * ============================================================================
 *
 *       Filename:  bst.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/17/2020 01:55:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct node {
    int elem;
    struct node* l;
    struct node* r;
} Node, Tree;

Tree* init(void);
Node* search(Tree* tree, int val);
Node* search2(Tree* tree, int val);
Tree* insert(Tree* tree, int val);
Tree* insert2(Tree* tree, int val);
void recurse_insert(Tree* tree, int val);
Tree* del(Tree* tree, int val);
void print(Tree* tree);

Tree* init(void) {
    return NULL;
}


Node* search2(Tree* tree, int val) {
    if (tree == NULL)
        return NULL;
    if (tree->elem == val)
        return tree;
    else if (val < tree->elem)
        return search2(tree->l, val);
    else 
        return search2(tree->r, val);
}

Node* search(Tree* tree, int val) {
    if (tree == NULL)
        return NULL;

    while(1) {
        if (val < tree->elem) {
            if (tree->l == NULL)
                return NULL;
            else
                tree = tree->l;
        } else if (val > tree->elem) {
            if (tree->r == NULL)
                return NULL;
            else
                tree = tree->r;
        } else {
            return tree;
        }
    }
}

void recurse_insert(Tree* tree, int val) {
    Node* new = malloc(sizeof(Node));
    new->elem = val;
    new->l = new->r = NULL;

    if (val > tree->elem) {
        // 应该放在右子树上
        if (tree->r == NULL) {
            tree->r = new;
            return;
        } else {
            recurse_insert(tree->r, val);
        }
    } else if (val < tree->elem) {
        if (tree->l == NULL) {
            tree->l = new;
            return;
        } else {
            recurse_insert(tree->l, val);
        }
    } else {
        // 处理相同的节点，报错并返回
        printf("已有节点%4d\n", val);
    }
}

Tree* insert2(Tree* tree, int val) {
    Node* new = malloc(sizeof(Node));
    new->elem = val;
    new->l = new->r = NULL;
    if (tree == NULL) {
        return new;
    } else {
        recurse_insert(tree, val);
        return tree;
    }
}

Tree* insert(Tree* tree, int val) {
    Node* new = malloc(sizeof(Node));
    new->elem = val;
    new->l = new->r = NULL;

    if (tree == NULL) {
        return new;
    } else {
        // 不是空树
        // 1. 找到需要下挂的节点
        Node* t = tree;
        while(1) {
            if (val < t->elem) {
                if (t->l != NULL) {
                    t = t->l;
                } else {
                    // 挂在t的左边
                    t->l = new;
                    return tree;
                }
            } else if (val > t->elem) {
                if (t->r != NULL) {
                    t = t->r;
                } else {
                    // 挂在t的右边
                    t->r = new;
                    return tree;
                }
            }
        }
    }
}


void print(Tree* tree) {
    if (tree->r != NULL)
        print(tree->r);

    printf("%5d", tree->elem);

    if (tree->l != NULL)
        print(tree->l);
}

int main() {
    Tree* t = init();
    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        t = insert2(t, rand() % 1000);
    }
    print(t);
    printf("\n");
}
