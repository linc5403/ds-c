/*
 * ============================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  list对外提供的接口（函数）和数据结构定义（struct）
 *
 *        Version:  1.0
 *        Created:  03/01/2020 02:06:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */

/* Definition for singly-linked list. */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head);

// 初始化链表
struct ListNode* init_list(void);

// 插入节点
struct ListNode* insert_at_head(struct ListNode* l, int val);

// 打印链表
void print_list(struct ListNode* l);
