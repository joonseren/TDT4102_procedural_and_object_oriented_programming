// TDT4102 Øving 11

#include "measurePerformance.h"
#include "vectorOptimization.h"
#include "optimizationTask.h"

int main() { 
    /// Task 1:
    //int i = 5e8;
    //iterationFunction(i);
    //iterationFunction2(i);
    //iterationFunction3(i);
    //iterationFunction4(i);
    
    /// Task 2:
    //int n = 1e6;
    //understandVector(n);
    //timeVector(n);

    /// Task 3:
    double time;
    Stopwatch clock;
    clock.start();
    optimizationTask();
    time = clock.stop();
    std::cout << "Time: " << time << " s" << std::endl;
    return 0;
}