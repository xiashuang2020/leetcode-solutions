//
// Created by pyxisha on 2021/3/13.
//

#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *ret = NULL;
    int *delta = NULL;
    int i = 0, j = 0;

    ret = calloc(1, 2 * sizeof(int));
    delta = calloc(1, numsSize * sizeof(int));

    for (i = 0; i < numsSize; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (delta[j] == nums[i])
            {
                ret[0] = j;
                ret[1] = i;
                *returnSize = 2;
                return ret;
            }
        }
        delta[i] = target - nums[i];
    }

    *returnSize = 2;
    return ret;
}