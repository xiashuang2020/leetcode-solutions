//
// Created by pyxisha on 2022/3/1.
//


#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int count = 1;
    int major = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        if (count == 0) {
            major = nums[i];
            count = 1;
        } else if (nums[i] == major) {
            count++;
        } else {
            count--;
        }
    }

    return major;
}

int main(void)
{
    int test1[7] = {2, 2, 1, 1, 1, 2, 2};
    printf("%d\n", majorityElement(test1, 7));
}