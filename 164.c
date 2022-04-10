//
// Created by pyxisha on 2022/2/21.
//

#include <stdio.h>
#include <stdlib.h>

int maximumGap(int* nums, int numsSize) {
    int max;
    int min;
    int gap;
    int *bucket_min;
    int *bucket_max;
    int ret = 0;

    if (numsSize < 2) {
        return 0;
    }

    max = nums[0];
    min = nums[0];

    for (int i = 0; i < numsSize; ++i) {
        max = nums[i] > max ? nums[i] : max;
        min = nums[i] < min ? nums[i] : min;
    }

    if (max == min)
        return 0;

    gap = (max - min) / (numsSize - 1);
    if (gap == 0)
        gap = 1;
    int bucket_size = ((max - min) / gap + 1);
    bucket_min = malloc(sizeof(int) * bucket_size);
    bucket_max = malloc(sizeof(int) * bucket_size);

    for (int i = 0; i < bucket_size; ++i) {
        bucket_max[i] = -1;
        bucket_min[i] = 0x7fffffff;
    }

    for (int i = 0; i < numsSize; ++i) {
        int bucket = (nums[i] - min) / gap;
        //printf("%d\n", bucket);
        if (bucket_min[bucket] > nums[i])
            bucket_min[bucket] = nums[i];
        if (bucket_max[bucket] < nums[i])
            bucket_max[bucket] = nums[i];
    }

    int a = -1;
    int b = 0x7fffffff;
    for (int i = 0; i < bucket_size; ++i) {
        b = bucket_min[i];
        if (a != -1 && b != 0x7fffffff && b - a > ret)
            ret = b - a;
        if (bucket_max[i] != -1)
            a = bucket_max[i];
    }

    free(bucket_max);
    free(bucket_min);

    return ret;
}

int main(void)
{
    int test1[4] = {3,6,9,1};
    int test2[4] = {100,3,2,1};
    int test3[10] = {1,1,1,1,1,5,5,5,5,5};
    int test4[2] = {1, 1000000};

    printf("%d\n", maximumGap(test1, 4));
    printf("%d\n", maximumGap(test2, 4));
    printf("%d\n", maximumGap(test3, 10));
    printf("%d\n", maximumGap(test4, 2));
}