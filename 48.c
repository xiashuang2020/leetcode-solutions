//
// Created by pyxisha on 2021/5/27.
//

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j;

    for (i = 0; i < matrixSize / 2; i++) {
        for (j = i; j < matrixSize - i - 1; j++) {
            //lt i, j
            //rt j, matrixSize - i - 1
            //rb matrixSize - i - 1, matrixSize - j -  1
            //lb matrixSize - j - 1, i
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = tmp;
        }
    }
}

int arr1[3] = {1, 2, 3};
int arr2[3] = {4, 5, 6};
int arr3[3] = {7, 8, 9};

int arr21[4] = {1, 2, 3, 4};
int arr22[4] = {5, 6, 7, 8};
int arr23[4] = {9, 10, 11, 12};
int arr24[4] = {13, 14, 15, 16};


int main(void) {
    int *arr[3] = {arr1, arr2, arr3};
    int *arr2[4] = {arr21, arr22, arr23, arr24};

    rotate(arr, 3, NULL);
    rotate(arr2, 4, NULL);

    return 0;
}