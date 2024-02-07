// Oving 3 TDT4102 
// ———————————————
// Implementation-file oppg. 5

#include "utilities.h"

// 5a)
int randomNumberGenerator() {
    random_device rd;
    default_random_engine generator(rd());
    int number = generator();
    cout << number << endl;
    return number; 
}

// 5b)
int randomWithLimits() {
    int lowerLimit = 0;
    int upperLimit = 0;

    cout << "Skriv inn den nedre grensen for et tilfelding generert tall: " << endl;
    cin >> lowerLimit;
    cout << "Skriv inn den øvre grensen for et tilfelding generert tall: " << endl;
    cin >> upperLimit;

    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(lowerLimit, upperLimit);

    cout << distribution(generator) << endl; 

    return distribution(generator);


}

