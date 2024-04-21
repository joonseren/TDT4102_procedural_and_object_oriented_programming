// TDT4102 Øving 11

#include "measurePerformance.h"
#include "vectorOptimization.h"
#include "optimizationTask.h"
#include "MyArray.h"
#include <random>


// Task 4:
template<typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b; 
}

template<typename T>
std::vector<T> shuffle(std::vector<T> vec) {
    for (int i{0}; i < vec.size(); i++) {
        std::random_device rd;
        std::default_random_engine generator(rd());
        std::uniform_int_distribution <int> distr(0, vec.size() - 1);
        int r = distr(generator);
        std::swap(vec.at(i), vec.at(r));
    }
    return vec;
}

template<typename T>
void printVector(std::vector<T> vec) {
    for (const T i : vec) {
        std::cout << i << " ";
    } std::cout << std::endl;
}


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
    /*
    double time;
    Stopwatch clock;
    clock.start();
    optimizationTask();
    time = clock.stop();
    std::cout << "Time: " << time << " s" << std::endl;
    return 0;
    */
    
    /// Task 4:
    // std::cout << maximum<double>(2.0, 3.0) << std::endl;

    // std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // printVector(shuffle(a));

    /// Task 5:

    MyArray<double, 5> arr(10);

    for (int i{0}; i < arr.getSize(); i++) {
        std::cout << arr.at(i) << " ";
    } std::cout << std::endl;


}