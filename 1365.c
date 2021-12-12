//
// Created by pyxisha on 2021/6/27.
//

#include <stdlib.h>

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    int *ret = malloc(sizeof(int) * numsSize);
    int count[101] = {0};

    for (int i = 0; i < numsSize; ++i) {
        count[nums[i]] += 1;
    }

    for (int i = 1; i < 101; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0)
            ret[i] = 0;
        else
            ret[i] = count[nums[i] - 1];
    }

    *returnSize = numsSize;
    return ret;
}

int main(void)
{
    int ret_size;
    int foo[5] = {8, 1, 2, 2, 3};
    int *ret = smallerNumbersThanCurrent(foo, 5, &ret_size);

    return 0;
}