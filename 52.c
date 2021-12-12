//
// Created by pyxisha on 2021/5/5.
//

/* 深度优先搜索 */

#define MAXN 10
#include <stdio.h>

static void dfs(char (*board)[MAXN], int n, int i,int *total)
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
            *total += 1;
        } else {
            dfs(board, n, i + 1, total);
        }

        board[i][k] = 0;
    }
}

int totalNQueens(int n){
    char board[MAXN][MAXN] = {0};
    int total = 0;

    dfs(board, n, 0, &total);
    return total;
}

int main(void)
{
    printf("%d\n", totalNQueens(1));
    printf("%d\n", totalNQueens(2));
    printf("%d\n", totalNQueens(3));
    printf("%d\n", totalNQueens(4));
    printf("%d\n", totalNQueens(9));
}