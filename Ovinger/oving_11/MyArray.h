// TDT4102 Øving 11

#pragma once
#include <iostream>
#include <stdexcept>

template<typename Type, int Size>
class MyArray {
private:
    Type elements[Size];

public:
    MyArray(Type t) {
        for (int i{0}; i < Size; i++) {
            elements[i] = t;
        }
    }
    int getSize() {return Size;}

    Type& at(int index) {
        if (index > Size) {
            throw std::out_of_range("Index is out of range");       
        }
        return elements[index];
    }
    
    void fill(Type t) {
        for (int i{0}; i < Size; i++) {
            elements[i] = t;
        }
    }
}; 