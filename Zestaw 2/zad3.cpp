#include <iostream>
#include <vector>
#include <list>

template <class InputIterator, class T>
T accumulate(InputIterator pierwszy, InputIterator ostatni, T init)
{
    T ogolnie = init;
    for (; pierwszy != ostatni; ++pierwszy)
        ogolnie += *pierwszy;
    return ogolnie;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << accumulate(v.begin(), v.end(), 0) << std::endl;

    std::list<double> l = {1.5, 2.5, 3.5};
    std::cout << accumulate(l.begin(), l.end(), 0.0) << std::endl;

    return 0;
}