//
// Created by pyxisha on 2022/4/26.
//


#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int xor = 0;
    int xor1 = 0;
    int xor2 = 0;
    int *ret = calloc(sizeof(int) * 2, 1);

    for (int i = 0; i < numsSize; ++i) {
        xor = xor ^ nums[i];
    }

    xor &= -xor;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] & xor) {
            xor1 = xor1 ^ nums[i];
        } else {
            xor2 = xor2 ^ nums[i];
        }
    }

    ret[0] = xor1;
    ret[1] = xor2;
    *returnSize = 2;
    return ret;
}