/*
 * ============================================================================
 *
 *       Filename:  util.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/22/2020 03:53:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include <string.h>
#include "util.h"

/* 是操作数则返回1，是操作符则返回0 */
int is_operand(const char* a) {
    if (strlen(a) > 1)
        return 1;
    switch (a[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 0;
        default:
            return 1;

    }
}
