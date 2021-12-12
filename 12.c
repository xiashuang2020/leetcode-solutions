//
// Created by pyxisha on 2021/5/29.
//

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

#include <stdlib.h>
#include <stdio.h>

static int toRoman(char *ret, char one, char five, char ten, int scale, int *num)
{
    int n1 = scale;
    int n2 = 5 * scale;
    int n3 = 10 * scale;
    int n = *num / n3;
    int i = 0;

    if (n > 0) {
        for (int j = 0; j < n; ++j) {
            ret[i++] = ten;
        }
    }

    *num -= n * n3;
    if (*num / (n3 - n1) != 0) {
        ret[i++] = one;
        ret[i++] = ten;
        *num -= (n3 - n1);
    } else if (*num / n2 != 0)
    {
        ret[i++] = five;
        *num -= n2;
    } else if (*num / (n2 - n1) != 0)
    {
        ret[i++] = one;
        ret[i++] = five;
        *num -= (n2 - n1);
    }

    return i;
}

char * intToRoman(int num) {
    char *ret;
    int i = 0;

    ret = calloc(100, 1);
    i += toRoman(ret + i, 'C', 'D', 'M', 100, &num);
    i += toRoman(ret + i, 'X', 'L', 'C', 10, &num);
    i += toRoman(ret + i, 'I', 'V', 'X', 1, &num);
    for (int j = 0; j < num; ++j) {
        ret[i++] = 'I';
    }

    return ret;
}

int main(void)
{
    printf("%s\n", intToRoman(4));
    printf("%s\n", intToRoman(12));
    printf("%s\n", intToRoman(58));
    printf("%s\n", intToRoman(199));
    printf("%s\n", intToRoman(1994));
    printf("%s\n", intToRoman(3999));
}