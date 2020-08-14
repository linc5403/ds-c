/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : sum_zero
 * @created     : Thursday Aug 13, 2020 14:34:27 CST
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

// 判断从head开始，有没有n个节点; 假设n>0
int valid(Node* head, int n) {
    if (head == NULL)
        return 0;

    int i = 1;
    while (i < n) {
        head = head->next;
        if (head == NULL)
            return 0;
        i++;
    }
    return 1;
}

int sum(Node* head, int n) {
    int r = 0;
    for (int i = 0; i < n; i++) {
        r = r + head->val;
        head = head->next;
    }
    return r;
}


// 返回值表示删除后的新链表的head
// Node* delete(Node* head, Node* subHead, int n) {
Node* delete(Node* head, Node* subHead, Node* subEnd) {
    if (head == subHead) {
        head = subEnd->next;
        /*
        // 要删除head开始的序列
        // 向后偏移n个节点
        for (int i = 0; i < n; i++)
            head = head->next;
        */
    } else {
        // 先找到subHead的前一个节点
        Node* pre = head;
        while(pre->next != subHead)
            pre = pre->next;
        // 找到子序列的后一个节点
        /*
        Node* next = subHead;
        for (int i = 0; i < n; i++)
            next = next->next;
        */
        pre->next = subEnd->next;
    }
    return head;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head){
    Node* subHead = head;
    int n = 1; // n表示当前子序列里面有多少个节点
    int sumary;
    Node* subEnd = head;
    while (subHead != NULL) {
        if (n == 1) {
            sumary = subHead->val;
        }
        // 从subHead开始，构造不同长度的子序列，判断其和是否为0
        // if (sum(subHead, n) == 0) {
        if (sumary == 0) {
            head = delete(head, subHead, subEnd);
            subHead = head;
            subEnd = head;
            n = 1;
        } else {
            n++;
            // 判断subHead开始是否还有n个节点可以进行计算
            subEnd = subEnd->next;
            if (subEnd == NULL) {
                subHead = subHead->next;
                subEnd = subHead;
                n = 1;
            } else {
                sumary += subEnd->val;  
            }
            /*
            if (valid(subHead, n) == 0) {
                subHead = subHead->next;
                n = 1;
            }
            */
        }
    }
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        printf("%4d", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node head;
    head.val = 1;
    Node val2;
    val2.val = 2;
    head.next = &val2;
    Node val3;
    val3.val = 3;
    val2.next = &val3;
    Node val4;
    val4.val = -3;
    val3.next = &val4;
    Node val5;
    val5.val = -2;
    val4.next = &val5;
    val5.next = NULL;
    print(&head);

    Node* new = removeZeroSumSublists(&head);
    print(new);

}
