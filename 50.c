//
// Created by pyxisha on 2021/5/23.
//

#include <stdio.h>

double myPow(double x, int n) {
    double ret = 1;
    int i;
    long iter;

    if (x == 1.0)
        return ret;

    if (x == -1.0) {
        if (n % 2 == 0)
        {
            return 1.0;
        } else {
            return -1.0;
        }
    }


    if (n < 0) {
        iter = -1 * (long)n;
        x = 1 / x;
    } else {
        iter = n;
    }

    for (i = 0; i < iter; i++) {
        ret *= x;
        if (ret == 0)
            return ret;
    }

    return ret;
}

int main(void)
{
    printf("%lf", myPow(2, -2));
}
