#include <iostream>
#include "Vault.h"

using namespace std;

#ifndef __SECURE_VAULT__
    #define __SECURE_VAULT__
    class SecureVault
    {
    protected:
        const string password;
        const bool security;
        const int money;

    public:
        SecureVault(): password("hNcaal9*930okf"), money(100), security(true) {}

        void checkWinCondition() {
            if (money == 0 && password == "123" && security == false) {
                cout << "You win!" << endl;
            } else {
                cout << "You have been arrested!" << endl;
            }
        }
    };

#endif