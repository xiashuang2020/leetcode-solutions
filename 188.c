//
// Created by xiash on 2022/3/25.
//

#include <stdlib.h>
#include <stdio.h>

int maxProfit(int k, int* prices, int pricesSize){
    int *dp = calloc(pricesSize * k * sizeof(int), 1);

    int pre_min = prices[0];
    if (k == 0 || pricesSize <= 1)
        return 0;
    dp[0] = 0;

    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < pre_min)
            pre_min = prices[i];

        int profit = prices[i] - pre_min;
        dp[i] = profit > dp[i - 1] ? profit : dp[i - 1];
    }

    for (int i = 1; i < k; ++i) {
        dp[i * pricesSize] = 0;
        pre_min = prices[0];

        for (int j = 1; j < pricesSize; ++j) {
            if (prices[j] - dp[(i - 1) * pricesSize + j - 1] < pre_min)
                pre_min = prices[j] - dp[(i - 1) * pricesSize + j - 1];
            int profit = prices[j] - pre_min;
            dp[i * pricesSize + j] = profit > dp[i * pricesSize + j - 1] ? profit : dp[i * pricesSize + j - 1];
        }
    }

    int ret = dp[k * pricesSize - 1];
    free(dp);
    return ret;
}


int main(void)
{
    int test[7] = {1, 7, 6, 2, 10, 3, 15};
    int test2[8] = {3, 3, 5, 0, 0, 3, 1, 4};
    int test3[5] = {1, 2, 3, 4, 5};
    int test4[7] = {2,1,4,5,2,9,7};

    printf("%d\n", maxProfit(2, test2, 8));
    printf("%d\n", maxProfit(2, test3, 5));
    printf("%d\n", maxProfit(2, test4, 7));
    return 0;
}