#include <iostream>
#include <cstring>

// szkielet szablonu
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

// przeciazenie dla wskaznikow
template <typename T>
T *max(T *a, T *b)
{
    return ((*a) > (*b)) ? a : b;
}

// przeciazenie dla tablicy
template <typename T>
T max(T *data, size_t n)
{
    T wynik = data[0];
    for (size_t i = 1; i < n; ++i)
        if (data[i] > wynik)
            wynik = data[i];
    return wynik;
}

// specka dla char*
template <>
char *max(char *a, char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

// specka dla const char*
template <>
const char *max(const char *a, const char *b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

template <typename T>
const T *max(T *a, const T *b)
{
    return ((*a) > (*b)) ? a : b;
}

int main()
{
    int i = 3, j = 7;
    std::cout << max(i, j) << std::endl;

    int *pi = &i, *pj = &j;
    std::cout << *max(pi, pj) << std::endl;

    int tab[] = {3, 1, 4, 1, 5, 9};
    std::cout << max(tab, (size_t)6) << std::endl;

    char s1[] = "Naomi";
    char s2[] = "Daria";
    std::cout << max(s1, s2) << std::endl;

    const char *cs1 = "Naomi";
    const char *cs2 = "Daria";
    std::cout << max(cs1, cs2) << std::endl;

    std::cout << max(s1, cs2) << std::endl;

    return 0;
}