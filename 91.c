//
// Created by pyxisha on 2021/4/11.
//

/* num_end_so_far[i] = num_end_so_far[i - 1] + num_end_so_far[i - 2]; */

#include <stdio.h>
#include <string.h>

#define ONEto9(x) ('1' <= (x) && (x) <= '9')

static inline int ONEto26(const char *x) {
    if (x[0] <= '0' || x[0] > '2')
        return 0;

    if (x[0] == '2' && x[1] > '6')
        return 0;

    return 1;
}

int numDecodings(char * s) {
    unsigned long n;
    int num_end_so_far[100] = {0};
    int i;

    if (s == NULL)
        return  0;

    n = strlen(s);

    num_end_so_far[0] = ONEto9(s[0]) ? 1 : 0;
    if (n == 1)
        return num_end_so_far[0];

    if (ONEto9(s[1]))
        num_end_so_far[1] = num_end_so_far[0];
    if (ONEto26(s))
        num_end_so_far[1] += 1;

    if (num_end_so_far[0] == 0 && num_end_so_far[1] == 0)
        return 0;

    for (i = 2; i < n; i++) {
        if (ONEto9(s[i]))
            num_end_so_far[i] = num_end_so_far[i - 1];
        if (ONEto26(s + i - 1))
            num_end_so_far[i] += num_end_so_far[i - 2];
        if (num_end_so_far[i - 1] == 0 && num_end_so_far[i] == 0)
            return 0;
    }

    return num_end_so_far[n - 1];
}

int main(void)
{
    char *s = "12";

    printf("%d \n", numDecodings(s));
    return 0;
}