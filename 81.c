//
// Created by pyxisha on 2021/5/3.
//

#include <stdio.h>
#include <stdbool.h>

/* mid == lo的情况 */

int search(int* nums, int numsSize, int target) {
    int lo = 0;
    int hi = numsSize;
    int mid;

    while (lo < hi) {
        mid = (lo + hi) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[mid] > nums[lo]) {
            if (target < nums[lo])
                lo = lo == mid ? lo + 1 : mid;
            else if (target < nums[mid])
                hi = mid;
            else if (target > nums[mid])
                lo = lo == mid ? lo + 1 : mid;
        } else if (nums[mid] < nums[lo]) {
            if (target < nums[mid])
                hi = mid;
            else if (target <= nums[hi - 1])
                lo = lo == mid ? lo + 1 : mid;
            else if (target > nums[hi - 1])
                hi = mid;
        } else {
            lo++;
        }
    }

    return false;
}

int main(void)
{
    int arr[10] = {2,5,6,0,0,1,2};
    int arr2[19] = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int arr3[22] = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};
    printf("%d\n", search(arr, 7, 0));
    printf("%d\n", search(arr, 7, 3));
    printf("%d\n", search(arr2, 19, 2));
    printf("%d\n", search(arr3, 22, 13));



}