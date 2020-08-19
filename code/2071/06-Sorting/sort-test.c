/*
 * ============================================================================
 *
 *       Filename:  sort-test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/2020 04:35:17 PM
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

#include "mylib.h"
// #include "quick.h"
#include "merge.h"


int main() {
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 100;
    printArray(a, 10);

    mergeSort(a, 10);
}
