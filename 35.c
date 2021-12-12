//
// Created by pyxisha on 2021/5/30.
//



int searchInsert(int* nums, int numsSize, int target){
    int lo = 0;
    int hi = numsSize;
    int mid;

    if (target < nums[lo])
        return 0;

    if (target > nums[hi - 1])
        return numsSize;


    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target)
            hi = mid;
        if (nums[mid] < target)
            lo = lo == mid? lo + 1 : mid;
    }

    return hi;
}


#include <stdio.h>
int main(void)
{
    int arr[10] = {1,3,5,6};

    printf("%d\n", searchInsert(arr, 4, 5));
    printf("%d\n", searchInsert(arr, 4, 2));
    printf("%d\n", searchInsert(arr, 4, 7));
    printf("%d\n", searchInsert(arr, 4, 0));
    printf("%d\n", searchInsert(arr, 1, 0));
}

