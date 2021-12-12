//
// Created by pyxisha on 2021/5/29.
//

#include <stdio.h>

int myAtoi(char * s) {
    int negative = 0;
    char digits[10];
    int n = 0;
    long ret = 0;
    int scale = 1;
    long min = -1 * (1L << 31);
    long max = (1UL << 31) - 1;


    if (!s)
        return 0;

    while (*s == ' ')
        s++;

    if (*s == '+')
        s++;
    else if (*s == '-') {
        negative = 1;
        s++;
    }

    while (*s == '0') {
        s++;
    }

    while ('0' <= *s && *s <= '9' && n < 10) {
        digits[n++] = *s;
        s++;
    }

    if ('0' <= *s && *s <= '9')
        return negative ? min : max;


    for (int i = n - 1; i >= 0; i--) {
        ret += scale * (digits[i] - '0');
        scale *= 10;
    }

    if (negative)
        ret = -1 * ret;

    if (ret < min)
        ret = min;

    if (ret > max)
        ret = max;

    return ret;
}

int main(void)
{
    printf("%d\n", myAtoi("42"));
    printf("%d\n", myAtoi("   -42"));
    printf("%d\n", myAtoi("4193 with words"));
    printf("%d\n", myAtoi("words and 987"));
    printf("%d\n", myAtoi("-91283472332"));
    printf("%d\n", myAtoi("-9128347233"));

}