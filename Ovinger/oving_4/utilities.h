// TDT4102 Øving 4

#pragma once
#include "std_lib_facilities.h"


// Task 1
// 1b)
int incrementByValueNumTimes(int startValue, int increment, int numTimes);

// 1d)
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

// 1e)
void swapNumbersByValue(int a, int b);
void swapNumbersByReference(int& a, int& b);

// 2a)
struct Student{
    string name;
    string studyProgram;
    int age;
};

// 2b)
void printStudent(struct Student stud);

// 2c)
string isInProgram(struct Student stud, string program);

// 2e)
/*
Feilen kommer av at Student structet blir definert flere ganger. Siden man 
includer "utilities.h" i "tests.h" og i main.cpp, blire Student definert to ganger i main.
For å løse problemet kan man fjerne "#include utilities.h" i main.cpp.
*/

// 3b)
string randomizeString(int numSign, char upperLimit, char lowerLimit);

// 3d)
string readInputToString(int n, char upperLimit, char lowerLimit);

// 3e)
int countChar(string str, char tegn);

// Task 4
int checkCharactersAndPosition(const string& code, const string& guess);
int checkCharacters(const string& code, const string& guess);


