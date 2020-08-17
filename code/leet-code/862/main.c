/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : main
 * @created     : Friday Aug 14, 2020 16:38:00 CST
 */

#include <stdio.h>

#include "LinkedQueue.h"

int max_n_sub(int* a, int size, int n);
int shortestSubarray(int* A, int ASize, int K);

int max_n_sub(int* a, int size, int n) {
    int max = 0;
    int last;
    for (int i = 0; i < n; i++) {
        max += a[i];
    }
    last = max;
    // 从n开始，直至size-1，进行计算
    for (int i = n; i < size; i++) {
        last -= a[i-n];
        last += a[i];
        if (last > max)
            max = last;
    }
    return max;
}

int shortestSubarray(int* A, int ASize, int K){
    // 连续子串
    for (int i = 1; i <= ASize; i++) {
        int max = max_n_sub(A, ASize, i);
        if (max >= K) {
            printf("max = %d\n", max);
            return i;
        }
    }
    return -1;
}

int main()
{
    // int a[] = {2,-1,2};
    int a[] = {1,2};
    int k = 4;
    printf("%d\n", shortestSubarray(a, sizeof(a) / sizeof(a[0]), k));
    
    return 0;
}

