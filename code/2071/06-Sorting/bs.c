/*
 * ============================================================================
 *
 *       Filename:  bs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/18/2020 04:04:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  lin chuan , linch1982@gmail.com
 *   Organization:  
 *
 * ============================================================================
 */
#include <stdlib.h>
#include "mylib.h"
#include "bs.h"

int binary_search(int a[], int begin, int end, int target);

int binary_search(int a[], int begin, int end, int target) {
    // 处理出错的情况
    if (begin >= end)
        return -1;
    // 处理只有一个元素的情况
    if (begin+1 == end) {
        if (a[begin] != target)
            return -1;
        else
            return begin;
    }
    // 处理多个元素
    int m = (begin + end) / 2;
    if (a[m] == target)
        return m;
    else if (a[m] < target)
        return binary_search(a, m+1, end, target);
    else
        return binary_search(a, begin, m, target);
}

int bs(int a[], int size, int target) {
    return binary_search(a, 0, size, target);
}

