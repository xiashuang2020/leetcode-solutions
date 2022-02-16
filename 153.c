//
// Created by pyxisha on 2022/2/14.
//

#include <stdio.h>

int findMin(int* nums, int numsSize) {
    if (numsSize == 1)
        return nums[0];

    int lo = 0;
    int hi = numsSize - 1;

    while (lo < hi)
    {
        int a = nums[lo];
        int b = nums[hi];
        if (lo + 1 == hi) {
            return a < b ? a : b;
        }
        int mid = (lo + hi) / 2;
        int m = nums[mid];

        if (m > a) {
            if (m > b) {
                lo = mid;
            } else {
                hi = mid;
            }
        } else {
            hi = mid;
        }
    }

    return nums[lo];
}

int main(void) {
    int test1[5] = {3, 4, 5, 1, 2};
    int test2[7] = {4,5,6,7,0,1,2};
    int test3[4] = {11, 13, 15, 17};

    printf("%d\n", findMin(test1, 5));
    printf("%d\n", findMin(test2, 6));
    printf("%d\n", findMin(test3, 4));
}