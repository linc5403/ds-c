/*
 * ============================================================================
 *
 *       Filename:  insertion.c
 *
 *    Description: 插入排序的示例 
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

void insertion(int a[], int n);
void printArray(int a[], int n);

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        // a[i]是要排序的元素，将其插入到合适的位置
        int j = i;
        while(j > 0 && a[j] < a[j-1]) {
            int t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;
            j--;
        }
        printArray(a, n);
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
    insertion(a, 10);

}
