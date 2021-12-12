//
// Created by pyxisha on 2021/6/5.
//

#include <stdlib.h>
#include <string.h>

#define SWAP(a, b) do { __typeof__(a) tmp = a; a = b; b = tmp;} while (0)

char *addBinary(char *a, char *b)
{
    char *ret = calloc(10001, 1);

    int l1 = strlen(a) - 1;
    int l2 = strlen(b) - 1;
    int i = 0;
    char carry = 0;

    while (l1 >= 0 || l2 >= 0 || carry) {
        char n1 = l1 >= 0 ? a[l1--] - '0' : 0;
        char n2 = l2 >= 0 ? b[l2--] - '0' : 0;

        char x = (n1 + n2 + carry) % 2;
        carry = (n1 + n2 + carry) / 2;
        ret[i++] = x + '0';
    }

    for (int j = 0; j < (i / 2); ++j) {
        SWAP(ret[j], ret[i - j - 1]);
    }

    return ret;
}

#include <stdio.h>

int main(void)
{
    printf("%s\n", addBinary("1111", "101"));
}