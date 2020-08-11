/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : arrayList
 * @created     : Tuesday Aug 11, 2020 15:04:23 CST
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* head;
    int length;
    int capacity;
} SeqList;

// 初始化顺序表
SeqList* initSeqList(int cap) {
    SeqList* pl = (SeqList*)malloc(sizeof(SeqList));
    pl->capacity = cap;
    pl->head = (int *)malloc(sizeof(int) * cap);
    pl->length = 0;
    return pl;
}

// 增加数据
void add(SeqList* pl, int value) {
    if (pl->length < pl->capacity) {
        pl->head[pl->length] = value;
        pl->length++;
    } else {
        printf("容量已满\n");
    }
}

// 删除数据
void delete(SeqList* pl) {
    if (pl->length != 0)
        pl->length--;
    else
        printf("空顺序表，无法删除\n");
}

void print(SeqList* pl) {
    for (int i = 0; i < pl->length; i++) {
        printf("%4d", pl->head[i]);
    }
    printf("\n");
}

int main() {
    SeqList* pl = initSeqList(10);
    for (int i = 0; i < 20; i++) {
        add(pl, i * 100);
        print(pl);
    }

    for (int i = 0; i < 20; i++) {
        delete(pl);
        print(pl);
    }


    return 0;
}
