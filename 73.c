//
// Created by pyxisha on 2021/6/7.
//

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int first_zero = 0;

    for (int i = 0; i < matrixSize; ++i) {
        if (matrix[i][0] == 0) {
            first_zero = 1;
            break;
        }
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 1; j < matrixColSize[0]; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = matrixSize - 1; i >= 0; i--) {
        for (int j = 1; j < matrixColSize[0]; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    if (first_zero) {
        for (int i = 0; i < matrixSize; ++i) {
            matrix[i][0] = 0;
        }
    }
}