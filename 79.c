//
// Created by pyxisha on 2021/7/16.
//


#include <stdbool.h>

static bool exist_r(char** board, int boardSize, int* boardColSize, char * word, int i, int j)
{
    char tmp = board[i][j];

    if (word[0] == 0)
        return true;

    board[i][j] = 0;
    if (i - 1 >= 0 && board[i - 1][j] == word[0] && exist_r(board, boardSize, boardColSize, word + 1, i - 1, j)) {
        board[i][j] = tmp;
        return true;
    } else if (i + 1 < boardSize && board[i + 1][j] == word[0] && exist_r(board, boardSize, boardColSize, word + 1, i + 1, j)) {
        board[i][j] = tmp;
        return true;
    } else if (j - 1 >= 0 && board[i][j - 1] == word[0] && exist_r(board, boardSize, boardColSize, word + 1, i, j - 1)) {
        board[i][j] = tmp;
        return true;
    } else if (j + 1 < boardColSize[0] && board[i][j + 1] == word[0] && exist_r(board, boardSize, boardColSize, word + 1, i, j + 1)) {
        board[i][j] = tmp;
        return true;
    } else {
        board[i][j] = tmp;
        return false;
    }
}


bool exist(char** board, int boardSize, int* boardColSize, char * word) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[0]; ++j) {
            if (board[i][j] == word[0] && exist_r(board, boardSize, boardColSize, word + 1, i, j))
                return true;
        }
    }

    return false;
}