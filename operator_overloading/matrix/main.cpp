#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    int **m = new int*[4];
    for (int i = 0; i < 4; i++) {
        m[i] = new int[5];
    }
    Matrix a(4, 5, m);
    for (int i = 4; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "a[" << i << "][" << j << "]: " << endl;
            cin >> m[i][j];
        }
    }
    for (int i = 4; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "a[" << i << "][" << j << "]: " << m[i][j] << endl;
        }
    }
    return 0;
}