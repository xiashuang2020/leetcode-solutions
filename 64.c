#include <stdio.h>
#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int map[200][200];

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    memset(map, 0, 200 * 200 * sizeof(int));
    int i = 0, j = 0;

    map[0][0] = grid[0][0];
    for (j = 1; j < gridColSize[0]; j++) {
        map[0][j] = map[0][j - 1] + grid[0][j];
    }

    for (i = 1; i < gridSize; ++i) {
        map[i][0] = map[i - 1][0] + grid[i][0];
    }

    for (i = 1; i < gridSize; i++) {
        for (j = 1; j < gridColSize[0]; ++j) {
            map[i][j] = MIN(map[i - 1][j], map[i][j - 1]) + grid[i][j];
        }
    }

    return map[gridSize - 1][gridColSize[0] - 1];
}

int main(void)
{
    int arr1[3] = {1, 3, 1};
    int arr2[3] = {1, 5, 1};
    int arr3[3] = {4, 2, 1};
    int *arr[3] = {arr1, arr2, arr3};
    int size = 3;

    printf("%d\n", minPathSum(arr, 3, &size));

}
