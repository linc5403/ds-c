/*
 * ============================================================================
 *
 *       Filename:  bubble.c
 *
 *    Description: 冒泡排序的示例 
 *
 *        Version:  1.0
 *        Created:  08/18/2020 10:02:22 AM
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

void bubble(int a[], int n);
void printArray(int a[], int n);

void bubble(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int sorted = 1; // 假设此次已经排序完成
        for (int j = 0; j < n-1-i; j++) {
            // 这是一次冒泡
            // j和j+1比较后是否交换
            if (a[j] > a[j+1]) {
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                sorted = 0;
            }
        }
        printArray(a, n);
        if (sorted == 1)
            break;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
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

}
