#ifndef HEAD
#define HEAD
    int** allocateMethod1(int rows, int cols);
    int** allocateMethod2(int rows, int cols);
    void freeMethod1(int **matrix);
    void freeMethod2(int **matrix, int rows);
#endif