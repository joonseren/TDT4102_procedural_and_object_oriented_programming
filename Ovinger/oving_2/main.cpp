// ØVING 2 - TDT4102
// meson compile -C builddir


#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Deklarasjon av funksjoner
void inputAndPrintInteger();
int inputInteger();
void inputIntegerAndPrintSum();
bool isOdd(int oddNumber);
void testIsOdd();
void inputNumbersSum();
void inputNumbersSumZero();
double inputDouble();
void valutaKalkulator();
void gangetabell();
double discriminant(double a, double b, double c);
pair<double, double> printRealRoots(double a, double b, double c);
void solveQuadraticEquation();
void pytagoras();
vector<double> calculateBalance(int rente, double innskudd, int years);
void printBalance();

//1 a)
void menu() {
        cout << "Velkommen til valgmenyen!\n"
        << "Her kan du velge hvilken funksjoner du vil kjøre.\n"
        << "For å kjøre en funksjon, tast inn tallet som tilhører funksjonen. Hvis du vil avslutte, trykk 0.\n"
        << "\n"
        << "[0]:    Avslutte programmet\n"
        << "[1]:    inputAndPrintInteger\n"
        << "[2]:    inputInteger\n"
        << "[3]:    inputIntegerAndPrintSum\n"
        << "[4]:    testIsOdd\n"
        << "[5]:    inputNumbersSum\n"
        << "[6]:    inputNumbersSumZero\n"
        << "[7]:    valutaKalkulator\n"
        << "[8]:    gangetabell\n"
        << "[9]:    solveQuadraticEquation\n"
        << "[10]:   Tegne Pytagoras\n"
        << "[11]:   printBalance()\n"
        << endl;

    while(1) {
        int meny_input;
        cin >> meny_input;

        switch (meny_input) {
            case 1:
            inputAndPrintInteger();
            break;

            case 2:
            inputInteger();
            break;

            case 3:
            inputIntegerAndPrintSum();
            break;

            case 4:
            testIsOdd();
            break;

            case 5:
            inputNumbersSum();
            break;

            case 6:
            inputNumbersSumZero();
            break;

            case 7:
            valutaKalkulator();
            break;

            case 8:
            gangetabell();
            break;

            case 9:
            solveQuadraticEquation();
            break;

            case 10:
            pytagoras();
            break;

            case 11:
            printBalance();
            break;

            default:
            return;
            break;

            
        }
    cout << "Kall på en ny funksjon! (Tast 0 for å avbryte)"  << endl; 
    } 
}

//1 b)
void inputAndPrintInteger() {
    int a = 0;
    cout << "Sriv inn et heltall:" << endl;
    cin >> a;
    cout << "Du skrev: " << a << endl;
    return;

}

//1 c)
int inputInteger() {
    int b;
    cout << "Sriv inn et heltall:" << endl;
    cin >> b;
    return b;
}

//1 d)
void inputIntegerAndPrintSum() {
    int c = inputInteger();
    int d = inputInteger();

    cout << "Summen av de to tallene: " << c+d << endl;

}

//1 e)
/* 
På grunn av inputInteger returnerer verdien brukeren skriver inn.
*/

//1 f)
bool isOdd(int oddNumber) {
    return oddNumber % 2 != 0;
}

void testIsOdd() {
    for(int i = 0; i <= 15; ++i){
        cout << "isOdd(" << i << ") = " << (isOdd(i) ? "true" : "false") << endl;

    }
    return;
}

//2 a)
void inputNumbersSum() {
    int n;
    int tall;
    vector<int> listeTall;
    int sum = 0;

    cout << "Skriv inn hvor mange tall du vil summere" << endl;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Skriv inn et heltall: " << endl;
        cin >> tall;
        listeTall.push_back(tall);


    }
    sum = accumulate(listeTall.begin(), listeTall.end(), 0);
    
    cout << "Summen av tallene du oppga er: " << sum << endl;

}

//2 b)
void inputNumbersSumZero() {
    int a;
    vector<int> list;
    cout << "Skriv inn heltall du vil summere, skriv 0 hvis du vil stoppe" << endl;
    while(a != 0) {
        cin >> a;
        cout << "Skriv inn et nytt tall:" << endl;
        list.push_back(a);

    }
    int sum = accumulate(list.begin(), list.end(), 0);

    cout << "Summen av tallene du oppga er: " << sum << endl;
    return; 
}
    
//2 c)
/*
I oppgave a) ber vi brukeren først å oppgi hvor mange tall han vil gi.
Da lønner det seg å velge en for-løkke fordi vi vet hvor mange iteresjoner vi ønsker.
Oppgave b) derimot, der skal brukeren skrive inn nye tall helt til han ikke gidder mer,
da er det best å bruke en while loop.
*/

//2 d)
double inputDouble() {
    double a;
    cout << "Skriv inn et desimaltall " << endl;
    cin >> a;
    return a;
}

//2 e)
void valutaKalkulator() {
    double kurs = 0.087;
    double a = inputDouble();
    if (a <= 0){
        cout << "Skriv inn et positivt tall" << endl;
    }else{
        double konvertering = a*kurs;
        cout << a << " NOK konvertert til EUR er: " << fixed << setprecision(2) << konvertering << " EUR" << endl;
    }
    return;
}

