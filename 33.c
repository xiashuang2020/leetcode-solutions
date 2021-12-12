//
// Created by pyxisha on 2021/5/3.
//

#include <stdio.h>

/* 想清楚情况即可，难度不大 */

int search(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize;
    int mid;

    while (lo < hi) {
        mid = (lo + hi) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > nums[lo]) {
            if (target < nums[lo])
                lo = lo == mid ? lo + 1 : mid;
            else if (target < nums[mid])
                hi = mid;
            else if (target > nums[mid])
                lo = lo == mid ? lo + 1 : mid;
        } else {
            if (target < nums[mid])
                hi = mid;
            else if (target <= nums[hi - 1])
                lo = lo == mid ? lo + 1 : mid;
            else if (target > nums[hi - 1])
                hi = mid;

        }
    }

    return -1;
}

int main(void)
{
    int arr[10] = {4, 5, 6, 7, 8, 9, 0, 1, 2, 3};
    int arr2[1] = {1};
    int arr3[7] = {4, 5, 6, 7, 0, 1, 2};
    int arr4[3] = {5, 1, 3};
    printf("%d\n", search(arr, 10, 7));
    printf("%d\n", search(arr2, 1, 0));
    printf("%d\n", search(arr3, 7, 3));
    printf("%d\n", search(arr3, 7, 0));
    printf("%d\n", search(arr4, 3, 3));
}