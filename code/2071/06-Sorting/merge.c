/*
 * ============================================================================
 *
 *       Filename:  merge.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2020 02:43:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>

#include "merge.h"
#include "mylib.h"

void merge(int a[], int n, int m);

void merge(int a[], int n, int m) {
    // 从0到m-1已经是有序的，从m到n-1也是有序的
    int r[n];
    int *b = a + m;
    int i = 0, j = 0, k = 0;
    while(i < m && j < n-m) {
        // 两个序列都没有遍历完
        if (a[i] < b[j]) {
            r[k] = a[i];
            i++; k++;
        } else {
            r[k] = b[j];
            j++; k++;
        }
    }

    if (i != m) {
        // a里面还有剩余元素
        while(i < m)
            r[k++] = a[i++];
    } else {
        // b还没有取完
        while(j < n-m)
            r[k++] = b[j++];
    }

    for (i = 0; i < n; i++)
        a[i] = r[i];

}


void mergeSort(int a[], int n) {
    if (n <= 1)
        return;

    int m = n / 2;
    mergeSort(a, m);
    mergeSort(a+m, n-m);
    merge(a, n, m);
    printArray(a, n);
}
