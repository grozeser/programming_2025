#include <iostream>

int main() {

    setlocale(LC_ALL, "Russian");

    // 1

    const int N = 9;
    int arr[N];
    std::cout << "Введите 9 целых чисел:" << std::endl;
    for (int i = 0; i < N; ++i)
        std::cin >> arr[i];
  
    int start3 = 0; 
    for (int i = 0; i < N; ++i) {
        int x = arr[i];
        if (x < 0)
            x = x * (-1);
        while (x >= 10)
            x = x / 10;
        if (x == 3) {
            start3 = 1;
            break;
        }
    }
  
    if (start3 == 1) {
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (arr[i] > arr[j]) {
                    int T = arr[i];
                    arr[i] = arr[j];
                    arr[j] = T;
                }
            }
        }
       
        std::cout << "\nесть число, начинающееся с 3:" << std::endl;
    }
    else {
        std::cout << "\nнет числа, начинающегося с 3" << std::endl;
    }
   
    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int I = arr[i];
            if (I < 0) {
                I = -I;
            }

            int sum_i = 0;
            while (I > 0) {
                sum_i += I % 10;
                I = I / 10;
            }

            int J = arr[j];
            if (J < 0) {
                J = -J;
            }

            int sum_j = 0;
            while (J > 0) {
                sum_j += J % 10;
                J = J / 10;
            }

            if (sum_i > sum_j) {
                int W = arr[i];
                arr[i] = arr[j];
                arr[j] = W;
            }
        }
    }
    
    std::cout << "\nМассив, упорядоченный по возрастанию суммы цифр:" << std::endl;
    for (int i = 0; i < N; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
    // 2

    const int line = 3;
    const int stl = 4;
    int matrix[line][stl];

    std::cout << "\nВведите элементы матрицы 3x4:" << std::endl;
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < stl; ++j)
            std::cin >> matrix[i][j];
    }

    int maxLine = 0;
    int maxSum = 0;
    int first = 1;

    for (int i = 0; i < line; ++i) {
        int sum = 0;
        for (int j = 0; j < stl; ++j)
            sum = sum + matrix[i][j];

        int absSum = sum;
        if (absSum < 0) {
            absSum = -absSum;
        }
        int absMax = maxSum;
        if (absMax < 0) {
            absMax = -absMax;
        }

        if (first == 1 || absSum > absMax) {
            maxSum = sum;
            maxLine = i;
            first = 0;
        }
    }

    for (int j = 0; j < stl; ++j)
        matrix[maxLine][j] = 999;

    std::cout << "\nМатрица после замены строки:" << std::endl;
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < stl; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
