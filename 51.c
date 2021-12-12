//
// Created by pyxisha on 2021/5/5.
//

/* 深度优先搜索 */

#define MAXN 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void dfs(char (*board)[MAXN], int n, int i,int *total, char*** ret)
{
    int valid = 1;
    int off;

    for (int k = 0; k < n; ++k) {
        valid = 1;
        for (int j = 0; j < i; ++j) {
            if (board[j][k] == 'Q') {
                valid = 0;
                break;
            }

            off = i - j;
            if (k - off >= 0 && board[j][k - off] == 'Q') {
                valid = 0;
                break;
            }

            if (k + off < n && board[j][k + off] == 'Q') {
                valid = 0;
                break;
            }

        }

        if (!valid)
            continue;

        board[i][k] = 'Q';
        if (i == n - 1) {
            ret[*total] = calloc(sizeof(char *) * n, 1);
            for (int j = 0; j < n; ++j) {
                ret[*total][j] = calloc(sizeof(char) * n, 1);
                memcpy(ret[*total][j], board[j], n);
            }
            *total += 1;
        } else {
            dfs(board, n, i + 1, total, ret);
        }

        board[i][k] = '.';
    }
}

#define MAX_SOLUTION 400

char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    char board[MAXN][MAXN] = { [0 ... 9] = {'.','.','.','.','.','.','.','.','.','.'}};
    int total = 0;
    char ***ret = NULL;
    int *returnColSize;

    ret = calloc(sizeof(char **) * MAX_SOLUTION, 1);
    returnColSize = calloc(sizeof(int) * MAX_SOLUTION, 1);
    for (int i = 0; i < MAX_SOLUTION; ++i) {
        returnColSize[i] = n;
    }

    dfs(board, n, 0, &total, ret);
    *returnSize = total;
    *returnColumnSizes = returnColSize;
    return ret;
}

int main(void) {
    int *retColSize;
    int retSize;
    char ***ret;

    ret = solveNQueens(9, &retSize, &retColSize);
    printf("%d\n", retSize);
}