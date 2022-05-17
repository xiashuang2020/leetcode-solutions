//
// Created by pyxisha on 2022/5/17.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int dp[200][200];

static void dfs(int** matrix, int matrixSize, int* matrixColSize, int i, int j)
{
    int siblings[4][2] = { {i - 1, j }, {i + 1, j}, {i, j - 1}, {i, j + 1}};
    dp[i][j] = 1;

    for (int k = 0; k < 4; ++k) {
        int nexti = siblings[k][0];
        int nextj = siblings[k][1];

        if (0 <= nexti && nexti < matrixSize && 0 <= nextj && nextj < matrixColSize[0]) {
            if (matrix[nexti][nextj] > matrix[i][j]) {
                if (dp[nexti][nextj] == 0)
                    dfs(matrix, matrixSize, matrixColSize, nexti, nextj);
                if (dp[nexti][nextj] + 1 > dp[i][j])
                    dp[i][j] = dp[nexti][nextj] + 1;
            }
        }
    }
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    memset(dp, 0, sizeof(dp));
    int max = 0;

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (dp[i][j] == 0) {
                dfs(matrix, matrixSize, matrixColSize, i, j);
            }

            if (dp[i][j] > max)
                max = dp[i][j];
        }
    }

    return max;
}

int main(void)
{
    int test1[3] = {6,4,5};
    int test2[3] = {3,2,6};
    int test3[3] = {2,2,1};

    int *test[3] = {test1, test2, test3};
    int col_size = 3;
    printf("%d\n", longestIncreasingPath(test, 1, &col_size));
}