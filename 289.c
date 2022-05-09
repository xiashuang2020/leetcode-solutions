//
// Created by pyxisha on 2022/5/9.
//

void gameOfLife(int** board, int boardSize, int* boardColSize){
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardColSize[0]; ++j) {
            int surroundings[8][2] = {
                    {i - 1, j - 1},
                    {i - 1, j},
                    {i - 1, j + 1},
                    {i, j - 1},
                    {i, j + 1},
                    {i + 1, j - 1},
                    {i + 1, j},
                    {i + 1, j + 1}
            };
            int live_sib_cnt = 0;

            for (int k = 0; k < 8; ++k) {
                int a = surroundings[k][0];
                int b = surroundings[k][1];
                if (0 <= a && a < boardSize && 0 <= b && b < boardColSize[0]) {
                    if (board[a][b] & 0x1) {
                        live_sib_cnt++;
                    }
                }
            }


        }
    }
}