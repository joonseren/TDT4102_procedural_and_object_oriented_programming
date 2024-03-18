// TDT4102 Øving 9

#include <iostream>

class Car {
private:
    int freeSeats;

public:
    bool hasFreeSeats();
    void reserveFreeSeat();
    Car(int fSeats) : freeSeats(fSeats) {};

};