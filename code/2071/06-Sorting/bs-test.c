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
#include <time.h>

#include "bs.h"
#include "mylib.h"
#include "quick.h"

#define SIZE 10

int main() {
    int a[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
        a[i] = rand() % 100;

    printArray(a, SIZE);
    quick(a, SIZE);
    printArray(a, SIZE);

    for (int i = 0; i < SIZE; i++) {
        int target = rand() % 100;
        int r = bs(a, SIZE, target);
        if (r == -1)
            printf("没有找到%d\n", target);
        else
            printf("%d的下标为%d\n", target, r);
    }

    return 0;
}
