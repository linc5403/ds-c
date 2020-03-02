/*
 * ============================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/2020 02:03:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main(int argc, char** argv) {
    unsigned int num;
    if (argc == 2) {
        num = atoi(argv[1]);
    } else {
        num = 10;
    }

    srand(time(NULL));

    // 1. 创建单链表
    struct ListNode* l = init_list();
    for (int i = 0; i < num; i++) {
        l = insert_at_head(l, rand() % 1000);
    }
    print_list(l);
    // 2. 调用排序的函数对该链表排序
    l = insertionSortList(l);
    print_list(l);
    // 3. 测试排序的结果是否正确

    return 0;
}
