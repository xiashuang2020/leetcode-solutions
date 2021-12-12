//
// Created by pyxisha on 2021/5/7.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int idx = 0;

static void dfs(int* nums, int level, int numsSize, int *curr, int **ret, int *returnColumnSizes) {
    int exist = 0;

    if (level == numsSize) {
        ret[idx] = malloc(numsSize * sizeof(int));
        memcpy(ret[idx], curr, numsSize * sizeof(int));
        returnColumnSizes[idx] = numsSize;
        idx++;
    }

    for (int i = 0; i < numsSize; ++i) {
        exist = 0;
        for (int j = 0; j < level; ++j) {
            if (curr[j] == nums[i])
                exist = 1;
        }

        if (exist)
            continue;

        curr[level] = nums[i];
        dfs(nums, level + 1, numsSize, curr, ret, returnColumnSizes);
    }

}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **ret;
    int *curr;

    ret = malloc(sizeof(int *) * 720);
    curr = malloc(sizeof(int) *numsSize);
    *returnColumnSizes = malloc(sizeof(int) * 720);
    idx = 0;

    dfs(nums, 0, numsSize, curr, ret, *returnColumnSizes);
    *returnSize = idx;
    return ret;
}

int main(void)
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int **ret;
    int retSize;
    int *retCol;

    ret = permute(arr, 6, &retSize, &retCol);

}