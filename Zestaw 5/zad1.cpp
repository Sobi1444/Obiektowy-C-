#include <iostream>

template <typename T>
class Is_class
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    // jesli T jest klasa to int T::* jest poprawne
    template <typename U>
    static one test(int U::*);
    // ta wersja pasuje do wszystkiego
    template <typename U>
    static two test(...);

public:
    enum
    {
        yes = (sizeof(test<T>(0)) == sizeof(one))
    };
};

struct Foo
{
    int x;
};

int main()
{
    std::cout << "Foo: " << Is_class<Foo>::yes << std::endl;
    std::cout << "int: " << Is_class<int>::yes << std::endl;
    return 0;
}