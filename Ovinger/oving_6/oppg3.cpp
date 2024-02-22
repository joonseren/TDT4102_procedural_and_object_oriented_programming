// TDT4102 ØVING 6

#include "oppg3.h"

// 3b)
void CourseCatalog::addCourse() {
    string courseCode;
    string courseName;
    cout << "Her kan du legge til emne i CourceCatalog" << endl;
    cout << "Skriv inn emnnekoden: " << endl;
    cin >> courseCode;
    cout << "Skriv inn emnenavnet: " << endl;
    cin >> courseName;
    courses.erase(courseCode);
    courses.insert({courseCode, courseName});
}

void CourseCatalog::removeCourse() {
    string courseCode;
    cout << "Her kan du fjerne et emne i CourceCatalog" << endl;
    cout << "Skriv inn emnnekoden: " << endl;
    cin >> courseCode;
    courses.erase({courseCode});
}

string CourseCatalog::getCourse() {
    string courseCode;
    cout << "Her kan du hente et emne i CourceCatalog" << endl;
    cout << "Skriv inn emnnekoden: " << endl;
    cin >> courseCode;
    return courses.at(courseCode);
}

// 3c)
ostream& operator<<(ostream& os, const CourseCatalog& c) {
    for (const auto& pair : c.courses) {
        os << "Emnekode: " << pair.first << ", Emnenavn: " << pair.second << endl;
    }
    return os;
}

// 3d)
void CourseCatalog::testFunction() {
    addCourse();
    cout << *this;
}

// 3e)
/*
Det som skjer når jeg prøver å endre navnet med testFunction er ingenting.
Når vi bruker [] overskriver det elementet som er der fra før og man kan da endre det.
En bedre måte kan være at man først sletter elementet man vil erstatte med .erase()
for å så legge det til på nytt med .insert()
*/

// 3f)
void CourseCatalog::courseToText() {
    
    filesystem::path outputFile{"courseCatalogNew.txt"};
    ofstream outputStream{"courseCatalogNew.txt"};


    for (const auto& pair : courses) {
        outputStream << pair.first << " | " << pair.second << endl;
    }
    
    
}

void CourseCatalog::courseFromText() {
    filesystem::path inputFile{"courseCatalog.txt"};
    ifstream inputStream{"courseCatalog.txt"};

    if (!inputStream) {
        error("Could not open courseCatalog.txt file, check file path");
    }

    string s;
    inputStream >> s;

}


