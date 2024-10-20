#include <iostream>
#include "Vault.h"
#include "SecureVault.h"
#include "NewVault.h"
#include "NewSecureVault.h"

using namespace std;


int main() {
    // part 1: 
    NewVault hackedVault;
    hackedVault.getHacked();
    hackedVault.checkWinCondition();
    // part 2 & 3:
    NewSecureVault hackedSecuredVault;
    hackedSecuredVault.getValues();
    hackedSecuredVault.checkWinCondition();
    return 0;
}