#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

/* init sequence list */
SeqList initSeqList(unsigned int capacity) {
    SeqList list;
    list.head = (int*) malloc(sizeof(int) * capacity);
    if (list.head == NULL) {
        printf("init list failed when malloc %d int\n", capacity);
        exit(0);
    }
    list.capacity = capacity;
    list.length = 0;
    return list;
}

/* display sequence list */
void displaySeqList(SeqList list) {
    for (int i = 0; i < list.length; i++) {
        if (i + 1 % 10 == 0) {
            printf("\n");
        }

        printf("%5d", list.head[i]);
    }
    printf("\n");
}

/* add elem into list at pos */
SeqList add(SeqList list, int elem, int pos) {
    if (pos > list.length || pos < 0) {
        printf("add function using invalid pos\n");
        return list;
    }

    if (list.length == list.capacity) {
        unsigned int new_cap = list.capacity << 1;
        int *temp = (int*)realloc(list.head, (new_cap) * sizeof(int));
        if (temp == NULL) {
            printf("realloc memory failed with %ud int\n", new_cap);
            return list;
        }
        list.head = temp;
        list.capacity = new_cap;
    }

    for (int i = list.length-1; i >= pos; i--) {
        list.head[i+1] = list.head[i];
    }
    list.head[pos] = elem;
    list.length++;
    return list;
}

/* del pos */
SeqList delete(SeqList list, int pos) {
    if (pos >= list.length || pos < 0) {
        printf("delete function using invalid pos\n");
        return list;
    }

    for (int i = pos; i < list.length-1; i++) {
        list.head[i] = list.head[i+1];
    }

    list.length--;
    return list;
}

int search(SeqList list, int elem) {
    for (int i = 0; i < list.length; i++) {
        if (list.head[i] == elem) {
            return i;
        }
    }
    return -1;
}

SeqList modify(SeqList list, int elem, int val) {
    int pos = search(list, elem);
    if (pos != -1) {
        list.head[pos] = val;
    } else {
        printf("can not find %d in list\n", elem);
    }
    return list;
}
