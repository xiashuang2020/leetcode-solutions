//
// Created by pyxisha on 2021/5/31.
//

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

#define RIGHT 0
#define DOWN  1
#define LEFT  2
#define UP    3

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;

    int i = 0, j = 0, k = 0;
    int *ret = calloc(sizeof(int) * (*returnSize), 1);
    int round = 0;
    int direction = j == n - round - 1? DOWN : RIGHT;

    while (k < *returnSize) {
        ret[k++] = matrix[i][j];
        if (direction == RIGHT) {
            if (++j == n - round - 1)
                direction = DOWN;
        } else if (direction == DOWN) {
            if (++i == m - round - 1)
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

int main(void)
{
    int *arrs[4];

    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int arr3[3] = {7, 8, 9};
    int arr4[3] = {10, 11, 112};
    int ret_size;
    int col_size = 1;
    arrs[0] = arr1;
    arrs[1] = arr2;
    arrs[2] = arr3;
    arrs[3] = arr4;

    int *ret = spiralOrder(arrs, 2, &col_size, &ret_size);

    printf("ret size %d\n", ret_size);

    for (int i = 0; i < ret_size; ++i) {
        printf("%d ", ret[i]);
    }

    printf("\n");
}