/*
 * ============================================================================
 *
 *       Filename:  circle_linked_list_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/20/2020 06:43:10 PM
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
#include "linked_list.h"

#if 1
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
    CircleLinkedNode* head = init_circle_linked_list();

    for (int i = 0; i < n; i++) {
        add_circle_linked_list(head, n-i, 0);
    }
    display_circle_linked_list(head);

    // 2. 循环计数，遇到m则将这个元素删除
    CircleLinkedNode* curr_pos = head->next; // 当前位置
    while(head->next) {
        // 计数到m则将当前元素删除 
        int count = 0;
        while(1) {
            count++;
            if (count == m) {
                break;
            }
            curr_pos = curr_pos->next;
        }
        printf("%5d", curr_pos->elem);
        CircleLinkedNode* t = curr_pos->next;
        delete_circle_linked_list_node(head, curr_pos);
        curr_pos = t;
    }
    printf("\n");
}

#else
int main() {
    CircleLinkedNode* head = init_single_linked_list();
    for (int i = 0; i < 10; i++) {
        add_circle_linked_list(head, i+1, i);
    }

    for (int i = 0; i < 11; i++)
    {
        int pos = search_circle_linked_list(head, i);
        printf("find %d at pos %d\n", i, pos);
    }



    for (int i = 0; i < 10; i++) {
        display_circle_linked_list(head);
        delete_circle_linked_list_node(head, head->next->next);
    }
}
#endif

