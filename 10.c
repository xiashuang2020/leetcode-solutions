//
// Created by pyxisha on 2021/4/18.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* 深度优先搜索 */

bool isMatch(char * s, char * p) {
    int i = 0, j = 0, rep = 0;
    int l1, l2;

    if (s == NULL || p == NULL)
        return false;

    l1 = strlen(s);
    l2 = strlen(p);

    while (j < l2) {
        if (p[j + 1] == '*') {
            rep = 0;
            while (i + rep <= l1) {
                if (isMatch(s + i + rep, p + j + 2))
                    return true;
                else if (p[j] != '.' && s[i + rep] != p[j])
                    return false;
                else
                    rep++;
            }
            return false;
        } else if (i < l1 && (p[j] == '.' || s[i] == p[j])) {
            i++;
            j++;
        } else {
            return false;
        }
    }

    return s[i] == 0 && p[j] == 0;
}

int main(void)
{
    printf("%d\n", isMatch("ab", ".*"));
    printf("%d\n", isMatch("aab", "c*a*b"));
    printf("%d\n", isMatch("mississippi", "mis*is*p*."));
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("ab", ".*c"));
    printf("%d\n", isMatch("abcdefg", ".*"));
    printf("%d\n", isMatch("a", "ab*"));
}