#include <iostream>

template <typename T, typename U>
class Is_convertible
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    static one test(U);
    static two test(...);

    // funkcja zamiast T() bo konstruktor moze nie istniec
    static T makeT();

public:
    enum
    {
        yes = (sizeof(test(makeT())) == sizeof(one)),
        same_type = false
    };
};

// specjalizacja dla identycznych typow
template <typename T>
class Is_convertible<T, T>
{
public:
    enum
    {
        yes = true,
        same_type = true
    };
};

int main()
{
    std::cout << "int->double: " << Is_convertible<int, double>::yes << std::endl;
    std::cout << "double->int: " << Is_convertible<double, int>::yes << std::endl;
    std::cout << "int->int: " << Is_convertible<int, int>::yes << std::endl;
    std::cout << "same int->int: " << Is_convertible<int, int>::same_type << std::endl;
    return 0;
}