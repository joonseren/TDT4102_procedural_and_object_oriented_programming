// TDT4102 Øving 11

#include "measurePerformance.h"
#include <vector>

void iterationFunction(const double n) {
    Stopwatch clock;
    clock.start();
    std::vector<int> numbers;
    double i;
    double j; 
    for (i = 0; i < n; i++) {
        j = i*2;
        numbers.push_back(j);
        std::cout << numbers.at(i) << " ";
    }
    double time = clock.stop();
    std::cout << "\nIterations: " << n << "\nTime: " << time << "s" << "\nAverage time per iteration: " << time/n << "s" << std::endl; 
}