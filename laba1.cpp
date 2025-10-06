#include <iostream>
#include <cmath>

//S = √p(p - a)(p - b)(p - c) - формула Герона
//p = (a + b + c) / 2 - формула полупериметра

int main()
{

    setlocale(LC_ALL, "Russian");

    int a, b, c;     
    float r1 = sizeof(float)*8;  
    int r2 = sizeof(int) * 8;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;


    float p;
    float S;

    p = (a + b + c) / 2;
    S = sqrt(p(p - a)(p - b)(p - c));

    std::cout << " int занимает " << r1 << "битов. Min=" << INT_MIN << "Max=" << INT_MAX << std::endl;
    std::cout << " int занимает " << r1 << "битов. Min=" << INT_MIN << "Max=" << INT_MAX << std::endl;
    std::cout << " int занимает " << r1 << "битов. Min=" << INT_MIN << "Max=" << INT_MAX << std::endl;

    std::cout << S << std::endl;
    

    return 0;
}


