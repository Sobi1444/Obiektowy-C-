#include <iostream>

template <typename T, typename U>
T convert(U u)
{
    return static_cast<T>(u);
}

template <>
int convert<int, double>(double u)
{
    std::cout << "specjalizacja int: ";
    return static_cast<int>(u);
}

template <>
double convert<double, double>(double u)
{
    std::cout << "specjalizacja double: ";
    return u;
}

int main()
{
    std::cout << convert<int>(3.14) << std::endl;
    std::cout << convert<double>(2.71) << std::endl;
    std::cout << convert<char>(65) << std::endl;

    return 0;
}