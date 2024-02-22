// TDT4102 ØVING 6
// Oppgave 3

#pragma once
#include "oppg1.h"

// 3a)
class CourseCatalog {
private:
    map<string, string> courses {
        {"TDT4102", "Prosedyre- og objekt-orientert programmering"},
    };

public:
    void addCourse();
    void removeCourse();
    string getCourse();
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);
    void testFunction();
    void courseToText();
    void courseFromText();
};
