#include <iostream>

using namespace std;

void add(int a, int b) {
    cout << "a+b: " << a + b << endl;
}

void add(float a, float b) {
    cout << "a+b: " << a + b << endl;
}

int main() {
    add(1, 2);
    float a = 4.4, b = 6;
    add(a, b);
    return 0;
}
