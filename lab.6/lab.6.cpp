#include <iostream>
#include "matrix.hpp"
#include "pointers.hpp"

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    {
        std::cout << "пункт 1\n";
        std::cout << "пункт 2\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            RunMatrix();
            break;
        case 2:
            PointerProgramm();
            break;
        }
    }

    return 0;
}
