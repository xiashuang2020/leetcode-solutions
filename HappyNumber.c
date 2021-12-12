//
// Created by pyxisha on 2021/3/19.
//
/* 如何判断是否有环 */

#include <stdbool.h>

int happy_next(int n)
{
    int next = 0;
    int tmp;

    while (n > 0)
    {
        tmp = n % 10;
        next += tmp * tmp;
        n /= 10;
    }

    return next;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;

    while (slow != 1) {
        slow = happy_next(slow);
        fast = happy_next(fast);
        fast = happy_next(fast);
        if (slow != 1 && slow == fast)
            return 0;
    }

    return 1;
}