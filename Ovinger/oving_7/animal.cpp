// TDT4102 Øving 7

#include "animal.h"

// 1b), c)
string Animal::toString() {
    return "Animal: " + name + ", " + to_string(age);
}

string Cat::toString() {
    return "Cat: " + name + ", " + to_string(age);
}

string Dog::toString() {
    return "Dog: " + name + ", " + to_string(age);
}


// 1d)
void testAnimal() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Animal{"Tiger", 30});
    animals.emplace_back(new Cat{"Sirius", 5});
    animals.emplace_back(new Dog{"Husky", 13});
    animals.emplace_back(new Animal{"Hvithai", 1000});

    //iterere gjennom vektoren
    for (int i = 0; i < animals.size(); i++) {
        cout << animals.at(i) -> toString() << endl;
    }
}

