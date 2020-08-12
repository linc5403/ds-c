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
SeqList* initSeqList() {
    SeqList* pl = (SeqList*)malloc(sizeof(SeqList));
    pl->capacity = 10;
    pl->head = (int *)malloc(sizeof(int) * 10);
    pl->length = 0;
    return pl;
}

// 增加数据
void add(SeqList* pl,int pos, int value) {
    if (pl->length == pl->capacity) {
        // 容量已满
        pl->capacity <<= 1;
        pl->head = (int *)realloc(pl->head, pl->capacity * sizeof(int));
    }

    // 从length-1到pos的元素都往后复制一次
    for (int i = pl->length; i > pos; i--) {
        pl->head[i] = pl->head[i-1];
    }

    pl->head[pos] = value;
    pl->length++;
}

// 删除数据
void del(SeqList* pl, int pos) {
    if (pos >= 0 && pos < pl->length) {
        // 从pos到length-1的元素都往左移动一次
        for (int i = pos; i < pl->length-1; i++) {
            pl->head[i] = pl->head[i+1];
        }
        pl->length--;
    } else {
        printf("pos(%d)非法，当前length为%d\n", pos, pl->length);
    }
}

void print(SeqList* pl) {
    for (int i = 0; i < pl->length; i++) {
        printf("%5d", pl->head[i]);
    }
    printf("\n");
}

int main() {
    SeqList* pl = initSeqList();
    for (int i = 0; i < 20; i++) {
        add(pl, i, i * 100);
        print(pl);
    }

    for (int i = 0; i < 20; i++) {
        del(pl, pl->length-1);
        print(pl);
    }

    return 0;
}
