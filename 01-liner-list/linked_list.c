/*
 * ============================================================================
 *
 *       Filename:  linked_list.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2020 05:07:58 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan (), linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_single_linked_list
 *  Description:  初始化单链表
 *  Return     :  表头(head)指针
 * ============================================================================
 */
SingleLinkedNode* init_single_linked_list(void) {
    SingleLinkedNode* head = malloc(sizeof(SingleLinkedNode));
    head->elem = 0;
    head->next = NULL;
    return head;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  add_single_linked_list
 *  Description:  添加elem到指定的pos
 *  Return     :  void
 * ============================================================================
 */
void add_single_linked_list(SingleLinkedNode* head, int elem, int pos) {
        //插入位置判断，取值范围为0～length
    int length = head->elem;//传入的是头结点，直接取链表长度值

    if (pos > length   || pos < 0) {
        printf("插入位置有误\n");
        return;
    }

    //找到需要插入位置的上一个结点
    SingleLinkedNode *temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    //新建一个结点
    SingleLinkedNode *add = (SingleLinkedNode *)malloc(sizeof(SingleLinkedNode));
    add->elem = elem;
    add->next = temp->next;//将新结点的next指向上一个结点原来的next
    temp->next = add;//将上一个结点指向新结点

    head->elem ++;//表长度+1
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  delete_single_linked_list
 *  Description:  删除指定位置的元素
 * ============================================================================
 */
void delete_single_linked_list(SingleLinkedNode *head, int pos) {
    //删除位置判断，取值范围为0～length-1
    int length = head->elem;//传入的是头结点，直接取链表长度值

    if (pos >= length || pos < 0) {
        printf("删除位置有误\n");
        return;
    }

    //找到需要删除位置的上一个结点
    SingleLinkedNode *temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    SingleLinkedNode *del = temp->next;//需要删除的结点
    temp->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    free(del);//释放内存
    del = NULL;

    head->elem --;//表长度-1
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  search_single_linked_list
 *  Description:  查找单链表中的元素
 * ============================================================================
 */
int search_single_linked_list(SingleLinkedNode *p , int elem) {
    int i = 0;
    SingleLinkedNode *temp = p;

    while (temp->next) {
        temp = temp->next;

        if (temp->elem == elem) {
            return i;
        }

        i++;
    }

    return -1;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  modify_single_linked_list
 *  Description:  将单链表中的pos位置元素值修改为val
 * ============================================================================
 */
void modify_single_linked_list(SingleLinkedNode *p, int pos, int val) {
    SingleLinkedNode *temp = p;

    for (int i = 0; i < pos + 1 ; i++) {
        temp = temp->next;
    }

    temp->elem = val;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  free_single_linked_list
 *  Description:  释放整个单链表
 * ============================================================================
 */
void free_single_linked_list(SingleLinkedNode *head) {
    SingleLinkedNode *cur = head;
    SingleLinkedNode *next;

    while (cur->next) {
        next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  display_single_linked_list
 *  Description:  打印单链表
 * ============================================================================
 */
void display_single_linked_list(SingleLinkedNode *p) {
    SingleLinkedNode *temp = p;
    printf("共%d个元素：", temp->elem);

    while (temp->next) {
        temp = temp->next;//跳过头结点
        printf("  %d", temp->elem);
    }

    printf("\n");
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  init_circle_linked_list
 *  Description:  初始化循环链表
 *  Return     :  表头(head)指针
 * ============================================================================
 */
CircleLinkedNode* init_circle_linked_list(void) {
    CircleLinkedNode* head = malloc(sizeof(CircleLinkedNode));
    head->elem = 0;
    head->next = NULL;
    return head;
}


/* 
 * ===  FUNCTION  =============================================================
 *         Name:  display_circle_linked_list
 *  Description:  
 * ============================================================================
 */
void display_circle_linked_list(CircleLinkedNode *head) {
    int n = head->elem;
    printf("共%d个元素：\n", n);
    if (n == 0) {
        return;
    }

    CircleLinkedNode *temp = head->next;

    int count = 0;
    do {
        count++;
        printf("%5d", temp->elem);
        temp = temp->next;
        if (count %10 == 0) {
            printf("\n");
        }
    } while(temp != head->next);

    printf("\n");
}


void add_circle_linked_list(CircleLinkedNode* head, int elem, int pos) {
        //插入位置判断，取值范围为0～length
    int length = head->elem;//传入的是头结点，直接取链表长度值

    if (pos > length   || pos < 0) {
        printf("插入位置有误\n");
        return;
    }

    //找到需要插入位置的上一个结点
    CircleLinkedNode *temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    //新建一个结点
    CircleLinkedNode *add = (CircleLinkedNode *)malloc(sizeof(CircleLinkedNode));
    add->elem = elem;

    // 如果是第一个元素，则该新增元素的next指向自己
    if (head->next == NULL) {
        head->next = add;
        add->next = add;
    } else if (pos == 0) {
        // 插入第一个位置，需要将最后一个元素的next指向这个新增的元素
        // 找到最后一个元素
        CircleLinkedNode* last = find_last_node(head);
        add->next = temp->next;
        head->next = add;
        last->next = add;
    } else {
        add->next = temp->next;//将新结点的next指向上一个结点原来的next
        temp->next = add;//将上一个结点指向新结点
    }
    head->elem++;//表长度+1
}

CircleLinkedNode* find_last_node(CircleLinkedNode* head) {
    if (head->next == NULL) {
        return NULL;
    }
    CircleLinkedNode* first = head->next;
    CircleLinkedNode* temp = first;
    while(temp->next != first) {
        temp = temp->next;
    }
    return temp;
}

void delete_circle_linked_list(CircleLinkedNode *head, int pos) {
    //删除位置判断，取值范围为0～length-1
    int length = head->elem;//传入的是头结点，直接取链表长度值

    if (pos >= length || pos < 0) {
        printf("删除位置有误\n");
        return;
    }

    //找到需要删除位置的上一个结点
    CircleLinkedNode *temp = head;

    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }

    CircleLinkedNode *del = temp->next;//需要删除的结点
    if (del->next == del) {
        // 有且只有一个节点而且要把这个节点删除
        head->next = NULL;
    } else if (pos == 0) {
        // 删除第一个节点
        CircleLinkedNode* last = find_last_node(head);
        last->next = del->next;
        head->next = del->next;
    } else {
        temp->next = del->next;//将上一个结点的指针指向删除结点的后一个结点
    }

    free(del); // 释放内存
    del = NULL;

    head->elem--; // 表长度-1
}

/* 
 * ===  FUNCTION  =============================================================
 *         Name:  delete_circle_linked_list_node
 *  Description:  删除head中的node节点
 *       Waring:  调用者必须保证node节点必须在head的链表中，否则会出现死循环
 * ============================================================================
 */
void delete_circle_linked_list_node(CircleLinkedNode *head, CircleLinkedNode* node) {
    if (head->next == node) {
        // 删除第一个节点
        if (node->next == node) {
            // 有且只有一个节点而且要把这个节点删除
            head->next = NULL;
        } else {
            // 找到最后一个节点
            CircleLinkedNode* last = find_last_node(head);
            last->next = node->next;
            head->next = node->next;
        }
    } else {
        CircleLinkedNode* t = head->next;
        while(t->next != node) {
            t = t->next;
        }
        t->next = node->next;
    }
    free(node);
    node = NULL;
    head->elem--;
}

int search_circle_linked_list(CircleLinkedNode *head, int elem) {
    CircleLinkedNode* first = head->next;
    if (first == NULL) {
        return -1;
    }

    CircleLinkedNode* t = first;

    int i = 0;

    do {
        if (t->elem == elem) {
            break;
        }
        t = t->next;
        i++;
    } while (t != first);

    if (t->elem == elem) {
        return i;
    } else {
        return -1;
    }
}

void modify_circle_linked_list(CircleLinkedNode *head, int pos, int val) {
    CircleLinkedNode *temp = head;

    for (int i = 0; i < pos + 1 ; i++) {
        temp = temp->next;
    }

    temp->elem = val;
}

void free_circle_linked_list(CircleLinkedNode *head) {
    while(head->next != NULL) {
        delete_circle_linked_list(head, 0);
    }
    free(head);
    head = NULL;
}

