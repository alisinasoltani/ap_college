#ifndef __MATRIX__
    #define __MATRIX__
    typedef struct Matrix {
        int rows;
        int cols;
        int **matrix;
    } Matrix;
    Matrix* createMatrix(const int rows, const int cols);
    void removeMatrix(Matrix* matrix, const int cols);
    // Addition of two matrices
    bool addMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result);
    // Addition of matrix and scalar
    bool addMatrix(const Matrix& mat, double scalar, Matrix& result);
    // Subtraction of two matrices
    bool subtractMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result);
    // Subtraction of matrix and scalar
    bool subtractMatrix(const Matrix& mat, double scalar, Matrix& result);

    void printMatrix(const Matrix *mat, const int rows, const int cols);
#endif