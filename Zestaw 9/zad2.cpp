#include <iostream>
#include <memory>

int main()
{
    // unique ptr trzyma tylko jeden surowy wskaznik wiec ma taki sam rozmiar
    std::cout << "sizeof(int*)             = " << sizeof(int *) << "\n";
    std::cout << "sizeof(unique_ptr<int>)  = " << sizeof(std::unique_ptr<int>) << "\n";

    // shared ptr trzyma dwa wskazniki na obiekt i na blok kontrolny
    std::cout << "sizeof(shared_ptr<int>)  = " << sizeof(std::shared_ptr<int>) << "\n";

    return 0;
}