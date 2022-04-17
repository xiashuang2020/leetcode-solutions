//
// Created by pyxisha on 2022/4/11.
//



#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize){
    int *ret = calloc(sizeof(int) * 2, 1);
    int major1 = 0;
    int major2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (cnt1 > 0 && major1 == nums[i]) {
            cnt1 += 2;
            cnt2--;
        } else if (cnt2 > 0 && major2 == nums[i]) {
            cnt2 += 2;
            cnt1--;
        } else {
            if (cnt1 <= 0) {
                cnt1 += 2;
                cnt2--;
                if (cnt1 > 0)
                    major1 = nums[i];
            } else if (cnt2 <= 0) {
                cnt2 += 2;
                cnt1--;
                if (cnt2 > 0)
                    major2 = nums[i];
            } else {
                cnt2--;
                cnt1--;
            }
        }
    }

    if (cnt1 > 0) {
        cnt1 = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] == major1)
                cnt1++;
        }
    }

    if (cnt2 > 0) {
        cnt2 = 0;
        for (int i = 0; i < numsSize; ++i) {
            if (nums[i] == major2)
                cnt2++;
        }
    }


    *returnSize = 0;
    if (cnt1 > numsSize / 3) {
        ret[*returnSize] = major1;
        (*returnSize)++;
    }

    if (cnt2 > numsSize / 3) {
        ret[*returnSize] = major2;
        (*returnSize)++;
    }

    return ret;
}

#include <stdio.h>

int main(void)
{
    int test1[2] = {1, 2};
    int test2[3] = {3, 2, 3};
    int test3[7] = {3, 2, 3, 2, 1, 1, 2};
    int test4[4] = {1, 2, 3, 4};
    int *ret;
    int ret_size;

    ret = majorityElement(test1, 1, &ret_size);
    for (int i = 0; i < ret_size; ++i) {
        printf("%d\n", ret[i]);
    }

    ret = majorityElement(test2, 3, &ret_size);
    for (int i = 0; i < ret_size; ++i) {
        printf("%d\n", ret[i]);
    }


    ret = majorityElement(test3, 7, &ret_size);
    for (int i = 0; i < ret_size; ++i) {
        printf("%d\n", ret[i]);
    }

    ret = majorityElement(test4, 4, &ret_size);
    for (int i = 0; i < ret_size; ++i) {
        printf("%d\n", ret[i]);
    }
}