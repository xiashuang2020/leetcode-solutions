//
// Created by pyxisha on 2021/5/4.
//

#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize){
    int max = 0x80000000;
    int maxsofar = 0;

    for (int i = 0; i < numsSize; ++i) {
        maxsofar += nums[i];
        max = MAX(maxsofar, max);
        if (maxsofar < 0)
            maxsofar = 0;
    }

    return max;
}

int main(void)
{
    int arr1[5] = {5,4,-1,7,8};
    int arr2[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int arr3[1] = {1};

    printf("%d\n", maxSubArray(arr1, 5));
    printf("%d\n", maxSubArray(arr2, 9));
    printf("%d\n", maxSubArray(arr3, 1));
}