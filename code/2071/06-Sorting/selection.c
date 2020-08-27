/*
 * ============================================================================
 *
 *       Filename:  selection.c
 *
 *    Description:  选择排序
 *
 *        Version:  1.0
 *        Created:  08/18/2020 09:27:34 AM
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

void selection(int a[], int n);
void printArray(int a[], int n);

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

void selection(int a[], int n) {
    // i从0到n-2
    for (int i = 0; i < n-1; i++) {
        // 从i到n-1选一个最小的出来，和i进行交换
        int iMin = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[iMin])
                iMin = j;
        }
        if (i != iMin) {
            int t = a[i];
            a[i] = a[iMin];
            a[iMin] = t;
        }
        printArray(a, n);
    }
}



int main() {
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 100;

    printArray(a, 10);
    selection(a, 10);

}
