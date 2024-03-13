// TDT4102 Øving 8

#include "dynamicMemoryIntro.h"
#include "fibonacci.h"
#include "Matrix.h"

int main() {
    
    Matrix m(3, 3);
    std::cout << m;
    m.set(1, 1, 1);
    std::cout << m;
    std::cout << m.getColumns();

    return 0;
}