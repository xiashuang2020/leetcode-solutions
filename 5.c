//
// Created by pyxisha on 2021/4/5.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 单数， 双数分开考虑，从1往外扩展 */

char *longestPalindrome(char * s) {
    int odd[1008], odd2[1008];
    int even[1008], even2[1008];
    int i, t = 0, n;
    int lo, mid, hi;
    int *odd_curr, *odd_next, *even_curr, *even_next, *tmp;
    int odd_num, even_num = 0, next_odd_num = 0, next_even_num = 0;
    char *ret = NULL;

    if (s == NULL)
        return NULL;

    odd_num = n = (int)strlen(s);
    for (i = 0; i < n; i++)
        odd[i] = i;

    for (i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            even[even_num] = i;
            even_num++;
        }
    }

    odd_curr = odd;
    odd_next = odd2;
    even_curr = even;
    even_next = even2;

    do {
        next_odd_num = 0;
        for (i = 0; i < odd_num; i++) {
            mid = odd_curr[i];
            lo = mid - t - 1;
            hi = mid + t + 1;
            if (0 <= lo && hi < n && s[lo] == s[hi]) {
                odd_next[next_odd_num] = mid;
                next_odd_num++;
            }
        }

        next_even_num = 0;
        for (i = 0; i < even_num; i++) {
            mid = even_curr[i];
            lo = mid - t - 1;
            hi = mid + t + 2;
            if (0 <= lo && hi < n && s[lo] == s[hi]) {
                even_next[next_even_num] = mid;
                next_even_num++;
            }
        }

        if (next_odd_num == 0 && next_even_num == 0)
            break;

        t++;
        odd_num = next_odd_num;
        even_num = next_even_num;
        tmp = odd_curr;
        odd_curr = odd_next;
        odd_next = tmp;
        tmp = even_curr;
        even_curr = even_next;
        even_next = tmp;
    } while (odd_num || even_num);

    ret = calloc(1008, 1);
    if (ret == NULL)
        return NULL;

    if (even_num) {
        lo = even_curr[0] - t;
        memcpy(ret, s + lo, t * 2 + 2);
    } else {
        lo = odd_curr[0] - t;
        memcpy(ret, s + lo, t * 2 + 1);
    }

    return ret;
}

int main(void)
{
    printf("ssss %s\n", longestPalindrome("abbbbd"));
}