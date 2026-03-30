#include <iostream>
#include <vector>
#include <list>
#include <iterator>
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

// wersja z jawna klasa cech
template <typename Cechy, typename IT>
typename Cechy::typ_sumy suma_iter(IT poczatek, IT koniec)
{
    typedef typename Cechy::typ_sumy typ_sumy;
    typ_sumy total = Cechy::zero();
    for (; poczatek != koniec; ++poczatek)
        total += *poczatek;
    return total;
}

// wersja domyslna - typ elementu pobierany przez iterator_traits
template <typename IT>
typename sum_traits<typename iterator_traits<IT>::value_type>::typ_sumy
suma_iter(IT poczatek, IT koniec)
{
    typedef typename iterator_traits<IT>::value_type typ_elementu;
    return suma_iter<sum_traits<typ_elementu>>(poczatek, koniec);
}

int main()
{
    // vector - RandomAccessIterator
    vector<int> vec = {10, 20, 30, 40};
    cout << "suma vector<int>: " << suma_iter(vec.begin(), vec.end()) << endl;

    // list - BidirectionalIterator
    list<float> lst = {1.5f, 2.5f, 3.0f};
    cout << "suma list<float>: " << suma_iter(lst.begin(), lst.end()) << endl;

    int tab[] = {1, 2, 3, 4, 5};
    cout << "suma int* (wskazniki): " << suma_iter(tab, tab + 5) << endl;

    return 0;
}