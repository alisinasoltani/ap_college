#include <iostream>

using namespace std;

#ifndef __VAULT__
    #define __VAULT__
    class Vault
    {
    protected:
        string password;
        bool security;
        int money;

    public:
        Vault()
        {
            password = "hNcaal9*930okf";
            security = true;
            money = 100;
        }

        int getMoney()
        {
            cout << "You lose!" << endl;
            return money;
        }

        void setMoney(int newValue)
        {
            cout << "You lose!" << endl;
            money = newValue;
        }

        void checkWinCondition()
        {
            if (money == 0 && password == "123" && security == false)
            {
                cout << "You win!" << endl;
            }
            else
            {
                cout << "You have been arrested!" << endl;
            }
        }
    };
#endif