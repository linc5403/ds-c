/*
 * ============================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/25/2020 12:52:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bubble.h"
#include "list.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s [number] [range]\n", argv[0]);
        return 0;
    }

    unsigned int num = atoi(argv[1]);
    unsigned int limit = atoi(argv[2]);

    List* l = init_list();
    time_t t;
    time(&t);
    srand((unsigned int) t);
    for (int i = 0; i < num; i++) {
        int r = rand() % limit ;
        insert_at_tail(l, r);
    }

    print_list(l);

    bubble_sort(l);
    print_list(l);

    return 0;
}
