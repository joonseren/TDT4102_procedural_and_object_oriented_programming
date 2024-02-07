
#include "std_lib_facilities.h"


// Oppgave 1
/*
def isFibonacciNumber(n):
    a = 0
    b = 0
    while b < n:
        temp = b
        b += a
        a = temp
    
*/


// Oppgave 2
// 2 a)

int maxOfTwo(int a, int b) {
    if (a > b) {
        cout << "A is greater than B" << endl;
        return a;   

    } else {
        cout << "B is greater than A" << endl;
        return b;
    }
}

// 2 c)
int fibonacci(int n) {
    int a = 0;
    int b = 1;
    int temp;
    cout << "Fibonacci numbers:" << endl;
    for (int x = 1; x < n + 1; ++x){
        cout << x << " " << b << endl;
        temp = b;
        b += a;
        a = temp; 
    }
    cout << "––––––––––" << endl;
    return b;   
}

// 2 d)
int squareNumberSum(int n){
    int totalSum = 0;
    for (int i = 1; i < n + 1; ++i){
        totalSum += i * i;
        cout << (i * i) << endl;

    }
    cout << totalSum << endl;
    return totalSum;
}

// 2 e)
void triangleNumbersBelow(int n){
    int acc = 1;
    int num = 2;
    cout << "Triangel numbers below " << n << endl;
    while (acc < n){
        cout << acc << endl;
        acc += num;
        num += 1;
    }
    return;
}

// 2 f)
bool isPrime(int n) {
    for (int j = 2; j < n; ++j){
        if (n%j == 0){
            return false;
        }
    }
    return true;
}

// 2 g)
void naivePrimeNumberSearch(int n){
    for (int number = 2; number < n; ++number){
        if (isPrime(number)){
            cout << number << " is a prime" << endl;
        }
    }
    return;
}


void inputAndPrintNameAndAge(){
    string name;
    int age;
    cout << "Skriv inn et navn: " << endl;
    cin >> name;
    cout << "Skriv inn alderen til " << name << ":" << endl;
    cin >> age;
    cout << name << " er " << age << " aar gammel" << endl;

}

int main() {
    // 2 b)
    cout << "Oppgave a)" << endl;
    cout << maxOfTwo(5, 6) << endl;
    cout << " " << endl;

    // 2 c) 
    cout << "Oppgave c)" << endl;
    cout << fibonacci(13) << endl;
    cout << " " << endl;

    // 2 d)
    cout << "Oppgave d)" << endl;
    cout << squareNumberSum(5) << endl;
    cout << " " << endl;   

    // 2 e)
    cout << "Oppgave e)" << endl;
    triangleNumbersBelow(10);
    cout << " " << endl;

    // 2 f)
    cout << "Oppgave f)" << endl;
    cout << isPrime(13) << endl;
    cout << " " << endl;

    // 2 g)
    cout << "Oppgave f)" << endl;
    naivePrimeNumberSearch(14);
    cout << " " << endl;


    cout << "Oppgave h)" << endl;
    inputAndPrintNameAndAge();


}