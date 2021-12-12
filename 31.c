//
// Created by pyxisha on 2021/4/12.
//

#include <stdio.h>

/* 有难度
 * 找到第一个 nums[j] < nums[j + 1] 的数字
 * 从后往前找到第一个大于j的数字t
 * 交换t和j， j + 1后的数从小到大排列
 * */

static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void nextPermutation(int *nums, int numsSize) {
    int i, j, l, t;

    if (numsSize < 2)
        return;

    l = 2;
    while (l <= numsSize) {
        j = numsSize - l;
        if (nums[j] < nums[j + 1]) {
            t = numsSize - 1;
            while (nums[t] <= nums[j]) t--;

            swap(nums + j, nums + t);

            for (i = j + 1; i < (j + 1 + numsSize) / 2; i++) {
                swap(nums + i, nums + numsSize - i + j);
            }
            return;
        }
        l++;
    }

    for (i = 0; i < numsSize / 2; i++) {
        swap(nums + i, nums + numsSize - i - 1);
    }
}

int main(void) {
    int arr1[2] = {1, 2};
    int arr2[5] = {3, 4, 5, 2, 1};
    int arr3[5] = {5, 4, 3, 2, 1};
    int arr4[8] = {4, 5, 6, 9, 8, 7, 3, 2};
    int arr5[8] = {4, 5, 6, 10, 9, 8, 7, 3};
    int arr6[8] = {4, 5, 6, 8, 7, 3, 2, 1};
    int arr7[3] = {1, 5, 1};

    nextPermutation(arr1, 2);
    nextPermutation(arr2, 5);
    nextPermutation(arr3, 5);
    nextPermutation(arr4, 8);
    nextPermutation(arr5, 8);
    nextPermutation(arr6, 8);
    nextPermutation(arr7, 3);
}