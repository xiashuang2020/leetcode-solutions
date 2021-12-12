//
// Created by pyxisha on 2021/6/27.
//

#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct numWithOriIndex {
    int num;
    int idx;
};

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    struct numWithOriIndex *arr = malloc(numsSize * sizeof(struct numWithOriIndex));
    struct numWithOriIndex *temp = malloc(numsSize * sizeof(struct numWithOriIndex));
    int *ret = calloc(sizeof(int) * numsSize, 1);

    for (int i = 0; i < numsSize; ++i) {
        arr[i].num = nums[i];
        arr[i].idx = i;
    }

    *returnSize = numsSize;
    int n = 1;
    while (n < numsSize) {
        int i = 0;
        int j = 0;
        while (i * 2 * n  + n < numsSize) {
            int left_index = i * 2 * n;
            int left_end = i * 2 * n + n;
            int right_index = i * 2 * n + n;
            int right_end = i * 2 * n + 2 * n;

            if (right_end > numsSize)
                right_end = numsSize;

            int rightAccessLeft = 0;
            while (left_index < left_end || right_index < right_end) {
                if (left_index >= left_end)
                    temp[j++] = arr[right_index++];
                else if (right_index >= right_end || arr[left_index].num <= arr[right_index].num) {
                    ret[arr[left_index].idx] += rightAccessLeft;
                    temp[j++] = arr[left_index++];
                }
                else {
                    temp[j++] = arr[right_index++];
                    rightAccessLeft++;
                }
            }
            i++;
        }
        while (j < numsSize) {
            temp[j] = arr[j];
            j++;
        }

        void *tmp = arr;
        arr = temp;
        temp = tmp;
        n *= 2;
    }


    return ret;
}

int main(void)
{
    int *ret;
    int test[4] = {5, 2, 6, 1};
    int ret_size;

    ret = countSmaller(test, 4, &ret_size);

    for (int i = 0; i < ret_size; ++i) {
        printf("%d ", ret[i]);
    }

    printf("\n");
    return 0;
}