// TDT4102 ØVING 6
// Oppagve 1

#include "oppg1.h"

// 1a)
filesystem::path fileName{"text.txt"};
ofstream outputStream{"text.txt"};

void inputToFile() {
    string quit = "quit";
    string word;
    while (word != quit) {
        cout << "Skriv inn et ord du ønsker å legge til i filen: " << endl;
        cin >> word;
        if (word != quit) {
            outputStream << word << endl;
        }
    }
}

// 1b)
filesystem::path textFile{"text.txt"};
ifstream inputStream{"text.txt"};
filesystem::path textFile2{"text2.txt"};
ofstream outputStream2{"text2.txt"};

void lineNumberFile() {
    if (!inputStream) {
        error("Could not find inputStreamfile");
    }
    if (!outputStream2) {
        error("Could not find outputStream2 file");
    }

    string line;
    int i = 1;
    while (getline(inputStream, line)) {
        outputStream2 << i << ":   " << line << endl;
        i++;
    }
}
