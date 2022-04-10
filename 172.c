//
// Created by pyxisha on 2022/3/2.
//

#include <stdlib.h>
#include <stdio.h>

int trailingZeroes(int n) {
    int *num5 = calloc(1, sizeof(int) * (n + 1));
    int ret = 0;

    for (int i = 1; i <= n ; ++i) {
        if (i % 5 == 0) {
            num5[i] = num5[i / 5] + 1;
            ret += num5[i];
        }
    }

    return ret;
}

int trailingZeroes1(int n) {
    int t = 5;
    int ret = 0;

    while (t <= n) {
        ret += n / t;
        t = t * 5;
    }

    return ret;
}

int main(void)
{
    printf("%d\n", trailingZeroes(25));
    printf("%d\n", trailingZeroes1(25));
}