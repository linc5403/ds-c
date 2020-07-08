/*
 * ============================================================================
 *
 *       Filename:  insertion.c
 *
 *    Description:  插入排序
 *
 *        Version:  1.0
 *        Created:  07/08/2020 02:32:12 PM
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
void insertion(int a[], int n);

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        // 将a[i]插入到合适的位置
        int j = i;
        while((j > 0) && (a[j] < a[j-1])) {
            // 交换j和j-1
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;
            // if (j == 0) // 已经将这个元素放到a[0]
            //    break;
        }
        printArray(a, 10);
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

    insertion(a, 10);

    printArray(a, 10);

    return 0;
}
