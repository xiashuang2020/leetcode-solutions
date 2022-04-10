//
// Created by pyxisha on 2022/2/17.
//
int findPeakElement(int* nums, int numsSize) {
    int lo = 0;
    int hi = numsSize - 1;

    if (numsSize == 1)
        return 0;

    while (lo < hi) {
        if (nums[lo] > nums[lo + 1])
            return lo;

        if (nums[hi] > nums[hi - 1])
            return hi;

        int mid = (lo + hi) / 2;
        if (nums[mid - 1]  < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;

        if (nums[mid - 1] > nums[mid])
            hi = mid;
        else
            lo = mid;
    }

    return lo;
}