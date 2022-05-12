//
// Created by pyxisha on 2022/5/11.
//


#include <stdio.h>
#include <stdlib.h>

int countVowelStrings(int n) {
    int dp[5] = { [0 ... 4] = 1};
    int ret = 0;

    for (int i = 2; i <= n; ++i) {
        int p = 0;

        for (int j = 4; j >= 0 ; --j) {
            dp[j] = dp[j] + p;
            p = dp[j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        ret += dp[i];
    }

    return ret;
}

int main(void) {
    printf("%d\n", countVowelStrings(2));
    printf("%d\n", countVowelStrings(33));
}