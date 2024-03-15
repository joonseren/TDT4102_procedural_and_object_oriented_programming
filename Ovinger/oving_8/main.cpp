// TDT4102 Øving 8

#include "dynamicMemoryIntro.h"
#include "fibonacci.h"
#include "Matrix.h"
#include "Intermezzo.h"

// Matrix testing functions

int main() {

    Matrix A(2, 2);
    A.set(0, 0, 1.0);
    A.set(0, 1, 2.0);
    A.set(1, 0, 3.0);
    A.set(1, 1, 4.0);

    Matrix B(2, 2);
    B.set(0, 0, 4.0);
    B.set(1, 0, 3.0);
    B.set(1, 0, 2.0);
    B.set(1, 1, 1.0);
    
    Matrix C(2, 2);
    C.set(0, 0, 1.0);
    C.set(1, 0, 3.0);
    C.set(1, 0, 1.5);
    C.set(1, 1, 2.0);

    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    
    A += B;
    
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;


    return 0;
}