#include <iostream>
#include <set>
#include <functional>
#include <algorithm>

int main()
{
    // less - domyslne sortowanie rosnaco
    std::set<int, std::less<int>> zbior_rosnaco;
    zbior_rosnaco.insert(5);
    zbior_rosnaco.insert(1);
    zbior_rosnaco.insert(8);
    zbior_rosnaco.insert(3);
    std::cout << "less (rosnaco): ";
    for (auto it = zbior_rosnaco.begin(); it != zbior_rosnaco.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // greater - sortowanie malejaco
    std::set<int, std::greater<int>> zbior_malejaco;
    zbior_malejaco.insert(5);
    zbior_malejaco.insert(1);
    zbior_malejaco.insert(8);
    zbior_malejaco.insert(3);
    std::cout << "greater (malejaco): ";
    for (auto it = zbior_malejaco.begin(); it != zbior_malejaco.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    // less_equal i greater_equal na vector z sort
    std::vector<int> v = {5, 1, 8, 3, 7};

    std::sort(v.begin(), v.end(), std::less_equal<int>());
    std::cout << "less_equal: ";
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;

    std::sort(v.begin(), v.end(), std::greater_equal<int>());
    std::cout << "greater_equal: ";
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}