#include <iostream>
#include "applyJob.h"
#include "sickArray.h"

using namespace std;

int main() {
    int a = 4;
    int *a_ptr = NULL;
    int &a_ref = a;
    idkWhatToNameThis(a_ptr, a_ref);
    a_ptr = &a;
    idkWhatToNameThis(a_ptr, a_ref);
    int b = 6;
    int &b_ref = b;
    idkWhatToNameThis(a_ptr, b);
    b = 4;
    idkWhatToNameThis(a_ptr, b);
    return 0;
}