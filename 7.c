//
// Created by pyxisha on 2021/4/5.
//

#include <stdio.h>

/* 越界的情况 */

static void int2digits(int x, int *digits, int *digits_num)
{
    *digits_num = 0;

    while (x != 0) {
        digits[*digits_num] = x % 10;
        (*digits_num)++;
        x = x / 10;
    }
}

int reverse(int x) {
    int target = 0;
    int digits[20] = {0};
    int max_digits[20] = {0};
    int least_digits[20] = {0};
    int digits_num = 0, max_digits_num = 0;
    int i = 0, mul = 0;
    int m = 0x7fffffff, l = -1 * m - 1;

    int2digits(x, digits, &digits_num);
    int2digits(m, max_digits, &max_digits_num);
    int2digits(l, least_digits, &max_digits_num);

    if (digits_num == max_digits_num) {
        if (x >= 0) {
            for (i = 0; i < digits_num; i++) {
                if (max_digits[digits_num - i - 1] > digits[i]) {
                    break;
                } else if (max_digits[digits_num - i - 1] < digits[i]) {
                    return 0;
                }
            }
        } else {
            for (i = 0; i < digits_num; i++) {
                if (least_digits[digits_num - i - 1] < digits[i]) {
                    break;
                } else if (least_digits[digits_num - i - 1] > digits[i]) {
                    return 0;
                }
            }
        }

    }

    for (i = digits_num - 1; i >= 0; i--)
    {
        mul = mul == 0 ? 1 : mul * 10;
        target += mul * digits[i];
    }

    return target;
}

int main(void)
{
    printf("reverse %d\n", reverse(123));
    printf("reverse %d\n", reverse(-123));
    printf("reverse %d\n", reverse(120));
    printf("reverse %d\n", reverse(0));
    printf("reverse %d\n", reverse(1534236469));
    printf("reverse %d\n", reverse(-2147483412));
    printf("reverse %d\n", reverse(-2147483419));
}