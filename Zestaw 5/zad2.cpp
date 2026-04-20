#include <iostream>
#include <vector>

template <typename T>
class Has_value_type
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    // proba wziecia value_type z U - jesli nie istnieje to SFINAE odpada
    template <typename U>
    static one test(typename U::value_type *);
    template <typename U>
    static two test(...);

public:
    enum
    {
        yes = (sizeof(test<T>(0)) == sizeof(one))
    };
};

int main()
{
    std::cout << "vector<int>: " << Has_value_type<std::vector<int>>::yes << std::endl;
    std::cout << "int: " << Has_value_type<int>::yes << std::endl;
    return 0;
}