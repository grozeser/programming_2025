#include <iostream>
#include <cmath>
using namespace std;

// Пункт 1

int read(int a) {
    cout << "исп. функция: противоположное число" << endl;
    return -a;
}

int read(int a, int b) {
    cout << "исп. функция: склеивание 2-х чисел" << endl;

    int digits = 0;
    int tmp = b;
    do {
        digits++;
        tmp /= 10;
    } while (tmp != 0);

    int x = 1;
    for (int i = 0; i < digits; ++i) {
        x *= 10;
    }

    return a * x + b;
}

int read(int a, int b, int c) {
    cout << "исп. функция: обработка 3-х чисел (0 = нет числа)" << endl;

    if (a != 0 && b == 0 && c == 0)
        return read(a);
    else if (a == 0 && b != 0 && c == 0)
        return read(b);
    else if (a == 0 && b == 0 && c != 0)
        return read(c);
    else if (a != 0 && b != 0 && c == 0)
        return read(a, b);
    else if (a != 0 && b == 0 && c != 0)
        return read(a, c);
    else if (a == 0 && b != 0 && c != 0)
        return read(b, c);
    else
        return read(read(a, b), c);
}

// Пункт 2 

void geronF(int a, int b, int c) {
    cout << "исп. функция: вычисление площади треугольника по формуле Герона" << endl;

    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "треугольник с такими сторонами не существует" << endl;
        return;
    }

    double p = (a + b + c) / 2.0;
    double S = sqrt(p * (p - a) * (p - b) * (p - c));

    cout << "a = " << a << "b = " << b << "c = " << c << endl;
    cout << "p = " << p << endl;
    cout << "S = " << S << endl;
}


int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    cout << "Введите номер пункта (1, 2): ";
    cin >> choice;

    if (choice == 1) {
        int a, b, c;
        cout << "Введите три целых числа: ";
        cin >> a >> b >> c;

        int result = read(a, b, c);
        cout << "Результат: " << result << endl;
    }
    else if (choice == 2) {
        int a, b, c;
        cout << "Введите стороны треугольника (целые числа): ";
        cin >> a >> b >> c;

        geronF(a, b, c);
    }
    else {
        cout << "выбран неверный пункт" << endl;
    }

    return 0;
}
