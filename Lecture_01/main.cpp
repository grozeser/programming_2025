int main() {

    // целочисленные
    char c1; // 1 байт, 256 значение, -128..127
    unsigned char c2; // 1 байт, 256 значений, 0..255
    short s1; // 2 байта, 65536 значений, -32768..37767
    unsigned short s2; // 2 байта, 65536 значений, 0..65535
    int i1; //4 байта, 4.147 млдр., -2^31 .. 2^31 - 1
    unsigned int i2; // 4 байта, 4.147 млдр., 0..2^32 - 1
    long long ll1; // 8 байт
    unsigned long long ull2; // 8 байт

    i1 = 10.5;
    std::cout << i1 << std::endl;

    // символьный
    char c3 = 'a';

    // вещественные
    float f = 3.141592f; // 4 байта, 6-7 значащих цифр
    double d = 3.14159211111111111; // 8байт, 15-16 значащих цифр

    float f1 = 10;

    // логический тип данных
    //bool b; // false (0)
    //bool b; // 1 байт

    // declaration - объявление
    // definition - определение

    int x = 123;

    std::cout << x << std::endl;

    int sumOfDigits; // lower camel case
    int SumOfDigits; // upper camel case
    int sum_of_digits; // snake case
    int sumofdigits;


    return 0;
}
    



#include <iostream>
//#include <cmath>

int main() {

    std::cout << pow(10, 5) << std::endl;
    std::cout << sin(1.5707) << std::endl;
    /*
    int x;
    int y;
    std::cin >> x >> y;
    std::cout << "x = " << x << "\n" << "y = " << y << std::endl;
    */

    // Арифметические операции
    // +, -, *, /, %, ++, --
    int x = 10;
    int y = 3;
    int z = 10 / 3;
    int mod = 10 % 3;
    
    // float f = x / y;
    float f = (x*1.f) / y;
    std::cout << f << std::endl;

    int k = 10;
    k = k + 10;
    k += 10; // -=, *=, /=, %=

    int i = 0;
    i += 1;
    i++; // постфиксный инкремент
    i--; // декремент
    ++i; // префиксный инкремент

    int j = 0;
    std::cout << ++j << std::endl;

    int q = 3.345f; // неявное приведение типа
    int w = (int)3.345f; // явное приведение типа, c-style cast
    int e = static_cast<int>(3.345f); // явное приведение типа, С++ style
    std::cout << q << std::endl;

    unsigned short d1 = 50000; // 2^16, 0..65535
    unsigned short d2 = 60000;
    unsigned short d3 = d1 + d2;
    std::cout << d3 << std::endl;

    unsigned short d4 = -1000;

    // CE
    // RE

    //int d5 = 0;
    //int d6 = 10 / 0;
    //std::cout << d6 / d5 << std::endl;
    //std::cout << d6 << std::endl;

    const int NMax = 10;
    NMax = 1;
    std::cout << NMax << std::endl;


    return 0;
}





