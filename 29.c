//
// Created by pyxisha on 2021/5/30.
//

#include <limits.h>
#include <stdio.h>

int divide(int dividend, int divisor) {
    int negative = 1;
    int ret = 0;
    int i;

    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        negative = 0;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;

    if (dividend == INT_MIN && divisor == INT_MIN)
        return 1;

    if (divisor == INT_MIN)
        return 0;

    if (divisor < 0) divisor = divisor - divisor - divisor;
    if (dividend == INT_MIN) {
        dividend += divisor;
        ret += 1;
    }

    if (dividend < 0) dividend = dividend - dividend - dividend;


    while (dividend >= divisor) {
        for (i = 0; dividend - (divisor << i) >= (divisor << i); i++);
        dividend -= divisor << i;
        ret += 1 << i;
    }

    return negative ? ret - ret - ret : ret;
}

int main(void)
{
    printf("%d\n", divide(10, 3));
    printf("%d\n", divide(10, -3));
    printf("%d\n", divide(1000, 1));
    printf("%d\n", divide(1000, -2));
    printf("%d\n", divide(0, -2));
    printf("%d\n", divide(-1, 1));
    printf("%d\n", divide(INT_MIN, 78));
    printf("%d\n", divide(INT_MIN, INT_MIN));
    printf("%d\n", divide(-2, INT_MIN));
    printf("%d\n", divide(1, 1));
}