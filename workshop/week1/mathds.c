#include <stdio.h>
#include <stdlib.h>
#include "mathds.h"

int** allocateMethod1(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    
    int *data = (int *)malloc(rows * cols * sizeof(int));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = &data[i * cols];
    }

    return matrix;
}

int** allocateMethod2(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    return matrix;
}

void freeMethod1(int **matrix) {
    free(matrix[0]);
    free(matrix);
}

void freeMethod2(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
