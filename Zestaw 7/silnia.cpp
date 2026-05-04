#include <iostream>

template <int N>
struct Factorial
{
    enum
    {
        val = N * Factorial<N - 1>::val
    };
};

template <>
struct Factorial<0>
{
    enum
    {
        val = 1
    };
};

int main()
{
    std::cout << Factorial<5>::val << std::endl;  // 120
    std::cout << Factorial<10>::val << std::endl; // 3628800
    return 0;
}