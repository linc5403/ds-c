/**
 * @author      : banyuan (linch1982@gmail.com)
 * @file        : sorted
 * @created     : Monday Mar 02, 2020 09:39:56 CST
 */

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main() {
    int a[] = {0,0,1,1,1,2,2,3,3,4};
    int len = removeDuplicates(a, sizeof(a) / sizeof(int));
    printf("new len is %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%4d", a[i]);
    }
    printf("\n");
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int i = 1; // 遍历数组的下标
    int j = 0; // 已经去除重复项的下标
    for(; i < numsSize; i++) {
        if (nums[i] != nums[j]) {
            // i是不重复项
             if (j + 1 != i) {
                nums[++j] = nums[i];
            } else {
                ++j;
            }
        }
    }
    return j+1;
}
