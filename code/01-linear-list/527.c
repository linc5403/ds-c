/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : 527
 * @created     : Wednesday May 27, 2020 09:27:51 CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int id;
    struct node * next;
} Node;

typedef struct {
    int length;
    Node* head;
} CircleList;


CircleList* initCircleList() {
    CircleList* pList = malloc(sizeof(CircleList));
    pList->head = NULL;
    pList->length = 0;
    return pList;
}

Node* find_pos(CircleList* plist, int n) {
    if (n >= plist->length || n < 0) {
        printf("查找位置不正确： %d\n", n);
        return NULL;
    }

    Node* t = plist->head;
    while(n >= 1) {
        t = t->next;
        n--;
    }
    return t;
}

void insert(CircleList* list, int id, int pos) {
    if (pos > list->length || pos < 0) {
        printf("插入的位置不正确\n");
        return;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node)); //为新节点分配空间
    newNode->id = id;
    
    if (pos == 0) {
        // 新的节点是头结点
        // 1. 查找最后一个节点
        Node* plast = find_pos(list, list->length-1);
        if (plast == NULL) {
            // 原来的链表是空链表
            list->head = newNode;
            newNode->next = newNode;
        } else {
            // 正常插入头节点
            // 1. 新节点的next指向原来的0号节点
            newNode->next = list->head;
            // 2. list->head 指向 新节点
            list->head = newNode;
            // 3. last节点的next指向新节点
            plast->next = newNode;
        }
        list->length++;
        return;
    } else {
        // pos不为0的情况
        Node* pre = list->head;
        // 非头结点
        while(pos > 1) {
            pos--;
            pre = pre->next;
        }
        newNode->next = pre->next;
        pre->next = newNode;
        list->length++;
        return;
    }
}

void delete(CircleList* list, int pos) {
    if (pos >= list->length || pos < 0) {
        printf("删除的位置不正确\n");
        return;
    }
    
    if (pos == 0) {
        Node* head = list->head; // 释放原来的head节点，不做要求
        list->head = list->head->next; // head 指向原来节点的下一个节点
        list->length--;
        free(head);              // 释放内存, 不做要求
    } else {
        Node* pre = list->head;
        while(pos > 1) {
            pre = pre->next;
            pos--;
        }
        Node* t = pre->next;    //不做要求
        pre->next = pre->next->next;
        list->length--;
        free(t);                //不做要求
    }
}

void displayList(CircleList* list) {
    Node* t = list->head;
    while(t->next != list->head) {
        printf("%d\n", t->id);
        t = t->next;
    }
    printf("%d\n", t->id);
    printf("\n");
}

int main() {
    CircleList* pList = initCircleList();
    for (int i = 1; i <=10; i++) {
        insert(pList, i, i-1);
    }
    displayList(pList);
}

