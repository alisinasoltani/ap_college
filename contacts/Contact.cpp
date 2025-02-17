#include <iostream>
#include "Contact.h"

Contact::Contact(): name(""), info(Contact_Info()) {}

Contact::Contact(const std::string& name, Contact_Info info): name(name), info(info) {}

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setInfo(const Contact_Info& info) {
    this->info = info;
}

void Contact::makeFavorite() {
    this->is_favorite = true;
}

std::string Contact::getName() const {
    return this->name;
}

Contact_Info Contact::getInfo() const {
    return this->info;
}

bool Contact::isFavorite() const {
    return this->is_favorite;
}
