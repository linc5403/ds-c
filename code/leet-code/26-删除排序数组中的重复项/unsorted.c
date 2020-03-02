/*
 * ============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/01/2020 03:19:27 PM
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

int removeDuplicates(int* nums, int numsSize);

int main(int argc, char** argv) {
    int nums[7]={0,1,2,5,1,2,3};
    int len=7;
    len=removeDuplicates(nums,len);
    printf("len is %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%4d", nums[i]);
    }
    printf("\n");
}


int removeDuplicates(int* nums, int numsSize) {
    int i = 1; // 遍历的下标
    int j = 0; // 已经排好的最后一个下标

    for (; i < numsSize; i++) {
        int exist = 0;
        for(int k = 0; k <= j; k++) {
            if (nums[k] == nums[i]) {
                exist = 1;
                break;
            }
        }
        if (!exist) {
            nums[j+1] = nums[i];
            j++;
        }
    }
    return j+1;
}
