#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

template <typename IT>
typename iterator_traits<IT>::difference_type
__odleglosc(IT poczatek, IT koniec, input_iterator_tag)
{
    typename iterator_traits<IT>::difference_type n = 0;
    while (poczatek != koniec)
    {
        ++poczatek;
        ++n;
    }
    return n;
}

// dwukierunkowy
template <typename IT>
typename iterator_traits<IT>::difference_type
__odleglosc(IT poczatek, IT koniec, bidirectional_iterator_tag)
{
    typename iterator_traits<IT>::difference_type n = 0;
    while (poczatek != koniec)
    {
        ++poczatek;
        ++n;
    }
    return n;
}

// swobodny dostep
template <typename IT>
typename iterator_traits<IT>::difference_type
__odleglosc(IT poczatek, IT koniec, random_access_iterator_tag)
{
    return koniec - poczatek;
}

// dispatcher - tworzy obiekt kategorii i przekazuje do odpowiedniej wersji
template <typename IT>
typename iterator_traits<IT>::difference_type
odleglosc(IT poczatek, IT koniec)
{
    typedef typename iterator_traits<IT>::iterator_category kategoria;
    return __odleglosc(poczatek, koniec, kategoria());
}

// minimalny iterator forward do testow
struct IterForward
{
    using iterator_category = forward_iterator_tag;
    using value_type = int;
    using difference_type = ptrdiff_t;
    using pointer = const int *;
    using reference = const int &;
    const int *ptr;
    IterForward(const int *p) : ptr(p) {}
    bool operator!=(const IterForward &o) const { return ptr != o.ptr; }
    IterForward &operator++()
    {
        ++ptr;
        return *this;
    }
    const int &operator*() const { return *ptr; }
};

int main()
{
    // rnd access
    vector<int> v = {1, 2, 3, 4, 5, 6};
    cout << "vector (random access): " << odleglosc(v.begin(), v.end()) << endl;

    // bidirectional
    list<int> l = {1, 2, 3, 4};
    cout << "list (bidirectional): " << odleglosc(l.begin(), l.end()) << endl;

    // forward - gorzej niz dwukierunkowy
    int raw[] = {1, 2, 3};
    cout << "forward iterator: "
         << odleglosc(IterForward(raw), IterForward(raw + 3)) << endl;

    return 0;
}