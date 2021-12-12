//
// Created by pyxisha on 2021/5/30.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 420
#define SWAP(a, b) do {__typeof__(a) tmp = a; a = b; b = tmp;} while(0)

static char *malloc_empty()
{
    char *ret = malloc(MAX);
    for (int l = 0; l < MAX; ++l) {
        ret[l] = '0';
    }
    return ret;
}


char *multiplyOne(char *num, char k, int n)
{
    int i, j;
    int base = 0; int carry = 0;
    int len = strlen(num);
    char *ret = malloc_empty();

    for (i = 0; i < n; i++)
        ret[i] = '0';

    for (j = len - 1; j >= 0; j--) {
        base = ((num[j] - '0') * k  + carry) % 10;
        carry = ((num[j] - '0') * k  + carry) / 10;
        ret[i++] = '0' + base;
    }

    ret[i++] = '0' + carry;
    return ret;
}

char *add(char *num1, char* num2)
{
    int i, carry = 0, base = 0;
    char *ret = malloc_empty();

    for (i = 0; i < MAX; i++) {
        base = (carry + (num1[i] - '0') + (num2[i] - '0')) % 10;
        carry = (carry + (num1[i] - '0') + (num2[i] - '0')) / 10;
        ret[i] = '0' + base;
    }

    return ret;
}

char *multiply(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *prev = malloc_empty();
    char *new_prev;


    if (len1 < len2) {
        SWAP(num1, num2);
        SWAP(len1, len2);
    }

    if (num1[0] == '0' || num2[0] == '0')
        return "0";

    for (int i = 0; i < len2; i++) {
        char *pass = multiplyOne(num1, num2[len2 - i - 1] - '0', i);
        //printf("%s\n", pass);
        new_prev = add(pass, prev);
        free(pass);
        free(prev);
        prev = new_prev;
    }

    for (int i = MAX - 1; i >= 0 ; i--) {
        if (prev[i] != '0') {
            for (int j = 0; j <= i / 2; ++j) {
                SWAP(prev[j], prev[i - j]);
            }
            prev[i + 1] = 0;
            break;
        }
    }

    return prev;
}

int main(void)
{
    //printf("%s\n", multiply("123", "0"));
    printf("%s\n", multiply("9", "9"));

    return 0;
}