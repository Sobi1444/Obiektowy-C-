#include <iostream>
#include <string>

template <typename T>
T maksimum(T a, T b)
{
    return (b < a) ? a : b;
}

int main()
{

    int i1 = 7, i2 = 5;
    std::cout << maksimum(i1, i2) << std::endl;
    double d1 = 3.1415, d2 = 2.71;
    std::cout << maksimum(d1, d2) << std::endl;
    std::string s1 = "Ania", s2 = "Basia";
    std::cout << maksimum(s1, s2) << std::endl;
    std::cout << maksimum<double>(3, 5) << std::endl;

    return 0;
}