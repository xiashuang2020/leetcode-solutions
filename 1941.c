//
// Created by pyxisha on 2021/7/31.
//


#include <stdbool.h>

bool areOccurrencesEqual(char *s) {
    int dict[26] = {0};
    int idx;

    if (*s != 0)
        idx = *s - 'a';

    while (*s) {
        dict[*s - 'a']++;
        s++;
    }

    int target = dict[idx];
    for (int i = 0; i < 26; ++i) {
        if (dict[i] != 0 && dict[i] != target)
            return false;
    }

    return true;
}