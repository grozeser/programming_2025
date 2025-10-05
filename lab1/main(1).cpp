#include <iostream>
#include <cmath>

//S = √p(p - a)(p - b)(p - c) - формула Герона
//p = (a + b + c) / 2 - формула полупериметра

int main()
{

    setlocale(LC_ALL, "Russian");

    int a, b, c, r1, r2;
    r1 = sizeof(int) * 8;
    std::cin >> a >> b >> c;
    
    double p, S; 
    r2 = sizeof(double) * 8;
   

    p = (a + b + c) / 2.0;
    S = std::sqrt(p * (p - a) * (p - b) * (p - c));
     
    std::cout << " int занимает " << r1 << "битов. Min=" << INT_MIN << "Max=" << INT_MAX << std::endl;
    std::cout << " double занимает " << r2 << "битов. Min=" << DBL_MIN << "Max=" << DBL_MAX << std::endl;
    

    std::cout << S << std::endl;


    return 0;
}




#include <iostream>
#include <bitset>

using namespace std;


//1



/*
int main() {

    short A;
    int i;

    cout << "A (0..255): ";
    cin >> A;
    cout << "i (0..7): ";
    cin >> i;


    bool bit = (A >> i) & 1;

    if (bit == 0) {
        short B = A * A;
        B &= ~(1 << i);

        cout << i << endl;

    }
    else {
        short C = 125;

        switch (i)
        case 0:
        case 2:
        case 4:
        case 6:
            for (int j = 0; j < 8; j += 2)
                C &= ~(1 << j);

            cout << C << endl;
    
            std::cout << A <<  " = " << std::bitset<8>(A) << std::endl;
    }

    return 0;
}*/ 


//2

 


int main() {
    setlocale(LC_ALL, "Russian");

    int N;
    cout << "Введите номер маршрута: ";
    cin >> N;

    switch (N) {




    case 113: cout << "КАЛИНИНГРАД – ЧАПАЕВО"; break;

    case 114: cout << "КАЛИНИНГРАД – ЗЕЛЕНОГРАДСК"; break;

    case 117: cout << "КАЛИНИНГРАД – МАМOНОВО"; break;

    case 118: cout << "КАЛИНИНГРАД – СВЕТЛОГОРСК"; break;

    case 119: cout << "КАЛИНИНГРАД – ПИОНЕРСКИЙ"; break;

    case 125: cout << "КАЛИНИНГРАД – ДОНСКОЕ"; break;

    case 136: cout << "КАЛИНИНГРАД – ПАРТИЗАНСКОЕ"; break;

    case 141: cout << "КАЛИНИНГРАД – ЗЕЛЕНОГРАДСК"; break;

    case 148: cout << "КАЛИНИНГРАД – БАГРАТИОНОВСК"; break;

    case 161: cout << "КАЛИНИНГРАД – СВЕТЛОЕ"; break;

    case 191: cout << "КАЛИНИНГРАД – БАГРАТИОНОВСК"; break;

    case 593: cout << "КАЛИНИНГРАД – МОРСКОЕ"; break;

    case 802: cout << "КАЛИНИНГРАД – ГДАНЬСК"; break;




    default: cout << "Маршрут с номером " << N << " не найден."; break;
    }

    return 0;
}
 


#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

  //1


    int N;
    cout << "Введите количество чисел в последовательности: ";
    cin >> N;

    int sum = 0;
    int max = 0;
    int num = 0;
    bool B = false;

    for (int i = 1; i <= N; i++) {
        int a;
        cout << "A" << i << " = ";
        cin >> a;

     
        if (a % 3 == 0 || a % 5 == 0 || a % 7 == 0) {
            continue;
        }

        sum += a;
        if (!B || a > max) {
            max = a;
            num = i;
        }
        B = true;
    }

    if (!B) {
        cout << "числа кратны 3, 5 и 7." << endl;
    }
    else {
        cout << "Сумма чисел = " << sum << endl;
        cout << "Наибольшее число = " << max << endl;
        cout << "Его номер в последовательности = " << num << endl;
    }

    //2


    int X;
    cout << "\nцелое число |X| < 1000: ";
    cin >> X;

    
    int digits = 0;
    int  Y = X;
    if (Y == 0) {
        digits = 1;
    }
    else {
        while (Y > 0) {
            ++digits;
            Y /= 10;
        }
    }

    
    int fDigit = X;
    if (fDigit == 0) {
        fDigit = 0;
    }
    else {
        do {
            if (fDigit < 10) break;
            fDigit /= 10;
        } while (fDigit >= 10);
    }

    cout << "Количество разрядов = " << digits << endl;
    cout << "Первая цифра = " << fDigit << endl;

    return 0;
}
