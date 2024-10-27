#include <iostream>
#include "Gun.h"

using namespace std;

Gun::Gun() {
    this->name = "";
    this->ammo = 0;
    this->fireRate = 0;
    this->isAutomatic = false;
}

Gun::Gun(string gun_name) {
    this->name = gun_name;
    this->ammo = 0;
    this->fireRate = 0;
    this->isAutomatic = false;
    // this->numberOfGuns += 1;
}

Gun::Gun(string gun_name, int gun_ammo) {
    this->name = gun_name;
    this->ammo = gun_ammo;
    this->fireRate = 0;
    this->isAutomatic = false;
    // this->numberOfGuns += 1
}

Gun::Gun(string gun_name, int gun_ammo, float fire_rate) {
    this->name = gun_name;
    this->ammo = gun_ammo;
    this->fireRate = fire_rate;
    this->isAutomatic = false;
    // this->numberOfGuns += 1;
}

Gun::Gun(string gun_name, int gun_ammo, float fire_rate, bool is_automatic) {
    this->name = gun_name;
    this->ammo = gun_ammo;
    this->fireRate = fire_rate;
    this->isAutomatic = is_automatic;
    // this->numberOfGuns += 1
}

Gun::Gun(Gun &gun) {
    this->name = gun.name;
    this->ammo = gun.ammo;
    this->fireRate = gun.fireRate;
    this->isAutomatic = gun.isAutomatic;
    // this->numberOfGuns += 1;
}

int Gun::getAmmo(string name) {
    return this->ammo;
}

float Gun::getFireRate(string name) {
    return this->fireRate;
}

bool Gun::isGunAutomatic(string name) {
    return this->isAutomatic;
}

// int Gun::getNumberOfGuns(string name) {
//     return this->numberOfGuns;
// }

bool Gun::setAmmo(int new_ammo) {
    this->ammo = new_ammo;
    return true;
}

bool Gun::setFireRate(float fire_rate) {
    this->fireRate = fire_rate;
    return true;
}

bool Gun::setGunAutomatic(bool mode) {
    this->isAutomatic = mode;
    return true;
}

bool Gun::changeGunName(string new_name) {
    this->name = new_name;
    return true;
}

Gun Gun::addGuns(Gun other) {
    this->name += other.name;
    this->ammo += other.ammo;
    this->fireRate *= other.fireRate;
    this->isAutomatic = this->isAutomatic || other.isAutomatic;
    return *this;
}

bool Gun::compareGuns(Gun other) {
    if ((this->name == other.name) && (this->ammo == other.ammo) && (this->fireRate == other.fireRate) && (this->isAutomatic == other.isAutomatic)) {
        return true;
    } else {
        return false;
    }
}

Gun Gun::operator+(Gun other) {
    return Gun::addGuns(other);
}

Gun Gun::operator+=(Gun other) {
    return Gun::addGuns(other);
    // to change
}

bool Gun::operator==(Gun other) {
    return Gun::compareGuns(other);
}

void Gun::operator=(Gun other) {
    this->name = other.name;
    this->ammo = other.ammo;
    this->fireRate = other.fireRate;
    this->isAutomatic = other.isAutomatic;
}

bool Gun::operator!=(Gun other) {
    return !Gun::compareGuns(other);
}

Gun Gun::operator--(int) { //postfix
    Gun temp = *this;
    this->ammo -= 1;
    return temp;

}

Gun& Gun::operator--() { //prefix
    this->ammo -= 1;
    return *this;
}

Gun Gun::operator++(int) { //postfix
    Gun temp = *this;
    this->ammo += 1;
    return temp;
}

Gun& Gun::operator++() { //prefix
    this->ammo += 1;
    return *this;
}

Gun Gun::operator*(int number) {
    this->ammo *= number;
    return *this;
}

Gun Gun::operator*=(int number) {
    this->ammo *= number;
    return *this;
}

Gun& Gun::operator[](int number) {
    this->ammo = number;
    return *this;
}

Gun Gun::operator/(int number) {
    if (number == 0) {
        cout << "zero division error!" << endl;
    } else {
        this->ammo /= number;
    }
    return *this;
}

Gun Gun::operator/=(int number) {
    if (number == 0) {
        cout << "zero division error!" << endl;
    } else {
        this->ammo /= number;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, Gun gun) {
    stream << "gun name: " << gun.name << "\nammo: " << gun.ammo << "\nfire rate: " << gun.fireRate << "\nis auto: " << gun.isAutomatic;
    return stream;
}

// std::istream& operator>>(std::istream& stream, Gun gun) {
    // std::cout << "gun name:" << endl;
    // stream >> gun.name;
    // std::cout << "ammo:" << endl;
    // stream >> gun.ammo;
    // std::cout << "fire rate:" << endl;
    // stream >> gun.fireRate;
    // std::cout << "is auto:" << endl;
    // stream >> gun.isAutomatic;
    // return stream;
// }