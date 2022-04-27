//
// Created by xiash on 2022/4/27.
//

#include <stdlib.h>
#include <stdio.h>

int nthUglyNumber(int n)
{
    int *dp = calloc(sizeof(int), n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;

    for (int i = 2; i <= n ; ++i) {
        int a = dp[p2] * 2;
        int b = dp[p3] * 3;
        int c = dp[p5] * 5;
        if (a <= b && a <= c) {
            dp[i] = a;
            p2++;
        }
        if (b <= a && b <= c) {
            dp[i] = b;
            p3++;
        }
        if (c <= a && c <= b) {
            dp[i] = c;
            p5++;
        }
    }

    return dp[n];
}

int main(void)
{
    for (int i = 1; i <= 30 ; ++i) {
        printf("%d\n", nthUglyNumber(i));
    }
}