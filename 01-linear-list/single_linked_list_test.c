/*
 * ============================================================================
 *
 *       Filename:  single_linked_list_test.c
 *
 *    Description:  单链表测试用例
 *
 *        Version:  1.0
 *        Created:  02/20/2020 06:08:37 PM
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

int main() {
    SingleLinkedNode* head = init_single_linked_list();
    for (int i = 0; i < 10; i++) {
        add_single_linked_list(head, i, 0);
    }
    
    display_single_linked_list(head);
    free_single_linked_list(head);
}

