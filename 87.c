//
// Created by pyxisha on 2021/6/14.
//

#include <string.h>
#include <stdio.h>
#include <stdbool.h>


bool isScramble(char *s1, char *s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) {
        return false;
    }

    bool dp[len][len][len + 1];

    memset(dp, 0, sizeof(dp));

    for (int k = 1; k <= len; ++k) {
        for (int i = 0; i + k <= len; ++i) {
            for (int j = 0; j + k <= len; ++j) {
                if (k == 1)
                    dp[i][j][k] = s1[i] == s2[j];
                else
                    for (int q = 1; q < k; ++q) {
                        if ((dp[i][j][q] && dp[i + q][j + q][k - q]) || (dp[i][j + k - q][q] && dp[i + q][j][k - q])) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
            }
        }
    }

    return dp[0][0][len];
}


int main(void) {
    char *test1 = "eebaacbcbcadaaedceaaacadccd";
    char *test2 = "eadcaacabaddaceacbceaabeccd";
    char *test3 = "abcde", *test4 = "deabc", *test5 = "ab", *test6 = "ba";

    printf("%d\n", isScramble(test3, test4));
    printf("%d\n", isScramble(test5, test6));


}