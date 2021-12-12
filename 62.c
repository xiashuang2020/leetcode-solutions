//
// Created by pyxisha on 2021/5/4.
//

/*
 * map[i][j] = map[i - 1][j] + map[i][j - 1]
 */

#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n){
    int **map = NULL;

    map = calloc(sizeof(int *) * (m + 1), 1);

    for (int i = 0; i <= m; ++i) {
        map[i] = calloc((n + 1) * sizeof(int), 1);
    }

    map[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            map[i][j] = map[i + 1][j] + map[i][j + 1];
        }
    }

    return map[0][0];
}

int main(void)
{
    printf("%d\n", uniquePaths(3, 7));
    printf("%d\n", uniquePaths(3, 2));
    printf("%d\n", uniquePaths(1, 1));
}