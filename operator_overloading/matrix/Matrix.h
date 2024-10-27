#ifndef __MATRIX__
    #define __MATRIX__
    class Matrix {
        private:
            int cols;
            int rows;
            int **matrix;
        
        public:
            Matrix(int rows, int cols, int **matrix) {
                this->rows = rows;
                this->cols = cols;
                this->matrix = new int*[rows];
                for (int i = 0; i < rows; i++) {
                    this->matrix[i] = new int[cols];
                    for (int j = 0; j < cols; j++) {
                        this->matrix[i][j] = matrix[i][j];
                    }
                }
            }

            Matrix(const Matrix &a) {
                this->rows = a.rows;
                this->cols = a.cols;
                this->matrix = new int*[a.rows];
                for (int i = 0; i < rows; i++) {
                    this->matrix[i] = new int[a.cols];
                    for (int j = 0; j < cols; j++) {
                        this->matrix[i][j] = a.matrix[i][j];
                    }
                }
            }

            ~Matrix() {
                for (int i = 0; i < rows; i++) {
                    delete matrix[i];
                }
                delete matrix;
            }
            
            Matrix* add(Matrix a, Matrix b) const;
            Matrix* multiply(Matrix a, Matrix b) const;
            Matrix* subtract(Matrix a, Matrix b) const;
            Matrix* determinant(Matrix a) const;
            Matrix* transpose(Matrix a) const;
            Matrix* operator+(Matrix other) const;
            Matrix* operator-(Matrix other) const;
            Matrix* operator*(Matrix other) const;
            void printMatrix(Matrix a) const;
    };
#endif