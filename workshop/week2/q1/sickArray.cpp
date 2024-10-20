#include <iostream>
#include "sickArray.h"

using namespace std;

void newArray(int**& arr, int& n) {
    arr = new int*[n];
    for (int i = 0; i < n; i++) {
        i == n-1 ? arr[i] = new int[n+1] : arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (j == n-1) {
                cout << "arr[" << i << "][" << j << "]: " << arr[i][j] << endl;
                cout << "arr[" << i << "][" << j+1 << "]: " << arr[i][j+1] << endl;
            } else {
                cout << "arr[" << i << "][" << j << "]: " << arr[i][j] << endl;
            }
        }
    }
}
void squareArray(int**& arr);
void printArray(int**& arr);
void freeArray(int**& arr);