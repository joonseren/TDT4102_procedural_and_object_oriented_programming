// TDT4102 Øving 9

#include "Car.h"

bool Car::hasFreeSeats() {
    if (freeSeats > 0) {
        return true;
    }
    return false;
}

void Car::reserveFreeSeat() {
    if (hasFreeSeats()) {
    freeSeats--;
    }
    else {
        std::cout << "full car"  << std::endl;
    }
}

 