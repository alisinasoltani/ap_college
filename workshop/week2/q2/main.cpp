#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix *matrix1 = createMatrix(3,3);
    Matrix *matrix2 = createMatrix(3,3);
    Matrix *matrix3 = createMatrix(2,4);
    Matrix *result = createMatrix(3,3);

    matrix1->matrix[0][0] = 1;
    matrix1->matrix[0][1] = 2;
    matrix1->matrix[0][2] = 3;
    matrix1->matrix[1][0] = 4;
    matrix1->matrix[1][1] = 5;
    matrix1->matrix[1][2] = 6;
    matrix1->matrix[2][0] = 7;
    matrix1->matrix[2][1] = 8;
    matrix1->matrix[2][2] = 9;

    matrix2->matrix[0][0] = 1;
    matrix2->matrix[0][1] = 2;
    matrix2->matrix[0][2] = 3;
    matrix2->matrix[1][0] = 4;
    matrix2->matrix[1][1] = 5;
    matrix2->matrix[1][2] = 6;
    matrix2->matrix[2][0] = 7;
    matrix2->matrix[2][1] = 8;
    matrix2->matrix[2][2] = 9;

    matrix3->matrix[0][0] = 1;
    matrix3->matrix[0][1] = 2;
    matrix3->matrix[0][2] = 3;
    matrix3->matrix[0][3] = 4;
    matrix3->matrix[1][0] = 5;
    matrix3->matrix[1][1] = 6;
    matrix3->matrix[1][2] = 7;
    matrix3->matrix[1][3] = 8;

    cout << "matrix 1: " << endl;
    printMatrix(matrix1, matrix1->rows, matrix1->cols);
    cout << "matrix 2: " << endl;
    printMatrix(matrix2, matrix2->rows, matrix2->cols);
    cout << "matrix 3: " << endl;
    printMatrix(matrix3, matrix3->rows, matrix3->cols);
    cout << "matrix1 + matrix2: " << endl;
    addMatrix(*matrix1, *matrix2, *result);
    printMatrix(result, result->rows, result->cols);
    cout << "matrix1 + 2: " << endl;
    addMatrix(*matrix1, 2, *result);
    printMatrix(result, result->rows, result->cols);
    cout << "matrix1 - 2: " << endl;
    subtractMatrix(*matrix1, 2, *result);
    printMatrix(result, result->rows, result->cols);
    cout << "matrix1 - matrix2: " << endl;
    subtractMatrix(*matrix1, *matrix2, *result);
    printMatrix(result, result->rows, result->cols);

    return 0;
}