#include <iostream>
#include <set>
#include <functional>

int main()
{
    std::set<int, std::greater<int>> zbior;

    zbior.insert(5);
    zbior.insert(1);
    zbior.insert(8);
    zbior.insert(3);
    zbior.insert(7);

    for (auto it = zbior.begin(); it != zbior.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}