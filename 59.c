/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define RIGHT 0
#define DOWN  1
#define LEFT  2
#define UP    3

#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ret;
    int *ret_col;
    int curr = 1;

    ret = calloc(sizeof(int *) * n, 1);
    for (int i = 0; i < n; ++i) {
        ret[i] = calloc(sizeof(int) * n, 1);
    }
    ret_col = calloc(sizeof(int) * n, 1);
    for (int i = 0; i < n; ++i) {
        ret_col[i] = n;
    }
    *returnSize = n;
    *returnColumnSizes = ret_col;

    int i = 0; int j = 0;
    int direction = RIGHT;
    int round = 0;
    while (curr <= n * n) {
        ret[i][j] = curr++;
        if (direction == RIGHT) {
            if (++j == n - round - 1)
                direction = DOWN;
        } else if (direction == DOWN) {
            if (++i == n - round - 1)
                direction = LEFT;
        } else if (direction == LEFT) {
            if (--j == round)
                direction = UP;
        } else if (direction == UP) {
            if (--i == round + 1) {
                direction = RIGHT;
                round += 1;
            }
        }
    }

    return ret;
}

#include <stdio.h>

int main(void)
{
    int ret_size;
    int *ret_col_size;

    int ** ret = generateMatrix(1, &ret_size, &ret_col_size);

    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 1; ++j) {
            printf("%d ", ret[i][j]);
        }
    }
}
