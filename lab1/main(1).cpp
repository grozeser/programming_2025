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