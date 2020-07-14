/*
 * ============================================================================
 *
 *       Filename:  arrayList.c
 *
 *    Description:  顺序表的示例
 *
 *        Version:  1.0
 *        Created:  07/06/2020 10:12:20 AM
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

typedef struct arrayList {
    int * head; // 容纳元素的数组
    int length; // 当前已有元素的个数
    int capacity; // 最多能容纳元素的个数
} ArrayList;

ArrayList initArrayList(int capacity);
void printArrayList(ArrayList l);
void insert(ArrayList *l, int value, int pos);
void delete(ArrayList *l, int pos);
// 在ArrayList中查找值为value的元素，如果存在返回其下标
int search(ArrayList *l, int value);
void modify(ArrayList *l, int pos, int value);


ArrayList initArrayList(int capacity) {
    ArrayList l;
    l.capacity = capacity;
    l.head = malloc(sizeof(int) * l.capacity);
    l.length = 0;
    return l;
}

// 打印ArrayList
void printArrayList(ArrayList l) {
    for (int i = 0; i < l.length; i++) {
        printf("%4d", l.head[i]);
    }
    printf("\n");
}

// 将一个元素插入到list中的position位置
void insert(ArrayList* l, int value, int pos) {
    if (pos > l->length || pos < 0) {
        // 非法的位置
        printf("pos: %d 非法，length为: %d\n", pos, l->length);
        return;
    }

    if (l->length == l->capacity) {
        // list满了
        l->head = realloc(l->head, l->capacity*2*sizeof(int));
        /*
        int* new = malloc(sizeof(int) * l->capacity * 2);
        // copy old to new
        for (int i = 0; i < l->capacity; i++) {
            new[i] = l->head[i];
        }
        free(l->head);
        l->head = new;
        */
        //l->capacity *= 2;
        l->capacity <<= 1;
    }

    for (int i = l->length-1; i >= pos; i--) {
        l->head[i+1] = l->head[i];
    }
    l->head[pos] = value;
    l->length++;
}

int main() {
    ArrayList l = initArrayList(4);
    insert(&l, 100, 0);
    insert(&l, 200, 0);
    insert(&l, 300, 0);
    insert(&l, 400, 0);
    insert(&l, 500, 0);
    insert(&l, 500, 10);
    printArrayList(l);
    return 0;
}
