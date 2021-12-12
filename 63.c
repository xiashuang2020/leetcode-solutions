//
// Created by pyxisha on 2021/5/4.
//

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int n = obstacleGridColSize[0];

    for (int i = 0; i < obstacleGridSize; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                obstacleGrid[i][j] = 0;
            } else if (j == 0 && i == 0) {
                obstacleGrid[i][j] = 1;
            } else if (j == 0) {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j];
            } else if (i == 0) {
                obstacleGrid[i][j] = obstacleGrid[i][j - 1];
            } else {
                obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
            }

        }

    }
    return obstacleGrid[obstacleGridSize - 1][n - 1];
}

int main(void)
{
    int arr1[3] = {0, 0, 0};
    int arr2[3] = {0, 1, 0};
    int arr3[3] = {0, 0, 0};
    int arr4[3] = {1, 0, 0};
    int *arr[4] = {arr4, arr1, arr2, arr3};
    int col[3] = {3, 3, 3};

    printf("%d\n", uniquePathsWithObstacles(arr, 4, col));
}