//
// Created by pyxisha on 2022/4/12.
//


#include <stdio.h>

int countDigitOne(int n) {
    int dp[9];
    int cnt_los[9];
    dp[0] = 1;
    cnt_los[0] = 10;
    int ret = 0;

    for (int i = 1; i < 9; ++i) {
        dp[i] = 9 * dp[i - 1] + 1 * cnt_los[i - 1] + dp[i - 1];
        cnt_los[i] = cnt_los[i - 1] * 10;
    }

    if (n == 0)
        return 0;
    else if (n < 10)
        return 1;

    int i = 0;
    for (; i < 8; ++i) {
        if (n < cnt_los[i + 1])
            break;
    }

    int h = n / cnt_los[i];
    int left = n - h * cnt_los[i];
    int cnt_left = countDigitOne(left);
    ret = h * dp[i] + 1 * (h > 1 ? cnt_los[i] : (left + 1)) + cnt_left;

    return ret;
}

int main(void)
{
    printf("%d\n", countDigitOne(0));
    printf("%d\n", countDigitOne(9));
    printf("%d\n", countDigitOne(10));
    printf("%d\n", countDigitOne(11));
    printf("%d\n", countDigitOne(13));
    printf("%d\n", countDigitOne(99));
    printf("%d\n", countDigitOne(100));
    printf("%d\n", countDigitOne(543));
    printf("%d\n", countDigitOne(999));
    printf("%d\n", countDigitOne(1003));
    printf("%d\n", countDigitOne(1000000000));
}