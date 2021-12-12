//
// Created by pyxisha on 2021/5/30.
//



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = malloc(sizeof(int) * 2);
    int lo = 0; int hi = numsSize, mid;
    int lomid = 0; int himid = 0, lohi = 0, hilo = 0;

    *returnSize = 2;

    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (target < nums[lo])
            break;
        else if (target > nums[hi - 1])
            break;
        else if (nums[mid] == target)
            goto find;
        else if (target < nums[mid]) {
            hi = mid;
        } else {
            lo = lo == mid ? mid + 1 : mid;
        }
    }

    ret[0] = -1;
    ret[1] = -1;
    return ret;

    find:
    lohi = mid;
    while (lo < lohi) {
        lomid = (lo + lohi) / 2;
        if (nums[lomid] < target)
            lo = lo == lomid ? lo + 1 : lomid;
        else if (nums[lomid] == target ) {
            lohi = lomid;
        }
    }

    ret[0] = lohi;
    hilo = mid;

    while (hilo < hi) {
        himid = (hilo + hi) / 2;
        if (nums[himid] > target)
            hi = himid;
        else if (nums[himid] == target)
            hilo = hilo == himid ? himid + 1 : himid;
    }

    ret[1] = hilo - 1;

    return ret;
}



int main(void)
{
    int arr[20] = {5,7,7,8,8,10};
    int retsize;
    int arr2[20] = {1,2,3,3,3,3,4,5,9};

    int *ret = searchRange(arr, 6, 8, &retsize);
    printf("%d %d\n", ret[0], ret[1]);

    ret = searchRange(arr, 6, 6, &retsize);
    printf("%d %d\n", ret[0], ret[1]);

    ret = searchRange(arr, 6, 7, &retsize);
    printf("%d %d\n", ret[0], ret[1]);

    ret = searchRange(arr, 0, 7, &retsize);
    printf("%d %d\n", ret[0], ret[1]);

    ret = searchRange(arr2, 9, 3, &retsize);
    printf("%d %d\n", ret[0], ret[1]);

}