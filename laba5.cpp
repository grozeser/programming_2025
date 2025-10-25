#include <iostream>

int Single(int digit) {
    std::cout << "Используется функция замены 1 числа на противоположное" << std::endl;
    return -digit;
}

int Double(int a, int b) {
    std::cout << "Используется функция склейки двух чисел в порядке ввода" << std::endl;
    int tmp = b;
    int digits = 0;
    if (tmp == 0) digits = 1; 
    while (tmp > 0) {
        tmp /= 10;
        digits++;
    }
    int mult = 1;
    for (int i = 0; i < digits; ++i) {
        mult *= 10;
    }
    int result = a * mult + b;
    return result;
}

int Triple(int a, int b, int c) {
    std::cout << "Используется функция обработки трёх чисел" << std::endl;
    int ab = Double(a, b);
    int tmp = c;
    int digits = 0;
    if (tmp == 0) digits = 1;
    while (tmp > 0) {
        tmp /= 10;
        digits++;
    }
    int mult = 1;
    for (int i = 0; i < digits; ++i) {
        mult *= 10;
    }
    int result = ab * mult + c;
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    std::cout << "Введите номер пункта (1 или 2): ";
    std::cin >> choice;

    if (choice == 1) {
        const int NMax = 3;
        int numbers[NMax];

        std::cout << "Введите три числа (0 если числа нет): ";
        for (int i = 0; i < NMax; ++i) {
            std::cin >> numbers[i];
        }

        int count = 0;
        for (int i = 0; i < NMax; ++i) {
            if (numbers[i] != 0) count++;
        }

        int result = 0;
        if (count == 1) {
            for (int i = 0; i < NMax; ++i) {
                if (numbers[i] != 0) {
                    result = Single(numbers[i]);
                    break;
                }
            }
        }
        else if (count == 2) {
            int first = 0, second = 0, found = 0;
            for (int i = 0; i < NMax; ++i) {
                if (numbers[i] != 0) {
                    if (found == 0) first = numbers[i];
                    else second = numbers[i];
                    found++;
                }
            }
            result = Double(first, second);
        }
        else if (count == 3) {
            result = Triple(numbers[0], numbers[1], numbers[2]);
        }
        else {
            std::cout << "Нет чисел для обработки" << std::endl;
            return 1;
        }

        std::cout << "Результат: " << result << std::endl;
    }
    else if (choice == 2) {
        std::cout << "Пункт 2: Дополнительная функция" << std::endl;
    }
    else {
        std::cout << "Неверный пункт" << std::endl;
    }
    return 0;
}

