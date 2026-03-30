#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
struct sum_traits
{
    typedef T typ_sumy;
    static typ_sumy zero() { return typ_sumy(); }
};

template <>
struct sum_traits<char>
{
    typedef int typ_sumy;
    static typ_sumy zero() { return 0; }
};

template <>
struct sum_traits<int>
{
    typedef long int typ_sumy;
    static typ_sumy zero() { return 0L; }
};

template <>
struct sum_traits<float>
{
    typedef double typ_sumy;
    static typ_sumy zero() { return 0.0; }
};

template <>
struct sum_traits<double>
{
    typedef double typ_sumy;
    static typ_sumy zero() { return 0.0; }
};

struct sum_char
{
    typedef char typ_sumy;
    static typ_sumy zero() { return 0; }
};

// wersja ogolna - klasa cech podana jawnie
template <typename Cechy, typename T>
typename Cechy::typ_sumy suma(T *poczatek, T *koniec)
{
    typedef typename Cechy::typ_sumy typ_sumy;
    typ_sumy total = Cechy::zero();
    for (; poczatek != koniec; ++poczatek)
        total += *poczatek;
    return total;
}

// wersja domyslna - wywoluje ogolna z sum_traits
template <typename T>
typename sum_traits<T>::typ_sumy suma(T *poczatek, T *koniec)
{
    return suma<sum_traits<T>, T>(poczatek, koniec);
}

int main()
{
    char napis[] = "@ @ @";
    int dlugosc = strlen(napis);

    // char -> int
    cout << "suma znakow (char->int): " << suma(napis, napis + dlugosc) << endl;

    // jawnie podana sum_char: wynik typu char
    cout << "suma char->char (sum_char): "
         << (int)suma<sum_char>(napis, napis + dlugosc) << endl;

    return 0;
}