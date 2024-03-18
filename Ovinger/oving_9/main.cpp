// TDT4102 Øving 9

#include "Person.h"


int main() {
    auto bil = std::make_unique<Car>(5);


    Person jens("Jens", "jens@gmail.com", std::move(bil));
    Person jensUBil("Jens", "jens@gmail.com");

    std::cout << jens << std::endl;
    std::cout << jensUBil << std::endl;
    return 0;
}
