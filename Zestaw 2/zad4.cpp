#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

template <typename T>
class SequenceGen
{
    T poczatek;
    T krok;

public:
    SequenceGen(T poczatek = T(), T krok = 1) : poczatek(poczatek), krok(krok) {}
    T operator()()
    {
        T tmp = poczatek;
        poczatek += krok;
        return tmp;
    }
};

int main()
{
    const size_t n = 20;
    std::vector<int> v(n);

    std::generate_n(v.begin(), n, SequenceGen<int>(1, 2));

    std::vector<int>::iterator it = std::find_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));

    if (it != v.end())
        std::cout << *it << std::endl;
    else
        std::cout << "nie znaleziono" << std::endl;

    return 0;
}