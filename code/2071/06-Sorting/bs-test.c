/*
 * ============================================================================
 *
 *       Filename:  bs-test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/2020 04:05:02 PM
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
#include "bs.h"

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int r = bs(a, sizeof(a) / sizeof(a[0]), 7);
    printf("r = %d\n", r);

    return 0;
}
