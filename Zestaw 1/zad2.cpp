#include <iostream>
#include <string>

template <typename T, typename U>
T convert(U u)
{
    return (T)u;
}

int main()
{
    double d = 1.618;
    int i = 113;

    std::cout << convert<int>(d) << std::endl;
    std::cout << convert<double>(i) << std::endl;
    std::cout << convert<char>(i) << std::endl;

    return 0;
}