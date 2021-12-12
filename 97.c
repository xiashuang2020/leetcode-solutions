//
// Created by pyxisha on 2021/6/6.
//

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int dp[101][101];

bool isInterleave(char * s1, char * s2, char * s3){
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int n3 = strlen(s3);

    if (n1 + n2 != n3)
        return false;

    memset(dp, 0, 101 * 101 * sizeof(int));
    dp[0][0] = 1;
    int equal = 1;
    for (int i = 1; i <= n1; ++i) {
        if (s1[i - 1] != s3[i - 1])
            equal = 0;
        dp[i][0] = equal ? 1 : 0;
    }

    equal = 1;
    for (int j = 1; j <= n2; ++j) {
        if (s2[j - 1] != s3[j - 1])
            equal = 0;
        dp[0][j] = equal? 1 : 0;

    }

    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1])
                dp[i][j] = 1;

            if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j])
                dp[i][j] = 1;

        }
    }

    return dp[n1][n2];
}

int main(void)
{
    printf("%d\n", isInterleave("ab", "cde", "acdbe"));
    printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    printf("%d\n", isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    printf("%d\n", isInterleave("abc", "", "abc"));
    printf("%d\n", isInterleave("", "abc", "abc"));

    return 0;
}