/*
 * ============================================================================
 *
 *       Filename:  21.c
 *
 *    Description:  将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *        Version:  1.0
 *        Created:  07/07/2020 11:59:29 AM
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
#include <time.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
struct ListNode* findMin(struct ListNode** pl1, struct ListNode** pl2, struct ListNode** ptail);
void print(struct ListNode* l);
struct ListNode* randinit(int num);
struct ListNode* add(struct ListNode* l, int val);

int main() {
    struct ListNode* l1 = randinit(10);
    print(l1);
    struct ListNode* l2 = randinit(10);
    print(l2);
    struct ListNode* r = mergeTwoLists(l1, l2);
    print(r);
}

struct ListNode* findMin(struct ListNode** pl1, struct ListNode** pl2, struct ListNode** ptail) {
    struct ListNode* l1 = *pl1;
    struct ListNode* l2 = *pl2;
    struct ListNode* min;
    struct ListNode* max;
    if (l1->val < l2->val) {
        min = l1;
        max = l2;
    } else {
        min = l2;
        max = l1;
    }
    struct ListNode* p = min;
    while(p->next && (p->next->val <= max->val)) {
        p = p->next;
    }
    *ptail = p;
    *pl1 = p->next;
    *pl2 = max;
    return min;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ret = NULL;
    struct ListNode* tail = NULL;
    int count = 100;
    // 将小的序列挂接在tail上
    while(l1 != NULL || l2 != NULL) {
        // 找出小的节点和结束的节点
        struct ListNode* newTail;
        struct ListNode* min = findMin(&l1, &l2, &newTail);
        printf("min = %d newTail = %d\n", min->val, newTail->val);
        if (ret == NULL) {
            ret = min;
            tail = newTail;
        } else {
            tail->next = min;
            tail = newTail;
        }
        count--;
        if (count == 0) 
            break;
    }
    if (l1 != NULL)
        tail = l1;
    if (l2 != NULL)
        tail = l2;
    return ret;
}

void print(struct ListNode* l) {
    while(l != NULL) {
        printf("%4d", l->val);
        l = l->next;
    }
    printf("\n");
}

struct ListNode* add(struct ListNode* l, int val) {
    struct ListNode* new = malloc(sizeof(struct ListNode));
    new->val = val;
    if (l == NULL) {
        new->next = NULL;
    } else {
        new->next = l;
    }
    return new;
}

struct ListNode* randinit(int num) {
    srand(time(NULL));
    struct ListNode* r = NULL;
    int count = rand() % num;
    int curr = 100;
    for (int i = 0; i < count; i++) {
        curr -= rand() % 10;
        r = add(r, curr);
    }
    return r;
}
