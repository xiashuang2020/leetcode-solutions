//
// Created by pyxisha on 2021/12/12.
//

long long subArrayRanges(int* nums, int numsSize) {
    int dp[numsSize][2];
    int len = 2;
    long long ret = 0;

    for (int i = 0; i < numsSize; ++i) {
        dp[i][0] = dp[i][1] = nums[i];
    }

    while (len <= numsSize) {
        for (int i = 0; i <= numsSize - len; ++i) {
            int m = dp[i][0] > nums[i + len - 1] ? dp[i][0] : nums[i + len - 1];
            int n = dp[i][1] < nums[i + len - 1] ? dp[i][1] : nums[i + len - 1];
            ret += m - n;
            dp[i][0] = m;
            dp[i][1] = n;
        }
        len++;
    }

    return ret;
}

#include <stdio.h>
int main(void)
{
    int arr1[3] = {1,2,3};
    printf("%lld\n", subArrayRanges(arr1, 3));
    int arr2[5] = {4,-2,-3,4,1};
    printf("%lld\n", subArrayRanges(arr2, 5));
}