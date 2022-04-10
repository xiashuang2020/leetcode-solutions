//
// Created by pyxisha on 2022/3/30.
//

int rob2(int* nums, int numsSize){
    int max_without = 0;
    int max_with = nums[0];

    if (numsSize <= 0)
        return 0;

    for (int i = 1; i < numsSize; ++i) {
        int new_max_with = max_without + nums[i];
        int new_max_without = max_with > max_without ? max_with : max_without;
        max_with = new_max_with;
        max_without = new_max_without;
    }

    return max_with > max_without ? max_with : max_without;
}

int rob(int* nums, int numsSize){
    int m1 = rob2(nums + 1, numsSize - 1);
    int m2 = nums[0] + rob2(nums + 2, numsSize - 3);

    return m1 > m2 ? m1 : m2;
}

#include <stdio.h>

int main(void)
{
    int test1[3] = {2, 3, 2};
    int test2[4] = {1, 2, 3, 1};
    int test3[3] = {1, 2, 3};

    printf("%d\n", rob(test1, 3));
    printf("%d\n", rob(test2, 4));
    printf("%d\n", rob(test3, 3));
}