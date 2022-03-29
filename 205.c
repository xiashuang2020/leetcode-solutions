//
// Created by xiash on 2022/3/25.
//

#include <stdbool.h>
#include <string.h>

bool isIsomorphic(char * s, char * t)
{
    char map[128];
    char map2[128] = {0};
    int len = strlen(s);

    if (len != strlen(t)) {
        return false;
    }

    for (int i = 0; i < 128; ++i) {
        map[i] = -1;
    }

    for (int i = 0; i < len; ++i) {
        char a = s[i];
        char b = t[i];

        if (map[a] != -1) {
            if (map[a] != b)
                return false;
        } else {
            if (map2[b] != 0)
                return false;
            map[a] = b;
            map2[b] = 1;
        }
    }

    return true;
}