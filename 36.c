//
// Created by pyxisha on 2021/4/7.
//

#include <stdbool.h>

/* 简单 */

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int raw[9][9] = {0};
    int column[9][9] = {0};
    int oblique[9][9] = {0};
    int i, j, k, idx;

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
                if (raw[i][idx] > 1 || column[j][idx] > 1 || oblique[k][idx] > 1)
                    return 0;

            }
        }
    }

    return 1;
}