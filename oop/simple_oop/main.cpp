#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    cout << "HELLO?" << endl;
    Calculator c;
    c.setBalance(1000);
    c.getBalance();
    return 0;
}