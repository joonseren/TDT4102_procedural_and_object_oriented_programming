// TDT4102 Øving 4
// meson compile -C builddir


#include "utilities.h"
#include "mastermind.h"


// Task 1
// 1c)
void menu() {
        cout << "Velkommen til valgmenyen!\n"
        << "Her kan du velge hvilken funksjoner du vil kjøre.\n"
        << "For å kjøre en funksjon, tast inn tallet som tilhører funksjonen. Hvis du vil avslutte, trykk 0.\n"
        << "\n"
        << "[0]:    Avslutte programmet\n"
        << "[1]:    testCallByValue\n"
        << "[2]:    testCallByReference\n"
        << "[3]:    swapNumbersByValue\n"
        << "[4]:    swapNumbersByReference\n"
        << "[5]:    printStudent\n"
        << "[6]:    randmoizeString TEST!\n"
        << "[7]:    readInputToTest TEST!\n"
        << "[8]:    countChar TEST!\n"
        << "[9]:    testString TEST!\n"
        << "[10]:   playMastermind\n"
        << endl;

    while(1) {
        int meny_input;
        cin >> meny_input;

        switch (meny_input) {
            case 1:
                testCallByValue();
                break;

            case 2:
                testCallByReference();
                break;

            case 3:
                swapNumbersByValue(6, 9);
                break;

            case 4: {
                int a = 6;
                int b = 9;
                swapNumbersByReference(a, b);
                break;
            }

            case 5: {
                Student studJonas;
                studJonas.name = "Jonas";
                studJonas.age = 21;
                studJonas.studyProgram = "Automatisering";
                printStudent(studJonas);
                cout << "Er studenten i studieprogrammet? " << isInProgram(studJonas, "Automatisering") << endl;

                break;
            }
            
            case 6:
                cout << randomizeString(4, 'A', 'F') << endl;
                break;

            case 7:  
                readInputToString(8, 'Z', 'A');
                break;

            case 8:
                cout << countChar("KKK", 'K') << endl;
                break;

            case 9:
                testString();
                break;
            
             case 10:
                playMastermind();
                break;
         


            default:
                return;


            
        }
    cout << "Kall på en ny funksjon! (Tast 0 for å avbryte)"  << endl; 
    } 
    return;
}

int main() {
    menu();
    return 0;
}



