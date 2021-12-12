//
// Created by pyxisha on 2021/5/30.
//

#include <string.h>

int strStr(char * haystack, char * needle) {
    int n = strlen(needle);
    int l = strlen(haystack);
    int i = 0;

    if (n == 0)
        return 0;

    if (l < n)
        return -1;

    for (i = 0; i <= l - n; i++) {
        if (strncmp(haystack + i, needle, n) == 0)
            return i;
    }

    return -1;

}