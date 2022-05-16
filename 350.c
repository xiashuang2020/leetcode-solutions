//
// Created by pyxisha on 2022/5/16.
//


#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *bucket1 = calloc(sizeof(int) * 1001, 1);
    int *bucket2 = calloc(sizeof(int) * 1001, 1);
    int *ret = calloc(sizeof(int) * 1001, 1);

    for (int i = 0; i < nums1Size; ++i) {
        bucket1[nums1[i]]++;
    }

    for (int i = 0; i < nums2Size; ++i) {
        bucket2[nums2[i]]++;
    }

    int j = 0;
    for (int i = 0; i <= 1000; ++i) {
        while (bucket1[i] > 0 && bucket2[i] > 0) {
            ret[j] = i;
            j++;
            bucket1[i]--;
            bucket2[i]--;
        }
    }

    *returnSize = j;
    return  ret;
}