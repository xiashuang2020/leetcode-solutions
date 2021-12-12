//
// Created by pyxisha on 2021/9/5.
//

#include <string.h>
#include <stdio.h>

unsigned int dp[1001][1000] = {0};

int numDistinct(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < len2; ++i) {
            for (int n = i + 1; n <= len1; ++n) {
                if (s[n - 1] == t[i]) {
                    if (i == 0)
                        dp[n][i] = 1 + dp[n - 1][i];
                    else
                        dp[n][i] = dp[n - 1][i - 1] + dp[n - 1][i];
                } else {
                    dp[n][i] = dp[n - 1][i];
                }
            }
    }

    return dp[len1][len2 - 1];
}

int main(void)
{

    char *s1 = "rabbbit";
    char *s2 = "rabbit";
    char *s3 = "babgbag";
    char *s4 = "bag";

    int ret = numDistinct(s3, s4);

    printf("%d\n", ret);

    return 0;
}