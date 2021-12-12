//
// Created by pyxisha on 2021/9/16.
//

#include <stdlib.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int *dp = calloc(pricesSize * 2 * sizeof(int), 1);
    int premin = prices[0];
    dp[0] = 0;


    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] < premin) {
            premin = prices[i];
        }
        if (prices[i] - premin > dp[i - 1])
            dp[i] = prices[i] - premin;
        else
            dp[i] = dp[i - 1];
    }

    dp[pricesSize] = 0;
    premin = prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        if (prices[i] - dp[i - 1] < premin)
            premin = prices[i] - dp[i - 1];
        dp[i + pricesSize] = dp[i + pricesSize - 1];
        if (prices[i] - premin > dp[i + pricesSize])
            dp[i + pricesSize] = prices[i] - premin;
    }

    int ret = dp[2 * pricesSize - 1];
    free(dp);
    return ret;
}

int main(void)
{
    int test[7] = {1, 7, 6, 2, 10, 3, 15};
    int test2[8] = {3, 3, 5, 0, 0, 3, 1, 4};
    int test3[5] = {1, 2, 3, 4, 5};
    int test4[7] = {2,1,4,5,2,9,7};

    printf("%d\n", maxProfit(test2, 8));
    printf("%d\n", maxProfit(test3, 5));
    printf("%d\n", maxProfit(test4, 7));
    return 0;
}