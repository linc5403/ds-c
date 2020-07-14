#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10
// 选择排序

void print_array(int a[], int size);
int find_min(int a[], int begin, int end);
void select_sort(int a[], int size);
void swap(int a[], int x, int y);

// 从数组a的begin到end中选择最下的那个元素，返回其下标
int find_min(int a[], int begin, int end) {
    int min_index = begin;
    for (int i = min_index + 1; i <= end; i++) {
        if (a[i] < a[min_index]) {
            min_index = i;
        }
    }
    return min_index;
//    return 下标;
}

// 交换数组a中x和y下标的元素值
void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}


// void select_sort(int *a, int size) {
void select_sort(int a[], int size) {
    /*
    从n个元素中选择最小的那个，放到0号位置
    从n-1个元素中选择最小的那个，放到1号位置
    从n-2个元素中选择最小的那个，放到2号位置
    从n-3个元素中选择最小的那个，放到3号位置
    。。。
    从2个元素中选择最小的那个，放到n-2号位置
     1. 从一堆数字里面选择最小的那个？？
     2. 交换位置
     */
    
    for (int i = 0; i < size-1; i++) {
        int min = find_min(a, i, size-1);
        if (i != min)
            swap(a, min, i);
    }
    
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int main() {
    // 构造测试数据
    int a[SIZE];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % 100;
    }
    print_array(a,SIZE);
    // 调用select_sort进行排序
    select_sort(a, SIZE);
    // 验证排序结果
    print_array(a, SIZE);
}

