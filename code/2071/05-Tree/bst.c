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
Node* find_father(Tree* tree, int val);

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
    if (val > tree->elem) {
        // 应该放在右子树上
        if (tree->r == NULL) {
            Node* new = malloc(sizeof(Node));
            new->elem = val;
            new->l = new->r = NULL;
            tree->r = new;
        } else {
            recurse_insert(tree->r, val);
        }
    } else if (val < tree->elem) {
        if (tree->l == NULL) {
            Node* new = malloc(sizeof(Node));
            new->elem = val;
            new->l = new->r = NULL;
            tree->l = new;
        } else {
            recurse_insert(tree->l, val);
        }
    } else {
        // 处理相同的节点，报错并返回
        printf("已有节点%4d\n", val);
    }
}

Tree* insert2(Tree* tree, int val) {
    if (tree == NULL) {
        Node* new = malloc(sizeof(Node));
        new->elem = val;
        new->l = new->r = NULL;
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

Node* find_father(Tree* tree, int val) {
    if (val < tree->elem) {
        if (tree->l == NULL) {
            return NULL;
        } else {
            if (tree->l->elem == val) {
                return tree;
            } else {
                return find_father(tree->l, val);
            }
        }
    } else {
        if (tree->r == NULL) {
            return NULL;
        } else {
            if (tree->r->elem == val) {
                return tree;
            } else {
                return find_father(tree->r, val);
            }
        }
    }
}

Tree* del(Tree* tree, int val) {
    if (tree->l == NULL && tree->r == NULL) {
        if (tree->elem == val) {
            free(tree);
            return NULL;
        } else {
            // 只有一个节点，而且不是你要删的节点
            printf("删除的值%5d不在树中\n", val);
            return tree;
        }
    }
    
    // 0. 要删除根节点
    if (tree->elem == val) {
        if (tree->r == NULL) {
            return tree->l;
        } else {
            // 右子树的最小节点在哪里？
            Node* t = tree;
            while(t->l)
                t = t->l;
            t->l = tree->l;
            return tree->r;
        }
    }

    // 1. 查找父节点
    Node* f = find_father(tree, val);
    Node* current;
    if (f == NULL) {
        // 找不到
        printf("删除的值%5d不在树中\n", val);
        return tree;
    } else {
        current = (val < f->elem) ? f->l:f->r;
    }
    int left = 1;
    if (val > f->elem)
        left = 0;
    
    // 2. 生成新的子树
    Tree* newTree;
    if (current->r == NULL) {
        newTree = current->l;
    } else {
        // 右子树的最小节点在哪里？
        Node* t = current;
        while(t->l)
            t = t->l;
        t->l = current->l;
        newTree = current->r;
    }

    // 3. 父节点挂接新的子树
    if (left)
        f->l = newTree;
    else
        f->r = newTree;
    return tree;
}

void print(Tree* tree) {
    if (tree == NULL) {
        printf("空树\n");
        return;
    }
    if (tree->r != NULL)
        print(tree->r);

    printf("%5d", tree->elem);

    if (tree->l != NULL)
        print(tree->l);
}

int main() {
    Tree* t = init();
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        t = insert2(t, rand() % 10);
        print(t);
        printf("\n");
    }

    for (int i = 0; i < 10; i++) {
        t = del(t, i);
        print(t);
        printf("\n");
    }
}
