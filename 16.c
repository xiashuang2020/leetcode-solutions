//
// Created by pyxisha on 2021/3/14.
//

#include <stdlib.h>

static int int_com(const void *a, const void* b)
{
    return *((int *)a) - *((int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int i, lo, hi, sum, delta = -1, new_delta, ret;

    qsort(nums, numsSize, sizeof(int), int_com);

    for (i = 0; i < numsSize - 2; i++)
    {
        lo = i + 1;
        hi = numsSize - 1;
        while (lo < hi)
        {
            sum = nums[i] + nums[lo] + nums[hi];
            new_delta = abs(target - sum);
            if (delta < 0 || new_delta < delta) {
                delta = new_delta;
                ret = sum;
            }
            if (sum < target) lo++;
            else if (sum == target) return target;
            else hi--;
        }
    }

    return ret;
}