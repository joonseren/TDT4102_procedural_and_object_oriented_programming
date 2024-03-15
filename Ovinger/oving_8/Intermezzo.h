// TDT4102 Øving 8

#pragma once
#include <iostream>
#include <utility>

// 3b)
void dummyTest();

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    // 3c)
    Dummy(const Dummy& other) : num(new int(*(other.num))) {}

    // 3e)
    Dummy& operator=(const Dummy& other) {
        delete num;
        num = new int(*(other.num));
        return *this;
    }

    ~Dummy() {
        delete num;
        num = nullptr;
    }
};
/*
Dette skjer på grunn av det ikke eksisterer en kopikonstruktør. Da peker alle variablene på samme sted i minne.
*/