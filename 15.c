//
// Created by pyxisha on 2021/3/13.
//

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/*
 * qosrt addr size size*size cmp
 * 固定一个数
 */

#include <stdlib.h>

static int compare_int(const void* a, const void *b)
{
    int num1 = *((int *)a);
    int num2 = *((int *)b);

    if (num1 > num2) {
        return 1;
    } else if(num1 == num2) {
        return 0;
    } else {
        return -1;
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int array_size = 1000;
    int i, lo, hi, sum;
    int (*ret_v)[3];
    int **ret;
    int answer_idx = 0;
    int *ret_column;

    qsort(nums, numsSize, sizeof(int), compare_int);

    ret_v = malloc(array_size * 3 * sizeof(int));

    for (i = 0; i < numsSize - 2; i++) {
        if (i == 0 || nums[i] != nums[i - 1]) {
            lo = i + 1;
            hi = numsSize - 1;
            while (lo < hi) {
                sum = nums[lo] + nums[hi] + nums[i];
                if (sum == 0) {
                    ret_v[answer_idx][0] = nums[i];
                    ret_v[answer_idx][1] = nums[lo];
                    ret_v[answer_idx][2] = nums[hi];
                    answer_idx++;
                    if (answer_idx >= array_size) {
                        array_size += 1000;
                        ret_v = realloc(ret_v, array_size * 3 * sizeof(int));
                    }
                    while (lo + 1 < numsSize && nums[lo + 1] == nums[lo]) lo++;
                    while (hi - 1 > 0 && nums[hi - 1] == nums[hi]) hi--;
                    lo++;
                    hi--;
                } else if (sum < 0) {
                    lo++;
                } else {
                    hi--;
                }
            }
        }
    }

    *returnSize = answer_idx;
    ret_column = malloc(answer_idx * sizeof(int));
    for (i = 0; i < answer_idx; i++)
        ret_column[i] = 3;

    ret = malloc(answer_idx * sizeof(int *));
    for (i = 0; i < answer_idx; i++)
        ret[i] = ret_v[i];

    *returnColumnSizes = ret_column;
    return ret;
}