//
// Created by pyxisha on 2021/5/30.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

static inline bool matchOne(char a, char b)
{
    return a == b || (b == '?' && a != 0);
}

static inline bool matchn(char *a, char *b, int n)
{
    for (int i = 0; i < n; ++i) {
        if (!matchOne(a[i], b[i]))
            return false;
    }

    return true;
}


bool isMatch(char *s, char *p) {
    int s_len = strlen(s);
    int p_len = strlen(p);
    int next_p = -1, next_p_len, pstart = 0;
    int prev_any = 0;


    int i = 0, j = 0;

    round:
    while (i < p_len) {
        if (!prev_any) {
            if (p[i] == '*') {
                while (p[i + 1] == '*') i++;
                prev_any = 1;
                i++;
            } else {
                if (!matchOne(s[j], p[i]))
                    return false;
                i++;
                j++;
            }
        }
        else {
            if (p[i] == '*') {
                while (p[i + 1] == '*') i++;
                i++;
                while (j + next_p_len <= s_len) {
                    if (matchn(s + j, p + next_p, next_p_len)) {
                        j += next_p_len;
                        next_p = -1;
                        goto round;
                    } else {
                        j++;
                    }
                }
                return false;
            } else {
                if (next_p == -1) {
                    next_p = i;
                    next_p_len = 1;
                } else {
                    next_p_len++;
                };
                i++;
            }
        }

    }

    if (next_p == -1)
        return prev_any || j == s_len;

    if (!prev_any && j + next_p_len != s_len)
        return false;

    if (j + next_p_len > s_len)
        return false;

    return matchn(s + s_len - next_p_len, p + next_p, next_p_len);
}

int main(void)
{
    printf("%d\n", isMatch("abceb", "*a*b"));
    printf("%d\n", isMatch("cb", "?b"));
    printf("%d\n", isMatch("", "*"));
    printf("%d\n", isMatch("mississippi", "m??*ss*?i*pi"));
    printf("%d\n", isMatch("aa", "a"));
    printf("%d\n", isMatch("aa", "aa"));
    printf("%d\n", isMatch("aa", "*"));
    printf("%d\n", isMatch("abc", "abc?*"));
}