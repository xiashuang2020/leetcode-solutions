//
// Created by pyxisha on 2021/5/28.
//

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int firstMissingPositive(int* nums, int numsSize){
    int i = 0;

    while (i < numsSize) {
        int n = nums[i];
        if (n > 0 && n <= numsSize && n != i + 1 && nums[n - 1] != n)
            swap(nums + i, nums + n - 1);
        else
            i++;
    }

    for (i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1)
            return i + 1;
    }

    return numsSize + 1;
}

int main(void)
{

    int arr1[3] = {1, 2, 3};
    int arr2[4] = {3,4,-1,1};
    int arr3[5] = {7,8,9,11,12};


    printf("%d\n", firstMissingPositive(arr1, 3));
    printf("%d\n", firstMissingPositive(arr2, 4));
    printf("%d\n", firstMissingPositive(arr3, 5));
}