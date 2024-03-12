// TDT4102 Øving 8

#pragma once
#include <iostream>

void newAndDelete();
void dynamicArrayExample();

class Example {
private:
    int *anInt;

public:
    Example(int i);
    Example();
    ~Example();
    int get() const;
    Example(const Example& other);
    Example& operator=(const Example& other);
};

