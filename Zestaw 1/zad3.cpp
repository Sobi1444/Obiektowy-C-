#include <iostream>

template <size_t N, typename T>
T iloczyn_skalarny(T *a, T *b)
{
    T wynik = 0;
    for (size_t i = 0; i < N; ++i)
        wynik += a[i] * b[i];
    return wynik;
}

int main()
{
    double v1[] = {1.0, 2.0, 3.0};
    double v2[] = {4.0, 5.0, 6.0};
    std::cout << iloczyn_skalarny<3>(v1, v2) << std::endl;

    int u1[] = {1, 2, 3, 4};
    int u2[] = {5, 6, 7, 8};
    std::cout << iloczyn_skalarny<4>(u1, u2) << std::endl;

    return 0;
}