//
// Created by xiash on 2022/4/26.
//

#include <stdlib.h>
#include <stdio.h>

int numSquares(int n)
{
    int *dp = calloc(sizeof(int) * (n + 1), 1);

    for (int i = 1; i * i <=n ; ++i) {
        if (i * i == n)
            return 1;
        dp[i * i] = 1;
    }

    for (int i = 0; i <= n ; ++i) {
        if (dp[i] == 0) {
            for (int j = 1; j * j < i; ++j) {
                if (dp[i] == 0 || dp[i] > dp[j * j] + dp[i - j * j])
                    dp[i] = dp[j * j] + dp[i - j * j];
            }
        }
    }

    return dp[n];
}

int main(void)
{
    printf("%d\n", numSquares(1));
    printf("%d\n", numSquares(2));
    printf("%d\n", numSquares(3));
    printf("%d\n", numSquares(12));
    printf("%d\n", numSquares(81));
    printf("%d\n", numSquares(82));
}