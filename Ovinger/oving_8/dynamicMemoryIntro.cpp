// TDT4102 Øving 8

#include "dynamicMemoryIntro.h"


// pointers in prosedural programming example
void newAndDelete() {
    int* x = new int;

    std::cout << "Skriv inn et heltall: ";
    std::cin >> *x;
    std::cout << "Takk! Du skrev " << *x << std::endl;

    delete x;
    x = nullptr;
}


void dynamicArrayExample() {
    int n = 0;
    std::cout << "Hvor mange tall vil du skrive inn?";
    std::cin >> n;

    double *numbers = new double[n] {};
    for (int i{0}; i < n; i++) {
        std::cout << "Number input: ";
        std:: cin >> numbers[i];
    }

    for (int i{0}; i < n; i++) {
        std::cout << numbers[i] << " ";
    } std::cout << std::endl;

    delete[] numbers;
    numbers = nullptr;

}


Example::Example(int i) {
    anInt = new int{i};
}

Example::Example() {
    anInt = new int{0};
}
Example::~Example() {
    delete anInt;
}
int Example::get() const {
    return *anInt;
}

Example::Example(const Example& other) {
    this->anInt = new int{};
    *anInt = other.get();
}

Example& Example::operator=(const Example& other) {
        delete anInt;
        anInt = new int{};
        *anInt = other.get();
        return *this;
    }