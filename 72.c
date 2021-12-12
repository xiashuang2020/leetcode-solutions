//
// Created by pyxisha on 2021/6/5.
//

#include <string.h>
#include <stdio.h>

#define SWAP(a, b) do { __typeof__(a) tmp = a; a = b; b = tmp;} while (0)
#define MIN(a,b) ((a) < (b) ? (a) : (b))
int map[512][512];

int minDistance(char *word1, char *word2){
    int n1 = strlen(word1);
    int n2 = strlen(word2);
    int find = 0;

    if (n1 > n2) {
        SWAP(word1, word2);
        SWAP(n1, n2);
    }

    if (n1 == 0)
        return n2;

    for (int i = 1; i <= n2; i++) {
        if (word2[i - 1] == word1[0]) {
            find = 1;
        }

        map[0][i] = find ? i - 1 : i;
    }

    for (int i = 0; i < n1; ++i) {
        map[i][0] = i + 1;
    }

    for (int i = 1; i < n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (word1[i] == word2[j - 1])
                map[i][j] = map[i - 1][j - 1];
            else {
                map[i][j] = MIN(MIN(map[i - 1][j - 1], map[i][j - 1]), map[i - 1][j]) + 1; //three situation
            }
        }
    }

    return map[n1 - 1][n2];
}

int main(void)
{
    /* printf("%d\n", minDistance("a", "a"));
    printf("%d\n", minDistance("a", "ab"));
    printf("%d\n", minDistance("ros", "horse"));
    printf("%d\n", minDistance("intention", "execution"));
    printf("%d\n", minDistance("sea", "eat")); */
    printf("%d\n", minDistance("plasma", "altruism"));
}
