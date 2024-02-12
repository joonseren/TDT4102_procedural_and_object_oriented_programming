// TDT4102 Øving 4

#include "utilities.h"


// Task 1
// 1a)
/*
Outputen til den koden er som følger: "v0: 5 increment: 2 iterations: 10 result: 25". 
*/

// 1b)
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

// 1d)
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }

}

// 1e)
void swapNumbersByValue(int a, int b) {
    cout << "value1 before: " << a << endl;
    cout << "value2 before: " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "value1 after: " << a << endl;
    cout << "value2 after: " << b << endl;
}

void swapNumbersByReference(int& a, int& b) {
    cout << "value1 before: " << a << endl;
    cout << "value2 before: " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "value1 after: " << a << endl;
    cout << "value2 after: " << b << endl;
}


// 2b)
void printStudent(struct Student stud){
    cout << "Studentens navn: " << stud.name << endl;
    cout << "Studentens alder: " << stud.age << endl;
    cout << "Studentens studieprogram: " << stud.studyProgram << endl;
    return;
}

// 2c)
string isInProgram(struct Student stud, string program) {
    bool result = stud.studyProgram == program;
    return result ? "JA" : "NEI";
}

// 3b)
string randomizeString(int numSign, char lowerLimit, char upperLimit) {
    string str{};

    for (int i{0}; i < numSign; i++) {
        random_device rd;
        default_random_engine generator(rd());
        uniform_int_distribution<int> distribution(static_cast<int>(lowerLimit), static_cast<int>(upperLimit));
        char sign = static_cast<char>(distribution(generator));

        str.push_back(sign);
    }
    return str; 
}

// 3d)
string readInputToString(int n, char lowerLimit, char upperLimit) {
   
    string ord;
    char inputTest{};
    while (ord.size() < n){
        
        cout << "Guess: " << endl;
       
        cin >> inputTest;
        inputTest = toupper(inputTest);
        if(!inputTest > lowerLimit || inputTest < upperLimit){
            cout << "Du skrev inn en bokstav som er utenfor definisjonsområdet." << endl;
        }else{
            ord.push_back(inputTest);  
        }

    }
    cout << "————————————————————————————————" << endl;
    cout << ord << endl;
    return ord;
}
 
// 3e)
int countChar(string str, char tegn) {
    int count{0};
    for (int i{0}; i < str.size(); i++) {
        if (str[i] == tegn) {
            count++;
        }
    }
    return count;
}

// Task 4
int checkCharactersAndPosition(const string& code, const string& guess) {
    int sumCorrect{0};
    for (int i{0}; i < code.length(); i++) {
        if (code.at(i) == guess.at(i)) {
            sumCorrect++;
        }
    }
    return sumCorrect;
}

int checkCharacters(const string& code, const string& guess) {
    int sumCorrect{0};
    
    for (char i = 'A'; i <= 'F'; i++) {
        int countCode = countChar(code, i);
        int countGuess = countChar(guess, i);

        sumCorrect += min(countCode, countGuess);
    }
    return sumCorrect;
}


