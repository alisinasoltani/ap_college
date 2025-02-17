#include <iostream>
#include "Matrix.h"

using namespace std;


Matrix* createMatrix(const int rows, const int cols) {
    int **matrix = new int*[cols];
    for (int i = 0; i < cols; i++) {
        matrix[i] = new int[rows];
    }
    Matrix* new_matrix = new Matrix;
    new_matrix->cols = cols;
    new_matrix->rows = rows;
    new_matrix->matrix = matrix;
    return new_matrix;
}

void removeMatrix(Matrix* matrix, const int cols) {
    for (int i = 0; i < cols; i++) {
        delete[] matrix->matrix[i];
    }
    delete[] matrix->matrix;
    delete[] matrix;
}

// Addition of two matrices
bool addMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result) {
    if (mat1.matrix != nullptr && mat2.matrix != nullptr && result.matrix != nullptr) {
        if (mat1.rows == mat2.rows && mat1.cols == mat2.cols) {
            for (int i = 0; i < mat1.rows; i++) {
                for (int j = 0; j < mat1.cols; j++) {
                    result.matrix[i][j] = mat2.matrix[i][j] + mat1.matrix[i][j];
                }
            }
            return true;
        } else {
            cout << "matrix sizes don't match" << endl;
            return false;
        }
    } else {
        cout << "invalid pointers!" << endl;
        return false;
    }
}

// Addition of matrix and scalar
bool addMatrix(const Matrix& mat, double scalar, Matrix& result) {
    if (mat.matrix != nullptr && result.matrix != nullptr) {
        if (mat.rows == result.rows && mat.cols == result.cols) {
            for (int i = 0; i < mat.rows; i++) {
                for (int j = 0; j < mat.cols; j++) {
                    result.matrix[i][j] = mat.matrix[i][j] + scalar;
                }
            }
            return true;
        } else {
            cout << "matrix sizes don't match" << endl;
            return false;
        }
    } else {
        cout << "invalid pointers!" << endl;
        return false;
    }
}

// Subtraction of two matrices
bool subtractMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result) {
    if (mat1.matrix != nullptr && mat2.matrix != nullptr && result.matrix != nullptr) {
        if (mat1.rows == mat2.rows && mat1.cols == mat2.cols) {
            for (int i = 0; i < mat1.rows; i++) {
                for (int j = 0; j < mat1.cols; j++) {
                    result.matrix[i][j] = mat2.matrix[i][j] - mat1.matrix[i][j];
                }
            }
            return true;
        } else {
            cout << "matrix sizes don't match" << endl;
            return false;
        }
    } else {
        cout << "invalid pointers!" << endl;
        return false;
    }
}

// Subtraction of matrix and scalar
bool subtractMatrix(const Matrix& mat, double scalar, Matrix& result) {
    if (mat.matrix != nullptr && result.matrix != nullptr) {
        if (mat.rows == result.rows && mat.cols == result.cols) {
            for (int i = 0; i < mat.rows; i++) {
                for (int j = 0; j < mat.cols; j++) {
                    result.matrix[i][j] = mat.matrix[i][j] - scalar;
                }
            }
            return true;
        } else {
            cout << "matrix sizes don't match" << endl;
            return false;
        }
    } else {
        cout << "invalid pointers!" << endl;
        return false;
    }
}

void printMatrix(const Matrix *mat, const int rows, const int cols) {
    cout << "rows: " << rows << " cols: " << cols << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "mat[" << i << "][" << j << "]: " << mat->matrix[i][j] << endl;
        }
    }
}