
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
 