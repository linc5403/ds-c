/*
 * ============================================================================
 *
 *       Filename:  stack.c
 *
 *    Description:  栈的示例
 *
 *        Version:  1.0
 *        Created:  07/07/2020 02:34:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    int elem;
    struct node *next;
} Node, LinkedList, Stack;

LinkedList* init(void);
Node* find(LinkedList* l, int pos);
void insertLinkedList(LinkedList* l,int value, int pos);
void deleteLinkedList(LinkedList* l, int pos);
Node* search(LinkedList* l, int value);
void modify(LinkedList* l, int pos, int value);
void print(LinkedList* l);

void push(Stack* s, int value);
int pop(Stack* s);
int peep(Stack* s);
int isEmpty(Stack* s);
int isOperator(char* s);

int main() {
    Stack* s = init();    
    char* a[] = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};
    int strNum = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < strNum; i++) {
        // 处理每个输入的字符串a[i]
        if (isOperator(a[i])) {
            // 运算符
            int r = pop(s);
            int l = pop(s);
            // 运算
            int rlt;
            switch (a[i][0]) {
                case '+':
                    rlt = l + r;
                    break;
                case '-':
                    rlt = l - r;
                    break;
                case '*':
                    rlt = l * r;
                    break;
                case '/':
                    rlt = l / r;
                    break;
                default:
                    printf("未知操作符%s\n", a[i]);
                    return -1;
            }
            push(s, rlt);
        } else {
            // 数字
            push(s, atoi(a[i]));
        }
    }
    int rlt = pop(s);
    printf("result is %d\n", rlt);
    return 0;
}

LinkedList* init() {
    Node* head = malloc(sizeof(Node));
    head->elem = 0; // head里面的elem表示链表中有多少个元素
    head->next = NULL;
    return head;
}

void insertLinkedList(LinkedList* l,int value, int pos) {
    if (pos > l->elem || pos < 0) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }

    Node* pNew = malloc(sizeof(Node));
    pNew->elem = value;

    Node* pre;
    if (pos == 0) {
        // 插入的位置是0
        pre = l;
    } else {
        pre = find(l, pos-1);
    }

    pNew->next = pre->next;
    pre->next = pNew;

    l->elem++;
}

// 在l中查找第pos个节点，并返回
Node* find(LinkedList* l, int pos) {
    Node* t = l->next;
    while(pos > 0) {
        t = t->next;
        pos--;
    }
    return t;
}

void print(LinkedList* l) {
    Node* temp = l->next;
    while(temp != NULL) {
        printf("%4d", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

void deleteLinkedList(LinkedList* l, int pos) {
    if (pos >= l->elem || pos < 0) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }

    Node* pre;
    if (pos == 0) {
        pre = l;
    } else {
        pre = find(l, pos-1);
    }

    pre->next = pre->next->next;
    l->elem--;
}

Node* search(LinkedList* l, int value) {
    Node* t = l->next;
    while(t != NULL) {
        if (t->elem == value)
            return t;
        t = t->next;
    }
    return NULL;
}

void modify(LinkedList* l, int pos, int value) {
    if (pos < 0 || pos >= l->elem) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->elem);
        return;
    }
    Node* t = find(l, pos);
    t->elem = value;
}

void push(Stack* s, int value) {
    insertLinkedList(s, value, 0);
}

int pop(Stack* s) {
    int r = s->next->elem;
    deleteLinkedList(s, 0);
    return r;
}

int peep(Stack* s) {
    return s->next->elem;
}

int isEmpty(Stack* s) {
    // return (s->elem == 0);
    return (s->next == NULL);
}

int isOperator(char* s){
    // "-" -> 1
    // "-12" -> 0
    // 此处未判断空字符串
    if (strlen(s) > 1)
        return 0;

    if (s[0] >= '0' && s[0] <= '9')
        return 0;
    else
        return 1;
}
