/*
 * ============================================================================
 *
 *       Filename:  quick.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/08/2020 05:20:50 PM
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

#define NUM 100

void printArray(int a[], int n);

void quick(int a[], int n);

void quick(int a[], int n) {
    if (n <= 1)
        return;
    // 将a[0]放到合适的位置
    int i = 1;
    int j = n-1;
    while (i <= j) {
        // 找到一个比a[0] 大的i;
        while(i < n && a[i] < a[0])
            i++;
        // 找到一个比a[0] 小的j;
        while(j > 0 && a[j] >= a[0])
            j--;
        if (i < j) {
            int t = a[j];
            a[j] = a[i];
            a[i] = t;
        }
    }
    if (j != 0) {
        int t = a[0];
        a[0] = a[j];
        a[j] = t;
    }

    quick(a, j + 1);
    quick(a+j+1, n-j-1);
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int main() {
    int a[NUM];
    srand(time(NULL));
    for (int i = 0; i < NUM; i++)
        a[i] = rand() % NUM;
    printArray(a, NUM);

    quick(a, NUM);

    printArray(a, NUM);

    return 0;
}
