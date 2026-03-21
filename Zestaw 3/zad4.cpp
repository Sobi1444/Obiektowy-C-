#include <iostream>
#include <vector>

// szablon podstawowy bez definicji
template <typename T, int N = 100, typename R = T *>
class Stack;

// specka dla zwyklych tablic
template <typename T, int N>
class Stack<T, N, T *>
{
    T _rep[N];
    int wierzcholek;

public:
    Stack() : wierzcholek(0) {}
    void push(T e) { _rep[wierzcholek++] = e; }
    T pop() { return _rep[--wierzcholek]; }
    bool jest_pusty() { return wierzcholek == 0; }
};

// specka dla kontenerow STL
template <typename T, int N, template <typename E, typename A> class Sequence>
class Stack<T, N, Sequence<T, std::allocator<T>>>
{
    Sequence<T, std::allocator<T>> _rep;

public:
    void push(T e) { _rep.push_back(e); }
    T pop()
    {
        T top = _rep.back();
        _rep.pop_back();
        return top;
    }
    bool jest_pusty() { return _rep.empty(); }
};

int main()
{
    Stack<int, 100> s_default;
    s_default.push(1);
    s_default.push(2);
    s_default.push(3);
    std::cout << s_default.pop() << std::endl;
    std::cout << s_default.pop() << std::endl;

    Stack<int, 0, std::vector<int>> s_container;
    s_container.push(4);
    s_container.push(5);
    s_container.push(6);
    std::cout << s_container.pop() << std::endl;
    std::cout << s_container.pop() << std::endl;

    return 0;
}