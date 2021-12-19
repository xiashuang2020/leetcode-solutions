//
// Created by xiash on 2021/12/19.
//

int dp[10001];

int kIncreasing(int* arr, int arrSize, int k) {
    int ret = 0;

    for (int i = 0; i < k; ++i) {
        int s = 0;
        dp[0] = 0;
        for (int j = 0; i + j * k < arrSize; ++j) {
            int pre_idx = 0;
            int curr = arr[i + j * k];
            for (int l = s; l > 0; --l) {
                if (curr >= dp[l]) {
                    pre_idx = l;
                    break;
                }
            }
            int max_end_so_far = pre_idx + 1;
            if (max_end_so_far > s) {
                s = max_end_so_far;
                dp[max_end_so_far] = curr;
            } else if (dp[max_end_so_far] > curr){
                dp[max_end_so_far] = curr;
            }
        }
        ret += s;
    }

    return arrSize - ret;
}

#include <stdio.h>
int main(void)
{
    int test1[18] = {12,6,12,6,14,2,13,17,3,8,11,7,4,11,18,8,8,3};
    int test2[5] = {5,4,3,2,1};
    int test3[6] = {4,1,5,2,6,2};
    printf("%d\n", kIncreasing(test1, 18, 1));
    printf("%d\n", kIncreasing(test2, 5, 1));
    printf("%d\n", kIncreasing(test3, 6, 2));
    printf("%d\n", kIncreasing(test3, 6, 3));

}