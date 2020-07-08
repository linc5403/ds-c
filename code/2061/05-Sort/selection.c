/*
 * ============================================================================
 *
 *       Filename:  selection.c
 *
 *    Description:  选择排序
 *
 *        Version:  1.0
 *        Created:  07/08/2020 01:37:34 PM
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

void selection(int a[], int n);
void printArray(int a[], int n);

void selection(int a[], int n) {
    // 遍历0到n-2，每次从未排序的序列中选择最小的，和i交换
    for (int i = 0; i < n-1; i++) {
        // 从i到n-1中找最小的元素下标
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i) {
            int temp = a[i]; 
            a[i] = a[min];
            a[min] = temp;
        }
        printArray(a, n);
    }
}

void printArray(int a[], int n) {
    for(int i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int main() {
    int a[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 100;
    printArray(a, 10);

    selection(a, 10);

    printArray(a, 10);

    return 0;
}
