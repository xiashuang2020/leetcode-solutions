//
// Created by xiash on 2022/4/1.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * shortestPalindrome(char *s) {
    int l = strlen(s);
    if (l == 0)
        return s;
    int *kmp = calloc(sizeof(int) * l, 1);

    kmp[0] = 0;
    int len = 0;
    int i = 1;
    while (i < l) {
        if (s[i] == s[len]) {
            len++;
            kmp[i] = len;
            i++;
        } else {
            if (len == 0) {
                kmp[i] = 0;
                i++;
            } else {
                len = kmp[len - 1];
            }
        }
    }

    char *r = malloc(l + 1);
    for (int i = 0; i < l; ++i) {
        r[i] = s[l - i - 1];
    }

    r[i] = 0;
    len = 0;
    i = 0;
    while (i < l) {
        if (s[len] == r[i]) {
            i++;
            len++;
        } else {
            if (len == 0)
                i++;
            else
                len = kmp[len - 1];
        }
    }

    int add_len = l - len;
    char *ret = malloc(add_len + l + 1);
    memcpy(ret, r, add_len);
    memcpy(ret + add_len, s, l + 1);

    return ret;
}

int main(void)
{
    printf(shortestPalindrome("aba"));
    printf("\n");
    printf(shortestPalindrome("abcde"));
    printf("\n");
    printf(shortestPalindrome("catacb"));
    printf("\n");
    printf(shortestPalindrome("aaabaaaa"));
    printf("\n");
}