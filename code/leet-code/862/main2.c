/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : main
 * @created     : Friday Aug 14, 2020 16:38:00 CST
 */

#include <stdio.h>

#include "LinkedQueue.h"

// 从a开始，查找第一个>=K的子序列
int findFirst(int* a, int size, int k, int* begin, int* end) {
    int first = 0; int last = 0; int sum = a[0];
    while (last < size) {
        if (sum >= k) {
            *begin = first;
            *end = last;
            return 1;
        }
        last++;
        if (last >= size) {
            return 0;
        }
        sum += a[last];
        if (sum <= 0) {
            first = last+1;
            while (first < size && a[first] < 0) {
                first++;
            }
            if (first >= size)
                return 0;
            else {
                last = first;
                sum = a[first];
            }
        }
    }
    return 0;
}

int shortestSubarray(int* A, int ASize, int K){
    int begin, end;
    int find = findFirst(a, size, k, begin, end);
    if (find) {
        // 找到第一个子序列>=k
        int currentLen =  end - begin + 1;
        // 试图查找下一个可以的尺寸
        int try = currentLen-1;
        begin++;
        while (end < ASize) {

        }

    } else
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

