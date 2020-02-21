#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// josephus_seq
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage  : %s total interval\n", argv[0]);
        printf("example: %s 20 4\n", argv[0]);
        return 0;
    }
    unsigned int n = atoi(argv[1]); // total number
    unsigned int m = atoi(argv[2]); // interval

    // 1. init SeqList
    SeqList list = initSeqList(n);
    for (int i = 0; i < list.capacity; i++) {
        list = add(list, list.capacity - i, 0);
    }
    displaySeqList(list);

    // 2. 循环计数，遇到m则将这个元素删除
    unsigned int curr_pos = 0; // 当前位置
    while(list.length) {
        // 计数到m则将当前元素删除 
        int count = 0;
        while(1) {
            count++;
            if (count == m) {
                break;
            }
            curr_pos = (curr_pos + 1) % list.length;
        }
        printf("%5d", list.head[curr_pos]);
        list = delete(list, curr_pos);
    }
    printf("\n");
}
