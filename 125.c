//
// Created by pyxisha on 2021/11/22.
//


#include <stdbool.h>
#include <string.h>
#include <stdio.h>

static bool is_lower(char c)
{
    return 'a' <= c && c <= 'z';
}

static bool is_upper(char c)
{
    return 'A' <= c && c <= 'Z';
}

static char to_lower(char c)
{
    if (is_upper(c))
        return c + 'a' - 'A';
    return c;
}

static char is_digit(char c)
{
    return '0' <= c && c <= '9';
}

static bool is_alpha(char c)
{
    return is_lower(c) || is_upper(c) || is_digit(c);
}

bool isPalindrome(char * s) {
    int i = 0;
    int j = strlen(s) - 1;


    while (i < j) {
        if (!is_alpha(s[i])) {
            i++;
            continue;
        }
        if (!is_alpha(s[j])) {
            j--;
            continue;
        }

        if (to_lower(s[i++]) != to_lower(s[j--]))
            return false;
    }

    return true;
}

int main(void)
{
    printf("%d\n", isPalindrome("A man, a plan, a canal: Panama"));
    printf("%d\n", isPalindrome("race a car"));
    printf("%d\n", isPalindrome(""));
    printf("%d\n", isPalindrome("0P"));
}