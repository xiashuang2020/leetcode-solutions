//
// Created by pyxisha on 2021/5/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int **ret;
static int ret_size = 0;
static int *ret_col_size;

static void dfs(int *nums, int *curr, int numsSize, int level) {
    int *new_nums;
    int n = -11;
    int i = 0, j = 0, k = 0;

    if (numsSize == 1) {
        curr[level++] = nums[0];
        ret[ret_size] = malloc(sizeof(int) * level);
        memcpy(ret[ret_size], curr, level * sizeof(int));
        ret_col_size[ret_size] = level;
        ret_size++;
        return;
    }

    new_nums = malloc(sizeof(int) * (numsSize - 1));
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == n)
            continue;

        n = curr[level] = nums[i];
        k = 0;
        for (j = 0; j < numsSize; j++) {
            if (j != i)
                new_nums[k++] = nums[j];
        }
        dfs(new_nums, curr, numsSize - 1, level + 1);
    }
}

static int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    int curr[10];
    ret = malloc(sizeof(int *) * 40320);
    ret_col_size = malloc(sizeof(int) * 40320);
    ret_size = 0;


    qsort(nums, numsSize, sizeof(int), cmp);
    dfs(nums, curr, numsSize, 0);
    *returnSize = ret_size;
    *returnColumnSizes = ret_col_size;

    return ret;
}

int main(void)
{
    int *retColSize;
    int retSize;
    int **retf;
    int nums[3] = {1, 2, 1};
    int nums2[3] = {1, 2, 3};
    int nums3[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    permuteUnique(nums, 3, &retSize, &retColSize);
    printf("%d\n", retSize);
    permuteUnique(nums2, 3, &retSize, &retColSize);
    printf("%d\n", retSize);
    permuteUnique(nums3, 8, &retSize, &retColSize);
    printf("%d\n", retSize);


    return 0;
}