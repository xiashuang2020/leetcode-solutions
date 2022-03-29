//
// Created by xiash on 2022/3/28.
//



int minSubArrayLen(int target, int* nums, int numsSize){
    int ret = 0;
    int len = 0;
    int i = 0;
    int j = 0;
    int sum = 0;

    while (i < numsSize && j <= numsSize) {
        if (sum < target) {
            if (j == numsSize)
                return ret;
            sum += nums[j];
            j++;
            len++;
        } else {
            if (ret == 0 || len < ret)
                ret = len;
            sum -= nums[i];
            i++;
            len--;
        }
    }

    return ret;
}

#include <stdio.h>
int main(void)
{
    int test1[6] = {2,3,1,2,4,3};
    int test2[3] = {1, 4, 4};
    int test3[8] = {1,1,1,1,1,1,1,1};
    int test4[5] = {1,2,3,4,5};
    printf("%d\n", minSubArrayLen(7, test1, 6));
    printf("%d\n", minSubArrayLen(4, test2, 4));
    printf("%d\n", minSubArrayLen(11, test3, 8));
    printf("%d\n", minSubArrayLen(11, test4, 5));
}