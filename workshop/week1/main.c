#include <stdio.h>
#include <stdlib.h>
#include "mathds.h"

int main() {
    int rows = 3, cols = 2;
    int **matrix1 = allocateMethod1(rows, cols);
    int **matrix2 = allocateMethod2(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix1[i][j] = i * cols + j + 1;
            matrix2[i][j] = i * cols + j + 1;
        }
    }
    printf("Matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    freeMethod1(matrix1);
    freeMethod2(matrix2, rows);

    return 0;
}   