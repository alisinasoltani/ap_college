#include <iostream>
#include "SecureVault.h"

using namespace std;

#ifndef __N_SECURE_VAULT__
    #define __N_SECURE_VAULT__
    class NewSecureVault: public SecureVault {
    protected:
        const string password;
        const bool security;
        const int money;
    public:
        NewSecureVault(): password("123"), money(0), security(false) {}
        void checkWinCondition() {
            if (money == 0 && password == "123" && security == false) {
                cout << "You win!" << endl;
            } else {
                cout << "You have been arrested!" << endl;
            }
        }
        void getValues() {
            cout << "pass: " << password << " sec: " << security << " money: " << money << endl;
        }
    };
#endif
