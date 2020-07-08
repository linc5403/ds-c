/*
 * ============================================================================
 *
 *       Filename:  bubble.c
 *
 *    Description:  冒泡排序
 *
 *        Version:  1.0
 *        Created:  07/08/2020 03:10:39 PM
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

void printArray(int a[], int n);

void bubble(int a[], int n);

void bubble(int a[], int n) {
    // i表示未排序的数组中最大的下标
    for (int i = n-1; i > 0; i--) {
        int sorted = 1;
        for (int j = 0; j < i; j++) {
            // 一轮排序将最大的冒泡到最右边
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                sorted = 0;
            }
        }
        printArray(a, 10);
        if (sorted == 1)
            break;
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

    bubble(a, 10);

    printArray(a, 10);

    return 0;
}
