/*
 * ============================================================================
 *
 *       Filename:  107.c
 *
 *    Description:  给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 *
 *        Version:  1.0
 *        Created:  07/13/2020 08:52:52 PM
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;

typedef struct list {
    struct TreeNode* node;
    struct list* next;
} List;

typedef struct listHead {
    List* list;
    int len;
    List* tail;
} ListHead;


void addTail(ListHead* l, Node* node);
ListHead* getNextLevel(ListHead* curr);
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes);

void addTail(ListHead* l, Node* node) {
    if (l->tail == NULL) {
        l->list = malloc(sizeof(List));
        l->list->node = node;
        l->list->next = NULL;
        l->tail = l->list;
    } else {
        l->tail->next = malloc(sizeof(List));
        l->tail = l->tail->next;
        l->tail->node = node;
        l->tail->next = NULL;
    }
    l->len++;
}

ListHead* getNextLevel(ListHead* curr) {
    ListHead* ret = malloc(sizeof(ListHead));
    ret->list = ret->tail = NULL;
    ret->len = 0;
    List* curr_list = curr->list;
    while(curr_list != NULL) {
        // 获取curr的子节点
        Node* l = curr_list->node->left;
        if (l != NULL) {
            addTail(ret, l);
        }
        Node* r = curr_list->node->right;
        if (r != NULL) {
            addTail(ret, r);
        }
        curr_list = curr_list->next;
    }
    return ret;
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        int** ret = malloc(sizeof(*ret));
        *ret = NULL;
        return ret;
    }

    int level = 0;
    ListHead* curr = malloc(sizeof(*curr));
    curr->len = 1;
    curr->list = malloc(sizeof(List));
    curr->list->node = root;
    curr->list->next = NULL;
    curr->tail = curr->list;
    ListHead* list[1000];

    // 返回每行的长度
    int** ret = malloc(sizeof(*ret));
    while(curr->len > 0) {
        list[level] = curr;
        level++;
        curr = getNextLevel(curr);
    }
    free(curr);
    *returnColumnSizes = malloc(sizeof(int*) * level);

    ret = malloc(sizeof(int*)*level);

    for(int i = 0; i < level; i++) {
        ret[level-1-i] = malloc(sizeof(int) * list[i]->len);
        (*returnColumnSizes)[level-1-i] = list[i]->len;
        List* t = list[i]->list;
        for(int j = 0; j < list[i]->len; j++) {
            ret[level-1-i][j] = t->node->val;
            t = t->next;
        }
    }
    *returnSize = level;
    return ret;
}

int main() {
    Node a;
    a.left = a.right = NULL;
    a.val = 1;
    Node b1;
    b1.left = b1.right = NULL;
    b1.val = 2;
    a.left = &b1;
    Node b2;
    b2.left = b2.right = NULL;
    b2.val = 3;
    a.right = &b2;
    int retrunSize;
    int * columnSize;
    int** ret;
    ret = levelOrderBottom(&a, &retrunSize, &columnSize);
    return 0;
}
