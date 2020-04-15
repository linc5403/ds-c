/*
 * ============================================================================
 *
 *       Filename:  linear-search.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/15/2020 02:53:09 PM
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

#define SIZE 10

int binary_search(int a[], int l, int h, int target);
void print_list(int a[], int size);
void inser_sort(int a[], int size);
void swap(int a[], int x, int y);

void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}
void inser_sort(int a[], int size) {
    for (int i = 1; i < size; i++) {
        // 将第i个元素放到合适的位置
        // i 和 i-1 比，可能交换也可能结束，交换后还要和i-2比
        int j = i;
        while(a[j] < a[j-1]) {
            swap(a, j, j-1);
            j--;
            if (j == 0)
                break;
        }
    }
}

int binary_search(int a[], int l, int h, int target) {
    if (l > h)
        return -1;
    int m = (l + h) / 2;
    if (a[m] == target) {
        return m;
    } else if (a[m] > target){
        // 在左边查找 target
        return binary_search(a, l, m-1, target);
    } else {
        // 在右边查找target
        return binary_search(a, m+1, h, target);
    }
}

void print_list(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    // 生成一个随机数组
    // 在里面查找某个值是否存在
    // 存在则返回其下标
    // 不存在则返回-1
    // int a[SIZE];
    int a[SIZE] = { 10,  17,  41,  46,  57,  67,  80,  80,  90,  92 };
# if 0
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
    }

    inser_sort(a, SIZE);
#endif
    print_list(a, SIZE);

    int target = atoi(argv[1]);

    int index = binary_search(a, 0, SIZE - 1, target);

    if (index == -1) {
        printf("Not found %d in array\n", target);
    } else {
        printf("Found %d at %d in array\n", target, index);
    }
    
}
