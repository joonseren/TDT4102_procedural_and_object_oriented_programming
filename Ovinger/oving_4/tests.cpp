// TDT4102 Øving 4

#include "tests.h"


// Task 1
// 1c)
void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

// 1d)
void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0 before: " << v0 << endl;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "increment: " << increment << endl;
    cout << "iterations: " << iterations << endl;
    cout << "result: " << v0 << endl; 
}

// 3a), c), f) 

void testString() {
    string grades = randomizeString(8, 'F', 'A');
    cout << "grades:\n" << grades << endl;


    vector<int> gradeCount{};
    gradeCount.push_back(countChar(grades, 'A'));
    gradeCount.push_back(countChar(grades, 'B'));
    gradeCount.push_back(countChar(grades, 'C'));
    gradeCount.push_back(countChar(grades, 'D'));
    gradeCount.push_back(countChar(grades, 'E'));
    gradeCount.push_back(countChar(grades, 'F'));

    cout << "gradeCount: " << endl;
    for(int grade : gradeCount) {
        cout << grade << " ";
    }
    cout << endl;


    int sum = 0;
    for(int i{0}; i < gradeCount.size(); i++) {
        sum += gradeCount[i]*(6 - i);
    }
    

    double gjSnitt = static_cast<double>(sum)/6;
    cout << "Gjennomsnittskarakter er:\n" << gjSnitt << endl;
}

