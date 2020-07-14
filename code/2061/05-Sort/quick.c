/*
 * ============================================================================
 *
 *       Filename:  quick.c
 *
 *    Description:  快速排序的示例
 *
 *        Version:  1.0
 *        Created:  07/09/2020 10:08:16 AM
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

void quick(int a[], int n);
void printArray(int a[], int n);
void swap(int a[], int i, int j);

void swap(int a[], int i, int j) {
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void quick(int a[], int n) {
    // 出口条件:当小于等于1个元素时，无需进行排序
    if (n <= 1)
        return;

    // 将a[0]放到合适的位置
    // 初始化i和j
    int i = 1;
    int j = n-1;
    while (i <= j) {
        // 找到一个比a[0]大的i
        while (i < n && a[i] <= a[0])
            i++;
        // 找到一个<=a[0]的j
        while (j > 0 && a[j] > a[0])
            j--;
        // 交换i和j
        if (i < j)
            swap(a, i, j);
    }
    // 交换a[0] 和 a[j]
    if (j != 0)
        swap(a, 0, j);
    // 处理j的左边和右边
    quick(a, j);
    quick(a+j+1, n-j-1);
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

    quick(a, 10);

    printArray(a, 10);

    return 0;
}
