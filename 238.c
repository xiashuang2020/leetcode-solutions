//
// Created by pyxisha on 2022/4/21.
//



#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *ret = calloc(sizeof(int) * numsSize, 1);

    ret[0] = 1;
    for (int i = 1; i < numsSize; ++i) {
        ret[i] = ret[i - 1] * nums[i - 1];
    }

    int right = 1;
    for (int i = numsSize - 1; i >= 0 ; i--) {
        ret[i] *= right;
        right *= nums[i];
    }

    *returnSize = numsSize;
    return ret;
}