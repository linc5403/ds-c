/*
 * ============================================================================
 *
 *       Filename:  tree.c
 *
 *    Description:  树的示例
 *
 *        Version:  1.0
 *        Created:  07/09/2020 01:52:17 PM
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
typedef struct node {
    int elem;
    struct node* l;
    struct node* r;
} Node, Tree;

Tree* init(void);
Tree* insert(Tree* root, int value);
Tree* search(Tree* root, int value);
void print(Tree* root);
void print_nicely(Tree* root);

int main() {
    Tree* tree = init(); // tree == NULL
    tree = insert(tree, 10);
    print_nicely(tree);
    tree = insert(tree, 5);
    print_nicely(tree);
    tree = insert(tree, 15);
    print_nicely(tree);
    tree = insert(tree, 20);
    print_nicely(tree);
    Node* n;
    int x = 15;
    n = search(tree, x);
    if (n != NULL)
        printf("%d\n", n->elem);
    else
        printf("Not found %d\n", x);

    x = 12;
    n = search(tree, x);
    if (n != NULL)
        printf("%d\n", n->elem);
    else
        printf("Not found %d\n", x);

    return 0;
}

Tree* insert(Tree* root, int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->elem = value;
    newNode->l = newNode->r = NULL;
    // root为NULL，表示空树
    if (root == NULL)
        return newNode;
    // 在已有的树里面添加新节点
    // 1. 查找哪个节点可以挂新节点
    Node* t = root;
    while(1) {
        if (value < t->elem) {
            if (t->l == NULL) {
                t->l = newNode;
                // 2. 挂
                break;
            }
            else
                t = t->l;
        }
        else {
            if (t->r == NULL) {
                // 2. 挂
                t->r = newNode;
                break;
            }
            else
                t = t->r;
        }
    }
    return root;
}

Tree* init(void) {
    return NULL;
}

void print(Tree* root) {
    if (root->l != NULL)
        print(root->l);
    // print(root);
    printf("%4d", root->elem);
    if (root->r != NULL)
        print(root->r);
}

void print_nicely(Tree* root) {
    print(root);
    printf("\n");
}


Node* search(Tree* root, int value) {
    if (root == NULL)
        return NULL;

    if (value == root->elem)
        return root;

    if (value < root->elem)
        return search(root->l, value);
    else
        return search(root->r, value);
}
