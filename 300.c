//
// Created by xiash on 2021/12/19.
//

#include <string.h>
#include <stdio.h>

int dp[2501];

int lengthOfLIS(int* nums, int numsSize) {
    int max = 0;
    
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < numsSize; ++i) {
        int curr = nums[i];
        int pre_idx = 0;
        int lo = 1;
        int hi = max;
        if (hi >= 1 && dp[1] < curr) {
            int mid;
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (lo == mid)
                    mid++;
                if (dp[mid] < curr) {
                    lo = mid;
                } else {
                    hi = hi == mid ? hi - 1 : mid;
                }

            }
            pre_idx = lo;
        }
        int max_end_here = pre_idx + 1;
        if (max_end_here > max || (max_end_here <= max && dp[max_end_here] > curr)) {
            dp[max_end_here] = curr;
        }
        if (max_end_here > max)
            max = max_end_here;
    }

    return max;
}

int main(void)
{
    int test[8] = {10,9,2,5,3,7,101,18};
    int test2[6] = {0,1,0,3,2,3};
    int test3[7] = {7,7,7,7,7,7,7};
    printf("%d\n", lengthOfLIS(test, 8));
    printf("%d\n", lengthOfLIS(test2, 6));
    printf("%d\n", lengthOfLIS(test3, 7));
}