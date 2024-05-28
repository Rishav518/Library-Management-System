/*
    person.h 
    Author: Dristi Bhugun <db1178@live.mdx.ac.uk>
    Created: 30/12/23
    Updated: 08/01/24
*/
#include "person.h"

std::string Person::getName() const {
    return name;
}

void Person::setName(std::string newName) {
    name = newName;
}

std::string Person::getAddress() const {
    return address;
}

void Person::setAddress(std::string newAddress) {
    address = newAddress;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(std::string newEmail) {
    email = newEmail;
}