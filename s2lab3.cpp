#include"library.hpp"
#include<iostream>

void printее(){
    std::cout << "ОЦЕНКА ЛАБОРАТОРНОЙ РАБОТЫ:\n";
    std::cout << "Интерес 10/10\n";
    std::cout << "Наполненность 100/10\n";
    std::cout << "Сложность 1000/10\n";
}

int main(){
    setlocale(LC_ALL, "Russian");

    Budget rusBudget(1000000, 2.5); 
    State russia("Россия", "Москва", FoundationDate(12, 6, 1990), 17125191, rusBudget);

    russia.addCity({ "Москва", 12000000, 0 });
    russia.addCity({ "Санкт-Петербург", 5000000, 0 });
    russia.addCity({ "Новосибирск", 1600000, 0 });

    std::cout << "До распределения бюджета:\n";
    russia.printInfo();

    std::cout << "\nРаспределяем бюджет...\n";
    russia.distributeBudget();
    russia.printInfo();

    State smallState("Пригород", "Центр", FoundationDate(1, 1, 2020), 500, Budget(50000, 1.0));
    smallState.addCity({ "Центр", 1000, 0 });

    State unionState = russia + smallState;
    std::cout << "\nПосле объединения (operator+):\n";
    unionState.printInfo();

    printее();

    return 0;
}
