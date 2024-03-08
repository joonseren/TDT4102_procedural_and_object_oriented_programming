// TDT4102 Øving 7

#pragma once
#include "std_lib_facilities.h"

// 1b), c)
class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}; // Konstruktør
    virtual ~Animal() {} // Destruktør
    virtual string toString();

};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}; // Konstruktør
    string toString() override;

};

class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}; // Konstruktør som kaller på Animal-konstruktøren
    string toString() override; // Bruker override for å overskrive parent funksjonen
};

// 1d)
void testAnimal();
/*
Det som skjer er at de arvede klassene Cat og Dog ikke får arvet toString() funksjonen.
Som betyr at den ikke vil fungere i de klassene. 

*/

