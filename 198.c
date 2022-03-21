//
// Created by xiash on 2022/3/18.
//



int rob(int* nums, int numsSize){
    int max_without = 0;
    int max_with = nums[0];

    for (int i = 1; i < numsSize; ++i) {
        int new_max_with = max_without + nums[i];
        int new_max_without = max_with > max_without ? max_with : max_without;
        max_with = new_max_with;
        max_without = new_max_without;
    }

    return max_with > max_without ? max_with : max_without;
}

#include <stdio.h>
int main(void)
{
    int test[4] = {1, 2, 3, 1};
    int test1[5] = {2,7,9,3,1};
    printf("%d\n", rob(test, 4));
    printf("%d\n", rob(test1, 5));
}