// TDT4102 Øving 8

#include "fibonacci.h"


// 1a)
void fillInFibonacciNumbers(int* result, int length) {
    if (length > 0) {
        result[0] = 0;
    }
    else if (length > 1) {
        result[1] = 1;
    }
    else {
        for(int i{2}; i < length; i++) {
            result[i] = result[i - 2] + result[i - 1];
        }
    }
}

// 1b)
void printArray(int* arr, int length) {
    for (int i{0}; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// 1c)
void createFibonacci() {
    int length;
    std::cout << "Hvor mange tall skal genereres? " << std::endl;
    std::cin >> length;

    

// 1. Spør brukeren hvor mange tall som skal genereres
// 2. Alloker minne til en tabell som er stor nok til tallrekka
// 3. Fylle tabellen med fillInFibonacciNumbers()
// 4. Skriv ut resultatet til skjerm med printArray()
// 5. Frigjør minnet du har reservert
}