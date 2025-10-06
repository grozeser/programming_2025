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
