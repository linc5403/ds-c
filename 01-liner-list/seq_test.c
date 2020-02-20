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

    // 1. init SeqList to all 1
    SeqList list = initSeqList(n);
    for (int i = 0; i < list.capacity; i++) {
        list = add(list, 1, 0);
    }
    displaySeqList(list);

    // 2. 计数置0 
    unsigned int curr_pos = 0;
    while(list.length) {
        int count = 0;
        while(1) {
            /*
            printf("count is %d\n", count);
            printf("curr_pos is %d\n", curr_pos);
            */
            //sleep(2);
            if (list.head[curr_pos] == 1) {
                count++;
                if (count == m) {
                    break;
                }
            }
            curr_pos = (curr_pos + 1) % list.capacity;
        }
        printf("%5d", curr_pos);
        list.head[curr_pos] = 0;
        list.length--;
        curr_pos = (curr_pos + 1) % list.capacity;
    }
    printf("\n");
}
