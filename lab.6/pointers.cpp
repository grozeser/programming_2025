#include <iostream>
#include "pointers.hpp"

void PointerProgramm() {
    int a, b;
    std::cout << "¬ведите a и b: ";
    std::cin >> a >> b;

    int* pa = &a;
    int* pb = &b;

    *pa *= 2; 

    int tp = *pa; 
    *pa = *pb;
    *pb = tp;

    std::cout << "a = " << a << ", b = " << b << std::endl;

}
