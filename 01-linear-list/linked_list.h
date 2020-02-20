/*
 * ============================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2020 05:08:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

typedef struct single_linked_node {
    struct single_linked_node *next;
    int elem;
} SingleLinkedNode, CircleLinkedNode;

typedef struct double_linked_node {
    struct node *pre;
    struct node *next;
    int elem;
} DoubleLinkedNode;


SingleLinkedNode* init_single_linked_list(void);
void add_single_linked_list(SingleLinkedNode* head, int elem, int pos);
void delete_single_linked_list(SingleLinkedNode *head, int pos);
int search_single_linked_list(SingleLinkedNode *p , int elem);
void modify_single_linked_list(SingleLinkedNode *p, int pos, int val); 
void free_single_linked_list(SingleLinkedNode *head);
void display_single_linked_list(SingleLinkedNode *p);

CircleLinkedNode* init_circle_linked_list(void);
void add_circle_linked_list(CircleLinkedNode* head, int elem, int pos);
void delete_circle_linked_list(CircleLinkedNode *head, int pos);
void delete_circle_linked_list_node(CircleLinkedNode *head, CircleLinkedNode* node);
int search_circle_linked_list(CircleLinkedNode *p , int elem);
void modify_circle_linked_list(CircleLinkedNode *p, int pos, int val); 
void free_circle_linked_list(CircleLinkedNode *head);
void display_circle_linked_list(CircleLinkedNode *p);
CircleLinkedNode* find_last_node(CircleLinkedNode* head);


