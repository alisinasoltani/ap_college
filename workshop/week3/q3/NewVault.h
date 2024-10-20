#include "Vault.h"

#ifndef __NEW_VAULT__
    #define __NEW_VAULT__
    class NewVault: public Vault {
    public:
        void getHacked() {
            Vault::password = "123";
            Vault::security = false;
            Vault::money = 0;
        }
    };
#endif