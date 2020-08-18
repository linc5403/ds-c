/*
 * ============================================================================
 *
 *       Filename:  quick.c
 *
 *    Description:  快排的示例
 *
 *        Version:  1.0
 *        Created:  08/18/2020 01:52:11 PM
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

void quick(int a[], int n);
void printArray(int a[], int n);

void quick(int a[], int n) {
    if (n <= 1)
        return;
    // 1. 使用a[0]将n个元素分为两个部分,a[0]放到j的位置
    int j = n-1;
    int i = 1;
    while(1) {
        // 找到一个比a[0]大的i
        while(i < n && a[i] < a[0])
            i++;
        // 找到一个比a[0]小的j
        while(j >= i && a[j] >= a[0])
            j--;
        if (i <= j) {
            // 未交叉，进行交换
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        } else {
            // 处理a[0] 和 a[j]
            if (j != 0) {
                int t = a[0]; a[0] = a[j]; a[j] = t;
            }
            break;
        }
    }
    // 2. 再对0 .. j-1 进行处理
    quick(a, j);
    // 3. 对j+1 .. n-1进行处理
    quick(a+j+1, n-(j+1));
    printArray(a, n);
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
    quick(a, 10);

}
