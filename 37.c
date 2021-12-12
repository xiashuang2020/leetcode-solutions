//
// Created by pyxisha on 2021/4/8.
//

#include <stdio.h>
#include <string.h>

/* 深度有限搜索
 * 如果非递归，需要保存遍历的状态
 * 回溯时，注意状态的更新
 */

void solveSudoku(char **board, int boardSize, int* boardColSize){
    int raw[9][9] = {0};
    int column[9][9] = {0};
    int oblique[9][9] = {0};
    int list[9][9] = {0};
    int valid[9][9] = {0};
    int i, j, k, idx, t, next_i, next_j;

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            k = j / 3 + (i / 3) * 3;
            if (board[i][j] == '.')
                continue;
            else {
                idx = board[i][j] - '1';

                raw[i][idx] += 1;
                column[j][idx] += 1;
                oblique[k][idx] += 1;
                list[i][j] = -1;
            }
        }
    }

    i = 0; j = 0;
    loop:
    while (i < 9) {
        if (list[i][j] == -1) {
            j++;
            if (j == 9) {
                i++;
                j = 0;
            }
        } else {
            k = j / 3 + (i / 3) * 3;
            for (t = valid[i][j]; t < 9; t++) {
                if (raw[i][t] == 0 && column[j][t] == 0 && oblique[k][t] == 0) {
                    board[i][j] = '1' + t;
                    raw[i][t] = 1;
                    column[j][t] = 1;
                    oblique[k][t] = 1;

                    next_j = j + 1;
                    next_i = i;
                    if (next_j == 9) {
                        next_i = i + 1;
                        next_j = 0;
                    }

                    while (next_i < 9 && list[next_i][next_j] == -1) {
                        next_j = next_j + 1;
                        if (next_j == 9) {
                            next_i = next_i + 1;
                            next_j = 0;
                        }
                    }

                    if (next_i < 9)
                        list[next_i][next_j] = i * 9 + j;

                    valid[i][j] = t + 1;
                    i = next_i;
                    j = next_j;
                    goto loop;
                }
            }

            next_i = list[i][j] / 9;
            next_j = list[i][j] % 9;
            i = next_i;
            j = next_j;
            k = j / 3 + (i / 3) * 3;
            raw[i][board[i][j] - '1'] = 0;
            column[j][board[i][j] - '1'] = 0;
            oblique[k][board[i][j] - '1'] = 0;
            board[i][j] = '.';
            memset((int *)valid + i * 9 + j + 1, 0, sizeof(valid) - (i * 9 + j + 1) * 4);
        }
    }
}

char g_board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

int main(void) {
    solveSudoku(g_board, 0, NULL);

    return 0;
}