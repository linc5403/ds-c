/*
 * ============================================================================
 *
 *       Filename:  max.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2020 10:04:56 PM
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

int rob(int* nums, int numsSize);

int rob(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    else if (numsSize == 1)
        return nums[0];

    int* max = malloc(sizeof(int) * (numsSize+1));
    max[0] = 0;
    max[1] = nums[0];
    max[2] = (nums[0] > nums[1]? nums[0]: nums[1]);

    for (int i = 2; i < numsSize; i++) {
        int max_with_i = max[i-1] + nums[i];
        max[i+1] = max[i] >  max_with_i? max[i]: max_with_i;
    }
    return max[numsSize];
}


int main() {
    //int a[] = {1, 2, 3, 1};
    int a[] = {1, 3, 1, 3, 100};
    //int a[] = {1, 3, 1, 3};
    printf("%d\n", rob(a, sizeof(a)/ sizeof(a[0])));
}
