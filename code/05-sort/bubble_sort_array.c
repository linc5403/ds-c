#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 1000
// 冒泡排序

void print_array(int a[], int size);
void swap(int a[], int x, int y);
void bubble_sort(int a[], int size);


// 交换数组a中x和y下标的元素值
void swap(int a[], int x, int y) {
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}


void bubble_sort(int a[], int size) {
    // 什么时候结束？？
    int swapped = 1; // 1->交换过，0->没有交换过
    for (int i = 0; i < size-1; i++) {
        swapped = 0;
        // 从下标开始，往右边进行比较和交换，使得大的数往右边跑
        // 小的数会往左边跑
        /* 如何判断当前的数组排序已经完成 */
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a, j, j+1);
                swapped = 1;
            }
        }
        if (swapped == 0) {
            // 一次交换都没有发生，那么表示当前的数组排序已经完成
            printf("一共进行了%d冒泡\n", i+1);
            break;
        }
    }
}


void print_array(int a[], int size) {
    for (int i = 0; i < size; i++)
        printf("%4d", a[i]);
    printf("\n");
}

int main() {
    // 构造测试数据
    // int a[SIZE] = {42,  78,  27};
    // i = 0 -> {42, 27, 78} 
    // j 也要从0开始
    int a[SIZE];

#if 1
    srand((unsigned int)time(NULL));
    for (int i = 0; i < SIZE; i++) {
        a[i] = rand() % SIZE;
    }
#endif
    // print_array(a,SIZE);
    // 调用bubble_sort进行排序
    bubble_sort(a, SIZE);
    // 验证排序结果
    // print_array(a, SIZE);
}

