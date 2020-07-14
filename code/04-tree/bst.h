/*
 * ============================================================================
 *
 *       Filename:  bst.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2020 10:37:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#ifndef BTS_T_H_
#define BTS_T_H_

typedef struct node {
    int data;
    struct node *l;
    struct node *r;
} TreeNode;

TreeNode* create(void);
TreeNode* search(TreeNode* root, int target);
TreeNode* insert(TreeNode* root, int data);
void print(TreeNode *root);

#endif