//2 f)
/*
Integer er en datatype som ikke kan behandle desimaltall, derfor bruker
vi inputDouble funksjonen som bruker datatypen double som kan behandle
desimaltall.
*/

//2 g)
void gangetabell() {
    int h;
    int b;
    cout << "Skriv inn høyden på tabellen" << endl;
    cin >> h;
    cout << "Skriv inn bredden på tabellen" << endl;
    cin >> b;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= b; ++j) {
            cout << setw(4) << i*j;
        }
        cout << endl;
    }
    return;
}

//3 a)
double discriminant(double a, double b, double c) {
    return pow(b, 2) - 4 * a * c;
}

//3 b)
pair<double, double> printRealRoots(double a, double b, double c) {
    if (discriminant(a, b, c) < 0) {
        return make_pair(0, 0);
    } else if(discriminant(a, b, c) == 0) {
        double x = -b/2*a;
        return make_pair(x, x);
    } else {
        double x1 = (-b - sqrt(discriminant(a, b, c)))/(2*a);
        double x2 = (-b + sqrt(discriminant(a, b, c)))/(2*a);
        return make_pair(x1, x2);
    }
}

//3 c), d), e)
void solveQuadraticEquation() {
    double a, b, c;
    cout << "Skriv inn 'a' i utrykket ax^2 + bx + c " << endl;
    cin >> a;
    cout << "Skriv inn 'b' i utrykket ax^2 + bx + c " << endl;
    cin >> b;
    cout << "Skriv inn 'c' i utrykket ax^2 + bx + c " << endl;
    cin >> c;

    pair<double, double> rotter = printRealRoots(a, b, c);

    if (discriminant(a, b, c) < 0) {
        cout << "Denne funksjonen har ingen reelle løsninger." << endl;
    } else if(discriminant(a, b, c) == 0) {
        cout << "Denne funksjonen har en reel løsning:" << endl;
        cout << "x = " << rotter.first << endl;
    } else {
        cout << "Denne funksjonen har to reelle løsninger:" << endl; 
        cout << "x = " << rotter.first << " V " << rotter.second << endl;
    }
}

//4 a), b), c), d)
void pytagoras() {
    TDT4102::AnimationWindow win;

    int a = 240;
    int b = 180;
    
    Point p1t{560, 360}; 
    Point p2t{560, 360 + a}; 
    Point p3t{560 + b, 360 + a};

    win.draw_triangle(p1t, p2t, p3t, Color::black);

    Point p1ka{559, 360};    
    Point p2ka{559 - a, 360};    
    Point p3ka{559 - a, 360 + a};    
    Point p4ka{559, 360 + a};
    win.draw_quad(p1ka, p2ka, p3ka, p4ka, Color::green);    

    Point p1kb{560 + b, 361 + a};
    Point p2kb{560, 361 + a};
    Point p3kb{560, 361 + a + b};
    Point p4kb{560 + b, 361 + a + b};
    win.draw_quad(p1kb, p2kb, p3kb, p4kb, Color::red);

    Point p1kc{560 + a + 1, 360 - b - 1};
    Point p2kc{560 + 1, 360 - 1};
    Point p3kc{560 + 1 + b, 360 + a - 1};
    Point p4kc{560 + 1 + a + b, 360 + a - b - 1};
    win.draw_quad(p1kc, p2kc, p3kc, p4kc, Color::blue);

    Point pBka{570, 360 + a/2};
    string B = "B";
    win.draw_text(pBka, B, Color::green);

    Point pAkb{560 + b/2, 330 + a};
    string A = "A";
    win.draw_text(pAkb, A, Color::red);

    Point pCkc{620, 360 + a/2};
    string c = "C";
    win.draw_text(pCkc, c, Color::blue);



    win.wait_for_close();
}

//5 a)
vector<double> calculateBalance(int rente, double innskudd, int years) {
    vector<double> saldoPerYear = {innskudd};

    for(int i= 0; i <= years; ++i) {
        double saldo = innskudd * pow(years, (1 + rente/100));
        saldoPerYear.push_back(saldo);
    }
    return saldoPerYear;
}

void printBalance() {
    int rente;
    double innskudd;
    int years;

    vector<double> saldoPerYear = calculateBalance(rente, innskudd, years);
    
    cout << "Skriv inn renten: " << endl;
    cin >> rente;
    cout << "Skriv inn inskuddet: " << endl;
    cin >> innskudd;
    cout << "Skriv inn hvor mange år du vil se kontoen for: " << endl;   
    cin >> years;

    for (double element : saldoPerYear) {
        cout << element << " ";
    }
    cout << endl;

    /*
    for(int i = 0; i <= years; ++i){
        cout << "År" << endl;
        cout << i << endl;
        for(int j = innskudd; j <= saldoPerYear.at(i); ++j) {
            cout << "Saldo" << endl;
            cout << saldoPerYear.at(j) << endl;

        }
    }
    */

}

int main()  {
    menu();
    return 0;
}
