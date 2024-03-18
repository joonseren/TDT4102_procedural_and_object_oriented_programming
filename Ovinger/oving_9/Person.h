// TDT4102 Øving 9

#pragma once
#include "Car.h"
#include <memory>
#include <string>


class Person {
private:
    std::string name;
    std::string email;

public:
    std::unique_ptr<Car> personCar;
    Person(std::string n, std::string mail, std::unique_ptr<Car> pCar) : name(n), email(mail), personCar(std::move(pCar)) {}
    Person(std::string n, std::string mail) : name(n), email(mail), personCar(nullptr) {}
    std::string getName();
    std::string getEmail();
    void setEmail(std::string inputEmail);
    bool hasAvailableSeats();
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};