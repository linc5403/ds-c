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

int search(int a[], int size, int target);
void print_list(int a[], int size);

int search(int a[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (a[i] == target) {
            return i;
        }
    }
    return -1;
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
    int a[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
    }

    print_list(a, SIZE);

    int target = atoi(argv[1]);

    int index = search(a, SIZE, target);

    if (index == -1) {
        printf("Not found %d in array\n", target);
    } else {
        printf("Found %d at %d in array\n", target, index);
    }
    
}
