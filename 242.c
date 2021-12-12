//
// Created by pyxisha on 2021/4/13.
//


#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char * s, char * t) {
    int map[26] = {0};
    unsigned long l;
    int i;

    if (s == NULL && t == NULL)
        return true;

    if (s == NULL || t == NULL)
        return false;

    l = strlen(s);
    if (l != strlen(t))
        return false;

    for (i = 0; i < l; i++) {
        map[s[i] - 'a']++;
        map[t[i] - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (map[i] != 0)
            return false;
    }

    return true;
}