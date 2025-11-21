#include <iostream> 
#include "matrix.hpp"

void createMatrix(int** matrix, int rows, int columns){
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < columns; ++j){
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int* zeroNum(int** a, int rows, int cols){
    int zero = 0;
    int* del = (int*)calloc(rows, sizeof(int));
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            if (a[i][j] == 0){
                ++zero;
                del[zero - 1] = i;
                break;
            }
        }
    }
    return del;
}

void RunMatrix(){
    int a, b, c, d;

    do {
        std::cout << "¬ведите A: ";
        std::cin >> a;
        if (a < 0){
            std::cout << "A отрицательное. ¬водите неотрицательное число." << std::endl;
        }
    } while (a < 0);

    do {
        std::cout << "¬ведите B: ";
        std::cin >> b;
        if (b < 0){
            std::cout << "B отрицательное. ¬водите неотрицательное число." << std::endl;
        }
    } while (b < 0);

    std::cout << "¬ведите C: ";
    std::cin >> c;
    std::cout << "¬ведите D: ";
    std::cin >> d;

    int** arr = (int**)malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; ++i)
        arr[i] = (int*)malloc(2 * sizeof(int));

    arr[0][0] = a;
    arr[0][1] = b;
    arr[1][0] = c;
    arr[1][1] = d;


    int rows = 2+a;
    int cols = 2+b;

    arr = (int**)realloc(arr, rows * sizeof(int*));
    for (int i = 0; i < rows; ++i){
            arr[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            arr[i][j] = i * c + j * d;

    int* tmp = zeroNum(arr, rows, cols);

    int countDelete = rows;
    for (int i = 1; i < rows; ++i){
        if (tmp[i] == 0){
            countDelete = i;
            break;
        }
    }

    for (int digit = 0; digit < countDelete; ++digit){
        --rows;
        int* pointer = arr[tmp[digit]];
        for (int i = tmp[digit]; i < rows; ++i)
            arr[i] = arr[i + 1];

        for (int i = digit + 1; i < countDelete; ++i)
            --tmp[i];

        free(pointer);
    }

    if (rows)
        arr = (int**)realloc(arr, rows * sizeof(int*));

    createMatrix(arr, rows, cols);

    for (int i = 0; i < rows; ++i)
        free(arr[i]);

    free(arr);
    free(tmp);
}




