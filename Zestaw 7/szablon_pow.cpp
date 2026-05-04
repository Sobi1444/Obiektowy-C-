#include <iostream>

template <int K, int N>
struct Pow
{
    enum
    {
        val = K * Pow<K, N - 1>::val
    };
};

template <int K>
struct Pow<K, 0>
{
    enum
    {
        val = 1
    };
};

int main()
{
    std::cout << Pow<2, 10>::val << std::endl; // 1024
    std::cout << Pow<3, 4>::val << std::endl;  // 81
    std::cout << Pow<5, 3>::val << std::endl;  // 125
    return 0;
}