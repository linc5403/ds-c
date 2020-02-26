/*
 * ============================================================================
 *
 *       Filename:  bubble.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/25/2020 12:08:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>

#include "bubble.h"

void bubble_sort(List* l) {
    while(l->head->sorted != 1) {
        // 每次排一个
        Node* t = l->head;
        while( (t->next != NULL)  && (t->next->sorted != 1)) {
            if (t->val > t->next->val) {
                swap_nodes(l, t, t->next);
                print_list(l);
            } else {
                t = t->next;
            }
        }
        t->sorted = 1;
    }
}
