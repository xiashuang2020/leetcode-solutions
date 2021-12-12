//
// Created by pyxisha on 2021/5/7.
//

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int idx;

void dfs(int* nums, int numSize, int size, int curr_idx, int *curr, int **ret, int *retCol)
{
    if (curr_idx == size) {
        retCol[idx] = size;
        if (size > 0) {
            ret[idx] = malloc(size * sizeof(int));
            memcpy(ret[idx], curr, sizeof(int) * size);
        }
        idx++;
    }

    for (int i = 0; i < numSize; ++i) {
        curr[curr_idx] = nums[i];
        dfs(nums + i + 1, numSize - i - 1, size, curr_idx + 1, curr, ret, retCol);
    }
}

int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **ret;
    int size = 0;
    int curr[10] = {0};

    ret = malloc(sizeof(int *) * 1024);
    *returnColumnSizes = malloc(sizeof(int) * 1024);
    idx = 0;

    for (size = 0; size <= numsSize; size++) {
        dfs(nums, numsSize, size, 0, curr, ret, *returnColumnSizes);
    }
    *returnSize = idx;
    return ret;
}

int main(void)
{
    int **ret;
    int arr[3] = {1, 2, 3};
    int *retCol;
    int retSize;

    ret = subsets(arr, 3, &retSize, &retCol);
    return 0;
}