// TDT4102 Øving 11

#include "vectorOptimization.h"

// 2a)
void understandVector(int n) {
    std::vector<int> vec;
    vec.resize(20); 
    std::cout << "__________Vector length: " << vec.size() << "\nVector capacity: " << vec.capacity() << std::endl;
    for (int i{0}; i < n; i++) {
        vec.push_back(i);
        std::cout << "Vector length: " << vec.size() << "\nVector capacity: " << vec.capacity() << std::endl;
    }
}

void timeVector(int n) {
    Stopwatch clock; 
    clock.start();
    
    std::vector<double> vec;
    vec.resize(n);
    for (int i{0}; i < n; i++) {
        vec.push_back(17);
    }
    double time = clock.stop();
    std::cout << "\nWith optimiztion improvements: resize(n)" << "\nIterations: " << n << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/n << "s" << std::endl; 
}

