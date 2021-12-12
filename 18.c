//
// Created by pyxisha on 2021/3/14.
//



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

static int int_com(const void *a, const void* b)
{
    return *((int *)a) - *((int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes)
{
    int array_size = 1000;
    int **ret;
    int (*ret_v)[4] = NULL;
    int *retC;
    int i, j, lo, hi, sum;
    int array_index = 0;

    qsort(nums, numsSize, sizeof(int), int_com);
    ret_v = malloc(sizeof(int) * 4 * array_size);

    for (i = 0; i < numsSize - 3; i++)
    {
        if (i == 0 || nums[i] != nums[i - 1]) {
            for (j = i + 1; j < numsSize - 2; j++)
            {
                if (j == i + 1 || nums[j] != nums[j - 1])
                {
                    lo = j + 1;
                    hi = numsSize - 1;
                    while (lo < hi) {
                        sum = nums[i] + nums[j] + nums[lo] + nums[hi];
                        if (sum < target) lo++;
                        else if (sum > target) hi--;
                        else {
                            ret_v[array_index][0] = nums[i];
                            ret_v[array_index][1] = nums[j];
                            ret_v[array_index][2] = nums[lo];
                            ret_v[array_index][3] = nums[hi];
                            array_index++;
                            if (array_index >= array_size) {
                                array_size += 1000;
                                ret_v = realloc(ret_v, array_size * 4 * sizeof(int));
                            }
                            while (lo < hi && nums[lo + 1] == nums[lo]) lo++;
                            while (lo < hi && nums[hi - 1] == nums[hi]) hi--;
                            lo++;
                            hi--;
                        }
                    }
                }
            }
        }
    }

    *returnSize = array_index;
    ret = malloc(sizeof(int *) * array_size);
    for (i = 0; i < array_index; i++)
        ret[i] = ret_v[i];

    retC = malloc(sizeof(int) * array_size);
    for (i = 0; i < array_index; i++)
        retC[i] = 4;

    *returnColumnSizes = retC;

    return ret;
}