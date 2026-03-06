#include <iostream>

template <int N>
struct Wektor
{
    int dane[N];
};

template <template <int N> class C, int K>
void wypisz_rozmiar(C<K>)
{
    std::cout << "rozmiar: " << K << std::endl;
}

int main()
{
    Wektor<3> w1;
    Wektor<5> w2;
    wypisz_rozmiar(w1);
    wypisz_rozmiar(w2);
    return 0;
}