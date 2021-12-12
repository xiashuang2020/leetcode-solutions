//
// Created by pyxisha on 2021/4/27.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 出现)在左边的情况下即不是一个合法的括号
 * 应该可参考max substr做一个线性算法
 */

int longestValidParentheses(char * s) {
    int l;
    int max = 0;
    int i, j;
    int *dp1;

    if (s == NULL || (l = strlen(s)) == 0)
        return 0;

    dp1 = calloc(l * sizeof(int), 1);
    if (dp1 == NULL)
        return 0;

    for (i = 0; i < l; i++) {
        for (j = 0; j < l - i; j++) {
            if (dp1[j] < 0)
                continue;
            else if (s[j + i] == ')') {
                dp1[j] -= 1;
                if (dp1[j] == 0)
                    max = i + 1;
            }
            else if (s[j + i] == '(')
                dp1[j] += 1;
        }
    }

    return max;
}

int main(void) {
    printf("%d\n", longestValidParentheses("()"));
    printf("%d\n", longestValidParentheses(")("));
    printf("%d\n", longestValidParentheses(")()())"));
}