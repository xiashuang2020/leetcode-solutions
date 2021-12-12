//
// Created by pyxisha on 2021/5/5.
//

/* 斐波拉契数列 */

int climbStairs(int n) {
    int i;
    int foo[46] = {0};

    foo[0] = 1;
    foo[1] = 1;

    for (i = 2; i <= n; i++) {
        foo[i] = foo[i - 1] + foo[i - 2];
    }

    return foo[i];
}