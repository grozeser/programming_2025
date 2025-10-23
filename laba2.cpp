
#include <iostream>
#include <bitset>

using namespace std;

//1

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
        C &= 0b10101010;
        cout << i << endl;

        cout << "A = " << A << bitset<8>(A) << endl;
           
        
    }
    



//2

 
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


    case 148: 
    case 191: cout << "КАЛИНИНГРАД – БАГРАТИОНОВСК"; break;

    case 161: cout << "КАЛИНИНГРАД – СВЕТЛОЕ"; break;

    case 593: cout << "КАЛИНИНГРАД – МОРСКОЕ"; break;

    case 802: cout << "КАЛИНИНГРАД – ГДАНЬСК"; break;




    default: cout << "Маршрут с номером " << N << " не найден."; break;
    }

    return 0;
}
 