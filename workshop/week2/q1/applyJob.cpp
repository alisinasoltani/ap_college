#include <iostream>
#include "applyJob.h"
#include "terminal_colors.h"

using namespace std;

bool isPointerNull(int* pointer) {
    return pointer == nullptr ? true : false; 
}

void idkWhatToNameThis(int* pointer, int& reference) {
    if (isPointerNull(pointer)) {
        cout << BOLDRED << "null pointer recieved" << endl;
        cout << "--------------------------------" << RESET << endl;
        
        return;
    }
    cout << MAGENTA << "this is the number's pointer (the address of memory it allocated): " << pointer << endl; 
    cout << MAGENTA << "and this is the number's reference (a.k.a. its shadow): " << reference << endl;
    if (*pointer == reference) {
        cout << MAGENTA << "the pointer and reference have the same value" << endl;
        if (pointer == &reference) {
            cout << MAGENTA << "and they are all casting one variable as well!" << RESET << endl;
        cout << CYAN << "--------------------------------" << RESET << endl;
        } else {
            cout << MAGENTA << "but they're not the same variable!" << RESET << endl;
        cout << CYAN << "--------------------------------" << RESET << endl;
        }
    } else {
        cout << MAGENTA << "the pointer and reference do not have the same value" << RESET << endl;
        cout << CYAN << "--------------------------------" << RESET << endl;
    }
}