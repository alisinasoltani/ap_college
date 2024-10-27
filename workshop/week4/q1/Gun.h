#include <iostream>

using namespace std;

#ifndef __GUN__
    #define __GUN__
    class Gun {
        private:
            int ammo;
            string name;
            float fireRate;
            bool isAutomatic;
            static int numberOfGuns;

            Gun addGuns(Gun other);
            bool compareGuns(Gun other);

        public:
            Gun();
            Gun(string gun_name);
            Gun(string gun_name, int gun_ammo);
            Gun(string gun_name, int gun_ammo, float fire_rate);
            Gun(string gun_name, int gun_ammo, float fire_rate, bool is_automatic);
            Gun(Gun &gun);
            // ~Gun();

            int getAmmo(string name);
            float getFireRate(string name);
            bool isGunAutomatic(string name);
            int getNumberOfGuns(string name);

            bool setAmmo(int new_ammo);
            bool setFireRate(float fire_rate);
            bool setGunAutomatic(bool mode);
            bool changeGunName(string new_name);

            Gun operator+ (Gun other);
            Gun operator+= (Gun other);
            bool operator== (Gun other);
            void operator= (Gun other);
            bool operator!= (Gun other);
            Gun operator-- (int); //postfix
            Gun& operator-- (); //prefix
            Gun operator++ (int); //postfix
            Gun& operator++ (); //prefix
            Gun operator* (int number);
            Gun operator*= (int number);
            Gun& operator[] (int number);
            Gun operator/ (int number);
            Gun operator/= (int number);
            friend std::ostream& operator<<(std::ostream& stream, Gun gun);
            friend std::istream& operator>>(std::istream& stream, Gun gun) {

            }
        };
#endif