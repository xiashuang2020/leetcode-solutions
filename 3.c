//
// Created by pyxisha on 2021/4/4.
//

#include <stdio.h>

/* 关键点，记录下每个字母上一次出现的位置 */

int lengthOfLongestSubstring(char * s)
{
    int hash[256] = {[0 ... 255] = -1, };
    int i = 0;
    int max = 0;
    int start = -1;

    while (s[i] != 0) {
        if (hash[s[i]] > start)
            start = hash[s[i]];
        hash[s[i]] = i;
        if (i - start > max)
            max = i - start;
        i++;
    }

    return max;
}

int main(void) {
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
}