#include <iostream>
#include <cmath>
using namespace std;


//1


int sumOfDigits(int x) {
    x = abs(x);
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}


bool start3(int x) {
    x = abs(x);
    while (x >= 10)
        x /= 10;
    return x == 3;
}


int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 9;       
    int arr[N];            
    cout << "Введите 9 целых чисел:" << endl;

    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    
    bool St3 = false;
    for (int i = 0; i < N; ++i) {
        if (start3(arr[i])) {
            St3 = true;
            break;
        }
    }
    

    if (St3) {
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (arr[i] > arr[j]) {
                    int tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        cout << "\nМассив упорядочен (есть число начинающееся с 3):\n";
    }
    else {
        cout << "\nМассив не упорядочен (нет числа начинающегося с 3)\n";
    }
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;

    
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (sumOfDigits(arr[i]) > sumOfDigits(arr[j])) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }


    cout << "\nМассив, упорядоченный по возрастанию суммы цифр:\n";
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << endl;


   //2


    const int line = 3;
    const int stl = 4;
    int matrix[line][stl];
    cout << "\nВведите элементы матрицы 3x4:\n";

    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < stl; ++j) {
            cin >> matrix[i][j];
        }
    }
   

    int maxLine = 0;
    int maxSum = 0;
    bool first = true;

    for (int i = 0; i < line; ++i) {
        int sum = 0;
        for (int j = 0; j < stl; ++j)
            sum += matrix[i][j];

        if (first || abs(sum) > abs(maxSum)) {
            maxSum = sum;
            maxLine = i;
            first = false;
        }
    }
    

    for (int j = 0; j < stl; ++j)
        matrix[maxLine][j] = 999;
    cout << "\nМатрица после замены строки:\n";

    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < stl; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
