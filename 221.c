//
// Created by pyxisha on 2022/4/10.
//

#include <stdlib.h>
#include <string.h>

int dp[300][300];

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    int ret = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == '0') {
                dp[i][j] = 0;
            } else {
                int i1 = i - 1;
                int j1 = j;
                int i2 = i;
                int j2 = j - 1;
                int i3 = i - 1;
                int j3 = j - 1;
                int p1 = i1 >= 0 ? dp[i1][j1] : 0;
                int p2 = j2 >= 0 ? dp[i2][j2] : 0;
                int p3 = (i3 >= 0 && j3 >= 0) ? dp[i3][j3] : 0;
                int p = p3;
                if (p2 < p)
                    p = p2;
                if (p1 < p)
                    p = p1;
                dp[i][j] = p + 1;
                if (dp[i][j] * dp[i][j] > ret) {
                    ret = dp[i][j] * dp[i][j];
                }
            }
        }
    }

    return ret;
}
