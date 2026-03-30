#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
struct sum_traits
{
    typedef T typ_sumy;
};

template <>
struct sum_traits<char>
{
    typedef int typ_sumy;
};

template <>
struct sum_traits<int>
{
    typedef long int typ_sumy;
};

template <>
struct sum_traits<float>
{
    typedef double typ_sumy;
};

template <>
struct sum_traits<double>
{
    typedef double typ_sumy;
};

template <typename T>
typename sum_traits<T>::typ_sumy suma(T *poczatek, T *koniec)
{
    typedef typename sum_traits<T>::typ_sumy typ_sumy;
    typ_sumy total = typ_sumy();
    for (; poczatek != koniec; ++poczatek)
        total += *poczatek;
    return total;
}

int main()
{
    char napis[] = "@ @ @";
    int dlugosc = strlen(napis);
    cout << "suma znakow (char->int): " << suma(napis, napis + dlugosc) << endl;

    int tab_int[] = {1, 2, 3, 4, 5};
    cout << "suma int (int->long): " << suma(tab_int, tab_int + 5) << endl;

    float tab_float[] = {1.1f, 2.2f, 3.3f};
    cout << "suma float (float->double): " << suma(tab_float, tab_float + 3) << endl;

    return 0;
}