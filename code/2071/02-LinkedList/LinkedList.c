/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : LinkedList
 * @created     : Wednesday Aug 12, 2020 13:39:12 CST
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

void insert(Node* pl, int pos, int value) {
    // 1. 创建新的节点
    Node* pNew = (Node*)malloc(sizeof(Node));
    pNew->elem = value;
    // 2. 找到pos-1这个节点
    Node* pre = find(pl, pos-1);
    if (pre == NULL) {
        // 找不到这个位置
        printf("找不到这个节点(%d), 总长度为%d\n", pos-1, pl->elem);
        return;
    }
    // 3. new->next = pre->next;
    pNew->pNext = pre->pNext;
    // 4. pre->next = new;
    pre->pNext = pNew;
    pl->elem++;
}

Node* search(Node* pl, int x) {
    // 获取0节点
    pl = pl->pNext;
    while(pl != NULL) {
        if (pl->elem == x)
            return pl;
        pl = pl->pNext;
    }
    return NULL;
}

void del(Node* pl, int pos) {
    // 1. 找到上一个节点
    Node* pre = find(pl, pos-1);

    if (pre == NULL) {
        // 找不到这个位置
        printf("找不到这个节点(%d), 总长度为%d\n", pos-1, pl->elem);
        return;
    }

    // 2. 上一个节点指向下一个节点
    pre->pNext = pre->pNext->pNext;
    pl->elem--;
}

void print(Node* pl) {
    pl = pl->pNext;
    while(pl != NULL) {
        printf("%5d", pl->elem);
        pl = pl->pNext;
    }
    printf("\n");
}

void modify(Node* pl, int pos, int value) {
    // 找到这个节点
    Node* p = find(pl, pos);
    if (p == NULL)
        printf("找不到这个节点(%d), 总长度为%d\n", pos, pl->elem);
    else
        p->elem = value;
}

int main() {
    Node* pl = init();

    for (int i = 0; i < 20; i++) {
        insert(pl, i, i * 100);
        print(pl);
    }

    Node* pr = search(pl, 1901);
    if (pr != NULL) {
        printf("找到了%d\n", pr->elem);
    } else 
        printf("没找到\n");

    modify(pl, 19, 1901);
    print(pl);

    /*
    for (int i = 0; i < 20; i++) {
        del(pl, pl->elem-1);
        print(pl);
    }
    */

    return 0;
}
