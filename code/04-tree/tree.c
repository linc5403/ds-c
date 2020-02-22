/*
 * ============================================================================
 *
 *       Filename:  tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 11:34:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "util.h"

TreeNode* find_position(TreeNode* t);
int is_tree_empty(BinaryTree* t);
void print_node_by_level(TreeNode* node);
void print_node_pretty(TreeNode* root);

int is_tree_empty(BinaryTree* t) {
    return t->root == NULL;
}

TreeNode* find_position(TreeNode* t) {
    if (is_operand(t->val)) {
        return NULL;
    }
    // 找这个节点的右节点
    if (t->r == NULL) {
        return t;
    } else {
        // 右边不为空，递归查找右边
        TreeNode* n = find_position(t->r);
        if (n) {
            return  n;
        }
    }

    if (t->l == NULL) {
        return t;
    } else {
        TreeNode* n = find_position(t->l);
        if (n) {
            return  n;
        }
    }
    return NULL;
}


BinaryTree* create_tree(void) {
    BinaryTree* t = malloc(sizeof(BinaryTree));
    t->root = NULL;
    t->height = 0;
    return t;
}

void insert(BinaryTree* t, char* val) {
    TreeNode* n = malloc(sizeof(TreeNode));
    n->l = n->r = NULL;
    n->val = val;

    if (is_tree_empty(t)) {
        n->level = 0;
        t->root = n;
        t->height = 1;
        return;
    }

    TreeNode* p = find_position(t->root);
    if (p->r == NULL) {
        p->r = n;
    } else {
        p->l = n;
    }
    n->level = p->level + 1;
    if (n->level + 1 > t->height) {
        t->height = n->level + 1;
    }
}

void display_tree(TreeNode* root) {
    if (root == NULL) {
        printf("empty tree\n");
        return;
    }

    if (root->l) {
        display_tree(root->l);
    }

    printf("%s ", root->val);

    if (root->r) {
        display_tree(root->r);
    }
}

void display_tree_post(TreeNode* root) {
    if (root == NULL) {
        printf("empty tree\n");
        return;
    }

    if (root->l) {
        display_tree_post(root->l);
    }

    if (root->r) {
        display_tree_post(root->r);
    }

    printf("%s ", root->val);
}


void print_node_by_level(TreeNode* node) {
    if (node->r) {
        print_node_by_level(node->r);
    }

    for (int i = 0; i < node->level; i++) {
        printf("    ");
    }

    printf("%s \n", node->val);

    if (node->l) {
        print_node_by_level(node->l);
    }
}

void print_tree(BinaryTree* tree) {
    if (tree->root == NULL) {
        printf("empty tree\n");
        return;
    }
    print_node_by_level(tree->root);
}

int count_node(TreeNode* node) {
    int i = 1;
    if (node->l) {
        i = i + count_node(node->l);
    }
    if (node->r) {
        i = i + count_node(node->r);
    }
    return i;
}
