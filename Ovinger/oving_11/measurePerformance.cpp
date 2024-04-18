// TDT4102 Øving 11

#include "measurePerformance.h"
#include <vector>
#include <array>

// 1 a), b)
void iterationFunction(int size) {
    Stopwatch clock;
    clock.start();
 

    for (int i = 0; i < size; i++) {
        std::unique_ptr<int> ptr = std::make_unique<int>(17);
    }
    
    double time = clock.stop();
    std::cout << "Pointer-type: unique" <<"\nIterations: " << size << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/size << "s" << std::endl; 
}

void iterationFunction2(int size) {
    Stopwatch clock;
    clock.start(); 

    for (int i = 0; i < size; i++) {
        std::shared_ptr<int> sharedptr = std::make_shared<int>(17);
    }
    
    double time = clock.stop();
    std::cout << "\nPointer-type: shared" << "\nIterations: " << size << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/size << "s" << std::endl; 
}


void iterationFunction3(int size) {
    Stopwatch clock;
    clock.start(); 
    constexpr int n = 10000;
    for (int i = 0; i < size; i++) {
        std::array<int, n> arr1;
    }
    
    double time = clock.stop();
    std::cout << "\nStack allocation" << "\nIterations: " << size << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/size << "s" << std::endl; 
}

void iterationFunction4(int size) {
    Stopwatch clock;
    clock.start(); 
    constexpr int n = 10000;
    for (int i = 0; i < size; i++) {
        std::array<int, n>* arr2 = new std::array<int, n>;
        delete arr2;
    }
    
    double time = clock.stop();
    std::cout << "\nHeap allocation" << "\nIterations: " << size << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/size << "s" << std::endl; 
}
