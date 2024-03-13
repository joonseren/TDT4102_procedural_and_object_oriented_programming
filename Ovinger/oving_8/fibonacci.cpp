// TDT4102 Øving 8

#include "fibonacci.h"


// 1a)
void fillInFibonacciNumbers(int* result, int length) {
    if (length > 0) {
        result[0] = 0;
    }
    if (length > 1) {
        result[1] = 1;
    }
    
    for(int i{2}; i < length; i++) {
        result[i] = result[i - 2] + result[i - 1];
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

    int *result = new int[length] {};

    fillInFibonacciNumbers(result, length);

    printArray(result, length);

    delete[] result;
    result = nullptr;
}


