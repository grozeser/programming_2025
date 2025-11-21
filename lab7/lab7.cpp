#include <iostream>
#include <vector>
#include <array>
#include <ctime>

using namespace std;

//1

void createVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << " ";
    }
    cout << "]\n";
}

void upgradeVector(vector<int>& v) {
    bool found = false;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] % 2 != 0) {
            v.insert(v.begin() + i + 1, 0);
            i++;
            found = true;
        }
    }
    if (!found) {
        v.insert(v.begin(), -1);
        v.push_back(-1);
    }
}

void addFront(vector<int>& v, int value) { v.insert(v.begin(), value); }
void addEnd(vector<int>& v, int value) { v.push_back(value); }
void clearVector(vector<int>& v) { v.clear(); }

void searchElement(const vector<int>& v, int value) {
    vector<int> ces;
    for (size_t i = 0; i < v.size(); i++)
        if (v[i] == value) ces.push_back(i);

    cout << "[";
    for (size_t i = 0; i < ces.size(); i++) {
        cout << ces[i];
        if (i != ces.size() - 1) cout << ",";
    }
    cout << "]\n";
}

//2

void PrintArray(const std::array<int, 10>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i];
        if (i != arr.size() - 1) std::cout << " ";
    }
    std::cout << "]" << std::endl;
}

void RandomArray(std::array<int, 10>& arr, int min = -10, int max = 10) {
    for (int& x : arr) {
        x = std::rand() % (max - min + 1) + min;
    }
}

void Sort(std::array<int, 10>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void SortByValue(std::array<int, 10> arr) {
    std::cout << "По значению - ДО сортировки:" << std::endl;
    PrintArray(arr);
    Sort(arr);
    std::cout << "По значению - ПОСЛЕ сортировки:" << std::endl;
    PrintArray(arr);
}

void SortByReference(std::array<int, 10>& arr) {
    std::cout << "По ссылке - ДО сортировки:" << std::endl;
    PrintArray(arr);
    Sort(arr);
    std::cout << "По ссылке - ПОСЛЕ сортировки:" << std::endl;
    PrintArray(arr);
}

void SortByPointer(std::array<int, 10>* arr) {
    std::cout << "По указателю - ДО сортировки:" << std::endl;
    PrintArray(*arr);
    Sort(*arr);
    std::cout << "По указателю - ПОСЛЕ сортировки:" << std::endl;
    PrintArray(*arr);
}

int main() {
    setlocale(LC_ALL, "RU");
    srand((unsigned int)time(0));

    vector<int> v = { 1, 32, 4 };
    int choice, value;

    while (true) {
        cout << "0. Выход\n1. Просмотр массива\n2. Добавить элемент в начало\n3. Добавить элемент в конец\n4. Очистка массива\n5. Поиск элемента\n6. Задание варианта\n";
        cout << "Выберите пункт: ";
        cin >> choice;

        switch (choice) {
        case 0: return 0;
        case 1: createVector(v); break;
        case 2:
            cout << "Введите число для начала: ";
            cin >> value;
            addFront(v, value);
            createVector(v);
            break;
        case 3:
            cout << "Введите число для конца: ";
            cin >> value;
            addEnd(v, value);
            createVector(v);
            break;
        case 4:
            clearVector(v);
            createVector(v);
            break;
        case 5:
            cout << "Введите число для поиска: ";
            cin >> value;
            searchElement(v, value);
            break;
        case 6:
            cout << "До изменения: ";
            createVector(v);
            upgradeVector(v);
            cout << "После изменения: ";
            createVector(v);
            break;
        }
    }
}
