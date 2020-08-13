/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : CircleList
 * @created     : Thursday Aug 13, 2020 10:30:34 CST
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    struct node* pNext;
} Node;

Node* init() {
    Node* pHead = (Node*)malloc(sizeof(Node));
    pHead->elem = 0; // head里面的elem表示这个链表有多少个节点
    pHead->pNext = NULL;
    return pHead;
}
//
// 用于查找一个已经存在的节点
Node* find(Node* pl, int pos) {
    // pos = 0; pl->pNext;
    // pos = 1; pl->pNext->pNext;
    // pos = 2; pl->pNext->pNext->pNext;
    // pos 是否在可访问的节点范围内
    if (pos >= pl->elem)
        return NULL;

    while(pos >= 0) {
        pl = pl->pNext;
        pos--;
    }
    return pl;
}

void print(Node* pl) {
    Node* zero = pl->pNext;
    pl = pl->pNext;
    if (pl == NULL) {
        printf("\n");
        return;
    }

    while(pl->pNext != zero) {
        printf("%5d", pl->elem);
        pl = pl->pNext;
    }

    printf("%5d", pl->elem);
    printf("\n");
}

void insert(Node* pl, int pos, int value) {
    Node* pNew = malloc(sizeof(Node));
    pNew->elem = value;
    // 1. 空链表
    if (pl->pNext == NULL) {
        pNew->pNext = pNew;
        pl->pNext = pNew;
        pl->elem++;
        return; 
    }
    // 2. 非0节点
    if (pos != 0) {
        Node* pre = find(pl, pos-1);
        pNew->pNext = pre->pNext;
        pre->pNext = pNew;
        pl->elem++;
        return;
    }
    // 3. 非空链表的0号节点
    // 3.1 找到End
    Node* end = find(pl, pl->elem-1);
    // 3.2 new->pNext = head->pNext;
    pNew->pNext = pl->pNext;
    // 3.3 end->pNext = new
    end->pNext = pl->pNext;
    // 3.4 head->next = new
    pl->pNext = pNew;
    pl->elem++;
}

remove(Node* curr, int num) {
    // 1. 找到上一个人
    for (int i = 0; i < num; i++)
        curr = curr->pNext;
    // 2. 保存下一个人
    // 3. 删除当前这个人
    // 4. 返回下一个开报数的人
}

int main() {
    Node* pl = init();
    for (int i = 0; i < 6; i++) {
        insert(pl, i, i+1);
        print(pl);
    }
    return 0;
}

