// TDT4102 Øving 9

#include "Person.h"

std::string Person::getName() {
    return name;
}
std::string Person::getEmail() {
    return email;
}

void Person::setEmail(std::string inputEmail) {
    email = inputEmail;
}
bool Person::hasAvailableSeats() {
    if (personCar != nullptr && personCar -> hasFreeSeats()) {
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    if (p.personCar == nullptr) {
    os << "Navn: " << p.name << "\nE-post: " << p.email << "\nBil: Ikke tildelt" << std::endl;
    }else {
    os << "Navn: " << p.name << "\nE-post: " << p.email << "\nBil: Tildelt" << std::endl;
    }
    return os;
}