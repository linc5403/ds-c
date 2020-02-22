/*
 * ============================================================================
 *
 *       Filename:  tree.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 11:34:15 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

typedef enum {ROOT=0, LEFT=1, RIGHT=2} POSITION;
#define LEFT 1
#define RIGHT 2
#define ROOT 0

typedef struct treeNode {
    char* val;
    struct treeNode* l;
    struct treeNode* r;
} TreeNode;

typedef struct {
    TreeNode* root;
} BinaryTree;

BinaryTree* create_tree(void);
void insert(BinaryTree* t, char* val);
void display_tree(TreeNode* root);
void display_tree_post(TreeNode* root);
