//
// Created by pyxisha on 2021/6/6.
//

#include <stdio.h>

int mySqrt(int x) {
    int lo;
    int mid = 1;

    if (x == 0)
        return 0;

    do
    {
        long target = mid * mid;
        if (target == x) {
            return mid;
        } else if (target < x) {
            lo = mid;
            mid = mid * 2;
        } else if (target > x) {
            if (mid - lo == 1) {
                return lo;
            }
            mid = (lo + mid) / 2;
        }
    } while (1);

    return lo;
}

int main(void)
{
    printf("%d\n", mySqrt(8));
    printf("%d\n", mySqrt(9));
    printf("%d\n", mySqrt(25));
    printf("%d\n", mySqrt(24));
}