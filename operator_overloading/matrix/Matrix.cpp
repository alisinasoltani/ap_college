#include <iostream>
#include "Matrix.h"

using namespace std;

Matrix* Matrix::add(Matrix a, Matrix b) const {}
Matrix* Matrix::multiply(Matrix a, Matrix b) const {}
Matrix* Matrix::subtract(Matrix a, Matrix b) const {}
Matrix* Matrix::determinant(Matrix a) const {}
Matrix* Matrix::transpose(Matrix a) const {}

Matrix* Matrix::operator+(Matrix other) const {
    return Matrix::add(*this, other);
}

Matrix* Matrix::operator-(Matrix other) const {
    return Matrix::subtract(*this, other);
}

Matrix* Matrix::operator*(Matrix other) const {
    return Matrix::multiply(*this, other);
}

void Matrix::printMatrix(Matrix a) const {}