// TDT4102 Øving 4

#include "mastermind.h"

// Task 4
void playMastermind() {
    cout << "Velkommen til Mastermind-spillet!" << endl;
    cout << "Du har 10 liv." << endl;
    
    constexpr int size = 4; 
    constexpr int letters = 6;  

    string code = randomizeString(size, 'A', 'A' + letters - 1);
    string guess;
    bool hasWon = false;
    cout << code << endl;

    for (int i{1}; i < 11; i++) {
        cout << "Dette er ditt " << i << " forsøk." << endl;
        guess = readInputToString(4, 'F', 'A');
        cout << "Antall riktige plasser:   " << checkCharactersAndPosition(code,  guess) << endl;
        cout << "Antall riktige bokstaver: " << checkCharacters(code, guess) << endl;
        cout << "————————————————————————————————————————————————————————————" << endl;
    
        if (checkCharactersAndPosition(code, guess) == size) {
            hasWon = true;
            break;
        }
    }
    
    if (hasWon) {
        cout << "Gratulerer du vant! Det rette ordet var: " << code << endl;   
    } else {
        cout << "Du tapte sucker! Det rette ordet var: " << code << endl;
    }

    char playAgain;

    cout << "Vil du spille på nytt? Y/N" << endl;
    cin >> playAgain;
    if (playAgain == 'Y') {
        playMastermind();
    } else {
        cout << "Good bye!" << endl;
    }



    return;
}

