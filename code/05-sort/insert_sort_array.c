#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 10
// 插入排序

void print_array(int a[], int size);
void swap(int a[], int x, int y);
void inser_sort(int a[], int size);


// 交换数组a中x和y下标的元素值
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
    // 调用insert_sort进行排序
    inser_sort(a, SIZE);
    // 验证排序结果
    print_array(a, SIZE);
}

