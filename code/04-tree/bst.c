/*
 * ============================================================================
 *
 *       Filename:  bst.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2020 10:37:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include "bst.h"
#include <stdio.h>
#include <time.h>

TreeNode* create(void) {
    return NULL;
}

TreeNode* search(TreeNode* root, int target) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == target) {
        return root;
    }

    if (root->data < target) {
        return search(root->r, target);
    } else {
        return search(root->l, target);
    }

}

TreeNode* insert(TreeNode* root, int data) {
    // 创建新节点
    TreeNode * new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->l = NULL;
    new_node->r = NULL;
    new_node->data = data;
    if (root == NULL) {
        // 空树
        return new_node;
    }
    // 找到一个节点node，可以挂接data
    if (data >= root->data) {
        root->r = insert(root->r, data);
    } else {
        root->l = insert(root->l, data);
    }
    return root;
}

void print(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    print(root->l);
    printf("%4d", root->data);
    print(root->r);
}

#define SIZE 20

int main(void) {
    srand(time(NULL));
    TreeNode* pt = create();
    for(int i = 0; i < SIZE; i++) {
        pt = insert(pt, rand() %100);
    }

    print(pt);
    printf("\n");
}
