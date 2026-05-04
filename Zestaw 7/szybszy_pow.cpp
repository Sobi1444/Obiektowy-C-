#include <iostream>

// N parzyste
template <int N, bool IsEven>
struct PowHelper
{
    static inline double calc(double x)
    {
        double half = PowHelper<N / 2, (N / 2) % 2 == 0>::calc(x);
        return half * half;
    }
};

// N nieparzyste
template <int N>
struct PowHelper<N, false>
{
    static inline double calc(double x)
    {
        double half = PowHelper<N / 2, (N / 2) % 2 == 0>::calc(x);
        return x * half * half;
    }
};

// przypadek bazowy
template <>
struct PowHelper<0, true>
{
    static inline double calc(double x) { return 1.0; }
};

// glowny szablon
template <int N>
inline double pow_fast(double x)
{
    return PowHelper<N, N % 2 == 0>::calc(x);
}

int main()
{
    std::cout << pow_fast<10>(2.0) << std::endl; // 1024
    std::cout << pow_fast<8>(3.0) << std::endl;  // 6561
    std::cout << pow_fast<0>(5.0) << std::endl;  // 1
    return 0;
}