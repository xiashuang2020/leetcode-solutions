//
// Created by xiash on 2022/3/4.
//

struct dp {
    int max_left_hp;
    int hp;
    int left_hp;
    int minimal_hp;
};

struct dp dp[200][200];
#define max(a, b) ((a) > (b) ? (a) : (b))

int calculateMinimumHP(int** dungeon, int dungeonSize, int* dungeonColSize) {
    dp[0][0].left_hp = dp[0][0].max_left_hp = dungeon[0][0];
    if (dp[0][0].max_left_hp < 0) {
        dp[0][0].hp = dp[0][0].minimal_hp = dp[0][0].max_left_hp * (-1) + 1;
    } else {
        dp[0][0].hp = dp[0][0].minimal_hp = 1;
    }

    for (int i = 0; i < dungeonSize; ++i) {
        for (int j = 0; j < dungeonColSize[0]; ++j) {
            int prev[2][2] = { {i - 1, j}, {i, j - 1} };
            int first = 1;
            for (int k = 0; k < 2; ++k) {
                int row = prev[k][0];
                int column = prev[k][1];
                if (row >= 0 && column >= 0) {
                    int max_left_hp = dp[row][column].max_left_hp + dungeon[i][j];
                    int hp;
                    if (max_left_hp < 0)
                        hp = (max_left_hp * -1 + 1);
                    else
                        hp = 1;
                    hp = max(dp[row][column].hp, hp);

                    int left_hp = dp[row][column].left_hp + dungeon[i][j];
                    int minimal_hp;
                    if (left_hp < 0)
                        minimal_hp = (left_hp * -1) + 1;
                    else
                        minimal_hp = 0;
                    minimal_hp = max(dp[row][column].minimal_hp, minimal_hp);

                    if (minimal_hp >= hp) {
                        minimal_hp = hp;
                        left_hp = max_left_hp;
                    }

                    if (first) {
                        dp[i][j].max_left_hp = max_left_hp;
                        dp[i][j].hp = hp;
                        dp[i][j].left_hp = left_hp;
                        dp[i][j].minimal_hp = minimal_hp;
                        first = 0;
                    } else {
                        if (dp[i][j].max_left_hp < max_left_hp || (dp[i][j].max_left_hp == max_left_hp && dp[i][j].hp > hp)) {
                            dp[i][j].max_left_hp = max_left_hp;
                            dp[i][j].hp = hp;
                        }

                        if (dp[i][j].minimal_hp > minimal_hp || (dp[i][j].minimal_hp == minimal_hp && dp[i][j].left_hp < left_hp)) {
                            dp[i][j].minimal_hp = minimal_hp;
                            dp[i][j].left_hp = left_hp;
                        }
                    }
                }
            }
        }
    }

    return dp[dungeonSize - 1][dungeonColSize[0] - 1].minimal_hp;
}

#include <stdio.h>
int main(void)
{
    int arr1[3] = {-2,-3,3};
    int arr2[3] = {-5,-10,1};
    int arr3[3] = {10,30,-5};
    int *test[3] = { arr1, arr2, arr3};
    int test_size[3] = {3, 3, 3};
    int arr4[3] = {0, 0, 0};
    int arr5[3] = {1, 1, -1};
    int *test2[2] = {arr4, arr5};

    printf("%d\n", calculateMinimumHP(test, 3, test_size));
    printf("%d\n", calculateMinimumHP(test2, 2, test_size));
}