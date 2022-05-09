//
// Created by pyxisha on 2022/5/2.
//



#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int *ret = calloc(sizeof(int) * numsSize, 1);

    int s = 0;
    int e = numsSize - 1;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 2 == 0) {
            ret[s++] = nums[i];
        } else {
            ret[e--] = nums[i];
        }
    }

    *returnSize = numsSize;
    return ret;
}