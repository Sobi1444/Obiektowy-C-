#include <iostream>

template <typename T>
class Stos
{
    static const size_t N = 100;
    T dane[N];
    size_t wierzcholek;

public:
    typedef T typ_wartosci;

    Stos() : wierzcholek(0) {}
    void push(T wartosc) { dane[wierzcholek++] = wartosc; }
    T pop() { return dane[--wierzcholek]; }
    bool jest_pusty() { return wierzcholek == 0; }
};

template <typename S>
typename S::typ_wartosci suma(S stos)
{
    typename S::typ_wartosci wynik = 0;
    while (!stos.jest_pusty())
    {
        wynik += stos.pop();
    }
    return wynik;
}

int main()
{
    Stos<int> s1;
    s1.push(44);
    s1.push(21);
    s1.push(55);
    std::cout << suma(s1) << std::endl;

    Stos<double> s2;
    s2.push(13.5);
    s2.push(24.5);
    s2.push(31.0);
    std::cout << suma(s2) << std::endl;

    return 0;
}